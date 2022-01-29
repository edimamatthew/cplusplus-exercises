/*
* This program takes a number and checks if it is positive or negative
*/

#include <iostream>

using namespace std;

int main()
{
	int number;

	cout << "Please enter a number: ";
	cin >> number;

	if (number > 0)
		cout << "The number " << number << " is a positive number.";
	else
		cout << "The number " << number << " is a negative number.";

	return 0;
}