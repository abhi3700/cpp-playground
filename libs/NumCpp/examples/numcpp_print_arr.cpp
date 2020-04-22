#include <iostream>
#include <NumCpp.hpp>	// nc array
#include <typeinfo>		// typeid


int main() {
	auto v = nc::linspace<int>(1, 10, 5);

	// check the type
	// std::cout << typeid(v).name() << std::endl;		// N2nc7NdArrayIiEE
	
	// print the array elements
	for(auto&& x : v) {
		std::cout << x << std::endl;
	}
	return 0;
}