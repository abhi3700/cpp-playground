#include <iostream>


using std::cin;
using std::string;


class chef
{
public:
	void make_chicken() {
		std::cout << "The chef makes yummy chicken" << std::endl;
	}

	void make_salad() {
		std::cout << "The chef makes salad" << std::endl;
	}

	void make_specialdish() {
		std::cout << "The chef makes bbg ribs" << std::endl;
	}
};


class italian_chef : public chef
{
public:
	// italian_chef();
	// ~italian_chef();

	void make_specialdish() {
		std::cout << "The chef makes chicken parm" << std::endl;
	}

	void make_pasta() {
		std::cout << "The chef makes pasta" << std::endl;
	}
	 
};


int main() {
	chef c;
	c.make_chicken();
	c.make_specialdish();

	italian_chef ic;
	ic.make_pasta();
	ic.make_specialdish();



	return 0;
}

