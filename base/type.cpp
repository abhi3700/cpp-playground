#include <iostream>
#include <typeinfo>

int main() {
	int a;
	int b;
	const char* str;
	std::cout << "name: " << typeid(a).name() << "\n";
	std::cout << "name: " << typeid(b).name() << "\n";
	std::cout << "name: " << typeid(str).name() << "\n";
	std::cout << "hashcode of" << a << ": " << typeid(a).hash_code() << "\n";
	std::cout << "hashcode of" << b << ": " << typeid(b).hash_code() << "\n";

	return 0;
}