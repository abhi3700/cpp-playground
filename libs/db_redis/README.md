# REDIS for C++
This is a C++ client for Redis. It's based on hiredis, and written in C++ 11 / C++ 17.

> NOTE: It depends upon the main C lib for Redis i.e. `hiredis`

## Features
* Most commands for Redis.
* Connection pool.
* Redis scripting.
* Thread safe unless otherwise stated.
* Redis publish/subscribe.
* Redis pipeline.
* Redis transaction.
* Redis Cluster.
* Redis Sentinel.
* STL-like interfaces.
* Generic command interface.

## Installation [For Linux (Ubuntu)]
### Part A - Install hiredis
1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos").
1. Clone the repo via git: `$ git clone https://github.com/redis/hiredis.git`
```console
Cloning into 'hiredis'...
remote: Enumerating objects: 31, done.
remote: Counting objects: 100% (31/31), done.
remote: Compressing objects: 100% (25/25), done.
remote: Total 3703 (delta 10), reused 14 (delta 6), pack-reused 3672
Receiving objects: 100% (3703/3703), 1.21 MiB | 1.29 MiB/s, done.
Resolving deltas: 100% (2314/2314), done.
```
1. `$ cd hiredis/`: Go to directory 'hiredis'
1. create `libhiredis.a` `libhiredis.so` files using make
```console
$ make
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb alloc.c
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb net.c
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb hiredis.c
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb sds.c
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb async.c
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb read.c
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb sockcompat.c
cc -shared -Wl,-soname,libhiredis.so.0.15 -o libhiredis.so alloc.o net.o hiredis.o sds.o async.o read.o sockcompat.o
ar rcs libhiredis.a alloc.o net.o hiredis.o sds.o async.o read.o sockcompat.o
cc -std=c99 -pedantic -c -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb test.c
cc -o hiredis-test -O3 -fPIC   -Wall -W -Wstrict-prototypes -Wwrite-strings -Wno-missing-field-initializers -g -ggdb -I. test.o libhiredis.a
Generating hiredis.pc for pkgconfig...
```
1. install the header files & libs in respective default locations
```console
$ sudo make install
[sudo] password for abhi3700:
mkdir -p /usr/local/include/hiredis /usr/local/include/hiredis/adapters /usr/local/lib
cp -pPR hiredis.h async.h read.h sds.h alloc.h /usr/local/include/hiredis
cp -pPR adapters/*.h /usr/local/include/hiredis/adapters
cp -pPR libhiredis.so /usr/local/lib/libhiredis.so.0.15
cd /usr/local/lib && ln -sf libhiredis.so.0.15 libhiredis.so
cp -pPR libhiredis.a /usr/local/lib
mkdir -p /usr/local/lib/pkgconfig
cp -pPR hiredis.pc /usr/local/lib/pkgconfig
```

