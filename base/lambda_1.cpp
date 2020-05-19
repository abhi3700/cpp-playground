/**
			Lambda function in C++
			- ambiguous 
			- define function inside another function
			- [capture] (argument) -> <return-type> {body} (to call)
			- lambda types:
			[=] — pass all variables in closure by value;
			[&] — pass all variables in closure by reference;
			[singleVar] — pass only this variable in closure to lambda by value;
			[&singleVar] — pass only this variable in closure to lambda by reference;
			[=, &singleVar] — pass all variables in closure to lambda by value, but singleVar by reference;
			[&, singleVar] — pass all variables in closure to lambda by reference, but singleVar by value;
 */

#include <iostream>
#include <functional>
#include <vector>

/*
Implement this using lambda:
f(x,y) = x^2 + 2xy + y^2;
*/
// int func_xy(int x , int y) {
// 	auto x_sq = [](int x) -> int {
// 		return x*x;
// 	}(x);
// 	auto y_sq = [](int y) -> int {
// 		return y*y;
// 	}(y);

// 	auto twoxy = [](int x, int y) -> int {
// 		return 2*x*y;
// 	}(x, y);

// 	return x_sq + y_sq + twoxy;
// }

int func_xy(int x , int y) {

	// auto fxy = [x, y] (int x, int y) -> int {
	// 	auto x_sq = [](int x) -> int {return x*x;}(x);
	// 	auto y_sq = [](int y) -> int {return y*y;}(y);
	// 	auto twoxy = [](int x, int y) -> int {return 2*x*y;}(x, y);
	// 	return x_sq + y_sq + twoxy;
	// };
	auto x_sq = [](int x) -> int {return x*x;}(x);
	auto y_sq = [](int y) -> int {return y*y;}(y);
	auto twoxy = [](int x, int y) -> int {return 2*x*y;}(x, y);
	return x_sq + y_sq + twoxy;

	// return fxy(x, y);

}

using std::string;

int main() {
	// ==============================================================
	/* Eg 1 - prints "Hello world" */
	// []() {
	// 	std::cout << "Hello world" << std::endl;
	// }();


	// ==============================================================
	/* Eg 2 */
	int ret_val = [] (int base_value) -> int {
		return base_value + 100;
	}(100);
	std::cout << ret_val << std::endl;			// 200

	// OR
	/* Eg 2 using capture */
	int base_value = 100;
	std::cout << [&]() {return base_value + 100;}() << std::endl;


	// ==============================================================
	/* Eg 2 using function pointer */
	// std::function<int(int)> fp = [] (int base_value) -> int {
	// 	return base_value + 100;
	// };					// also can be used 'auto'

	// int ret_val = fp(150);
	// std::cout << ret_val << std::endl;			// 250

	// ==============================================================
	/* Eg 4: Capture values from outside lambda function */
	string a = "100", b = "150";
	[=]() mutable {
		std::cout << "a = " << stoi(a) + 30 << std::endl;
		std::cout << "b = " << stoi(b) + 50 << std::endl;
	}();
	[&]() mutable {
		std::cout << "a = " << stoi(a) + 30 << std::endl;
		std::cout << "b = " << stoi(b) + 50 << std::endl;
	}();

	// ==============================================================
	/* Eg 5: '=' va '&' capture values */
	std::vector<int> v1 = {10, 20, 30, 40};

	// pass by value
	[=]() mutable {
		std::cout << "Pass by value" << std::endl;
		v1.emplace_back(1000);
	}();

	for_each(v1.begin(), v1.end(), [](int a){std::cout << a << std::endl;});

	// pass by reference
	[&]() mutable {
		std::cout << "Pass by reference" << std::endl;
		v1.emplace_back(1000);
	}();

	for_each(v1.begin(), v1.end(), [](int a){std::cout << a << std::endl;});

	return 0;
}