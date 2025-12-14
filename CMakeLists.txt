cmake_minimum_required(VERSION 3.15)

project(SolvedProblems VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add cmake/ to module path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Add common include directory (for bits/stdc++.h, etc.)
include_directories(${CMAKE_SOURCE_DIR})

# ============================================================================
# Target Filter Configuration
# ============================================================================
# Set TARGET_FILTER to filter which targets to include (regex pattern)
# Examples:
#   set(TARGET_FILTER ".*")           # Include all targets (default)
#   set(TARGET_FILTER "ITSA_.*")      # Only ITSA targets
#   set(TARGET_FILTER "atcoder_.*")   # Only atcoder targets
#   set(TARGET_FILTER "aoc_2024_.*")  # Only aoc_2024 targets
#   set(TARGET_FILTER "hoj_.*")       # Only hoj targets
#   set(TARGET_FILTER "(ITSA|atcoder)_.*")  # Multiple categories
#
# Can also be set via command line: cmake -DTARGET_FILTER="ITSA_.*" ..
# ============================================================================
if(NOT DEFINED TARGET_FILTER)
    set(TARGET_FILTER ".*" CACHE STRING "Regex pattern to filter targets")
endif()

message(STATUS "Target filter: ${TARGET_FILTER}")

file(GLOB subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(subdir ${subdirs})
	if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
		if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
			add_subdirectory(${subdir})
		endif()
	endif()
endforeach()

