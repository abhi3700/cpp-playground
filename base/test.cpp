#include <iostream>		// std::cout
#include <string>		// std::string, std::stoi

int main() {
	std::string my_str_var = "23,56,455";
	int my_int_var_c, my_int_var_cpp;

	// C++
	// my_int_var_cpp = std::stoi(my_str_var);
	// std::cout << my_int_var_cpp + 5 << '\n';

	// C
	const char* my_char_var = my_str_var.c_str();
	my_int_var_c = atoi(my_char_var);
	std::cout << my_int_var_c << '\n';
	std::cout << my_int_var_c + 00005 << '\n';
	
	return 0;
}