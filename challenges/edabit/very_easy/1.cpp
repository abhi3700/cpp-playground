/*
		- Check whether parsed array are identical
		- Compile using
			- `g++ 1.cpp && ./a.out`

*/

#include <iostream>
#include <vector>

using std::vector;
using vec = std::vector<int>


bool checkEquals(std::vector<int> arr1, std::vector<int> arr2) {
	  return arr1 == arr2;
}

int main() {
	
	// M-1
	auto v1 = {1, 2};
	auto v2 = {1, 3};
	auto v3 = {4, 5, 6};
	auto v4 = {4, 7, 6};

	std::cout << checkEquals(v1, v2) << "\n";
	std::cout << checkEquals(v1, v1) << "\n";
	std::cout << checkEquals(v3, v3) << "\n";
	std::cout << checkEquals(v3, v4) << "\n";

	// =============================================================================
	// M-2
/*	std::cout << checkEquals(vec{1, 2}, vec{1, 3}) << "\n";
	std::cout << checkEquals(vec{1, 2}, vec{1, 2}) << "\n";
	std::cout << checkEquals(vec{4, 5, 6}, vec{4, 5, 6}) << "\n";
	std::cout << checkEquals(vec{4, 5, 6}, vec{4, 7, 6}) << "\n";
*/
	return 0;
}