// This program helps 2 brothers to roll a dice two times so as to determine who should do the chores
// The person with the highest sum of both dice becomes the unlucky one
// Then, the program simulates this 10,000 times to determine if it is fair or not


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// Initialize random number generator
	srand((unsigned int)time(NULL));

	const int DICE_MAX = 6;
	const int ARRAY_SIZE = 2;

	// Declare the results array to hold the data when rolled 10,000 times and initialie with zero (0)
	// The first element represents the first brother, while the second element represents the second brother
	int results[ARRAY_SIZE] = {0,0};

	for (int counter = 0; counter < 10000; counter++)
	{
		// Roll the dice two times for the first brother and save the sum of both results
		int brotherOneDiceOne = (rand() % DICE_MAX) + 1;
		int brotherOneDiceTwo = (rand() % DICE_MAX) + 1;
		int brotherOneDiceSum = brotherOneDiceOne + brotherOneDiceTwo;

		// Roll the dice two times for the second brother and save the sum of both results
		int brotherTwoDiceOne = (rand() % DICE_MAX) + 1;
		int brotherTwoDiceTwo = (rand() % DICE_MAX) + 1;
		int brotherTwoDiceSum = brotherTwoDiceOne + brotherTwoDiceTwo;

		// If the first brother got less sum when rolling both, then he wins and is the lucky one.
		// So add it to his data in the array
		if (brotherOneDiceSum < brotherTwoDiceSum)
		{
			results[0] = results[0]++;
		}
		else {
			// If the second brother is rather the one with less sum when rolling both, then he wins. Add to his data in the array
			results[1] = results[1]++;
		}
	}

	// Output the result and handle the tabular formatting

	cout << left << setw(20) << "Name" << setw(20) << "Wins" << setw(20) << "Loses" << endl;

	for (int x = 0; x < ARRAY_SIZE; x++)
	{
		int loss;
		string name = "Brother " + to_string(x + 1);

		if (x == 0)
			loss = results[x + 1];
		else
			loss = results[x - 1];

		cout << left << setw(20) << name << setw(20) << results[x] << setw(20) << loss << endl;
	}

	return 0;
}
