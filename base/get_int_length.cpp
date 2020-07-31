#include <iostream>

uint64_t int_length(uint64_t i) {
	    uint64_t l=0;
	    for(;i;i/=10) l++;
	    return l==0 ? 1 : l;
	}

int main() {
	uint64_t year = 2020;

	std::cout << int_length(year) << "\n";
    return 0;
}