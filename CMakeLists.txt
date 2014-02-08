cmake_minimum_required(VERSION 2.8)
project(RosalindInfo)

# Cmake options
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/klib)
add_subdirectory(${CMAKE_SOURCE_DIR}/kmlib)
include_directories(${CMAKE_SOURCE_DIR}/kmlib/include)

link_directories(${CMAKE_SOURCE_DIR}/kmlib/lib)



enable_testing()

# CC options
add_definitions(-std=gnu99 -O3 -fgnu89-inline)

FILE(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/src/*.c")

foreach(source ${sources})
	get_filename_component(bin_name ${source} NAME_WE)
	add_executable(${bin_name} ${source})
	target_link_libraries(${bin_name} km gmp z)
endforeach(source)
