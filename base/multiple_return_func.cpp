/*
	Create a multiple return types function.
*/

#include <iostream>		// cout
#include <utility>		// std::pair, std::make_pair

// using namespace std;
using std::string;


std::pair<string, int> set_weekno(string day, int num) {
	return std::make_pair(day, num);
}

int main() {
	// M-1:
	// std::pair<string, int> daynum_week;

	// daynum_week = std::make_pair("Sunday", 0);


	// std::cout << daynum_week.first << std::endl;
	// std::cout << daynum_week.second << std::endl;

// ---------------------------------------------------------------------------


	std::pair<string, int> a = set_weekno("Sunday", 0);

	std::cout << a.first << std::endl;		// Sunday
	std::cout << a.second << std::endl;		// 0
	
	return 0;
}