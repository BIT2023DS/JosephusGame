cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

project(JosephusGame)

file(GLOB SOURCES *.cpp)

add_subdirectory(3rdparty/RapidFuzz)

add_executable(JosephusGame ${SOURCES})

target_link_libraries(JosephusGame rapidfuzz::rapidfuzz)