#include <iostream>
// #include <magic_enum/include/magic_enum.hpp>
#include <pprint/include/pprint.hpp>

enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	constexpr auto color_names = magic_enum::enum_names<Color>();
	std::cout << color_names[0] << std::endl;

	pprint::PrettyPrinter p;
	p.print(color_names);


	return 0;
}