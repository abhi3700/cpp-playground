#include <iostream>
#include <string>
#include "car.hpp"

using std::string;

// class car {
// private:
// 	/*	
// 		M-1: define attributes as private & then define `set()` methods for assigning values separately
// 		Pros: provide "data hiding" is to keep internal data hidden from other classes which use the class.
// 		private vars not accessed using `car.model_name`
// 	*/
// 	string model_name;
// 	string make_year;
// 	bool brake_status;
// 	bool door_status;

// public:
// 	/*	
// 		M-2: define attributes as public & then no need to define `set()` methods for assigning values separately
// 		Cons: compromise "data hiding"
// 		public vars accessed using `car.model_name`
// 	*/	
// /*	string model_name;
// 	string make_year;
// 	bool brake_status;
// 	bool door_status;
// */

// 	// Constructor
// 	car(string _model_name, string _make_year, bool _brake_status, bool _door_status) {
// 		model_name = _model_name;
// 		make_year = _make_year;
// 		brake_status = _brake_status;
// 		door_status = _door_status;
// 	}

// 	void set_model_name(string _model_name) {
// 		this->model_name = _model_name;
// 	}

// 	void set_make_year(string _make_year) { 
// 		this->make_year= _make_year;
// 	}

// 	void set_brake_status(bool _brake_status) {
// 		this->brake_status =  _brake_status;
// 	}

// 	void set_door_status(bool _door_status) {
// 		this->door_status = _door_status;
// 	}


// 	string get_model_name() const {
// 		return model_name;
// 	}

// 	string get_make_year() const { 
// 		return make_year;
// 	}

// 	bool get_brake_status() {
// 		return brake_status;
// 	}

// 	bool get_door_status() {
// 		return door_status;
// 	}
// };

int main() {
	// initialization
	car c1 = car("BMW 320d", "2017", false, false);
	
	// apply brake
	// v1.brake_status = true;			// when var is public
	c1.set_brake_status(true);		// when var is private

	// close door
	// v1.door_status = true;			// when var is public
	c1.set_door_status(true);		// when var is private

	std::cout << v1.get_model_name() << "\n";
	std::cout << v1.get_make_year() << "\n";
	std::cout << v1.get_brake_status() << "\n";
	std::cout << v1.get_door_status() << "\n";


	return 0;
}