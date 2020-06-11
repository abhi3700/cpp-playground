# Excel
Header only xlsxwriter (already implemented for Python) implementation in C.

## Features

## Installation [For Linux (Ubuntu)]
1. Open bash by <kbd>win + r</kbd> & type 'bash' and <kbd>enter</kbd>.
1. Install __libxlsxwriter__ using Homebrew: `$ brew install libxlsxwriter`
	- here, dependencies: `patchelf`, `zlib` & then the main lib: `libxlsxwriter` is installed 

```console
...
...
...
==> Installing dependencies for libxlsxwriter: patchelf and zlib
==> Installing libxlsxwriter dependency: patchelf
==> Pouring patchelf-0.10.x86_64_linux.bottle.1.tar.gz
🍺  /home/linuxbrew/.linuxbrew/Cellar/patchelf/0.10: 8 files, 921.5KB
==> Installing libxlsxwriter dependency: zlib
==> Pouring zlib-1.2.11.x86_64_linux.bottle.tar.gz
🍺  /home/linuxbrew/.linuxbrew/Cellar/zlib/1.2.11: 12 files, 424KB
==> Installing libxlsxwriter
==> Pouring libxlsxwriter-0.9.5.x86_64_linux.bottle.tar.gz
🍺  /home/linuxbrew/.linuxbrew/Cellar/libxlsxwriter/0.9.5: 35 files, 1.3MB
```
1. [OPTIONAL] Also, do this if there is any error like this:
```console
$ ./a.out
./a.out: error while loading shared libraries: libxlsxwriter.so: cannot open shared object file: No such file or directory
```

	- Solution: `$ sudo ldconfig -v`. Then the issue is resolved.
1. DONE!


## Editor (Sublime Text 3)
1. Use C++ packages as per [this guide](https://github.com/abhi3700/My_Learning-Cpp/blob/master/README.md#sublime-text-3-recommended-editor)
1. Now, for proper linting, copy & paste the folder (i.e. `include` inside ) into `mingw-64` directory (in C:\ drive): __"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++"__ 
1. DONE!

## Compiler (GNU, CMake) [For Linux (Ubuntu)]
* GNU: `$ gcc hello.c -I/usr/local/include -L/usr/local/lib -lxlsxwriter && time ./a.out` - this creates & runs a `a.out` file on successful compilation. Also, shows the time
* CMake: `$ cmake .` & then `$ make` & then `./test`

## Quick Start
* Example code:
```cpp
#include <xlsxwriter.h>

int main() {
    lxw_workbook *workbook  = workbook_new("hello.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row = 0;
    int col = 0;
    worksheet_write_string(worksheet, row, col, "Hello me!", NULL);
    return workbook_close(workbook);
}
``` 

## Coding

## Resources
* Github: https://github.com/jmcnamara/libxlsxwriter