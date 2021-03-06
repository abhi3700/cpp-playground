#include <iostream>
#include <magic_enum/include/magic_enum.hpp>

enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	auto color = magic_enum::enum_cast<Color>("GREEN");		// string type
	if (color.has_value())
	{
		std::cout << color.value() << std::endl;	// M-1: using magic_enum
		std::cout << Color::GREEN << std::endl;		// M-2
	}


	return 0;
}