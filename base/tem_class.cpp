/**
 * 
 * 					Description:
 * 					- Trying to calculate plusone by 2 main methods: Template, Class
 * 					- Template: create a generic templated function
 * 					- Class:
 * 						+ M-1: Do using `plusme()` func
 * 						+ M-2: Do using `operator()()` func
 * 
 * 
 * 
 */

#include <iostream>
#include <boost/assert.hpp>


template<typename T>
T plusone(T x) {
	return x + 1;
}

class Plus
{
	int val;
public:
	Plus(){}
	Plus(int _val) {
		val = _val;
	}

	int plusme(int x) const {
		return x + val;
	}

	int operator() (int x) const {
		return x + val;
	}



	
};


int main() {

	// ----------Using Template------------------	
	// auto x = plusone(45);
	// auto y = plusone(6.13);

	// std::cout << x << std::endl;
	// std::cout << y << std::endl;

	// ----------Using Class------------------	
	/* M-1 */
	// auto p = Plus(2);
	// auto x = p.plusme(45);
	// BOOST_ASSERT(x == 47);


	/* M-2 */
	auto x = Plus(2);
	BOOST_ASSERT(x(45) == 47);


	return 0;
}