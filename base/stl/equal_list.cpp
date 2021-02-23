/*
		Check if the list has same elements
		- M-1 using stl algorithm
			+ here, the original vector is changed.
		- M-2 using for loop
			+ here, the original vector NOT changed.

		* References
			- https://www.xspdf.com/resolution/58200222.html
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main() {
	vector<int> myvector{1, 1, 1};

	// M-1
/*	if ( std::adjacent_find( myvector.begin(), myvector.end(), std::not_equal_to<>() ) == myvector.end() )
	    std::cout << "All elements are equal each other" << "\n";
*/
	// M-2
	//assuming v has at least 1 element
	if ( std::equal(myvector.begin() + 1, myvector.end(), myvector.begin()) )
	    std::cout << "All elements are equal each other" << "\n";


	return 0;
}


