#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
	std::vector<int> v = {1, 2, 4, 9, 67};

	std::cout << "Print the list: " << "\n";

	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i << "\n";
	}

	int n1;
	std::cout << "Enter n1: " << "\n";
	std::cin >> n1;

	auto result1 = std::find(std::begin(v), std::end(v), n1);

	// search for 'n1'
	if(result1 != std::end(v)) {
		std::cout << "Vector contains: " << n1 << "\n";
	} else {
		std::cout << "Vector doesn't contain: " << n1 << "\n";		
	}

	return 0;
}