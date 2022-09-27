// This program stores the grades of students in a 3 dimensional array
// Then loops through it to get individual average, lowest average and highest average

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const int STUDENTS = 3;
	const int COURSES = 3;
	const int GRADES = 3;
	double average = 0;
	int total = 0;
	double lowestAverage = 0;
	double highestAverage = 0;
	string name;

	// The 3 dimensional array
	int grades[STUDENTS][COURSES][GRADES] = {
		{ {70, 80, 90}, {80, 70, 60}, {90, 87, 99} },
		{ {50, 60, 70}, {76, 86, 96}, {80, 99, 60} },
		{ {87, 89, 87}, {90, 79, 69}, {79, 60, 40} },
	};
	
	cout << left << setw(15) << "Name" << setw(10) << "Course 1" << setw(10) << "Course 2" << setw(10) << "Course 3" << endl;

	cout << fixed << setprecision(2);

	for (int i = 0; i < STUDENTS; i++)
	{
		average = 0;
		total = 0;
		name = "Student " + to_string(i + 1);
		cout << left << setw(15) << name << setw(10);
		for (int j = 0; j < COURSES; j++)
		{
			for (int k = 0; k < GRADES; k++)
			{
				// Add up the total grades for each student
				total += grades[i][j][k];
			}
			// Get the average
			average = static_cast<double>(total) / COURSES;

			if (average > highestAverage)
			{
				highestAverage = average;
			}

			// On first loop, store the average in the lowest average variable.
			// On subsequent loops, check if the average is less and update if true
			if (lowestAverage == 0 || average < lowestAverage)
				lowestAverage = average;

			cout << setw(10) << average;
			total = 0;
		}
		cout << endl;
	}

	cout << endl;
	cout << "Highest Average: " << highestAverage << endl;
	cout << "Lowest Average: " << lowestAverage << endl;


	return 0;
}
