# ============================================================================
# CMakeLists.txt - CMake Configuration for 30-Day DSA Challenge (Linux)
# ============================================================================
# This file configures the build system for Linux platform.
# It supports:
# - Building all 30 daily solutions
# - CLI launcher for interactive learning
# - Testing framework
# ============================================================================

cmake_minimum_required(VERSION 3.15)

# ============================================================================
# Project Configuration
# ============================================================================
project(DSA_30_Days_Challenge
    VERSION 1.0.0
    DESCRIPTION "30-Day Data Structures and Algorithms Learning Project"
    LANGUAGES CXX
)

# ============================================================================
# C++ Standard Configuration
# ============================================================================
# Use C++17 for modern features (auto, structured bindings, etc.)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================================
# Compiler Flags
# ============================================================================
# Enable warnings and optimizations for GCC/Clang
add_compile_options(-Wall -Wextra -O2)

# ============================================================================
# Output Directories
# ============================================================================
# Place all executables in bin/ directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ============================================================================
# Build Configuration Options
# ============================================================================
option(BUILD_ALL_DAYS "Build all day solutions" ON)
option(BUILD_TESTS "Build test executables" ON)

# ============================================================================
# Include Directories
# ============================================================================
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

# ============================================================================
# Function to Add a Day's Solution
# ============================================================================
# This function creates an executable for each day's solution
# Parameters:
#   day_num - The day number (e.g., 01, 02, ..., 30)
function(add_day_solution day_num)
    set(target_name "Day${day_num}")
    set(source_file "${CMAKE_SOURCE_DIR}/src/Day${day_num}/solution.cpp")

    if(EXISTS ${source_file})
        add_executable(${target_name} ${source_file})

        set_target_properties(${target_name} PROPERTIES
            OUTPUT_NAME "day${day_num}"
        )

        # Add to install targets
        install(TARGETS ${target_name} RUNTIME DESTINATION bin)
    endif()
endfunction()

# ============================================================================
# Build All Daily Solutions
# ============================================================================
if(BUILD_ALL_DAYS)
    message(STATUS "Building all 30 day solutions...")

    # Loop through all 30 days
    foreach(day_num RANGE 1 30)
        # Format day number with leading zero (01, 02, ..., 30)
        if(day_num LESS 10)
            set(day_formatted "0${day_num}")
        else()
            set(day_formatted "${day_num}")
        endif()

        add_day_solution(${day_formatted})
    endforeach()
endif()

# ============================================================================
# Linux CLI Launcher
# ============================================================================
message(STATUS "Building Linux CLI launcher...")

add_executable(dsa_launcher
    src/cli_launcher/main.cpp
)

set_target_properties(dsa_launcher PROPERTIES
    OUTPUT_NAME "dsa"
)

install(TARGETS dsa_launcher RUNTIME DESTINATION bin)

# ============================================================================
# Testing Configuration
# ============================================================================
if(BUILD_TESTS)
    enable_testing()

    # Add test for each day
    foreach(day_num RANGE 1 30)
        if(day_num LESS 10)
            set(day_formatted "0${day_num}")
        else()
            set(day_formatted "${day_num}")
        endif()

        set(test_input "${CMAKE_SOURCE_DIR}/tests/Day${day_formatted}/input.txt")
        set(test_expected "${CMAKE_SOURCE_DIR}/tests/Day${day_formatted}/expected.txt")

        if(EXISTS ${test_input} AND EXISTS ${test_expected})
            add_test(
                NAME Test_Day${day_formatted}
                COMMAND Day${day_formatted} < ${test_input}
            )
        endif()
    endforeach()
endif()

# ============================================================================
# Installation Configuration
# ============================================================================
# Install source files with markdown docs
install(DIRECTORY
    src/Day01 src/Day02 src/Day03 src/Day04 src/Day05
    src/Day06 src/Day07 src/Day08 src/Day09 src/Day10
    src/Day11 src/Day12 src/Day13 src/Day14 src/Day15
    src/Day16 src/Day17 src/Day18 src/Day19 src/Day20
    src/Day21 src/Day22 src/Day23 src/Day24 src/Day25
    src/Day26 src/Day27 src/Day28 src/Day29 src/Day30
    DESTINATION share/dsa-30days/src
    FILES_MATCHING PATTERN "*.md" PATTERN "*.cpp"
)

install(FILES README.md DESTINATION share/dsa-30days)
install(DIRECTORY tests DESTINATION share/dsa-30days)

# ============================================================================
# Summary
# ============================================================================
message(STATUS "")
message(STATUS "==========================================")
message(STATUS "  DSA 30-Day Challenge Build Configuration")
message(STATUS "==========================================")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Tests: ${BUILD_TESTS}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "==========================================")
message(STATUS "")
