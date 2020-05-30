/*
			Get row size of all/any row
*/

#include <csv-parser/csv.hpp>


int main() {
	csv::CSVReader reader("../data/cs.csv");

	for(auto&& row : reader) {
		std::cout << row.size() << "\n";
		break;
	}

	return 0;
}