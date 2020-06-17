# Cryptography (Hashing, Encryption)
Header-only C++17 library provides CSV reading/writing.

## Features
* [x] Hashing
* [ ] Encryption

## Installation [For Linux (Ubuntu) on Win10]
<!-- 1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos\cpp_libs\"). -->
1. Open `git-bash` terminal at your preferred directory path ("F:\Coding\github_repos\") to clone a library repo.
	- `$ git clone https://github.com/aksalj/hashlibpp.git` 
1. Open `bash` (ubuntu) terminal at this location. `$ start .` >> <kbd>ctrl+l</kbd> >> type "bash". And the bash terminal opens.
1. `$ ./build.sh` - Go to "src" directory >> `make` >> create include, lib folders >> copy the necessary files into the folders
1. `$ cd build` - here you get `include` & `lib` folders.
1. `$ sudo cp ./lib/libhl++.a /usr/local/lib` - copy the `.a` file to "/usr/local/lib" path.
1. Now, goto "include/" folder & wrap all the header files into "hashlibpp" folder.
1. `$ sudo cp -r ./hashlibpp /usr/local/include` - Now, copy the "hashlibpp" folder (with all the header files) into "/usr/local/include/" path.
1. DONE!


## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `csv-parser`) into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp && time ./a.out` - this creates & runs a `./a.out` file on successful compilation. Also, shows 
* CMake: `$ mkdir build && cd build` & `$ cmake ..` & then `$ make` & then `./test`
```cmake
cmake_minimum_required(VERSION 3.5)

set(cmake_cxx_standard 17)
set(cmake_cxx_standard_required on)

project(sha384)

include_directories(/usr/local/include)

add_executable(sha384 main.cpp)
target_link_libraries(sha384 /usr/local/lib/libhl++.a)
```

## Quick Start
* Example code:
```cpp
#include <hashlibpp/hashlibpp.h>
#include <string>
#include <iostream>  //for "cerr"


int main() {
	//creating a wrapper object 
	hashwrapper *myWrapper = new sha256wrapper();
	 
	try{
		// create a hash from a string
		std::string hash1 = myWrapper->getHashFromString("Hello World");
		std::cout << hash1 << "\n";
	    
	    // create a hash based on a file
		// std::string hash2 = myWrapper->getHashFromFile("README.md");

	}catch(hlException &e) {
	 	std::cerr << "Error("  << e.error_number() << "): " << e.error_message() << std::endl;
	}

	delete myWrapper;
	return 0;	
}
``` 

## Coding

## Resources
* Hashing
	- Github: https://github.com/aksalj/hashlibpp.git
