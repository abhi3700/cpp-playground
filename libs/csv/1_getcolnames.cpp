/*
                Example 1
                - print the column names
                    + M-1: using `pprint`
                    + M-2: using simple for_v loop
                NOTE: in both the cases, the output file is of size 320-330 KB.
*/

#include <csv-parser/csv.hpp>
// #include <pprint/include/pprint.hpp>


using std::string;

// pprint::PrettyPrinter p;

int main() {
    csv::CSVReader reader("../data/equipment.csv");

    auto cols = reader.get_col_names();

    // M-1
    // p.print(cols);

    // M-2
    for (auto i = cols.begin(); i != cols.end(); ++i)
    {
        std::cout << *i << "\n";
    }


    return 0;
}