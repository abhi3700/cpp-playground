/**
 * 				Assigning to Vector
 * 				- `+=` operator
 * 
 */

#include <iostream>			// cout, endl
#include <boost/assign/std/vector.hpp>		// for vector & '+=' operator
#include <boost/assert.hpp>		// for BOOST_ASSERT [not Mandatory, if boost/ is included in any form]

using namespace boost::assign;		// for += operator 

int main() {
	std::vector<int> vals;
	vals += 1, 2, 3, 4, 5;	

	// assert
	BOOST_ASSERT(vals.size() == 5);		// nothing, if true
	BOOST_ASSERT(vals[0] == 1);			// nothing, if true
	BOOST_ASSERT(vals[4] == 5);			// nothing, if true

	// display the output
	for (std::vector<int>::iterator i = vals.begin(); i != vals.end(); ++i)
	{
		std::cout << *i << std::endl;
	}


	return 0;
}