/*
			Implement `Pair` using `Struct`
			- Demerit: for each type, you have to define.
*/

#include <iostream>

struct pair
{
	double first;
	double second;
};

int main() {
	pair p{9, 10};
	std::cout << p.first << ", " << p.second << "\n";

	return 0;
}