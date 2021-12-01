cmake_minimum_required(VERSION 3.16)
project(aoc2021 DESCRIPTION "Solutions for Advent of Code 2021"
                LANGUAGES CXX)

include(FetchContent)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(src)

add_subdirectory(ext/range-v3)
FetchContent_GetProperties(range-v3)

add_library(range_v3 INTERFACE IMPORTED)
set_target_properties(range_v3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${range-v3_SOURCE_DIR}/include)
target_link_libraries(Library range_v3)

add_subdirectory(apps)
