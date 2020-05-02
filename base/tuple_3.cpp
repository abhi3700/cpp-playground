/**
 * 				Tuple
 * 				- a sequence of elements (of any type)
 * 				- total no. of elements is 3 here.
 * 
 */

#include <iostream>
#include <tuple>

using std::string;

int main() {
	std::tuple<string, int, int> t1 = {"abhijit", 102, 2423432};

	std::cout << std::get<0>(t1) << std::endl;
	std::cout << std::get<1>(t1) << std::endl;
	std::cout << std::get<2>(t1) << std::endl;


	return 0;
}