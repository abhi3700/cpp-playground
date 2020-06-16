/*
			Lexicographical comparison for Objects - "Time"

			> NOTE: Always write object name starting with capital letter -e.g. "Time" instead of "time"
*/

#include <iostream>
#include <tuple>

class Time
{
private:
	int hr;		// 00 - 23
	int min;	// 00 - 59
	int sec;	// 00 - 59
public:
	// Time() : hr(), min(), sec() {}
	Time(int h, int m, int s) : hr(h), min(m), sec(s) {}

	int hour() { return this->hr; }
	int minute() { return this->min; }
	int second() {return this->sec; }

	bool operator <(Time& rhs) {
		return std::tie(hr, min, sec) < std::tie(rhs.hr, rhs.min, rhs.sec);
	}
};

int main() {
	Time t1(12, 43, 23);
	// std::cout << t1.hour() << "\n";
	Time t2(12, 34, 45);

	t1 < t2 ? std::cout << "t1 < t2" << "\n" : std::cout << "t1 > t2" << "\n";

	return 0;
}