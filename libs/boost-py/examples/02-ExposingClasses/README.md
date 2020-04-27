# Classes
## Installation
* "CMakeLists.txt"
```console

```

## Execution
1. `$ cmake .`
```console
$ cmake .
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.6.9", minimum required is "3")
-- Found PythonLibs: /usr/lib/x86_64-linux-gnu/libpython3.6m.so (found suitable version "3.6.9", minimum required is "3")
-- Boost  found.
-- Found Boost components:
   python3
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/f/Coding/github_repos/cpp-playground/libs/boost-py/examples/02-ExposingClasses
```
1. `$ make`
```console
$ make
Scanning dependencies of target classes
[ 50%] Building CXX object CMakeFiles/classes.dir/classes.cpp.o
[100%] Linking CXX shared module classes.so
[100%] Built target classes
```
1. `$ python3 classes.py`
```console
$ python3 classes.py
bom dia!
Good Morning, Buon giorno, Kali mera
```