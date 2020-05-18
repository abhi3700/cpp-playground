/**
 * 						Accumulate function
 * 						=======1st syntax=========
 * 						accumulate(first, last, sum);
						first, last : first and last elements of range 
						              whose elements are to be added
						sum :  initial value of the sum


 * 						=======2nd syntax=========
						accumulate(first, last, sum, myfun); 
						myfun : a function for performing any 
						        specific task. For example, we can
						        find product of elements between
						        first and last. * 						
 * 						
 * 						
 */



#include <iostream>
// #include <iterator>
#include <vector>
#include <numeric>
#include <boost/assign/list_of.hpp>

using boost::assign::list_of;

int main() {
    std::vector<int> v1;
    v1 = list_of(1) (2) (4);

    auto d = static_cast<double>(std::accumulate(v1.begin(), v1.end(), 0)/v1.size());			// convert to double

    std::cout << d << std::endl;

	return 0;
}