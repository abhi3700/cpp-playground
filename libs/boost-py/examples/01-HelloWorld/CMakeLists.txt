cmake_minimum_required(VERSION 3.0)
 
project(greeter)

# Find necessary packages
find_package(PythonInterp 3)
find_package(PythonLibs 3 REQUIRED)
 
# find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR})

# Including both boost & python directories
include_directories(${Boost_INCLUDE_DIR} ${PYTHON_INCLUDE_DIR})

# message(${Boost_INCLUDE_DIR})		# /usr/local/include
# message(${PYTHON_INCLUDE_DIR})		# /usr/include/python3.6m
 
# Build & Link our library
# add_library(hello MODULE hello.cpp) 		# OR
PYTHON_ADD_MODULE(hello hello.cpp)


# setting Boost_LIBRARIES & PYTHON_LIBRARIES
if(UNIX)
        set(Boost_LIBRARIES "/usr/lib/x86_64-linux-gnu/libboost_python3-py36.so.1.65.1")
        set(PYTHON_LIBRARIES "/usr/lib/x86_64-linux-gnu/libpython3.6m.so")
endif()

target_link_libraries(hello ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# don't prepend wrapper library name with lib ==> otherwise, it would prepare "libhello.so" file
set_target_properties(hello PROPERTIES PREFIX "")

# test to find the executable in WORKING_DIRECTORY, this is sufficient
add_test(NAME 01-HelloWorld COMMAND ${PYTHON_EXECUTABLE} hello.py)