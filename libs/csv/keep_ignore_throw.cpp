/*
		"Keep/Ignore/Throw" for rows of variable length
			- keep rows with variable length
			- ignore rows with variable length
			- throw	errors at position of row with variable length
*/
#include <csv-parser/csv.hpp>


int main() {
	csv::CSVFormat format;
	// format.variable_columns(true);
	// format.variable_columns(csv::VariableColumnPolicy::KEEP);
	// format.variable_columns(csv::VariableColumnPolicy::IGNORE);
	format.variable_columns(csv::VariableColumnPolicy::THROW);

	csv::CSVReader reader("../data/state-population_variable.csv", format);
	for(auto&& row : reader) {
		if(row["population"].is_null()) {
			std::cout << row["year"].get<>() << "\n";
		}
	}


	return 0;
}