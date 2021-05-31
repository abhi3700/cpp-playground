/*

			About
			=====
			- uint64_t to string & then extract a substring from the main string
			- string to uint64_t
*/

#include <iostream>
#include <string>
#include <cstdlib>

using std::string;

int main() {
	uint64_t i1 = 92101622458197;
	auto s = std::to_string(i1).substr(4, 10);				// uint64_t to string & then extract a substring from the main string
	auto i2 = strtoull(s.c_str(), NULL, 10);				// string to uint64_t

	std::cout << s << "\n";
	std::cout << i2 << "\n";

	return 0;
}