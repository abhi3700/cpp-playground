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

<details>
	<summary>View code:</summary>

```cpp
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <typeinfo>

using std::string;
using boost::algorithm::trim;
using boost::algorithm::trim_copy;


int main()
{
	string s1 = "	Welcome to the boost		";
	string s2 = s1;
	string s3 = "   C++ is actually simple, but made complex to support everything";
	
	trim(s2);	// trimming only the string s2

	string new_string = trim_copy(s3);	// trimming s3 & store the modified copy in new string.


	// print the final strings
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << new_string << std::endl;

	return 0;  
}
```
</details>

## Resources
* Website: https://www.boost.org/
* Github: https://github.com/boostorg/boost
* Github repo (maintained by me): https://github.com/abhi3700/boost
* Documentation: https://www.boost.org/doc/libs/1_72_0/doc/html/index.html
