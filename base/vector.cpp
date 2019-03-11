#include <iostream>
#include <vector>

int main() {
	std::vector<char> c = {'a', 'b'};
	for (std::vector<char>::iterator i = c.begin(); i != c.end(); ++i)
	{
		std::cout << *i << "\n";
	}
	return 0;
}