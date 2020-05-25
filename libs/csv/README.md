# CSV
Header-only C++17 library provides CSV reading/writing.

## Features
* get column names
* print the cell values.
* remove empty rows (at least one cell is empty)
* filtering with multiple conditions

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
* GNU: `$ g++ -std=c++17 test.cpp -pthread && time ./a.out` - this creates & runs a `a.out` file on successful compilation. Also, shows 
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
#include <csv-parser/csv.hpp>
// #include <pprint/include/pprint.hpp>


using std::string;

// pprint::PrettyPrinter p;

int main() {
    csv::CSVReader reader("../data/equipment.csv");

    auto cols = reader.get_col_names();

    // M-1
    // p.print(cols);

    // M-2
    for (auto i = cols.begin(); i != cols.end(); ++i)
    {
        std::cout << *i << "\n";
    }


    return 0;
}
``` 

## Coding
* [Get column names](./1_getcolnames.cpp)
* [Print all](./2_printall.cpp)
* [Print all (with filtering)](./3_printall_filter.cpp)

## Resources
* Github: https://github.com/Neargye/csv-parser