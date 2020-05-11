#include <iostream>

template <typename T>
T abs(T n) {
	return (n < 0) ? -n : n;
}

int main() {
	int int1 = 5;  // int
	int int2 = -6; // int
	long lon1 = 7000L;  // long
	long lon2 = -8000L; // long 
	double dub1 = 9.95;  // double 
	double dub2 = -10.15;  // double
	char ch1 = 'a';  // char
	char ch2 = -'a';  // char


	// calls instantiate functions
	std::cout << "abs(" << int1 << ") = " << abs(int1) << '\n';
	std::cout << "abs(" << int2 << ") = " << abs(int2) << '\n';
	std::cout << "abs(" << lon1 << ") = " << abs(lon1) << '\n';
	std::cout << "abs(" << lon2 << ") = " << abs(lon2) << '\n';
	std::cout << "abs(" << dub1 << ") = " << abs(dub1) << '\n';
	std::cout << "abs(" << dub2 << ") = " << abs(dub2) << '\n';
	std::cout << "abs(" << ch1 << ") = " << abs(ch1) << '\n';
	std::cout << "abs(" << ch2 << ") = " << abs(ch2) << '\n';

	return 0;
}