import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.program.model.symbol.ExternalLocation;
import ghidra.program.model.symbol.ExternalLocationIterator;
import ghidra.program.model.symbol.ExternalManager;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ExportOblivionReference extends GhidraScript {

	private static class FunctionRow {
		String name;
		Address entry;
		long size;
		boolean thunk;
		String callingConvention;
	}

	private static class ExportRow {
		Address address;
		String symbolName;
	}

	private static String sanitizeStem(String name) {
		String lower = name.toLowerCase();
		if (lower.endsWith(".exe") || lower.endsWith(".dll")) {
			lower = lower.substring(0, lower.lastIndexOf('.'));
		}
		return lower.replaceAll("[^a-z0-9_-]", "_");
	}

	private static String csvEscape(String value) {
		if (value == null) {
			return "";
		}
		if (!value.contains(",") && !value.contains("\"") && !value.contains("\n")) {
			return value;
		}
		return "\"" + value.replace("\"", "\"\"") + "\"";
	}

	private static String formatAddress(Address address) {
		return address == null ? "N/A" : address.toString();
	}

	private static void writeLines(Path output, List<String> lines) throws IOException {
		try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
			for (String line : lines) {
				writer.write(line);
				writer.newLine();
			}
		}
	}

	private void appendDecompile(
		DecompInterface decompiler,
		Function function,
		long size,
		List<String> outputLines
	) {
		outputLines.add("/* " + function.getName() + " @ " + formatAddress(function.getEntryPoint()) + " size " + size + " */");
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
		if (args.length < 1) {
			throw new IllegalArgumentException(
				"Usage: ExportOblivionReference.java <output_root> [max_decomp_functions]"
			);
		}

		int maxDecomp = 120;
		if (args.length >= 2) {
			maxDecomp = Integer.parseInt(args[1]);
		}

		Program program = currentProgram;
		String programName = program.getName();
		Path outputRoot = Paths.get(args[0]);
		Path programOutputDir = outputRoot.resolve(sanitizeStem(programName));
		Files.createDirectories(programOutputDir);

		monitor.setMessage("Collecting functions for " + programName);
		FunctionManager functionManager = program.getFunctionManager();
		List<FunctionRow> rows = new ArrayList<>();
		FunctionIterator functionIterator = functionManager.getFunctions(true);
		while (functionIterator.hasNext() && !monitor.isCancelled()) {
			Function function = functionIterator.next();
			if (function.isExternal()) {
				continue;
			}

			FunctionRow row = new FunctionRow();
			row.name = function.getName();
			row.entry = function.getEntryPoint();
			row.size = function.getBody().getNumAddresses();
			row.thunk = function.isThunk();
			row.callingConvention = function.getCallingConventionName() == null ? "" : function.getCallingConventionName();
			rows.add(row);
		}

		rows.sort(
			Comparator.comparingLong((FunctionRow row) -> row.size).reversed()
				.thenComparing(row -> formatAddress(row.entry))
				.thenComparing(row -> row.name)
		);

		List<String> functionLines = new ArrayList<>();
		functionLines.add("name,entry,size,thunk,calling_convention");
		for (FunctionRow row : rows) {
			functionLines.add(
				csvEscape(row.name) + "," +
				csvEscape(formatAddress(row.entry)) + "," +
				row.size + "," +
				(row.thunk ? "1" : "0") + "," +
				csvEscape(row.callingConvention)
			);
		}
		writeLines(programOutputDir.resolve("functions.csv"), functionLines);

		monitor.setMessage("Collecting imports for " + programName);
		List<String> importLines = new ArrayList<>();
		ExternalManager externalManager = program.getExternalManager();
		for (String libraryName : externalManager.getExternalLibraryNames()) {
			ExternalLocationIterator externalLocations = externalManager.getExternalLocations(libraryName);
			while (externalLocations.hasNext() && !monitor.isCancelled()) {
				ExternalLocation location = externalLocations.next();
				String label = location.getLabel() == null ? "" : location.getLabel();
				importLines.add(libraryName + "!" + label + " @ " + formatAddress(location.getAddress()));
			}
		}
		importLines.sort(String::compareTo);
		writeLines(programOutputDir.resolve("imports.txt"), importLines);

		monitor.setMessage("Collecting exports for " + programName);
		SymbolTable symbolTable = program.getSymbolTable();
		List<ExportRow> exports = new ArrayList<>();
		List<String> exportLines = new ArrayList<>();
		AddressIterator externalEntryPoints = symbolTable.getExternalEntryPointIterator();
		while (externalEntryPoints.hasNext() && !monitor.isCancelled()) {
			Address address = externalEntryPoints.next();
			Symbol symbol = symbolTable.getPrimarySymbol(address);
			ExportRow exportRow = new ExportRow();
			exportRow.address = address;
			exportRow.symbolName = symbol == null ? "<no_symbol>" : symbol.getName();
			if ("entry".equals(exportRow.symbolName)) {
				continue;
			}
			exports.add(exportRow);
			exportLines.add(formatAddress(address) + " " + exportRow.symbolName);
		}
		exports.sort(
			Comparator.comparing((ExportRow row) -> formatAddress(row.address))
				.thenComparing(row -> row.symbolName)
		);
		exportLines.sort(String::compareTo);
		writeLines(programOutputDir.resolve("exports.txt"), exportLines);

		monitor.setMessage("Collecting non-default symbols for " + programName);
		List<String> symbolLines = new ArrayList<>();
		SymbolIterator symbols = symbolTable.getAllSymbols(true);
		while (symbols.hasNext() && !monitor.isCancelled()) {
			Symbol symbol = symbols.next();
			if (symbol.isExternal() || symbol.getSource() == SourceType.DEFAULT) {
				continue;
			}
			symbolLines.add(
				formatAddress(symbol.getAddress()) + " " + symbol.getSource() + " " + symbol.getName(true)
			);
		}
		symbolLines.sort(String::compareTo);
		writeLines(programOutputDir.resolve("analysis_symbols.txt"), symbolLines);

		monitor.setMessage("Decompiling exports for " + programName);
		DecompInterface decompiler = new DecompInterface();
		decompiler.openProgram(program);

		List<String> exportDecompLines = new ArrayList<>();
		exportDecompLines.add("/*");
		exportDecompLines.add("Program: " + programName);
		exportDecompLines.add("Decompiled exports");
		exportDecompLines.add("*/");
		exportDecompLines.add("");

		int decompiledExportCount = 0;
		for (ExportRow exportRow : exports) {
			if (monitor.isCancelled()) {
				break;
			}

			Function function = functionManager.getFunctionAt(exportRow.address);
			if (function == null) {
				exportDecompLines.add(
					"/* " + exportRow.symbolName + " @ " + formatAddress(exportRow.address) + " has no associated function */"
				);
				exportDecompLines.add("");
				continue;
			}

			appendDecompile(decompiler, function, function.getBody().getNumAddresses(), exportDecompLines);
			decompiledExportCount++;
		}
		writeLines(programOutputDir.resolve("decompile_exports.c"), exportDecompLines);

		monitor.setMessage("Decompiling top functions for " + programName);
		List<String> decompLines = new ArrayList<>();
		decompLines.add("/*");
		decompLines.add("Program: " + programName);
		decompLines.add("Functions decompiled: top " + maxDecomp + " by body size");
		decompLines.add("*/");
		decompLines.add("");

		int decompiledCount = 0;
		for (FunctionRow row : rows) {
			if (decompiledCount >= maxDecomp || monitor.isCancelled()) {
				break;
			}
			Function function = functionManager.getFunctionAt(row.entry);
			if (function == null) {
				continue;
			}

			appendDecompile(decompiler, function, row.size, decompLines);
			decompiledCount++;
		}

		writeLines(programOutputDir.resolve("decompile_top_functions.c"), decompLines);

		List<String> metadata = new ArrayList<>();
		metadata.add("program_name=" + programName);
		metadata.add("program_language=" + program.getLanguageID());
		metadata.add("program_compiler_spec=" + program.getCompilerSpec().getCompilerSpecID());
		metadata.add("image_base=" + formatAddress(program.getImageBase()));
		metadata.add("function_count=" + rows.size());
		metadata.add("import_count=" + importLines.size());
		metadata.add("export_count=" + exportLines.size());
		metadata.add("analysis_symbol_count=" + symbolLines.size());
		metadata.add("decompiled_export_count=" + decompiledExportCount);
		metadata.add("decompiled_function_count=" + decompiledCount);
		writeLines(programOutputDir.resolve("metadata.txt"), metadata);

		println("Exported Oblivion references for " + programName + " -> " + programOutputDir);
	}
}
