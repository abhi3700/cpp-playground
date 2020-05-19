/*
			Generic ADD function using lambda

*/

#include <iostream>

int main() {
	auto add = [] (auto a, auto b) {
		return a + b;
	};
	std::cout << add(1, 2) << "\n"; 		// int
	std::cout << add(1.0, 2.0) << "\n";		// double
	std::cout << add(1.0f, 2.0f) << "\n";	// float
	return 0;
}

