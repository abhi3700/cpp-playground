#include <pprint/include/pprint.hpp>

using namespace std::complex_literals;

int main() {
	pprint::PrettyPrinter p;
	std::complex<double> c1 = 1. + 2.5i;
	std::complex<double> c2 = 6. + 9.5i;

	p.print(c1, "*" , c2, "=", c1*c2);
	std::cout << c1 << "*" << c2 << " = " << c1*c2 << std::endl;

	return 0;
}