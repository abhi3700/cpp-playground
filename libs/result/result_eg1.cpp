/*
			Mathematics: Solve equation "ax^2 + bx + c"
				* x1 =  (-b + sqrt(b^2 - 4*a*c))/2a
				* x2 =  (-b - sqrt(b^2 - 4*a*c))/2a

*/

#include <iostream>
#include <result/include/result.hpp>
#include <cmath>
#include <utility>

using result::Result;
using result::Ok;
using result::Err;
using std::string;
using std::pair;
using std::make_pair;

auto Div(double a, double b) -> Result<double, string> {
	if(b == 0)
		return Err(string{"Division: Denominator should not be zero."});
	else
		return Ok(a/b);
}

auto Sqrt(double a) -> Result<double, string> {
	if(a < 0)
		return Err(string{"Sqrt: no. can't be negative."});
	else
		return Ok(sqrt(a));
}


auto parse(double a) -> Result<double, string> {
	try {
		return Ok(a);
	}
	catch(const std::exception& e) {
		return Err(string(e.what()));
	}
}


/*auto Oper(double a, double b, double c) -> Result<double, string> {
	auto y = pow(b, 2) - 4*a*c;
	if(y < 0)
		return Err(string{"Operation: (b^2 - 4ac) is negative."});
	else
		return parse(y).and_then([&] (auto _y) {
			return parse(b).and_then([&] (auto _b) {
				return parse(a).map([&] (auto _c) {
					return Div(-b, 2*a).unwrap() + Div(Sqrt(y).unwrap(), 2*a).unwrap();			// M-1
					// return Div(-b + Sqrt(y).unwrap(), 2*a).unwrap();							// M-2 [Recommended]

				});
			});
		});
}
*/

auto Oper(double a, double b, double c) -> Result<pair<double, double>, string> {
	double x1 = 0.0, x2 = 0.0;
	auto y = pow(b, 2) - 4*a*c;

	if(a == 0)
		return Err(string{"Operation error: a can't be zero."});
	else if(y < 0)
		return Err(string{"Operation error: Factor (b^2 - 4ac) can't be negative."});
	else
		x1 = parse(y).and_then([&] (auto _y) {
			return parse(b).and_then([&] (auto _b) {
				return parse(a).map([&] (auto _c) {
					return Div(-b, 2*a).unwrap() + Div(Sqrt(y).unwrap(), 2*a).unwrap();			// M-1
					// return Div(-b + Sqrt(y).unwrap(), 2*a).unwrap();							// M-2 [Recommended]

				});
			});
		}).unwrap();

		x2 = parse(y).and_then([&] (auto _y) {
			return parse(b).and_then([&] (auto _b) {
				return parse(a).map([&] (auto _c) {
					return Div(-b, 2*a).unwrap() - Div(Sqrt(y).unwrap(), 2*a).unwrap();			// M-1
					// return Div(-b - Sqrt(y).unwrap(), 2*a).unwrap();							// M-2 [Recommended]

				});
			});
		}).unwrap();

		return Ok(make_pair(x1, x2));
}


int main() {
	// auto res = Oper(0, 4, 5);		// prints error
	// auto res = Oper(3, 4, 5);		// prints error
	auto res = Oper(3, 10, 5);
	double x1 = 0.0, x2 = 0.0;

	if(res.is_ok()) {
		x1 = res.unwrap().first;
		x2 = res.unwrap().second;
		std::cout << "x1 = " << x1 << "\n";
		std::cout << "x2 = " << x2 << "\n";
	}
	else
		std::cout << res.unwrap_err() << "\n";



	return 0;
}

