#include <csv-parser/csv.hpp>
#include <algorithm>

using csv::CSVReader;
using std::string;


int main() {
	CSVReader reader("../data/state-population.csv");
	std::vector<string> st_names;

	for(auto&& row : reader) {
		if(row["state/region"].is_str()) {
			st_names.emplace_back(row["state/region"].get<>());
		}
	}

	// remove duplicates
	auto ip = std::unique(st_names.begin(), st_names.end());	// Now v becomes like this: {1 3 10 1 3 7 8 * * * * *}, where * means undefined 
	st_names.resize(std::distance(st_names.begin(), ip));		// Resizing the vector so as to remove the undefined terms

	// verify the vector
	for (std::vector<string>::iterator i = st_names.begin(); i != st_names.end(); ++i)
	{
		std::cout << *i << ",";
	}
	std::cout << st_names.size() << "\n";

	// std::cout << "Enter the year (1990-2013): " << "\n";
	// int year;
	// std::cin >> year;
	// std::cout << "Enter the States out of this list: \n[";

	// for (std::vector<string>::iterator i = st_names.begin(); i != st_names.end(); ++i)
	// {
	// 	std::cout << *i << ", ";
	// }
	// std::cout<< "]" << "\n";

	// string st_in;
	// bool find_status = false;
	// while(!find_status) {
	// 	std::cin >> st_in;
	// 	auto it = std::find(st_names.begin(), st_names.end(), st_in);
	// 	if(it != st_names.end()) {
	// 		find_status = true;
	// 	} else {
	// 		find_status = false;
	// 		std::cout << "The entered state is NOT found. \nPlease try again..." << "\n";
	// 	}

	// }

	// for(auto&& row : reader) {
		
	// }

	return 0;
}