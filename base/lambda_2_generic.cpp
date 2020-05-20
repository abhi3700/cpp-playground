/*
			Generic ADD function using lambda
				- int
				- double
				- float
				- string

*/

#include <iostream>
#include <boost/assign/std/vector.hpp>

using std::string;
using namespace boost::assign;

int main() {
	auto add = [] (auto a, auto b) {
		return a + b;
	};

	// operation & display
	std::cout << add(1, 2) << "\n"; 		// int
	std::cout << add(1.0, 2.0) << "\n";		// double
	std::cout << add(1.0f, 2.0f) << "\n";	// float
	std::cout << add(string("abhijit "), string("roy")) << "\n";	// string
	return 0;
}

