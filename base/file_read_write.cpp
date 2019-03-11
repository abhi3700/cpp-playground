#include <iostream>		// cin, cout
#include <fstream>		// ofstream, ifstream
#include <string>		// string


int main() {
	// std::ofstream op;	

	// Output text to a file (create if doesn't exist).
	// op.open("user.txt");
	// op << "abhijit my age is 25 " << '\n';
	// op.close();

	std::ifstream ip;

	std::string str;

	ip.open("user.txt");
		
	ip >> str;

	// M-1
	while(!ip.eof()) {
		std::cout << str;
		ip >> str;		// ignores the 'spaces'
	}

	// M-2
	// while(getline(ip, str)) {
	// 	std::cout << str;
	// }

	return 0;
}