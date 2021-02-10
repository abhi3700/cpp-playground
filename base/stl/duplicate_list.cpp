/*
		Check if the list has any duplicates
		- M-1 using stl algorithm
			+ here, the original vector is changed.
		- M-2 using for loop
			+ here, the original vector NOT changed.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// M-2
bool hasDuplicates(const std::vector<int>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}


int main() {
    std::vector<int> v = {1,2,3,3,4,5};
    // std::vector<int> v = {1,2,3,4,5};
    
    // ========================================================================
/*    // M-1
    auto it = std::unique(v.begin(), v.end());
    std::cout << ((it == v.end()) ? "Unique\n" : "Duplicate(s)\n") << "\n";
    
    // print & check the original v is not changed.
    for(auto&& i : v) {
    	std::cout << i << ",";
    }
    std::cout << "\n";
*/
    // ========================================================================
    // M-2
    std::cout << hasDuplicates(v) << "\n";
    std::cout << (false == 0) << "\n";
    // print & check the original v is not changed.
    for(auto&& i : v) {
    	std::cout << i << ",";
    }
    std::cout << "\n";


    return 0;
}