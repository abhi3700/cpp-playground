/*
			Define new column names as header row
*/

#include <csv-parser/csv.hpp>


using std::string;

int main () {
	csv::CSVFormat format;
	std::vector<string> v1{"states", "ag", "tot", "pop"};
	format.column_names(v1);

	csv::CSVReader reader("../data/state-population_wo_col.csv", format);

	auto get_cols = reader.get_col_names();

	// print new col names
	for(auto&& c : get_cols) {
		std::cout << c << ", ";
	}
	std::cout << "========================" << "\n";

	// display all the rows
	for(auto&& row : reader) {
		std::cout << row[0].get<>() << ",";
		std::cout << row[1].get<>() << ",";
		std::cout << row[2].get<>() << ",";
		std::cout << row[3].get<>() << "\n";
	}

	return 0;
}