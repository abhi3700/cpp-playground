#include <iostream>


using std::string;


class section
{
	string employee_name;
	string employee_code;
	char employee_shift;

public:
	section();

	// TODO set the employee's name into CSV
	void set_employee_name(string name) {employee_name = name;}
	void set_employee_code(string code) {employee_code = code;}

	// TODO get the employee's name from CSV
	string get_employee_name() {return employee_name;}
	string get_employee_code() {return employee_code;}
	char get_employee_shift() {return employee_shift;}
	
};

class dryetch : section
{
public:
	dryetch() : section() {};
	
};

int main() {
	

	return 0;
}