#include <iostream>
#include <vector>

using std::string;


void vector_eg() {
	// std::vector<string> v {"aamir", "hrithik", "family"};
	std::vector<string> v;


	v.emplace_back("aamir");
	v.emplace_back("hrithik");
	v.emplace_back("family");

	v.pop_back();	// erase from back


	std::cout << "Without Iterator:" << std::endl;
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << std::endl;
	}

	std::cout << "With Iterator:" << std::endl;
	for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}


int main() {
	vector_eg();


	return 0;
}
