#include <iostream>
#include <typeinfo>

#define FALSE 0;
#define TRUE 1;

int main() {
	char ch_arr[] = {
		'a', 'b','c', 'd', 'e'
	};		// std. definition of array

	char* dup_arr;		// pointer way of defining array
	bool val = FALSE;
	dup_arr = ch_arr;	// assign ch_arr (defined in another way) to dup_arr

	std::cout << typeid(ch_arr).name() << '\n';
	std::cout << typeid(dup_arr).name() << '\n';
	if( typeid(dup_arr).name() == typeid(ch_arr).name() ) {		// check if both are equal
		std::cout << "TRUE" << '\n';
	}





	return 0;
}