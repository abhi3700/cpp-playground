# Boost-Python
* This package helps to bind Python & C++ in 2 ways:
	- Interprete Python (with C++ modules)
		- run via `$ python hello.py`
		- modules written in "hello.cpp" file.
	- Compile C++ (with Python modules). This is also called as "Embedding".
		- run via `$ g++ hello.cpp -o hello`
		- modules written in "hello.py" file.
* The 2 languages has its own benefits:
	- __fast code__ in C++.
	- __code fast__ in Python.

## Installation [For Linux (Ubuntu)]
> Note that Boost Python components require a Python version suffix (Boost 1.67 and later), e.g. python36 or python27 for the versions built against Python 3.6 and 2.7, respectively. This also applies to additional components using Python including mpi_python and numpy. Earlier Boost releases may use distribution-specific suffixes such as 2, 3 or 2.7. These may also be used as suffixes, but note that they are not portable. [Source](https://cmake.org/cmake/help/v3.12/module/FindBoost.html)

__Follow the steps below:__

* Download the latest boost lib from [here](https://www.boost.org/users/download/).

* Open `bash` terminal
```console
tar -xzvf boost_1_72_0.tar.gz
cd boost_1_72_0
```
* Install __python3.6m__: `$ sudo apt-get install python3.6-dev`
	- check the installation whether __python3.6m__ is present inside '/usr/include/' directory:
```console
$ find /usr/include -name python3.6m
/usr/include/python3.6m
/usr/include/x86_64-linux-gnu/python3.6m
```
* create 'user-config.jam' file in home directory
	- `$ nano ~/user-config.jam`
	- write this content inside the file or else, just copy "./extra/user-config.jam" to "~/" using `$ cp ./extra/user-config.jam ~/`
```txt
echo "using mpi ;
using gcc: : g++ ;
using python : 3.6 : /usr/bin/python3 : /usr/include/python3.6m : /usr/local/lib ;"
```
* `$ ./bootstrap.sh --with-python=/usr/bin/python3 --with-python-version=3.6 --with-python-root=/usr/local/lib/python3.6 --prefix=/usr/local`
```console
Building Boost.Build engine with toolset gcc... tools/build/src/engine/b2
Unicode/ICU support for Boost.Regex?... not found.
Generating Boost.Build configuration in project-config.jam for gcc...

Bootstrapping is done. To build, run:

    ./b2

To generate header files, run:

    ./b2 headers

To adjust configuration, edit 'project-config.jam'.
Further information:

   - Command line help:
     ./b2 --help

   - Getting started guide:
     http://www.boost.org/more/getting_started/unix-variants.html

   - Boost.Build documentation:
     http://www.boost.org/build/
```
	-  NOTE: Here, please ensure that `gcc` is installed, or else: just do it by `sudo apt install g++` & `sudo apt-get install gcc`. The error could be like this in form of "bootstrap.log" file.
```console
###
###
### Using 'cxx' toolset.
###
###
cxx --version
./build.sh: 17: ./build.sh: cxx: not found
```
* Then,
```console
$ sudo ./b2 install -a --with=all
$ sudo ldconfig
```
* From apt
```console
$ sudo apt-get install libboost-all-dev
```
* find `libboost_python3.so` via:
```console
$ sudo find /usr/lib -name "libboost_python-py36.so"
/usr/lib/x86_64-linux-gnu/libboost_python-py36.so
```
* cd to where you find it
```console
$ cd /usr/lib/x86_64-linux-gnu/
```
* link libboost_python3.so
```console
$ sudo ln -s libboost_python-py36.so libboost_python3.so
```
* This step is to let `g++` find `pyconfig.h` file.
	- locate in `/usr/include/` via:
```console
$ find /usr/include -name pyconfig.h
/usr/include/python2.7/pyconfig.h
/usr/include/python3.6m/pyconfig.h
/usr/include/x86_64-linux-gnu/python2.7/pyconfig.h
/usr/include/x86_64-linux-gnu/python3.6m/pyconfig.h
```
	- Now, add it to C++ include path by adding this to `.bashrc` file via `$ nano ~/.bashrc`
```console
# 'pyconfig.h' for Boost-python
export CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:/usr/include/python3.6m/"
```
* add `include_directories(/usr/include/python3.6m)` to 'CMakeLists.txt' for a project (say hello). The "CMakeLists.txt" looks like:
```cmake
cmake_minimum_required(VERSION 3.7.2)

find_package(PythonInterp 3)
find_package(PythonLibs 3)
PYTHON_ADD_MODULE(hello hello.cpp)
include_directories(/usr/include/python3.6m)
FILE(COPY hello.py DESTINATION .)
add_test(NAME 01-HelloWorld COMMAND ${PYTHON_EXECUTABLE} hello.py)
```
* `$ cmake .`
* `$ make`
* Now, after successful build by `make`, it gives this error on running this file `$ ./hello.so` or `python3 hello.py`:
```console
Segmentation fault (core dumped)
```
* ~~The "CMakeLists.txt" is as follows:~~
```cmake
cmake_minimum_required(VERSION 3.0)

find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR})
# message(${PYTHON_VERSION_MAJOR})

find_package(PythonInterp 3)
find_package(PythonLibs 3 REQUIRED)

PYTHON_ADD_MODULE(hello hello.cpp)

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
# message(${Boost_INCLUDE_DIRS})		# /usr/local/include

FILE(COPY hello.py DESTINATION .)

target_link_libraries(hello ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
add_test(NAME 01-HelloWorld COMMAND ${PYTHON_EXECUTABLE} hello.py)
# message(${PYTHON_EXECUTABLE})		# /usr/bin/python3
```

* It still gives "Segmentation fault". But this time it's because of this "hello.so" file. 
	- Just check via `$ ldd hello.so`
```console
        linux-vdso.so.1 (0x00007ffffbe49000)
        libpython3.6m.so.1.0 => /usr/lib/x86_64-linux-gnu/libpython3.6m.so.1.0 (0x00007f5afad50000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f5afa9c0000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f5afa7a0000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f5afa3a0000)
        libexpat.so.1 => /lib/x86_64-linux-gnu/libexpat.so.1 (0x00007f5afa160000)
        libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f5af9f40000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f5af9d10000)
        libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f5af9b00000)
        libutil.so.1 => /lib/x86_64-linux-gnu/libutil.so.1 (0x00007f5af98f0000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f5af9550000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f5afb800000)
```
* So, it is missing `libboost_python3-py36.so.1.65.1` i.e. boost_python, which has already been installed via `$ sudo apt-get install libboost-all-dev`:
	- just locate this via:
```console
$ ls /usr/lib/x86_64-linux-gnu | grep libboost_python3 | grep 1.65.1
libboost_python3-py36.so.1.65.1
```

	> NOTE: for 64-bit machine, it gets saved into `/usr/lib/x86_64-linux-gnu`, otherwise into `/usr/lib` folder.

	- __[NOT Mandatory]__ add to `LD_LIBRARY_PATH` via `$ export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/libboost_python3-py36.so.1.65.1`
* So, the __FINAL__ "CMakeLists.txt" is as follows:
```cmake
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
add_test(NAME 01-HelloWorld COMMAND ${PYTHON_EXECUTABLE} hello.py)```
* `$ cmake .` & then `$ make`
```console
$ cmake .
-- Boost  found.
-- Found Boost components:
   python3
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/f/Coding/github_repos/cpp-playground/gitcpplibs/boost-py-eg/01-HelloWorld
$ make
[100%] Built target hello
```
* running the file
```console
$ ./hello.so
Segmentation fault (core dumped)
$ python3 hello.py
hello, world
```

	> NOTE: `$ python3 hello.py` is the ideal way to run the "hello.py" program. "hello.so" is not executable.



* Also, you can see the content of "hello.so" file:
```console
$ ldd hello.so
        linux-vdso.so.1 (0x00007fffef7f9000)
        libboost_python3-py36.so.1.65.1 => /usr/lib/x86_64-linux-gnu/libboost_python3-py36.so.1.65.1 (0x00007f554ee20000)
        libpython3.6m.so.1.0 => /usr/lib/x86_64-linux-gnu/libpython3.6m.so.1.0 (0x00007f554e770000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f554e3e0000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f554e1c0000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f554ddc0000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f554dba0000)
        libexpat.so.1 => /lib/x86_64-linux-gnu/libexpat.so.1 (0x00007f554d950000)
        libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f554d730000)
        libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f554d520000)
        libutil.so.1 => /lib/x86_64-linux-gnu/libutil.so.1 (0x00007f554d310000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f554cf70000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f554f400000)
```
	- So, you can see that  `libboost_python3-py36.so.1.65.1` gets added.
* DONE!


* ### NOTES
	- If there is no `*.so` file then, the error will look like this on execution:
```console
$ python3 hello.py
Traceback (most recent call last):
  File "hello.py", line 3, in <module>
    import hello
  File "/mnt/f/Coding/github_repos/cpp-playground/libs/boost-py/examples/01-HelloWorld/hello.py", line 4, in <module>
    print (hello.greet())
AttributeError: module 'hello' has no attribute 'greet'
```
	- `Boost_INCLUDE_DIR` = "/usr/local/include"
	- `PYTHON_INCLUDE_DIR` = "/usr/include/python3.6m"
	- `Boost_LIBRARIES` = "/usr/lib/x86_64-linux-gnu/libboost_python3-py36.so.1.65.1"
	- `PYTHON_LIBRARIES` = "/usr/lib/x86_64-linux-gnu/libpython3.6m.so"
	- Link these 2 libraries - Boost & Python
	- This is to create `hello.so` i.e. not prepend like `libhello.so` use this line:
```cmake
set_target_libraries(hello PROPERTIES PREFIX "")
```


## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy the "Boost" folder (comes with downloaded .zip) & paste into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++__" 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp -o test && ./test`
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:

<details>
	<summary>View code:</summary>

```cpp

```
</details>

## Resources
* Website: https://www.boost.org/
* Github: https://github.com/boostorg/boost
* Github repo (maintained by me): https://github.com/abhi3700/boost
* Documentation: https://www.boost.org/doc/libs/1_72_0/doc/html/index.html
* Getting Started with linux: https://www.boost.org/doc/libs/1_72_0/more/getting_started/unix-variants.html

## References
* https://github.com/zpoint/Boost-Python-Examples
* https://github.com/abingham/boost_python_tutorial
* https://www.auctoris.co.uk/2017/12/21/advanced-c-python-integration-with-boost-python/
