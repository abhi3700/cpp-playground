#include <iostream>
#include <utility>

using std::string;


enum car_type
{
	Hatchback = 1,
	Sedan = 2,
	SUV = 3
};

class uber
{
public:
	uber();
	// ~uber();

	float calc_epr(double start_loc, double finish_loc, string car_type) {
		float est_price = 0.00f;
		/*
			TODO: define the formula
		*/

		return est_price;
	}
	unsigned long calc_eta(double start_loc, double finish_loc) {
		unsigned long res;
		/*
			TODO: define the formula
		*/
		return res;

	}


	/*
	`double` has been chosen as it is more precise than float.
	`unsigned long` ranges from 0 to 4.2 billion integer no.
	@return: std::pair<float, unsigned long>
	*/
	std::pair<float, unsigned long> book_ride(double start_loc, double finish_loc, string car_type) {
		std::cout << "The ride is on the way!..." << std::endl;

		float a = calc_epr(start_loc, finish_loc, car_type);	// calculate Estimated price of ride
		unsigned long b = calc_eta(start_loc, finish_loc);				// calculate ETA of the ride

		return std::make_pair(a, b);
	}

	void cancel_ride(float ride_no) {
		
	}
	
};



class cabeos
{
public:
	cabeos();
	// ~cabeos();
	
};


int main() {




	return 0;
}