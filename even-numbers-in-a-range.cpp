// This program returns all the even numbers within a range

#include <iostream>
using namespace std;

int main()
{
	// Declare variables
	int least_number;
	int highest_number;

	// Take inputs to determine the range
	cout << "Enter the least number: ";
	cin >> least_number;

	cout << "Enter the highest number: ";
	cin >> highest_number;

	// Loop through the provided range and check if each number is even
	for (int x = least_number; x <= highest_number; x++) {
		if (x % 2 == 0 && x != 0) {
			cout << x << endl;
		}
	}

	return 0;
}