# Magic Enum
Header-only C++17 library provides static reflection for enums, work with any enum type without any macro or boilerplate code.

## Features
* Get to print the name of variable rather than it's default/custom value. E.g. `enum level {LOW, MEDIUM, HIGH}` --> `LOW` printable. By std. method, only `0` can be printed. 
* Limitations:
	- follow the compiler compatibility
	- Enum value must be in range `[MAGIC_ENUM_RANGE_MIN, MAGIC_ENUM_RANGE_MAX]`. By default `MAGIC_ENUM_RANGE_MIN = -128`, `MAGIC_ENUM_RANGE_MAX = 128`
		+ redefine like this:
```cpp
#define MAGIC_ENUM_RANGE_MIN = 0
#define MAGIC_ENUM_RANGE_MIN = 256
```


## Installation [For Linux (Ubuntu)]
1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos\").
1. `$ mkdir magic_enum`
1. `$ cd magic_enum`
1. Clone the repo's sub-folder via svn: `$ svn checkout https://github.com/Neargye/magic_enum/trunk/include`
1. Now, copy the magic_enum folder (with include/magic_enum.hpp) into "/usr/local/include/" path.
1. DONE!

> ##### NOTE: Compiler compatibility
>	- Clang/LLVM >= 5
>	- MSVC++ >= 14.11 / Visual Studio >= 2017
>	- Xcode >= 10
>	- GCC >= 9
> So, I used Clang as difficulty faced in installing the required version of gcc.
> syntax: `$ clang++ -std=c++17 test.cpp && ./a.out`


## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `magic_enum`) into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ clang++ -std=c++17 test.cpp && ./a.out` - this creates & runs a `a.out` file on successful compilation.
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
``` 

## Coding
* [Basics](./basics.cpp)
* [Complex no.](./complex_no.cpp)

## Resources
* Github: https://github.com/Neargye/magic_enum