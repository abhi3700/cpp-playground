/*
			Header row
			- assign any row as the header row
*/
#include <csv-parser/csv.hpp>

using csv::CSVReader;
using csv::CSVFormat;

int main() {
	CSVFormat format;
	format.header_row(3);
	CSVReader reader("../data/equipment_header.csv", format);


	for(auto&& row : reader) {
		std::cout << row[0].get<>() << ", "
					<< row["Site"].get<>() << ", " 
					<< row["Etch Rate (A/Min)"].get<>() << ", " 
					<< row["Result"].get<>() << 
		"\n";
	}


}