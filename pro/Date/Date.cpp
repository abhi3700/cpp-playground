#include "Date.hpp"

Date::Date(unsigned short day, unsigned short month, unsigned int year ) {
	if( day > 31 || day < 1 )
		day = 1;
	if( month > 12 || month < 1 )
		month = 1;
	if( year < 1 )
		year = 1970;

	_day = day;
	_month = month;
	_year = year;
}

// set day and month with a check.
bool Date::setDate( unsigned short d, unsigned short m  ) {
	if( m >= 1 && m <= 12 ) { // within Jan to Dec months.
		if( d >= 1 && d <= 31 ) { // within Dates - 1 to 31 of these months - Jan to Dec.
			if (d == 30 && m == 2 ) // excluding the 30 Feb
				return false;
			else if (d == 31) { // excluding all the 31's of months - Feb, 
				if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) 
					return false;
			}
			else {
				_day = d;
				_month = m;
				return true;
			}
		}
	}
	else 
		return false;
}

unsigned short Date::getDay() const {
	return this->_day;
}

unsigned short Date::getMonth() const {
	return this->_month;
}

bool Date::setYear( unsigned int y ) {
	if (y <= 0)
		return false;
	else  {
		_year = y;
		return false;
	}

}
unsigned int Date::getYear() const {
	return this->_year;
}

bool Date::isEarlier(const Date& d) const {
	if(d._year > _year)
		return true;
	else if( (d._year == _year) && (d._month > _month) )
		return true;
	else if( (d._year == _year) && (d._month == _month) && (d._day > _day) )
		return true;
	else 
		return false;
}

bool Date::isLater(const Date& d) const {
	if(d._year < _year)
		return true;
	else if( (d._year == _year) && (d._month < _month) )
		return true;
	else if( (d._year == _year) && (d._month == _month) && (d._day < _day) )
		return true;
	else 
		return false;
}

bool Date::isEqual(const Date& d) const {
	if( (d._year == _year) && (d._month == _month) && (d._day == _day) )
		return true;
	else 
		return false;
}

void Date::printDate() const {
	cout << this->_day << "-" << this->_month << "-" << this->_year;

}
