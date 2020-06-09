/*
				Write data to CSV
					- writing data
					- reading data

*/

#include <csv-parser/csv.hpp>
#include <fstream>		// ifstream, ofstream
#include <vector>
#include <deque>
#include <list>

using std::string;
using csv::make_csv_writer;
// using 

int main() {
	// create file (if doesn't exist)
	std::ofstream out_file("../data/demo_writer2.csv");

	// Use `make_csv_writer` to put data to file
	auto writer = csv::make_csv_writer(out_file);

	// put data to writer var
	writer << std::vector<string>{"Name", "Division", "EmpCode"}
			<< std::deque<string>{"Abhijit", "Design", "10244"}
			<< std::list<string>{"Victor", "Testing", "102435"};

	// close the file
	out_file.close();

	// read data from existing file
	std::cout << "==================" << "\n";
	csv::CSVReader reader("../data/demo_writer2.csv");

	// print the values
	for(auto&& row : reader) {
		std::cout << row[0].get<>() << ", " 
					<< row[1].get<>() << ", "
					<< row[2].get<>()		
		<< "\n";
	}

	return 0;
}