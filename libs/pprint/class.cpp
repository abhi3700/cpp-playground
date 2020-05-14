/*
*/

#include <pprint/include/pprint.hpp>

pprint::PrettyPrinter p;

// empty object
class Food {};

// Date object
class Date {
	unsigned int month, day, year;
public:
	Date(unsigned int m, unsigned int d, unsigned int y) : month(m), day(d), year(y) {};

	friend std::ostream& operator<<(std::ostream& os, const Date& dt) {
		os << dt.month << "/" << dt.day << "/" << dt.year;
		return os;
	}
};


int main() {
	Food f;
	p.print(f);

	Date date(05, 14, 2020);
	p.print("Today's date: ", date);


	return 0;
}
