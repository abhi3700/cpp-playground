/*
		- preserve the decimal places using double type for uint64_t (8 bytes). Why double, not float? - because
									uint64_t is a 8 byte (64-bit) which fits well with double 8 bytes, not float (4 bytes)

*/

#include <iostream>


using std::string;


int main() {
	uint64_t num = 4235435436;
	double res = (double)num;
	std::cout << res <<"\n";

	return 0;
}