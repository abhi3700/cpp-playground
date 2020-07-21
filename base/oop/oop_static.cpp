/*
			Use of `static` member (variables, functions) of a Class
			- Static member (valid for both data, function members)
				+ There is only one copy of the member, no matter how many objects are created.
				+ can be initialized anywhere outside the class, main function using scope (::) operator.
				+ is shared by all the objects of the class.
				+ is initialized to zero, if no other initialization is present.
				+ can't be defined inside the class, but can be outside the class.
			- Static member function:
				+ can be called using class name & scope operator (::)
				+ can only access static data members, other static member functions, & other functions from outside the class.
				+ don't have access to `this` pointer
				+ can be used whether object of this class has been created or not.


*/
#include <iostream>

using std::string;

class car
{

private:
	static string color;
	string brand = "";

public:
	// car();
	// car(string c, string b) : color(c), brand(b) {}			// FAIL, not allowed as a static data member can only be initialized at its definition
	void set_color(string c) {
		color = c;
	}

	void set_brand(string b) {
		brand = b;
	}

	static string get_color() {
		return color;
	}

	string get_brand() {
		return brand;
	}
	
};

string car::color = "white";	// OK, static member
// string car::brand = "";		// FAIL, not a static data member of ‘class car’


int main() {
	std::cout << car::get_color() << "\n";		// Ok, 'white',   static member. Called w/o any object of the class

	std::cout << "-------------------------" << "\n";
	car c1;
	c1.set_color("blue");
	c1.set_brand("BMW");

	std::cout << c1.get_color() << "\n";		// 'blue'
	std::cout << car::get_color() << "\n";		// Ok, 'blue'

	std::cout << "-------------------------" << "\n";
	car c2;
	c2.set_color("green");
	c2.set_brand("Audi");

	std::cout << c1.get_color() << "\n";		// 'green' => not giving 'blue', as the static member is updated & shared by the both objects c1, c2.
	std::cout << c2.get_color() << "\n";		// green
	std::cout << car::get_color() << "\n";		// Ok, green => updated 'blue' with 'green'


	return 0;
}


/*
CONSOLE Output:
$ sudo g++ -std=c++17 test.cpp && ./a.out
white
-------------------------
blue
blue
-------------------------
green
green
green


*/