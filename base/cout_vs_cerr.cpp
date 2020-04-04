#include <iostream>
#include <chrono>

using namespace std::chrono;

int main() {
	auto cout_start_time = high_resolution_clock::now();
	std::cout << "Hello world" << std::endl;
	auto cout_stop_time = high_resolution_clock::now();
// ----------------------------------------------------------------
	auto cerr_start_time = high_resolution_clock::now();
	std::cerr << "Hello world" << std::endl;
	auto cerr_stop_time = high_resolution_clock::now();

	std::cout << "The time taken for cout is: " << duration_cast<microseconds>(cout_stop_time - cout_start_time).count() << " milliseconds" << std::endl;
	std::cout << "The time taken for cerr is: " << duration_cast<microseconds>(cerr_stop_time - cerr_start_time).count() << " milliseconds" << std::endl;

	return 0;

}


/*
// Testing
The test data shows this:
The time taken for cout is: 400 milliseconds
The time taken for cerr is: 778 milliseconds

The time taken for cout is: 341 milliseconds
The time taken for cerr is: 547 milliseconds

The time taken for cout is: 406 milliseconds
The time taken for cerr is: 818 milliseconds

The time taken for cout is: 406 milliseconds
The time taken for cerr is: 829 milliseconds

The time taken for cout is: 390 milliseconds
The time taken for cerr is: 771 milliseconds

The time taken for cout is: 401 milliseconds
The time taken for cerr is: 611 milliseconds

*/

/*
// Conclusion
This clearly shows that cout is faster than cerr.
*/

