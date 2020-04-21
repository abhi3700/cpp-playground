#include <iostream>

using std::string;
using std::cin;

int main() {
	string str;
	std::cout << "Enter a string" << std::endl;
	
	cin >> str;

	// getline(cin, str);

	std::cout << str << std::endl;


	return 0;
}