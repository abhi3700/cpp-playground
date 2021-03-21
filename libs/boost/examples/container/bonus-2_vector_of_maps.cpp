/*
			Vector of Map
			- each component has map of unique (key, value) pair
			- can have same values with different keys inside vector
				+ E.g. 3: (4, "vincent") ("3", vincent)
			- Not acceptable inside vector
				+ E.g. 1: (5, "Cat") (5, "john")
				+ E.g. 2: (5, "Cat") (5, "Cat")

*/
#include <iostream>
#include <string>
#include <vector>
#include <map>


using std::string;
using std::vector;
using std::map;
using std::make_pair;

int main() {
	vector<map<string, string>> v1{};
	
	// =========================================================
	// Insertion
	// M-1
	// map<string, string> m1;
	// m1.insert(make_pair("symbol_name", "EOS"));
	// m1.insert(make_pair("symbol_precision", "4"));
	// m1.insert(make_pair("contract", "eosio.token"));
	// m1.insert(make_pair("value", "90000"));
	// v1.emplace_back(m1);

	// ---------------------------------------------------------
	// M-2
	v1.emplace_back(map<string, string>{
		make_pair("symbol_name", "EOS"),
		make_pair("symbol_precision", "4"),
		make_pair("contract", "eosio.token"),
		make_pair("value", "90000")
	});

	v1.emplace_back(map<string, string>{
		make_pair("symbol_name", "FUTBOL"),
		make_pair("symbol_precision", "4"),
		make_pair("contract", "tokenfutbol1"),
		make_pair("value", "110000")
	});

	// =========================================================
	// Search
	// search for contract as "tokenfutbol1"
	auto search_index = 0;

	// M-1: using for loop method
	for (int i = 0; i < v1.size(); ++i)
	{
		if(v1[i]["contract"] == "tokenfutbol1") {
			search_index = i;
			break;
		}
	}

	std::cout << "the element found at index: " << search_index << "\n";

	// M-2: using iterator method TODO


	// =========================================================
	// Display
	std::cout << v1[0]["symbol_name"] << "\n";
	std::cout << v1[0]["symbol_precision"] << "\n";
	std::cout << v1[1]["symbol_name"] << "\n";

	return 0;
}