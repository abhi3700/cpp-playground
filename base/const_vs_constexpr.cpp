#include <iostream>

// const function
const int square1(int var) {
	return var ^ 2;
} 

// constexpr function
constexpr int square2(int var) {
	return var ^ 2;
} 

// non-const/constexpr function
int square3(int var) {
	return var ^ 2;
} 


int main() {
	// define variables
	const int var1 = 34;
	constexpr int var2 = 23424;
	int var3 = 4234;						// warning: g++: warning note - 'int var3' is not const

	// Case 1: assigning `const func` to `const variable`
	const int var4 = square1(var1);			// OK
	const int var5 = square1(var2);			// OK
	const int var6 = square1(var3);			// OK, may be evaluated at run time (as the var is non-const)

	// Case 2: assigning `const` func to `constexpr variable`
	constexpr int var7 = square1(var1);		// Error, g++: error - call to non-'constexpr' function 'const int square1(int)'
	constexpr int var8 = square1(var2);		// Error, g++: error - call to non-'constexpr' function 'const int square1(int)'
	constexpr int var9 = square1(var3);		// Error, g++: error - call to non-'constexpr' function 'const int square1(int)' 

	// Case 3: assigning `constexpr func` to `const variable`
	const int var10 = square2(var1);		// OK 
	const int var11 = square2(var2);		// OK
	const int var12 = square2(var3);		// OK, may be evaluated at run time (as the var is non-const)

	// Case 4: assigning `constexpr func` to `constexpr variable`
	constexpr int var13 = square2(var1);	// OK
	constexpr int var14 = square2(var2);	// OK,
	constexpr int var15 = square2(var3);	// Error, g++: error - the value of 'var3' is not usable in a constant expression 

	// Case 5: assigning `func` to `const variable`
	const int var16 = square3(var1);		// OK, evaluated in run-time (as the func is non-const)
	const int var17 = square3(var2);		// OK, evaluated in run-time (as the func is non-const)
	const int var18 = square3(var3);		// OK, evaluated in run-time (as the func is non-const)

	// Case 6: assigning `func` to `constexpr variable`
	constexpr int var19 = square3(var1);	// Error, g++: error - call to non-'constexpr' function 'int square3(int)' 
	constexpr int var20 = square3(var2);	// Error, g++: error - call to non-'constexpr' function 'int square3(int)'
	constexpr int var21 = square3(var3);	// Error, g++: error - call to non-'constexpr' function 'int square3(int)'

	return 0;
}