/*
		Mathematical operation: (-b + sqrt(b^2 - 4*a*c))/2a = ((-b/a) + sqrt(b^2 - 4*a*c)/a)/2
*/

#include <iostream>
#include <result/include/result.hpp>
#include <cmath>

using std::string;
using result::Result;
using result::Ok;
using result::Err;


auto Div(double a, double b) -> Result<double, string>{
	if (b == 0)
		return Err(string{"denominator can't be zero"});
	else
		return Ok(a/b);
}


auto Sqrt(double a) -> Result<double, string> {
	if (a < 0)
		return Err(string{"sqrt of negative no is NOT possible."});
	else
		return Ok(sqrt(a));
}

auto Log(double a) -> Result<double, string> {
	if (a <= 0)
		return Err(string{"log of zero & negative no.s is NOT possible."});
	else
		return Ok(log(a));
}

auto Add(double a, double b) {
	return -a + b;
}

auto parse(double a) -> Result<double, string>{
	try {
		return Ok(a);
	}
	catch(const std::exception& e) {
		return Err(string(e.what()));
	}
}


Result<double, string>
operate (double a, double b, double c) {
	auto y = pow(b, 2) - 4*a*c;

	return parse(y).and_then([&] (auto _y){
		return parse(b).and_then([&] (auto _b) {
			return parse(a).map([&](auto _a) {
				return Div(_y, _a).unwrap();
			});
		});
	}); 
}




int main() {
	std::cout << operate(3, 4, 5) << "\n";

	return 0;
}