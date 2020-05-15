#include <iostream>
#include <magic_enum/include/magic_enum.hpp>


enum Color
{
	RED = 2,
	BLUE = 4,
	GREEN = 10
};

int main() {
	auto color_entries = magic_enum::enum_entries<Color>();
	std::cout << color_entries[0].first << ", " << color_entries[0].second << std::endl;

	// display all the entries at once.
	for (auto i = color_entries.begin(); i != color_entries.end(); ++i)
	{
		std::cout << (*i).first << ", " << (*i).second << std::endl;
	}

	return 0;
}