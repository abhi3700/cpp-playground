#include <iostream>
#include <magic_enum/include/magic_enum.hpp>

enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	constexpr auto colors = magic_enum::enum_values<Color>();
	std::cout << colors[2] << std::endl;


	return 0;
}