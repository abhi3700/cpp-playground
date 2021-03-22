/*
			Map
			- unique (key, value) pair
			- can have same values with different keys.
				+ E.g. 3: (4, "vincent") ("3", vincent)
			- Not acceptable
				+ E.g. 1: (5, "Cat") (5, "john")
				+ E.g. 2: (5, "Cat") (5, "Cat")

*/
#include <iostream>
#include <map>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>

using std::string;
using namespace boost::assign;


int main() {
	std::map<int, string> m1;
	// insert(m1) (1, "abhijit") (4, "victor") (3, "vincent") (5, "cat");
	// m1 = list_of<std::pair<int, string>>(1, "abhijit") (4, "victor") (3, "vincent") (5, "cat");
	m1 = map_list_of(1, "abhijit") (4, "victor") (3, "vincent") (5, "cat");

	// access
	std::cout << m1[4] << std::endl;
	std::cout << m1.at(4) << std::endl;		// [RECOMMENDED]]

	auto it = m1.begin();
	std::cout << (*it).second << std::endl;
	advance(it, 2);
	std::cout << (*it).second << std::endl;

	// change the value of 2nd itr;
	auto it_change = m1.begin();
	advance(it_change, 2);
	it_change->second = "samaira";


	// display
	for (auto itr = m1.begin(); itr != m1.end(); ++itr)
	{
		// std::cout << (*itr).first << ", " << (*itr).second << std::endl;
		std::cout << itr->first << ", " << itr->second << std::endl;
	}
	std::cout << "----------------------------" << "\n";

	for(auto&& i : m1) {
		std::cout << i.first << ", " << i.second << std::endl;
	}
	std::cout << "----------------------------" << "\n";

	std::cout << m1.size() << "\n";
	for (auto i=0; i <= m1.size(); ++i)
	{
		std::cout << m1.at(i) << ", " << m1.at(i) << std::endl;
	}





	return 0;
}