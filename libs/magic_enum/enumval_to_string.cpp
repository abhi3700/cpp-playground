#include <iostream>
#include <magic_enum/include/magic_enum.hpp>

enum Color
{
	RED = 2,
	GREEN = 4,
	BLUE = 10,
};

int main() {
	auto color_name = magic_enum::enum_name(Color::BLUE);

	std::cout << color_name << std::endl;

	return 0;
}