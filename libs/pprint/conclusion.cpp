/*
		Conclusion
		- Pros: Many, as we have seen in this chapter
		- Cons:
			+ just create a "Hello world" & then, `cout` --> 9 KB is the file size of `a.out` file, when compared to do the same with `pprint` --> 27 KB. So, 3 times.
*/

// #include <iostream>

// int main() {
// 	std::cout << "Hello world!" << std::endl;

// 	return 0;
// }


#include <pprint/include/pprint.hpp>

int main() {
	pprint::PrettyPrinter p;
	p.print("Hello world!");

	return 0;
}