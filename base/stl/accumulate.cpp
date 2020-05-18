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

    // M-1:
    std::cout << std::accumulate(v1.begin(), v1.end(), 0) << std::endl;				// 0 + 1 + 2 + 4 = 7

    // M-2
	auto lambda = [&](double a, double b){return a + b; };
    std::cout << std::accumulate(v1.begin(), v1.end(), 0, lambda) << std::endl;				// 0 + (0+1) + (0+2) + (0+4) = 7

	auto l = [&](double a, double b){return a * b; };
    std::cout << std::accumulate(v1.begin(), v1.end(), 1, l) << std::endl;				// 1 + (1*1) + (1*2) + (1*4) = 8


	return 0;
}