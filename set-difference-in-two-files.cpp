// This program reads integers from 2 files, creates an array of them and checks the set difference

#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	// Declare variables

	ifstream fileOne;
	ifstream fileTwo;
	int fileOneData;
	int fileTwoData;
	int fileOneCounter = 0;
	int fileTwoCounter = 0;
	int counter = 0;

	// Open the two files
	fileOne.open("file1.txt");
	fileTwo.open("file2.txt");

	// Check if file one opened successfully
	if (fileOne)
	{
		// Run a loop to get the number of integers in the first file which will be used to create the firstArray
		while (fileOne >> fileOneData) fileOneCounter++;

		// Clear the buffer and return fileOne loop to the first position so we can read the data from the beginning
		fileOne.clear();
		fileOne.seekg(0, ios::beg);

		// Create a new dynamic array for firstArray
		int* firstArray = new int[fileOneCounter];

		// Loop and get data from the file, then store in the newly created array
		while (fileOne >> fileOneData) {
			firstArray[counter] = fileOneData;
			counter++;
		}

		counter = 0; // Reset counter to zero after the process, so that file two can also use it

		// Check if file 2 opened successfully. Most of the comments in file one above applies here too
		if (fileTwo)
		{
			while (fileTwo >> fileTwoData) fileTwoCounter++;

			fileTwo.clear();
			fileTwo.seekg(0, ios::beg);

			int* secondArray = new int[fileTwoCounter];

			while (fileTwo >> fileTwoData) {
				secondArray[counter] = fileTwoData;
				counter++;
			}

			cout << "Set difference: ";

			// Loop through the first array.
			// On each iteration, also loop through the second array to see if element in the first array exist in the second array
			// If it exists, break out of the loop.
			// If not, when it gets to the end, of the second loop, then output the data in the first loop as not being found in second array
			// Then, we have the set difference
			for (int i = 0; i < fileOneCounter; ++i)
			{
				int j;
				for (j = 0; j < fileTwoCounter; ++j)
					if (firstArray[i] == secondArray[j]) {
						break;
					}
				if (j == fileTwoCounter) {
					cout << firstArray[i] << " ";
				}
			}

			cout << endl;

			// Delete the dynamically created arrays (to free the space) as we are now done with them
			delete[] firstArray;
			delete[] secondArray;

		}
		else {
			cout << "Could not open file 2";
		}

	}
	else {
		cout << "Could not open file 1";
	}

	// Close the two files that were opened
	fileOne.close();
	fileTwo.close();

	return 0;
}
