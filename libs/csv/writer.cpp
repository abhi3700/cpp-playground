#include <csv-parser/csv.hpp>
#include <sstream>
#include <vector>
#include <deque>
#include <list>


using csv::CSVReader;
using csv::make_csv_writer;
using std::string;


int main() {
    std::ofstream outfile("../data/demo_writer.csv");       // create file
	
    auto writer = make_csv_writer(outfile);

	writer << std::vector<string>({ "A", "B", "C" })
    << std::deque<string>({ "I'm", "too", "tired" })
    << std::list<string>({ "to", "write", "documentation" });

    outfile.close();        // close file

    // Read file data
    CSVReader reader("../data/demo_writer.csv");


    for(auto&& row : reader) {
    	std::cout << row["A"].get<>() << ", "
    				<< row["B"].get<>() << ", "
    				<< row["C"].get<>()
    	<< "\n";
    }


	return 0;
}