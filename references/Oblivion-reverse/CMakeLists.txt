cmake_minimum_required(VERSION 3.16)

file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" OBLIVION_VERSION
    LIMIT_COUNT 1
    REGEX "^[0-9]+\.[0-9]+\.[0-9]+$")

if(OBLIVION_VERSION STREQUAL "")
    message(FATAL_ERROR "VERSION must contain a semantic version like 0.1.0")
endif()

project(oblivion_game VERSION ${OBLIVION_VERSION} LANGUAGES C)

# Ship a release-configured build by default so the produced DLL matches
# the original Quake II release binaries unless the user explicitly asks
# for another configuration.
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Collect every C source under src/game and src/common.
file(GLOB GAME_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.c"
)

if(GAME_SOURCES STREQUAL "")
    message(FATAL_ERROR "No source files found under src/game")
endif()

add_library(oblivion_game MODULE ${GAME_SOURCES})

target_include_directories(oblivion_game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/game
        ${CMAKE_CURRENT_SOURCE_DIR}/src/common
)

target_compile_definitions(oblivion_game
    PRIVATE
        _GNU_SOURCE
)

option(OBLIVION_ENABLE_LOCAL_DEPLOY "Copy Windows builds to a local Quake II test install when available" ON)
set(OBLIVION_LOCAL_DEPLOY_DIR "C:/q2Clean/oblivion-re" CACHE PATH
    "Local Quake II game directory used for optional Windows post-build deployment")

if(WIN32)
    if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
        message(FATAL_ERROR
            "Quake II expects a 32-bit gamex86.dll. Configure CMake for a Win32 build (e.g. -A Win32).")
    endif()

    # game.def lists the exports that the engine expects on Windows builds.
    target_sources(oblivion_game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/game/game.def)
    set_target_properties(oblivion_game PROPERTIES
        PREFIX ""
        OUTPUT_NAME "gamex86"
        RUNTIME_OUTPUT_NAME "gamex86"
        ARCHIVE_OUTPUT_NAME "gamex86"
        SUFFIX ".dll"
    )

    get_filename_component(OBLIVION_LOCAL_DEPLOY_PARENT "${OBLIVION_LOCAL_DEPLOY_DIR}" DIRECTORY)
    if(OBLIVION_ENABLE_LOCAL_DEPLOY AND EXISTS "${OBLIVION_LOCAL_DEPLOY_PARENT}")
        add_custom_command(TARGET oblivion_game POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory "${OBLIVION_LOCAL_DEPLOY_DIR}"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "$<TARGET_FILE:oblivion_game>"
                "${OBLIVION_LOCAL_DEPLOY_DIR}/$<TARGET_FILE_NAME:oblivion_game>"
        )
    endif()
else()
    set_target_properties(oblivion_game PROPERTIES
        PREFIX ""
        OUTPUT_NAME "game"
    )

    if(APPLE)
        set_target_properties(oblivion_game PROPERTIES
            SUFFIX ".dylib"
        )
    endif()
endif()

install(TARGETS oblivion_game
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
