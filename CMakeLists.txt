cmake_minimum_required(VERSION 3.10)
project(ProjectName C)
include(CTest)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Define options for debug levels
set(DEBUG_LEVELS "NONE;ERROR;WARN;INFO;DEBUG" CACHE STRING "Available debug levels")
set(CURRENT_DEBUG_LEVEL "INFO" CACHE STRING "Current debug level")
set_property(CACHE CURRENT_DEBUG_LEVEL PROPERTY STRINGS ${DEBUG_LEVELS})

# Convert the string to the corresponding debug level constant
string(TOUPPER ${CURRENT_DEBUG_LEVEL} CURRENT_DEBUG_LEVEL)
set(CURRENT_DEBUG_LEVEL DEBUG_LEVEL_${CURRENT_DEBUG_LEVEL})

# Add a compiler definition for the debug level
add_compile_definitions(CURRENT_DEBUG_LEVEL=${CURRENT_DEBUG_LEVEL})

# Compiler flags
add_compile_options(-Wall)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
file(GLOB LIBRARIES_SRC "${CMAKE_SOURCE_DIR}/src/*.c")
set(MAIN_SRC ${CMAKE_SOURCE_DIR}/main.c)

# Tests
set(TEST_SAMPLE_SRC ${CMAKE_SOURCE_DIR}/tests/test_sample_library.c)
add_executable(test_sample ${TEST_SAMPLE_SRC} ${LIBRARIES_SRC})
add_test(NAME test_sample COMMAND $<TARGET_FILE:test_sample>)

set(TEST_ANOTHER_SRC ${CMAKE_SOURCE_DIR}/tests/test_another_library.c)
add_executable(test_another ${TEST_ANOTHER_SRC} ${LIBRARIES_SRC})
add_test(NAME test_another COMMAND $<TARGET_FILE:test_another>)

# Main executable
add_executable(ProjectName ${MAIN_SRC} ${LIBRARIES_SRC})
