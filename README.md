# cpp-playground
Practice C++ coding with other github repos

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