### Part B - Install redis-plus-plus
1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos").
1. Clone the repo via git:
```console
$ git clone https://github.com/sewenew/redis-plus-plus.git
Cloning into 'redis-plus-plus'...
remote: Enumerating objects: 174, done.
remote: Counting objects: 100% (174/174), done.
remote: Compressing objects: 100% (66/66), done.
remote: Total 2717 (delta 73), reused 145 (delta 54), pack-reused 2543
Receiving objects: 100% (2717/2717), 675.86 KiB | 917.00 KiB/s, done.
Resolving deltas: 100% (1612/1612), done.
```
1. `$ cd redis-plus-plus/`: Go to directory 'redis-plus-plus'
1. create folder >> build with C++17 integration
```
$ mkdir compile && cd compile
$ cmake -DCMAKE_BUILD_TYPE=Release -DREDIS_PLUS_PLUS_CXX_STANDARD=17 ..
```
1. make
```console
$ make
[  2%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/command.cpp.o
[  5%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/command_options.cpp.o
[  8%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/connection.cpp.o
[ 11%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/connection_pool.cpp.o
[ 14%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/crc16.cpp.o
[ 17%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/errors.cpp.o
[ 20%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/pipeline.cpp.o
[ 23%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/redis.cpp.o
[ 26%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/redis_cluster.cpp.o
[ 29%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/reply.cpp.o
[ 32%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/sentinel.cpp.o
[ 35%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/shards.cpp.o
[ 38%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/shards_pool.cpp.o
[ 41%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/subscriber.cpp.o
[ 44%] Building CXX object CMakeFiles/shared.dir/src/sw/redis++/transaction.cpp.o
[ 47%] Linking CXX shared library libredis++.so
[ 47%] Built target shared
[ 50%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/command.cpp.o
[ 52%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/command_options.cpp.o
[ 55%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/connection.cpp.o
[ 58%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/connection_pool.cpp.o
[ 61%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/crc16.cpp.o
[ 64%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/errors.cpp.o
[ 67%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/pipeline.cpp.o
[ 70%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/redis.cpp.o
[ 73%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/redis_cluster.cpp.o
[ 76%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/reply.cpp.o
[ 79%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/sentinel.cpp.o
[ 82%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/shards.cpp.o
[ 85%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/shards_pool.cpp.o
[ 88%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/subscriber.cpp.o
[ 91%] Building CXX object CMakeFiles/static.dir/src/sw/redis++/transaction.cpp.o
[ 94%] Linking CXX static library lib/libredis++.a
[ 94%] Built target static
[ 97%] Building CXX object test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o
[100%] Linking CXX executable test_redis++
[100%] Built target test_redis++
```
1. Install i.e. copy header & lib files into `/usr/local/include` & `/usr/local/lib` respectively.
```console
$ sudo make install
[sudo] password for abhi3700:
[ 47%] Built target shared
[ 94%] Built target static
[100%] Built target test_redis++
Install the project...
-- Install configuration: "Release"
-- Installing: /usr/local/lib/libredis++.a
-- Installing: /usr/local/lib/libredis++.so
-- Set runtime path of "/usr/local/lib/libredis++.so" to ""
-- Installing: /usr/local/include/sw/redis++/command.h
-- Installing: /usr/local/include/sw/redis++/command_args.h
-- Installing: /usr/local/include/sw/redis++/command_options.h
-- Installing: /usr/local/include/sw/redis++/connection.h
-- Installing: /usr/local/include/sw/redis++/connection_pool.h
-- Installing: /usr/local/include/sw/redis++/errors.h
-- Installing: /usr/local/include/sw/redis++/pipeline.h
-- Installing: /usr/local/include/sw/redis++/queued_redis.h
-- Installing: /usr/local/include/sw/redis++/queued_redis.hpp
-- Installing: /usr/local/include/sw/redis++/redis++.h
-- Installing: /usr/local/include/sw/redis++/redis.h
-- Installing: /usr/local/include/sw/redis++/redis.hpp
-- Installing: /usr/local/include/sw/redis++/redis_cluster.h
-- Installing: /usr/local/include/sw/redis++/redis_cluster.hpp
-- Installing: /usr/local/include/sw/redis++/reply.h
-- Installing: /usr/local/include/sw/redis++/sentinel.h
-- Installing: /usr/local/include/sw/redis++/shards.h
-- Installing: /usr/local/include/sw/redis++/shards_pool.h
-- Installing: /usr/local/include/sw/redis++/subscriber.h
-- Installing: /usr/local/include/sw/redis++/transaction.h
-- Installing: /usr/local/include/sw/redis++/utils.h
```

## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `sw` & `hiredis` from "/usr/local/include") into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp -lredis++ -lhiredis -pthread && ./a.out` - this creates & runs a `a.out` file on successful compilation.
* CMake: `mkdir build && cd build` >> `$ cmake ..` >> `$ make` >> `./app` [Source](https://github.com/sewenew/redis-plus-plus/issues/5)
```cmake
cmake_minimum_required(VERSION 3.5.0)

project(app)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -W -Werror -fPIC")

set(SOURCE_FILES test.cpp)
add_executable(app ${SOURCE_FILES})

# <------------ add hiredis dependency here --------------->
find_path(HIREDIS_HEADER hiredis)
target_include_directories(app PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(app ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency here -------------->
find_path(REDIS_PLUS_PLUS_HEADER sw)      # NOTE: this should be *sw* NOT *redis++*
target_include_directories(app PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(app ${REDIS_PLUS_PLUS_LIB})
```
* When linking with shared libraries, and running your application, you might get the following error message:
```console
error while loading shared libraries: xxx: cannot open shared object file: No such file or directory.
```
That's because the linker cannot find the shared libraries. In order to solve the problem, you can add the path where you installed hiredis and redis-plus-plus libraries, to LD_LIBRARY_PATH environment variable. For example:
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

## Quickstart
* Code:
```cpp
#include <sw/redis++/redis++.h>
#include <iostream>

using namespace sw::redis;
using std::string;


// const string redis_uri = "redis://h:pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";
const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {

	try {
		auto redis = Redis(redis_uri);
		std::cout << redis.ping() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
```
* Output:
```console
$ g++ -std=c++17 test.cpp -lredis++ -lhiredis -pthread
$ ./a.out
PONG
```
* Observation
	+ The original URI which is provided to us via Heroku database is
```
redis://h:pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989
```
	+ But, the URL to be parsed into the Redis() function is:
```
tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989
```
	+ Here, the username `h` is dropped & `redis` is replaced with `tcp`

## Coding
* [Quickstart](./quickstart.cpp)
* [Set & Get](./setget.cpp)
* [Multiple Set & Get](./msetget.cpp)
* [List](./list.cpp)

## References
* Redis client written in C++ - https://github.com/sewenew/redis-plus-plus