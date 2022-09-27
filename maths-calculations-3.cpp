/*
* Mathematics calculations
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Declare variable and take input

	float f, a, x, c;
	cout << "Enter the value of a: ";
	cin >> a;

	cout << "Enter the value of x: ";
	cin >> x;

	cout << "Enter the value of c: ";
	cin >> c;

	// Calculate numerator and denominator

	float numerator = pow(a, 3) - x;
	float denominator = pow(x, 2) - c;

	// Correct test input: a: 6, x: 3, c: 4
	// Error test input: a: 3, x: 0, c: 4

	// Check if conditions are true for the function to run
	if ((denominator != 0) && (2 * x > 0)) {

		// Calculate value of f
		f = (numerator / denominator) + log(2 * x);

		// Output the value of the calculation
		cout << "At point a = " << a << ", x = " << x << ", c = " << c << ", f = " << f << endl;
	}
	else {
		// Let the user know the program function cannot run
		cout << "At point f ERROR!!!!" << endl;
	}
}