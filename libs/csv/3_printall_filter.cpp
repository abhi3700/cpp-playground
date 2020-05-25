/*
				Example 3
				- print the rows, filterng the rows (AND logical condition) 
					+ where 'Date' column has no value
					+ where 'Result' column has 'Pass' value
					+ where 'Etch Rate (A/Min)' column has value <= 11000
*/

#include <csv-parser/csv.hpp>
#include <pprint/include/pprint.hpp>

pprint::PrettyPrinter p;

using std::string;

int main() {
	csv::CSVReader reader("../data/equipment.csv");
	// p.print(reader.get_col_names());			// just for reference (without viewing the CSV file)

	for(auto& row : reader) {
		if(row[0].is_str() 
			&& row["Result"].get<string>() == "Pass"
			&& row["Etch Rate (A/Min)"].get<string>() <= "11000"
			) {
			std::cout << row[0].get<string>() << ","
						<< row["Site"].get<string>() << ","
						<< row["Etch Rate (A/Min)"].get<string>() << ","
						<< row["Result"].get<string>() << ","
			<< "\n";

		}
	}

	return 0;
}
