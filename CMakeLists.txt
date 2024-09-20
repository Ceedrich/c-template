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

# Compiler flags
add_compile_options(-Wall)

# Main executable
add_executable(main main.c)
set_target_properties(main PROPERTIES
    LINK_FLAGS "-Wl,-e,custom_entry_point"
)
