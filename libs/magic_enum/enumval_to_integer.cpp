#include <iostream>
#include <magic_enum/include/magic_enum.hpp>

enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	constexpr auto color_integer = magic_enum::enum_integer(Color::GREEN);
	std::cout << color_integer << std::endl;

	return 0;
}