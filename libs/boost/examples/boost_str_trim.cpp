/**
 * 		This is Boost example-1, where you will learn about trimming string.
 * 		NOTE: Please, note the difference b/w 
 * 			- trim(s): modify the original, but can't be stored into a separate variable.
 * 			- trim_copy(s): copy & modify & store into a new string variable. The original is NOT changed.
 */

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <typeinfo>

using std::string;
using boost::algorithm::trim;
using boost::algorithm::trim_copy;


int main()
{
	string s1 = "	Welcome to the boost		";
	string s2 = s1;
	string s3 = "   C++ is actually simple, but made complex to support everything";
	
	trim(s2);	// trimming only the string s2

	string new_string = trim_copy(s3);	// trimming s3 & store the modified copy in new string.


	// print the final strings
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << new_string << std::endl;

	return 0;  
}




