/*
*/

#include <pprint/include/pprint.hpp>

using std::string;

pprint::PrettyPrinter p;

int main() {
	auto hello = [] () {
		std::cout << "hello world" << std::endl;
		p.print("hello world");
	};
	hello();

	return 0;
}