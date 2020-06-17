cmake_minimum_required(VERSION 3.5)

set(cmake_cxx_standard 17)
set(cmake_cxx_standard_required on)

project(sha384)

include_directories(/usr/local/include)

add_executable(sha384 main.cpp)
target_link_libraries(sha384 /usr/local/lib/libhl++.a)