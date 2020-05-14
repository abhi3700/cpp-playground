/*
*/

#include <pprint/include/pprint.hpp>

pprint::PrettyPrinter p;

int main() {
	std::optional<int> i;
	// std::optional<int> i = 6;
	
	p.print(i);

	// std::cout << i << std::endl;

	return 0;
}
