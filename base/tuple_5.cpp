/**
 * 				Tuple
 * 				- a sequence of elements (of any type)
 * 				- total no. of elements is 5 here.
 * 
 */

#include <iostream>
#include <tuple>

using std::string;

int main() {
	std::tuple<string, int, int, string, string> t1 = {"abhijit", 102, 2423432, "fab", "dry_etch"};

	std::cout << std::get<0>(t1) << std::endl;
	std::cout << std::get<1>(t1) << std::endl;
	std::cout << std::get<2>(t1) << std::endl;
	std::cout << std::get<3>(t1) << std::endl;
	std::cout << std::get<4>(t1) << std::endl;


	return 0;
}