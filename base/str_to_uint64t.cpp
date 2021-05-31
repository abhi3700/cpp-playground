/*
		convert string to uint64_t
		- `stoi()` won't work here, as it returns upto a 32 bit integer.
		- strtoull is applied for min. uint64_t to uint128_t & further. Basically, the max of `unsigned long long`
		- Reference:
			- https://stackoverflow.com/a/58063723/6774636 [Using C lib i.e. cstdlib]
			- https://stackoverflow.com/a/42356960/6774636 [Using Boost lib]
*/

//======================================================================================================================
// M-1: Using std lib

#include <iostream>
#include <string>
#include <cstdlib> 		// for strtoull

using std::string;

inline uint64_t str_to_uint64t(const string& s) {
	// char* end;
	// uint64_t num = strtoull(s.c_str(), &end, 10);
  uint64_t num = strtoull(s.c_str(), NULL, 10);        // RECOMMENDED
	return num;
}

int main() {
  // for 64 bit
  string value= "14443434343434343434";
  std::cout << "UInt64: " << str_to_uint64t(value) << "\n";

  // for 8 bit
  string value_2= "4";
  std::cout << "UInt8: " << stoi(value_2) << "\n";

  return 0;
}




//======================================================================================================================
// M-2: Using Boost lib
// Compile using 
// 		- `g++ file.cpp -I /mnt/f/Coding/github_repos && ./a.out`

/*
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp> //I've multiple versions of boost installed, so this path may be different for you

int main()
{
    using boost::lexical_cast;
    using namespace std;

    const string s("2424242");
    uint64_t num = lexical_cast<uint64_t>(s);
    cout << num << endl;

    return 0;
}
*/