/*
This is a tour of Modern C++
----------------------------
	- Learning about some variables, strings, vectors

*/
// ==========================================================
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Person
{
	string name;
	int age;
};

int main() {
	int a = 1;
	// int a{1};
	std::cout << a << std::endl;

// ------------------------------------------------------
	// string s = "abhijit";
	string s{"abhijit"};
	std::cout << s << std::endl;
// ------------------------------------------------------
	// vector<int> v;
	// v.push_back(10);
	// v.push_back(20);
	vector<int> v{10, 20};

	std::cout << v.at(0) << std::endl;		// print 0th i.e. 1st element
	std::cout << v.at(1) << std::endl;		// print 1st i.e. 2nd element
	// std::cout << v.at(2) << std::endl;		// print 1st i.e. 2nd element
// ------------------------------------------------------
	// map<string, string> capitals = {
	// 	{"UK", "london"}, {"India", "Delhi"}
	// };

	map<string, string> capitals{
		{"UK", "london"}, {"India", "Delhi"}
	};

	for(auto&& i : capitals) {
		std::cout << i.first << ": " << i.second << std::endl;	
	}
// ------------------------------------------------------

	Person p = {"abhijit", 27};
	// Person p{"abhijit", 27};
	std::cout << p.name << ", " << p.age << std::endl;


	// getchar();
	return 0;
}