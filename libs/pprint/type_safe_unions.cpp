/*
*/

#include <pprint/include/pprint.hpp>
using std::string;

pprint::PrettyPrinter p;

int main() {
	std::vector<std::variant<
		bool,
		int,
		float,
		int*,
		string,
		std::map<string, std::map<string, int>>,
		std::pair<double, string>,
		std::vector<int>
	>> v1;

	v1.emplace_back(true);
	v1.emplace_back(34);
	v1.emplace_back("vincent");
	v1.emplace_back(std::map<string, std::map<string, int>>{
		{"a", {{"b", 1}}},
		{"c", {{"d", 2}, {"e", 3}}}
	});
	v1.emplace_back(std::vector<int>{1, 2, 4});
	v1.emplace_back(std::pair<double, string>{3.4, "abhijit"});

	p.indent(2);
	p.quotes(true);
	p.print(v1);

	return 0;
}