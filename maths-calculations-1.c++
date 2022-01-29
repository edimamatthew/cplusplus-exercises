/*
	Mathematics calculations
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Declare variables
	double x, y, xmin, xmax, dx;

	// Take inputs
	cout << "Input xmin, xmax, dx\n";
	cin >> xmin >> xmax >> dx;
	cout << "  while loop  \n";

	// Set x to minimum
	x = xmin;

	// Start while loop
	while (x <= xmax)
	{
		// Check for positive numbers
		if (x > 0) {
			// Calculate
			y = pow(log(x), 3);
			// Output data
			cout << "At x= " << x << " \t y= " << y << endl;
		}
		else
			// Show error if x is negative
			cout << "At x= " << x << " \t y = error\n";
		x += dx; // increment x by delta x
	}

	// Start do while loop
	cout << " \n do...  while loop  \n";
	x = xmin;

	do {
		if (x > 0)
		{
			// Calculate
			y = pow(log(x), 3);
			cout << "At x= " << x << " \t y= " << y << endl;
		}
		else
			// Show error if x is negative
			cout << "At x= " << x << " \t y = error\n";
		x += dx; // Increment x by delta x
	} while (x <= xmax);

	puts("OK!");

	return 0;
}