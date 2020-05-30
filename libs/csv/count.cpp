/*
		- Count the no. of rows where, "Etch Rate (A/Min)" has values b/w (9000, 12000)
		- Also, print the rows ("Date", "Etch Rate (A/Min)") values.
*/

#include <csv-parser/csv.hpp>

using csv::CSVReader;
using std::string;

int main() {
	CSVReader reader("../data/equipment.csv");

	int cnt = 0;
	for(auto&& row : reader) {
		if(row[0].is_str()
			&& row["Etch Rate (A/Min)"].get<double>() > 9000.0000 
			&& row["Etch Rate (A/Min)"].get<double>() < 12000.0000 
			) {
			std::cout 
				<< row[0].get<string>() << ", "
				<< row["Etch Rate (A/Min)"].get<double>() << "\n";
			++cnt;
		}
	}
	std::cout << cnt << "\n";



	return 0;
}
