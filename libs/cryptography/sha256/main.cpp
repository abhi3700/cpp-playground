#include "hashlibpp/hashlibpp.h"
#include <iostream>

int main() {
	hashwrapper *mywrapper = new sha256wrapper();
	try {
		std::string hash1 = mywrapper->getHashFromString("abhijit");
		std::cout << hash1 << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	delete mywrapper;

	return 0;
}