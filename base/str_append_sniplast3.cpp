/*
		- 'append' is much faster than '+'
		- preserve the decimal places using double type
		- snip last 3 digits from string using `substr`

*/

#include <iostream>
#include <string>


using std::string;


int main() {
	string s1 = "abhijit";
	string s2 = " roy";
	string s3 = " is a";
	string s4 = " good boy.";
	double res = (double)4235435436/1000;
	std::cout << res <<"\n";
	string id_str = std::to_string(res);

	string s5 = id_str.substr(id_str.find(".")+1, 3);
	// s.erase(std::prev(s.end()))

	string s = s1.append(s2).append(s3).append(s4).append(s5);
	std::cout << s << "\n";

	return 0;
}