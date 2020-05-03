/**
 *   				Conversion
 *   				- integer to string
 *   				- double to string
 *   				- float to string
 * 					- string to integer
 * 					- string to double
 * 					- string to float
 */
#include <iostream>

using std::string;
using std::to_string;
using std::stoi;

int main() {
	string s1 = "34324";
	int i1 = 232;
	double d1 = 232.43;
	float f1 = 232.43f;

	// convert ... to string
	std::cout << to_string(i1) << std::endl;		// convert integer to string
	std::cout << to_string(d1) << std::endl;		// convert double to string
	std::cout << to_string(f1) << std::endl;		// convert float to string
	
	// convert string to ...
	std::cout << stoi(s1) << std::endl;				// convert string to double
	std::cout << stod(s1) << std::endl;				// convert string to double
	std::cout << stof(s1) << std::endl;				// convert string to float

	return 0;
}