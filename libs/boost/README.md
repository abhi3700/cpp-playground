# Boost
The Boost organization and wider Boost community supports research and education into the best possible uses of C++ and libraries developed for it, particularly, but not exclusively those contained in the Boost Library.

## Installation [For Linux (Ubuntu)]
Please, refer to [this](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#using-boost-library-or-custom-library-via-mingw-64)

## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy the "Boost" folder (comes with downloaded .zip) & paste into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++__" 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp -o test && ./test`
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
#include <iostream>
#include <NumCpp.hpp>	// nc array
#include <typeinfo>		// typeid


int main() {
	auto v = nc::linspace<int>(1, 10, 5);

	// check the type
	// std::cout << typeid(v).name() << std::endl;		// N2nc7NdArrayIiEE
	
	// print the array elements
	for(auto&& x : v) {
		std::cout << x << std::endl;
	}
	return 0;
}
``` 

## Resources
* Github: https://github.com/dpilger26/NumCpp
* Brief syntaxes: https://github.com/dpilger26/NumCpp#from-numpy-to-numcpp--a-quick-start-guide
* Examples: https://github.com/dpilger26/NumCpp/tree/master/examples
* Documentation: https://dpilger26.github.io/NumCpp/doxygen/html/index.html