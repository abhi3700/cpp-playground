/**
 * 					Pair
 * 					- a sequence of 2 elements (any type)
 * 					
 */

#include <iostream>
#include <utility>

using std::string;

int main() {
	std::pair<string, int> p1 = {"abhijit", 102};

	std::cout << p1.first << std::endl;
	std::cout << p1.second << std::endl;

	return 0;
}