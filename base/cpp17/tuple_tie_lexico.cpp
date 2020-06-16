/*
				Purpose: to bind iterator with bool inserter to a container "Set"
				- pre C++17
				- post C++17
				- compare (lexicographical) 2 sets: comparing the integer part & (if equal, then string) & (if equal, then float)
					* Application: time (hh::mm::ss): https://www.pluralsight.com/blog/software-development/simplifying-lexicographical-comparisons-with-c--
*/


#include <iostream>
#include <set>
#include <iterator>
#include <tuple>


using std::string;

struct S
{
	int n;
	string s;
	float d;

	bool operator<(const S& rhs) const{
		return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
	}
};

int main() {
	// Set1
	std::set<S> my_set1;
/*
	// pre C++17
	S val1{100, "victor", 34.5};

	// define iterator & insert
	std::set<S>::iterator it1;
	bool inserter1;

	// then, return the iter, inserter using `tie`
	std::tie(it1, inserter1) = my_set1.insert(val1);

	if(inserter1) {
		// std::cout << "values are inserted." << "\n";
		std::cout << "Values (" << it1->n  << "," << it1->s << ", ... are inserted" << "\n";
	}

*/	
	// post C++17
	S val1{10000, "0ictor", 34.5};
	const auto [iter1, inserter1] = my_set1.insert(val1);
	if(inserter1) {
		std::cout << "Values (" << iter1->n  << "," << iter1->s << ", ... are inserted" << "\n";
	}


	std::set<S> my_set2;
	S val2{10000, "abhijit", 4.56};
	const auto[iter2, inserter2] = my_set2.insert(val2);

	if(inserter2) {
		// std::cout << "values are inserted." << "\n";
		std::cout << "Values (" << iter2->n  << "," << iter2->s << ", ... are inserted" << "\n";
	}

	// compare 2 sets
	my_set1 < my_set2 ? std::cout << "1 < 2" << "\n" : std::cout << "1 > 2" << "\n"; 


	return 0;
}