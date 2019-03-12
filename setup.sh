#!/bin/bash
##########################################################################
# This sets up the dependency libraries from different github repositories.
# NOTE: in case of any unexpected error, try to use `dos2unix <shell-script-file-name.sh>`
##########################################################################
# -----------------------------------------------------------------
# include/boost
if [[ -d "include/boost" ]]; then
	# echo "boost folder exist"
	cd ./include/boost
	git pull
	cd ..
	cd ..
else
	# echo "boost folder NOT exist"
	cd ./include
	git submodule add https://github.com/abhi3700/boost boost
	cd ..
fi
# -----------------------------------------------------------------
# include/simdjson
if [[ -d "include/simdjson" ]]; then
	# echo "simdjson folder exist"
	cd ./include/simdjson
	svn update
	cd ..
	cd ..
else
	# echo "simdjson folder NOT exist"
	cd ./include
	svn checkout https://github.com/lemire/simdjson/trunk/include/simdjson
	cd ..
fi
# -----------------------------------------------------------------
# include/spdlog
if [[ -d "include/spdlog" ]]; then
	# echo "spdlog folder exist"
	cd ./include/spdlog
	git pull
	cd ..
	cd ..
else
	# echo "spdlog folder NOT exist"
	cd ./include
	git clone -b v1.x --single-branch https://github.com/gabime/spdlog.git
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/exercism-exercises
if [[ -d "gitcpplibs/exercism-exercises" ]]; then
	# echo "exercism-exercises folder exist"
	cd ./gitcpplibs/exercism-exercises
	svn update
	cd ..
	cd ..
else
	# echo "exercism-exercises folder NOT exist"
	cd ./gitcpplibs
	svn checkout https://github.com/exercism/cpp/trunk/exercises exercism-exercises
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/denismatveev-exercises
if [[ -d "gitcpplibs/denismatveev-exercises" ]]; then
	# echo "denismatveev-exercises folder exist"
	cd ./gitcpplibs/denismatveev-exercises
	git pull
	cd ..
	cd ..
else
	# echo "denismatveev-exercises folder NOT exist"
	cd ./gitcpplibs
	git submodule add https://github.com/denismatveev/exercises.git denismatveev-exercises
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/sagar-cpp
if [[ -d "gitcpplibs/sagar-cpp" ]]; then
	# echo "sagar-cpp folder exist"
	cd ./gitcpplibs/sagar-cpp
	git pull
	cd ..
	cd ..
else
	# echo "sagar-cpp folder NOT exist"
	cd ./gitcpplibs
	git submodule add https://github.com/Sagar-022/c_plus_plus sagar-cpp
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/cpp-primer
if [[ -d "gitcpplibs/cpp-primer" ]]; then
	# echo "cpp-primer folder exist"
	cd ./gitcpplibs/cpp-primer
	git pull
	cd ..
	cd ..
else
	# echo "cpp-primer folder NOT exist"
	cd ./gitcpplibs
	git submodule add https://github.com/Mooophy/Cpp-Primer.git cpp-primer
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/leet-code
if [[ -d "gitcpplibs/leet-code" ]]; then
	# echo "leet-code folder exist"
	cd ./gitcpplibs/leet-code
	git pull
	cd ..
	cd ..
else
	# echo "leet-code folder NOT exist"
	cd ./gitcpplibs
	git submodule add https://github.com/wj-zhu/leet-code.git leet-code
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/boost-py-eg
if [[ -d "gitcpplibs/boost-py-eg" ]]; then
	# echo "boost-py-eg folder exist"
	cd ./gitcpplibs/boost-py-eg
	git pull
	cd ..
	cd ..
else
	# echo "boost-py-eg folder NOT exist"
	cd ./gitcpplibs
	git submodule add https://github.com/TNG/boost-python-examples.git boost-py-eg
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/cpp-patterns-wj
if [[ -d "gitcpplibs/cpp-patterns-wj" ]]; then
	# echo "cpp-patterns-wj folder exist"
	cd ./gitcpplibs/cpp-patterns-wj
	git pull
	cd ..
	cd ..
else
	# echo "cpp-patterns-wj folder NOT exist"
	cd ./gitcpplibs
	git submodule add https://github.com/wj-zhu/cpp-patterns.git cpp-patterns-wj
	cd ..
fi
# -----------------------------------------------------------------
# gitcpplibs/cpp-wj
if [[ -d "gitcpplibs/cpp-wj" ]]; then
	# echo "cpp-wj folder exist"
	cd ./gitcpplibs/cpp-wj
	svn update
	cd ..
	cd ..
else
	# echo "cpp-patterns-wj folder NOT exist"
	cd ./gitcpplibs
	svn checkout https://github.com/wj-zhu/snippets/trunk/cpp cpp-wj
	cd ..
fi
