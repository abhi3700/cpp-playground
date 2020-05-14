# pprint
A Templatized Header Only C++ Implementation of [pprint](https://github.com/p-ranav/pprint) Library

## Features
* very easy to write than `cout`.
* add quotes into strings.
* __complex_no:__ `cout` shows the real & imag part of complex no. like `(1,2.5)`, but `pprint` shows the entire no. (including _iota_ i.e. _i_) like `(1 + 2.5i)`
* made for `enum`, `containers`, `lambda`, `optional`, `type_safe_unions`, `classes`, `user_defined_type`

## Installation [For Linux (Ubuntu)]
1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos\").
1. `$ mkdir pprint`
1. `$ cd pprint`
1. Clone the repo's sub-folder via svn: `$ svn checkout https://github.com/p-ranav/pprint/trunk/include`
1. Now, copy the pprint folder (with include/ppprint.hpp) into "/usr/local/include/" path.
1. DONE!

## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `pprint`) into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp && ./a.out` - this creates a `a.out` file on successful compilation.
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
#include <pprint/include/pprint.hpp>

int main() {
	pprint::PrettyPrinter printer;
	printer.print("Hello World!");

	return 0;
}
``` 

## Coding
* [Basics](./basics.cpp)
* [Complex no.](./complex_no.cpp)
* [Enum](./enum.cpp)
* [Sequence Container](./container_sequence.cpp)
* [Associative Container](./container_associative.cpp)
* [Lambda](./lambda.cpp)
* [Type Safe Unions](./type_safe_unions.cpp)
* [optional](./optional.cpp)
* [class](./class.cpp)
* [User defined type](./user_defined_type.cpp)
* [Conclusion](./conclusion.cpp)

## Resources
* Github: https://github.com/p-ranav/pprint