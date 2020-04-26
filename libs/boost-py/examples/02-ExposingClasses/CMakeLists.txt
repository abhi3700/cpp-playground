cmake_minimum_required(VERSION 3.0)
 
project(classes)

# Find necessary packages
find_package(PythonInterp 3)
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIR})
 
# find_package(Boost COMPONENTS python3 REQUIRED)
find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR})

include_directories(${Boost_INCLUDE_DIR})
 
# Build & Link our library
add_library(classes MODULE classes.cpp)

# setting Boost_LIBRARIES & PYTHON_LIBRARIES
if(UNIX)
        set(Boost_LIBRARIES "/usr/lib/x86_64-linux-gnu/libboost_python3-py36.so.1.65.1")
        set(PYTHON_LIBRARIES "/usr/lib/x86_64-linux-gnu/libpython3.6m.so")
endif()

target_link_libraries(classes ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# don't prepend wrapper library name with lib
set_target_properties(classes PROPERTIES PREFIX "")