/*
		Print the rows where a column has null value
*/

#include <csv-parser/csv.hpp>

using csv::CSVReader;

int main() {
	CSVReader reader("../data/state-population_null.csv");
	for(auto&& row : reader) {
		if(row["population"].is_null()) {
			std::cout << row["year"].get<>() << "\n";
		}
	}

	return 0;
}