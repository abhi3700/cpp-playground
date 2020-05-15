#include <iostream>
#include <magic_enum/include/magic_enum.hpp>
#include <typeinfo>

enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	auto color = magic_enum::enum_value<Color>(1);
	std::cout << color << std::endl;

	return 0;
}