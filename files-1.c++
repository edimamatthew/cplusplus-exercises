/* 
* This program reads data from one file into another file
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream ages("ages.txt", ios::in);
	fstream newAges("newAges.txt", ios::out);
	int age;

	if (ages)
	{
		for (int x = 1; x <= 2; x++)
		{
			ages >> age;
			newAges << age << endl;
		}
		cout << "The operation has been successfully processed." << endl;
	}
	else
		cout << "The file is not available." << endl;

	ages.close();
	newAges.close();

	return 0;
}
