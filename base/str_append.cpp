/*
	Join strings
	- M-1: using '+' takes a longer time
	- M-2: append() is much faster
*/
#include <iostream>
#include <string>

using std::string;


int main() {
	string s2 = "abhijit";
	string str = "";
	// auto s1 = "abhijit ".append("is a good boy ").append("& very talented");				// WRONG, "" is read as const char*. So, `append()` is inside the string class.
	auto s1 = string("abhijit ").append("is a good boy ").append("& very talented");		// CORRECT	"" is wrapped with string() to convert from const char* to string class

	std::cout << s1 << "\n";


	return 0;
}
