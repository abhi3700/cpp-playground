#include <csv-parser/csv.hpp>
#include <fstream>		// ifstream, ofstream
#include <vector>
#include <deque>
#include <list>

using std::string;
using csv::make_csv_writer;
// using 

int main() {
	std::ofstream out_file("../data/demo_writer2.csv");

	auto writer = csv::make_csv_writer(out_file);

	writer << std::vector<string>{"Name", "Division", "EmpCode"}
			<< std::deque<string>{"Abhijit", "Design", "10244"}
			<< std::list<string>{"Victor", "Testing", "102435"};

	out_file.close();

	std::cout << "==================" << "\n";
	csv::CSVReader reader("../data/demo_writer2.csv");

	for(auto&& row : reader) {
		std::cout << row[0].get<>() << ", " 
					<< row[1].get<>() << ", "
					<< row[2].get<>()		
		<< "\n";
	}

	return 0;
}