import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.program.model.symbol.SourceType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class ExportSelectedFunctions extends GhidraScript {

	private static class TargetRow {
		String requestedName;
		String addressText;
		Address address;
		Function function;
		String status;
		boolean created;
		boolean renamed;
	}

	private static String sanitizeStem(String name) {
		String lower = name.toLowerCase();
		if (lower.endsWith(".exe") || lower.endsWith(".dll")) {
			lower = lower.substring(0, lower.lastIndexOf('.'));
		}
		return lower.replaceAll("[^a-z0-9_-]", "_");
	}

	private static void writeLines(Path output, List<String> lines) throws IOException {
		try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
			for (String line : lines) {
				writer.write(line);
				writer.newLine();
			}
		}
	}

	private static String formatAddress(Address address) {
		return address == null ? "N/A" : address.toString();
	}

	private static List<TargetRow> parseTargetsFromSpec(String spec) {
		List<TargetRow> rows = new ArrayList<>();
		for (String rawEntry : spec.split(";")) {
			String entry = rawEntry.trim();
			if (entry.isEmpty()) {
				continue;
			}

			String requestedName = entry;
			String addressText = entry;
			int split = entry.indexOf('=');
			if (split >= 0) {
				requestedName = entry.substring(0, split).trim();
				addressText = entry.substring(split + 1).trim();
			}

			TargetRow row = new TargetRow();
			row.requestedName = requestedName;
			row.addressText = addressText;
			rows.add(row);
		}
		return rows;
	}

	private static List<TargetRow> parseTargets(String[] args, int startIndex) {
		List<TargetRow> rows = new ArrayList<>();
		if (startIndex >= args.length) {
			return rows;
		}

		if (args.length - startIndex == 1) {
			String argument = args[startIndex];
			if (argument.startsWith("@")) {
				return parseTargetsFromFile(argument.substring(1));
			}
			return parseTargetsFromSpec(argument);
		}

		for (int i = startIndex; i < args.length; i++) {
			String current = args[i].trim();
			if (current.isEmpty()) {
				continue;
			}

			if (current.contains("=")) {
				rows.addAll(parseTargetsFromSpec(current));
				continue;
			}

			TargetRow row = new TargetRow();
			row.requestedName = current;
			if (i + 1 < args.length) {
				row.addressText = args[++i].trim();
			}
			else {
				row.addressText = current;
			}
			rows.add(row);
		}

		return rows;
	}

	private static List<TargetRow> parseTargetsFromFile(String pathText) {
		Path path = Paths.get(pathText);
		List<String> lines;
		try {
			lines = Files.readAllLines(path, StandardCharsets.UTF_8);
		}
		catch (IOException exception) {
			throw new IllegalArgumentException("Unable to read target list: " + pathText, exception);
		}

		List<TargetRow> rows = new ArrayList<>();
		for (String rawLine : lines) {
			String line = rawLine.trim();
			if (line.isEmpty() || line.startsWith("#")) {
				continue;
			}
			rows.addAll(parseTargetsFromSpec(line));
		}
		return rows;
	}

	private Function ensureFunctionAt(FunctionManager functionManager, TargetRow row) throws Exception {
		Function function = functionManager.getFunctionAt(row.address);
		if (function != null) {
			row.status = "existing";
			return maybeRenameExactMatch(function, row);
		}

		Function containing = functionManager.getFunctionContaining(row.address);
		if (containing != null && !containing.getEntryPoint().equals(row.address)) {
			row.status = "inside_existing:" + containing.getName() + "@" + formatAddress(containing.getEntryPoint());
			return containing;
		}

		disassemble(row.address);
		function = functionManager.getFunctionAt(row.address);
		if (function == null) {
			function = createFunction(row.address, row.requestedName);
			if (function != null) {
				row.created = true;
			}
		}

		if (function == null) {
			containing = functionManager.getFunctionContaining(row.address);
			if (containing != null) {
				row.status = "inside_existing:" + containing.getName() + "@" + formatAddress(containing.getEntryPoint());
				return containing;
			}

			row.status = "missing";
			return null;
		}

		function = maybeRenameExactMatch(function, row);

		if (row.status == null) {
			row.status = row.created ? "created" : "existing";
		}
		return function;
	}

	private Function maybeRenameExactMatch(Function function, TargetRow row) {
		if (function == null || !function.getEntryPoint().equals(row.address)) {
			return function;
		}

		String currentName = function.getName();
		if (row.requestedName.equals(currentName)) {
			return function;
		}

		try {
			function.setName(row.requestedName, SourceType.USER_DEFINED);
			row.renamed = true;
		}
		catch (Exception ignored) {
			// Keep the existing name if the requested rename fails.
		}
		return function;
	}

	private void appendDecompile(
		DecompInterface decompiler,
		TargetRow row,
		Function function,
		List<String> outputLines
	) {
		String name = function == null ? row.requestedName : function.getName();
		long size = function == null ? 0 : function.getBody().getNumAddresses();
		outputLines.add(
			"/* " + name + " @ " + row.addressText + " status " + row.status + " size " + size + " */"
		);

		if (function == null) {
			outputLines.add("/* no function recovered */");
			outputLines.add("");
			return;
		}

		DecompileResults results = decompiler.decompileFunction(function, 90, monitor);
		if (results == null || !results.decompileCompleted() || results.getDecompiledFunction() == null) {
			outputLines.add("/* decompile failed */");
			outputLines.add("");
			return;
		}

		outputLines.add(results.getDecompiledFunction().getC());
		outputLines.add("");
	}

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length < 2) {
			throw new IllegalArgumentException(
				"Usage: ExportSelectedFunctions.java <output_root> <name=address;...> or <output_root> <name> <address> ..."
			);
		}

		Program program = currentProgram;
		Path outputRoot = Paths.get(args[0]);
		Path programOutputDir = outputRoot.resolve(sanitizeStem(program.getName()));
		Files.createDirectories(programOutputDir);

		List<TargetRow> targets = parseTargets(args, 1);
		FunctionManager functionManager = program.getFunctionManager();

		monitor.setMessage("Recovering selected functions for " + program.getName());
		for (TargetRow row : targets) {
			row.address = toAddr(row.addressText);
			row.function = ensureFunctionAt(functionManager, row);
			if (row.status == null) {
				row.status = "existing";
			}
		}

		List<String> summary = new ArrayList<>();
		summary.add("requested_name,address,status,actual_name,entry,size,renamed");
		for (TargetRow row : targets) {
			String actualName = row.function == null ? "" : row.function.getName();
			String entry = row.function == null ? "" : formatAddress(row.function.getEntryPoint());
			long size = row.function == null ? 0 : row.function.getBody().getNumAddresses();
			summary.add(
				row.requestedName + "," +
				row.addressText + "," +
				row.status + "," +
				actualName + "," +
				entry + "," +
				size + "," +
				row.renamed
			);
		}
		writeLines(programOutputDir.resolve("selected_functions_summary.csv"), summary);

		DecompInterface decompiler = new DecompInterface();
		decompiler.openProgram(program);

		List<String> decompLines = new ArrayList<>();
		decompLines.add("/*");
		decompLines.add("Program: " + program.getName());
		decompLines.add("Decompiled selected functions");
		decompLines.add("*/");
		decompLines.add("");

		for (TargetRow row : targets) {
			appendDecompile(decompiler, row, row.function, decompLines);
		}

		writeLines(programOutputDir.resolve("decompile_selected_functions.c"), decompLines);
		println("Exported selected functions for " + program.getName() + " -> " + programOutputDir);
	}
}
