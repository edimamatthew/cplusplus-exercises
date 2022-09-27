/*
* Mathematics calculations
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Declare variables
	double x, a, b;

	// Take inputs
	cout << "Enter the value of a: "; cin >> a;

	cout << "Enter the value of b: "; cin >> b;

	// Calculate
	x = (a < b) ? pow(fabs(a), 1. / 4.) : (a * pow(b, 2) - 1);
	// Show result
	cout << "At a= " << a << ", b= " << b << ", x= " << x << endl;

	return 0;

}
