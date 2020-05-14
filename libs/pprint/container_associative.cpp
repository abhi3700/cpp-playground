/*
*/

#include <pprint/include/pprint.hpp>


using std::string;

pprint::PrettyPrinter p;

int main() {
	std::unordered_map<string, std::set<int>> m1 = {
		{"abhijit", {1, 2, 3}},
		{"vincent", {10, 20, 30}},
		{"cat", {11, 21, 31}},
	};

	p.print("Map: ", m1);
	return 0;
}