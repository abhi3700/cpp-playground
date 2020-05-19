#include <iostream>
#include <variant>
#include <pprint/include/pprint.hpp>


using std::string;
pprint::PrettyPrinter p;

int main() {
	std::vector<std::variant<
				int,
				bool,
				float,
				double,
				char,
				long,
				string,
				std::vector<int>,
				std::map<int, string>
	>> v1;

	v1.emplace_back(1);
	v1.emplace_back(2343243l);
	v1.emplace_back("abhijit roy");
	v1.emplace_back(std::vector<int>{1, 2, 3});
	v1.emplace_back(std::map<int, string>{{1, "abhijit"}, {2, "vincent"}});

	p.quotes(true);
	p.print(v1);

	return 0;
}