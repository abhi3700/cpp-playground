# cpp-playground
Practice C++ coding with other github repos

## Installation
## GCC: GNU Compiler Collection
* gcc vs g++ differences
	- define
```
  gcc: GNU C Compiler
  g++: GNU C++ Compiler
```
	- gcc will compile: *.c/*.cpp files as C and C++ respectively.
	- g++ will compile: *.c/*.cpp files but they will all be treated as C++ files.
	- Also if you use g++ to link the object files it automatically links in the std C++ libraries (gcc does not do this).
	- gcc compiling C files has fewer predefined macros.
	- gcc compiling *.cpp and g++ compiling *.c/*.cpp files has a few extra macros.

> Note: For c++ you should use g++.

* OS
	- Linux (Ubuntu)
		+ Install using `sudo apt install g++`
		+ Test using `g++ hello.cpp` --> creates `a.out` file in this directory. <br/>
			Also, using `g++ hello.cpp -o hello` --> creates `hello` file in this directory.
	- Windows
	 

### CMake


## Dependencies
* C++ Include libs - `include`
  - Boost - [My repo in Github](https://github.com/abhi3700/boost) - `git`
    + create: `git submodule add https://github.com/abhi3700/boost boost`
    + update: `cd boost` >> `git pull`  
  - [simdjson](https://github.com/lemire/simdjson) - `svn`
    + create: `svn checkout https://github.com/lemire/simdjson/trunk/include/simdjson`
    + update: `cd boost` >> `svn update`  
  - [spdlog](https://github.com/gabime/spdlog)
  https://github.com/gabime/spdlog/branches/v1.x/include/spdlog
    + create: `git clone -b v1.x --single-branch https://github.com/gabime/spdlog.git`
    + update: `cd spdlog` >> `git pull`

* C++ Github repositories (References)- `gitcpplibs`
	- [exercism](https://github.com/exercism/cpp)	- `svn`
		+ create: `svn checkout https://github.com/exercism/cpp/trunk/exercises exercism-exercises`
		+ update: `cd exercism-exercises` >> `svn update` (inside the folder)
	- [denismatveev-exercises](https://github.com/denismatveev/exercises) - `git`
		+ create: `git submodule add https://github.com/denismatveev/exercises.git denismatveev-exercises`
		+ update: `cd denismatveev-exercises` >> `git pull`
	- [sagar-cpp](https://github.com/Sagar-022/c_plus_plus) - `git`
		+ create: `git submodule add https://github.com/Sagar-022/c_plus_plus sagar-cpp`
		+ update: `cd sagar-cpp` >> `git pull`	
	- [cpp-primer](https://github.com/Mooophy/Cpp-Primer.git) - `git`
		+ create: `git submodule add https://github.com/Mooophy/Cpp-Primer.git cpp-primer`
		+ update: `cd cpp-primer` >> `git pull`	
  - [leet-code](https://github.com/wj-zhu/leet-code) - `git`
    + create: `git submodule add https://github.com/wj-zhu/leet-code.git leet-code`
    + update: `cd leet-code` >> `git pull`
  - [boost-py-eg](https://github.com/TNG/boost-python-examples) - 'git'
    + create: `git submodule add https://github.com/TNG/boost-python-examples.git boost-py-eg`
    + update: `cd boost-py-eg` >> `git pull`
  - [cpp-patterns-wj](https://github.com/wj-zhu/cpp-patterns) - `git`
    + create: `git submodule add https://github.com/wj-zhu/cpp-patterns.git cpp-patterns-wj`
    + update: `cd cpp-patterns-wj` >> `git pull`
  - [cpp-wj](https://github.com/wj-zhu/snippets/tree/master/cpp) - `svn`
    + create: `svn checkout https://github.com/wj-zhu/snippets/trunk/cpp cpp-wj`
    + update: `cd cpp-wj` >> `svn update`

## Use
For using it in your local PC, follow the steps below:
* Clone the repo - `git clone https://github.com/abhi3700/cpp-playground.git`
* Update the blank submodule - `git submodule update`