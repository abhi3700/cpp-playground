# Eigen
C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms

## Features
* Used in the multi-threading application

## Installation [For Linux (Ubuntu)]
1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos\cpp_libs\").
1. Clone the repo's sub-folder via svn: `$ svn checkout https://github.com/vincentlaucsb/csv-parser/trunk/single_include csv-parser`
1. Now, copy the csv-parser folder (with csv.hpp) into "/usr/local/include/" path.
1. DONE!


## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `csv-parser`) into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp && time ./a.out` - this creates & runs a `a.out` file on successful compilation. Also, shows 
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
#include <eigen/Dense>
#include <iostream>

using Eigen::MatrixXd;

int main() {
	MatrixXd m(3, 3);

	// setting & displaying values for the matrix
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m(i, j) = i + j;
			std::cout << m(i, j) << " ";
		}
		std::cout << "\n";
	}


	return 0;
}
``` 

## Coding
* [Set & Get values of matrix](./set_get_matrix.cpp)

## Resources
* [Gitlab](https://gitlab.com/libeigen/eigen/-/tree/master/Eigen), 
* [Main page](http://eigen.tuxfamily.org/index.php?title=Main_Page), 
* [Getting Started](http://eigen.tuxfamily.org/dox/GettingStarted.html)
