/**
 * 				Set
 * 				- a sequence of keys
 * 
 */

#include <iostream>
#include <set>


int main() {
	std::set<int> s1 = {1, 2, 3};
	
	// print the elements
	for (std::set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	return 0;
}