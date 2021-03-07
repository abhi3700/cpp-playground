/*
		Check if the list has same elements
		- M-1.1 using stl algorithm
			+ here, if the v.size is 0, then also it will print "All elements are equal to each other".
			+ here, comparing all the elements to its adjacent element.
		- M-1.2 using stl algorithm [RECOMMENDED]
			+ here, if the v.size is 0, then also it will print "All elements are equal to each other".
			+ here, the condition has been put using lambda by comparing all the elements to its 1st element.
		- M-2 using for loop
			+ here, if the v.size is 0, then also it will print error as "Segmentation fault (core dumped)".

		* References
			- https://www.xspdf.com/resolution/58200222.html
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main() {
	vector<int> myvector{};
	// vector<int> myvector{1, 1, 1};

/*	// M-1.1
	if ( std::adjacent_find( myvector.begin(), myvector.end(), std::not_equal_to<>() ) == myvector.end() )
	    std::cout << "All elements are equal to each other" << "\n";

    // print & check the original myvector is not changed.
    for(auto&& i : myvector) {
    	std::cout << i << ",";
    }
*/
	// M-1.2
	if ( std::all_of(myvector.begin(), myvector.end(), [&myvector](auto i){return i == myvector[0];}) ) {
	    std::cout << "All elements are equal to each other" << "\n";
	}

    // print & check the original myvector is not changed.
    for(auto&& i : myvector) {
    	std::cout << i << ",";
    }

	// M-2
	//assuming v has at least 1 element
/*	if ( std::equal(myvector.begin() + 1, myvector.end(), myvector.begin()) )
	    std::cout << "All elements are equal to each other" << "\n";

    // print & check the original myvector is not changed.
    for(auto&& i : myvector) {
    	std::cout << i << ",";
    }


*/
	return 0;
}


