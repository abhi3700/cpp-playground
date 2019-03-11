#include <string>
#include <iostream>

using namespace std;

class Date {
	public:
		Date( unsigned short = 1, unsigned short = 1, unsigned int = 1970 ); // constructor

		bool isEarlier( const Date& ) const;
		bool isLater( const Date& )  const;
		bool isEqual( const Date& ) const;

		bool setDate( unsigned short d, unsigned short m  );

		unsigned short getDay() const;

		unsigned short getMonth() const;

		bool setYear( unsigned int year );
		unsigned int getYear() const;

		void printDate() const;

	private:
		unsigned short _day, _month;
		unsigned int _year;

};