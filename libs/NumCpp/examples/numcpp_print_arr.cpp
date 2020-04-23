#include <iostream>
#include <NumCpp.hpp>	// nc array
#include <typeinfo>		// typeid


int main() {
	auto v1 = nc::linspace<int>(1, 10, 5);
	auto v2 = nc::linspace<double>(1.0, 12.9, 2.0);
	auto v3 = nc::linspace<double>(1.0f, 12.9f, 2.0f);

	std::cout << typeid(v1).name() << std::endl;		// N2nc7NdArrayIiEE
	std::cout << typeid(v2).name() << std::endl;		// N2nc7NdArrayIdEE
	std::cout << typeid(v3).name() << std::endl;		// N2nc7NdArrayIdEE
	
	// prints elements of array
	for(auto&& x : v1) {
		std::cout << x << std::endl;
	}

	// prints elements of array
	for(auto&& x : v2) {
		std::cout << x << std::endl;
	}

	// prints elements of array
	for(auto&& x : v3) {
		std::cout << x << std::endl;
	}

	return 0;
}
