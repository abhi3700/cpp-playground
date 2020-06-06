/**
 * 					Remove duplicates
 * 					- select duplicates & make it undefined using `std::unique` returns iterator
 * 					- resize to remove the undefined using `.resize()`
 * 					
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v1{1,3,8,9,5,5,7,8,7,10,11,34,45,56,34};
	// remove duplicates
	auto ip = std::unique(v1.begin(), v1.end());		// Now, 'v1' becomes like {1,3,8,9,5,7,8,10,11,34,45,56,*,*,*} where, * -> undefined
	v1.resize(std::distance(v1.begin(), ip));			// resize 'v1' so as to remove the undefined terms

	// verify the vector
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << *i << "\n";
	}

	return 0;
}