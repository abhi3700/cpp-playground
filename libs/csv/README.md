# CSV
Header-only C++17 library provides CSV reading/writing.

## Features
* get column names
* print all the cell values.
* print all (filtering with multiple conditions)
* get row_size
* count the no. of rows
* pick any row as _header_row_
* Print the rows where a column has null value
* Keep/Ignore/Throw
    - keep rows with variable length
    - ignore rows with variable length
    - throw errors at position of row with variable length
* Define new column names as header row
* Write data to CSV

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
* [Get column names](./getcolnames.cpp)
* [Print all](./printall.cpp)
* [Print all (with filtering)](./printall_filter.cpp)
* [Row size](./row_size.cpp)
* [Count](./count.cpp)
* [Header row](./header_row.cpp)
* [Example 1](./eg1.cpp)
* [Null values](./null.cpp)
* [Keep/Ignore/Throw](./keep_ignore_throw.cpp)
* [define new row as header](./define_new_col_header_row.cpp)
* [Write data to CSV](./writer.cpp)

## Resources
* Github: https://github.com/vincentlaucsb/csv-parser
