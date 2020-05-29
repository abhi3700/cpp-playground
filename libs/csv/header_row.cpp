#include <csv-parser/csv.hpp>

using std::string;

int main() {
	csv::CSVFormat format;
	format.header_row(3);
	csv::CSVReader reader("../data/equipment_header.csv", format);

	auto cols = reader.get_col_names();

	for(auto& row : reader) {
		std::cout << row[0].get<string>() << ", "
					<< row["Site"].get<string>() << ", "
					<< row["Result"].get<string>() << ", "
					<< row["Etch Rate (A/Min)"].get<string>()
					<< "\n";
	}

	return 0;
}