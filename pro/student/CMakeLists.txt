cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(student)
include_directories(include)
set(SOURCES src/student.cpp src/mainapp.cpp)
file(GLOB SOURCES "src/*.cpp")
add_executable(testStudent ${SOURCES})
CMAKE_CURRENT