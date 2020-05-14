#include <pprint/include/pprint.hpp>

enum House
{
	LOW,
	MEDIUM,
	HIGH
};

enum Color
{
	RED = 3,
	BLUE = 6,
	GREEN = 8
};

int main() {
	pprint::PrettyPrinter p;
	House h_qual = HIGH;
	p.print("House quality: ", h_qual);

	Color c_num = BLUE;
	p.print("Color no.: ", BLUE);

	return 0;
}