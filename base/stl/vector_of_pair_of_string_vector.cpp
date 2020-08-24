/*
					Vector of pair of (string, vector<int>)
					- operations:
						+ insert
						+ access
						+ search
						+ display

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::make_pair;

int main() {
	using pair = std::pair<string, std::vector<int>>;
	std::vector<pair> v1;

	// =============insert element=======================
	v1.emplace_back(make_pair("create", std::vector<int>{1, 3, 5, 6}));
	v1.emplace_back(make_pair("assign", std::vector<int>{143, 545, 66, 77}));
	v1.emplace_back(make_pair("reachsrc", std::vector<int>{43, 2334, 56, 34}));

	// =============Access elements by index=======================
	std::cout << "size: " << v1.size() << "\n";
	std::cout << "0th primary: " << v1[0].first << "\n";
	std::cout << "0th secondary's 4th element val: " << v1[0].second[3] << "\n";
	std::cout << "0th secondary element (i.e. vector) size: " << v1[0].second.size() << "\n";


	// =============Access elements by iterator=======================
	std::cout << "-----------------------------------" << "\n";
	auto it = v1.begin();
	std::cout << "0th primary: " << it->first << "\n";
	std::cout << "0th secondary's 4th element val: " << it->second[3] << "\n";
	std::cout << "0th secondary element (i.e. vector) size: " << it->second.size() << "\n";

	// =============search =======================
	std::cout << "-----------------------------------" << "\n";
	// search for key
	auto s_pri = "assign";
	auto find_it_pri = std::find_if(v1.begin(), v1.end(), [&](auto& v){ return v.first == s_pri; });

	if(find_it_pri != v1.end()) {
		std::cout << "item found for key at position: " << find_it_pri - v1.begin() << " & it's secondary element's first val is: " << find_it_pri->second[0] << "\n";
	} else {
		std::cout << "item not found" << "\n";
	}

	// =============display =======================
	std::cout << "-----------------------------------" << "\n";
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		auto row_no = i - v1.begin();
		std::cout << "row " << row_no << ": ( " << i->first << ", " << "[";
		auto vsec = i->second;
		for (int j = 0; j < vsec.size(); ++j)
		{
			std::cout << vsec[j] << ",";
		}
		std::cout << "] )" << "\n";
	}

	return 0;
}