/*
			Structured binding with C++17 
			- define an array
			- extract the elements like this (shown below)
*/

#include <iostream>
#include <vector>

int main() {
	double my_array[3] = {1.0, 4.5, 6.7};
	auto [a, b, c] = my_array;		// structured binding

	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	return 0;
}