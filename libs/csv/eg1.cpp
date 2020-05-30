#include <csv-parser/csv.hpp>

using csv::CSVReader;

int main() {
	CSVReader reader("../data/state-population.csv");
	int year;
	std::cout << "Enter the year (1990-2013): " << "\n";
	std::cin >> year;

	auto pop_tot = 0, state_cnt = 0;
	for(auto&& row : reader) {
		if(row["ages"].get<>() == "under18"
			&& row["year"].get<int>() == year
			&& row["population"].is_int()) {		// to ignore 'NaN'
			pop_tot += row["population"].get<int>();
			++state_cnt;
		}
	}

	std::cout << "The total population for " << state_cnt << " states/regions in the year " << year << ": " << pop_tot << "\n";

	return 0;
}