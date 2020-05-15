#include <iostream>
#include <magic_enum/include/magic_enum.hpp>

enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	constexpr auto color_count = magic_enum::enum_count<Color>();
	std::cout << color_count << std::endl;

	return 0;
}