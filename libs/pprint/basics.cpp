#include <pprint/include/pprint.hpp>

using std::string;

int main() {
	pprint::PrettyPrinter printer;
	printer.print(4);
	printer.print(4.0);
	printer.print(4.4f);
	printer.print(343235l);
	printer.print(343235ul);
	printer.print(true);
	printer.print('z');
	printer.print("abhijit");

	printer.quotes(true);
	printer.print("A", "B", "C");
	printer.quotes(false);

	printer.quotes(true);
	printer.print("abhijit is a good boy.");
	printer.quotes(false);

	auto kids_num = 4;
	printer.print("There were ", kids_num, " kids in the ground.");

	return 0;
}