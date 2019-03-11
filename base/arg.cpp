#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "argc = " << argc << '\n';

	int sum = 0;

	std::cout << "\nThe commands are:" << '\n';

	if(argc > 1) {
		for(int i=0; i < argc; ++i) {
			printf("arg[%d] = %s\n", i, argv[i]);
			sum += atoi(argv[i]);
		}

		std::cout << "\nSum = " << sum << '\n';

	}
	return 0;
}