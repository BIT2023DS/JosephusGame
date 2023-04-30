cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

project(JosephusProblem)

file(GLOB SOURCES *.cpp)

add_executable(JosephusProblem ${SOURCES})