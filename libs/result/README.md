# result
A Templatized Header Only C++ Implementation of [result](https://github.com/p-ranav/result) Library

## Features
> __Highlight:__ can be used in functional programming

* can be used for many mathematical operations at once (while checking for errors) using `and_then()`
* compose output of one function with that of another function, using `map`
* type conversion from one type to another can be done for both `Ok` & `Err`.

## Installation [For Linux (Ubuntu)]
1. Open `bash` (ubuntu) terminal at your preferred directory path ("F:\Coding\github_repos\").
1. `$ mkdir result`
1. `$ cd result`
1. Clone the repo's sub-folder via svn: `$ svn checkout https://github.com/p-ranav/result/trunk/include`
1. Now, copy the result folder (with include/ppprint.hpp) into "/usr/local/include/" path.
1. DONE!

## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `result`) into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ g++ -std=c++17 test.cpp && ./a.out` - this creates a `a.out` file on successful compilation.
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
#include <iostream>
#include <result/include/result.hpp>


using result::Result;
using result::Ok;
using result::Err;

using std::string;

auto Div(double x, double y) -> Result<double, string> {
  if(y == 0.0) {
    return Err(string{"Division by zero."});
  } else {
    return Ok(x/y);
  }
}

int main() {
  auto result1 = Div(100.0, 40.0);
  if(result1.is_ok()) {
    std::cout << result1.unwrap() << std::endl;
  }

  auto result2 = Div(100.0, 0.0);
  if(result2.is_err()) {
    std::cout << result2.unwrap_err() << std::endl;
  }

  return 0;
}
``` 

## Coding

## Resources
* Github: https://github.com/p-ranav/result