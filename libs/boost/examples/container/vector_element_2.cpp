#include <iostream>
#include <boost/assign/list_of.hpp>
#include <vector>
#include <algorithm>

using std::string;
using namespace boost::assign;

int main() {
	typedef std::pair<string, int> pair;
	std::vector<pair> v1;
	// insert
	v1 = list_of<pair>("abhijit", 102) ("adi", 103) ("victor", 1034) ("vincent", 102);
	// v1 = map_list_of("abhijit", 102) ("adi", 103) ("victor", 1034) ("vincent", 102);
	
	// access
	std::cout << v1.size() << std::endl;
	std::cout << v1[0].first << std::endl;
	std::cout << v1[0].second << std::endl;
	std::cout << v1.at(0).first << std::endl;
	std::cout << v1.at(0).second << std::endl;

	auto it = v1.begin();
	std::cout << (*it).first << std::endl;
	std::cout << (*it).second << std::endl;
	advance(it, 1);
	std::cout << (*it).first << std::endl;
	std::cout << (*it).second << std::endl;
	advance(it, -1);
	std::cout << (*it).first << std::endl;
	std::cout << (*it).second << std::endl;

	std::cout << "===============================" << std::endl;

	// search by primary key
	auto s_pri = "adi";
	auto find_it_pri = std::find_if(v1.begin(), v1.end(), [&](auto& v){ return v.first == "victor"; });

	if(find_it_pri != v1.end()) {
		std::cout << s_pri << " is found at position " << find_it_pri - v1.begin() << std::endl;
		std::cout << "And the secondary key at this position is: " << find_it_pri->second << "\n";
	} else {
		std::cout << s_pri << " is NOT found." << std::endl;
	}

	// search by secondary key
	auto s_sec = 1034;
	auto find_it_sec = std::find_if(v1.begin(), v1.end(), [&](auto& v){ return v.second == 1034; });

	if(find_it_sec != v1.end()) {
		std::cout << s_sec << " is found at position " << find_it_sec - v1.begin() << std::endl;
		std::cout << "And the primary key at this position is: " << find_it_sec->first << "\n";
	} else {
		std::cout << s_sec << " is NOT found." << std::endl;
	}

	std::cout << "===============================" << std::endl;
	// display
	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i].first << ", " << v1[i].second << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	for(auto& i : v1) {
		std::cout << i.first << ", " << i.second << std::endl;
	}

	std::cout << "-------------------------------" << std::endl;
	for (std::vector<pair>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << (*i).first << ", " << (*i).second << std::endl;
	}



	return 0;
}