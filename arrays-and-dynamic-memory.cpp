// This program passes an array to a function to manipulate, create a new array and return the pointer to the new array

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int* arrayManip(int[], const int);

int main()
{
	const int SIZE = 5;
	int data[SIZE] = { 0,1,0,1,0 };

	cout << "Old data: ";

	for (int count = 0; count < SIZE; count++)
	{
		cout << data[count];

		if (count != SIZE - 1)
		{
			cout << " - ";
		}
	}

	cout << endl;
	cout << "New data: ";

	// Retrieve the newly created array from the pointer and use it
	int* array = arrayManip(data, SIZE);

	for (int count = 0; count < SIZE + 1; count++)
	{
		cout << array[count];

		if (count != SIZE)
		{
			cout << " - ";
		}
	}

	cout << endl;

	delete[] array;

	return 0;
}

int* arrayManip(int data[], const int SIZE)
{
	const int NEW_SIZE = SIZE + 1;

	// Create a new array and store in the pointer
	int* array = new int[NEW_SIZE];

	array[0] = 0;

	for (int count = 0; count < SIZE; count++)
	{
		array[count + 1] = data[count];
	}

	return array;
}
