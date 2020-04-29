/**
 *  Capitalize & Trim string using Boost string lib
 *  1. Capitalize: capitaliz
 *  2. Trim
 *  3. return the final string
 */

#include <iostream>
#include <boost/algorithm/string.hpp>

using std::string;
using namespace boost;

int main() {
	string str1 = " hello string1! ";
	string str2 = " hello string2! ";

	// capitalize original str1
	to_upper(str1);		// " HELLO STRING1! "
	std::cout << "str1: " << str1 << std::endl;		// " HELLO STRING1! "
	std::cout << "str2: " << str2 << std::endl;		// " hello string2! "

	// trim original str2
	trim(str2);			// "hello string2!"
	std::cout << "str1: " << str1 << std::endl;		// " HELLO STRING1! "
	std::cout << "str2: " << str2 << std::endl;		// "hello string2!"

	return 0;
}