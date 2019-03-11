#include "Date.cpp"

int main() {
	Date d1, d2;

	int da1, da2, mo1, mo2;
	int y1, y2;

	cout << "Date 1: \nEnter a day: " << endl;
	cin >> da1;

	cout << "Enter a month: " << endl;
	cin >> mo1;

	cout << "Enter a year: " << endl;
	cin >> y1;

	d1.setDate(da1, mo1);
	d1.setYear(y1);

	cout << "Date 2: \nEnter a day: " << endl;
	cin >> da2;

	cout << "Enter a month: " << endl;
	cin >> mo2;

	cout << "Enter a year: " << endl;
	cin >> y2;

	d2.setDate(da2, mo2);
	d2.setYear(y2);
	
	// print dates:
	cout << "Date 1: " << endl;
	d1.printDate();

	cout << "\n"; // next line

	cout << "Date 2: " << endl;
	d2.printDate();


	cout << "\n"; // next line
	// compare dates
	if (d1.isEarlier(d2)) {
		d1.printDate(); cout << " is earlier than "; d2.printDate(); cout << endl;
	} 

	if (d1.isLater(d2)) {
		d1.printDate(); cout << " is later than "; d2.printDate(); cout << endl;
	}	

	// equal dates comparison
	if (d1.isEqual(d2)) {
		d1.printDate(); cout << " is equal to "; d2.printDate(); cout << endl;
	}


	return 0;
}