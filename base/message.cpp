#include <iostream>
#include <string>

using std::string;

string user_message(int numtries) {
	int num = 5;
	/*static*/ string msg[num] = {
		"abhijit is a good boy",
		"scl is a bad place to work",
		"git is a distributed protocol",
		"bash is an awesome terminal",
		"fast typing is not necessary for a coder"
	}; 

	if(numtries < 0)
		numtries = 0;
	else if(numtries >= num)
		numtries = num-1;

	return msg[numtries];
}

int main() {
	std::cout << "Enter the number" << '\n';
	int num;
	std::cin >> num;
	std::cout << user_message(num) << '\n';
	

	return 0;
}