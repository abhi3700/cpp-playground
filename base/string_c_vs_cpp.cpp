/**

	Difference b/w "string C" vs "string C++":
		- C
			+ defined by `const char*`
		- C++
			+ defined by `std::string`

 */


#include <iostream>

int main() {
	// M-1:
	std::string str_cpp = "abhijit";
	const char* str_c = str_cpp.c_str();

	// M-2:
	const char* str_c = "abhijit";	
	std::string str_cpp = str_c;

	std::cout << str_cpp << std::endl;
	std::cout << str_c << std::endl;

	return 0;
}