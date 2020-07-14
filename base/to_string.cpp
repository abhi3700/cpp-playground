#include <iostream>


int main() {
	double d1 = 3.4;
	double d2 = 1e-9;
	double d3 = 1e40;

	std::cout << d1 << "\n";		// 3.4
	std::cout << std::to_string(d1) << "\n";		// "3.40000"
	std::cout << d2 << "\n";		// 1e-9
	std::cout << std::to_string(d2) << "\n";		// Note: returns "0.000000"
	std::cout << d3 << "\n";		// 3.4
	std::cout << std::to_string(d3) << "\n";		// Note: Does not return "1e+40".

	return 0;
}