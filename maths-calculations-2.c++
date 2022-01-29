/*
	Mathematics calculations
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// Declare variables
	float x, z, xmin, xmax, dx, x_m, z_m;

	// Take inputs
	puts("Input xmin, xmax dx");
	cin >> xmin >> xmax >> dx;

	// Initialize z_m with zero
	z_m = 0;

	// start for loop
	for (x = xmin; x <= xmax; x+=dx) {
		// check if value is positive before calculating
		if (x + 1 > 0) {
			z = log(x + 1); // calculate log
			// output the result
			cout << "At x=" << setw(6) << x << " z= " << z << endl;
			// check for highest value and add it to the variable
			if (z > z_m) {
				x_m = x;
				z_m = z;
			}
		}
		else
			// show error if program cannot be calculated
			cout << "At x=" << setw(6) << x << " error\n";
	}
	// output the maximum
	cout << "At x=" << setw(6) << x_m << " max z=" << z_m << endl;

	return 0;
}
