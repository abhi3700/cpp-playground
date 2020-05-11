#include <iostream>

template <typename T>
int find(T* array, T value, int size) {
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}

char char_arr[] = {1, 3, 5, 9, 11, 13};		// the char Array
char ch = 5;	// value to find
int int_arr[] = {1, 3, 5, 9, 11, 13};
int in = 6;
long lon_arr[] = {1L, 3L, 5L, 9L, 11L, 13L};
long lo = 11L;
double dub_arr[] = {1.0, 3.0, 5.0, 9.0, 11.0, 13.0};
double db = 4.0;

int main() {
	std::cout << "5 in char Array: index = " << find(char_arr, ch, 6) << '\n';
	std::cout << "6 in int Array: index = " << find(int_arr, in, 6) << '\n';
	std::cout << "11L in long Array: index = " << find(lon_arr, lo, 6) << '\n';
	std::cout << "4.0 in double Array: index = " << find(dub_arr, db, 6) << '\n';

	return 0;
}