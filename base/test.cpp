#include <iostream>
#include <stdio.h>

#define PI 3.1416f

struct person
{
	int age;
	std::string name;
};

int main() {
	const char* str = "C";
	std::string strcpp = "C++";
	// scanf("Enter the string, %s", str);
	printf("print the string, %s\n", str);
	std::cout << strcpp <<std::endl;
	std::cout << "Hello world" <<std::endl;
    printf("Hello world\n");

    person p;
    p.age = 19;
    p.name = "abhfjbd";

    std::cout << p.name << std::endl;

    return 0;
}


