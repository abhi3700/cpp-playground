# Telegram for C++

## Installation (on Linux (Ubuntu))
* `$ sudo apt-get install g++ make binutils cmake libssl-dev libboost-system-dev zlib1g-dev libcurl4-openssl-dev`

> NOTE: If you want to use curl-based http client `CurlHttpClient`, you also need to install `libcurl4-openssl-dev` package.

* Library installation: `libTgBot.a` file
	- clone git repo & build using `cmake`
```console
$ git clone https://github.com/reo7sp/tgbot-cpp
$ cd tgbot-cpp
$ cmake .
$ make -j4
$ sudo make install
```
	- see the directory & find `libTgBot.a` file
```console
$ tree -L 1
.
├── CMakeCache.txt
├── CMakeFiles
├── CMakeLists.txt
├── Dockerfile
├── Dockerfile_test
├── Doxyfile
├── LICENSE
├── Makefile
├── README.md
├── cmake_install.cmake
├── include
├── libTgBot.a
├── samples
├── src
├── sw.cpp
├── test
└── tools
```
	- copy the file to `/usr/local/lib` via: `$ sudo cp libTgBot.a /usr/local/lib/`

## Editor
* Setup the Sublime Text 3 editor for C++ as per [instructions](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor).
* Suggestions for this package: Just copy the "tgbot" folder into this directory: `"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"`
* Now, the linting gets activated.

## Compile
* Using `CMake` on Bash terminal | Linux (Ubuntu)

## Get Started
* Create a directory "echobot" like this:
```console
$ tree -L 3
.
└── echobot
    ├── CMakeLists.txt
    └── src
        └── main.cpp

2 directories, 2 files
```
* `cmake .`
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
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Looking for pthread_create
-- Looking for pthread_create - not found
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Found OpenSSL: /usr/lib/x86_64-linux-gnu/libcrypto.so (found version "1.1.1")
-- Boost  found.
-- Found Boost components:
   system
-- Found CURL: /usr/lib/x86_64-linux-gnu/libcurl.so (found version "7.58.0")
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/f/Coding/github_repos/cpp-playground/libs/telegram/examples/echobot
```
* `make`
```console
$ make
Scanning dependencies of target echobot
[ 50%] Building CXX object CMakeFiles/echobot.dir/src/main.cpp.o
[100%] Linking CXX executable echobot
[100%] Built target echobot
```
* `./echobot`
```console
$ ./echobot
Bot username: tgcpp_bot
Long poll started
User wrote /start
Long poll started
Long poll started
User wrote I am a handsome guy
Long poll started
```
* parallely, on Telegram screen
```console
abhi3700, [29.04.20 03:18]
/start

Telegram C++, [29.04.20 03:38]
Hi!

abhi3700, [29.04.20 03:38]
I am a handsome guy

Telegram C++, [29.04.20 03:38]
Your message is: I am a handsome guy
```
* Press <kbd>ctrl + z</kbd> to exit.


## Repositories
* C++ library for Telegram bot API - https://github.com/reo7sp/tgbot-cpp