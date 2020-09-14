/*
	Erase a vector element by index
	- the index is generated from random no.
	- then, the element at that index is removed using iterator method.

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

int main() {
	std::vector<int> v {354, 765, 2334, 878, 545, 35345};
	srand(time(0));

	int rand_index = rand() % (v.size()-1);

	// original vector
	for(auto&& i : v) {
		std::cout << i << ",";
	}
	std::cout << "\n";

	v.erase(std::find(v.begin(), v.end(), v[rand_index]));

	for(auto&& i : v) {
		std::cout << i << ",";
	}
	std::cout << "\n";

	return 0;
}
