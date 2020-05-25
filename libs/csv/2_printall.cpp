/*
				Example 2
				- print the rows (all)
*/

#include <csv-parser/csv.hpp>

using csv::CSVReader;

int main() {
	CSVReader reader("../data/equipment.csv");
	for(auto& row : reader) {
		std::cout 
				<< row[0].get<std::string>() << ","
				<< row["Site"].get<std::string>() << ","
				<< row["Result"].get<std::string>() << ","
				<< row["Etch Rate (A/Min)"].get<std::string>()
		<< "\n";
	}

	return 0;
}

