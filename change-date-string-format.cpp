// This program takes date input as string in format 07/21/2003, then formats and outputs it as July 21, 2003

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function prototypes
vector<string> splitDate(string, char);
string monthNumberToName(int month);
string formatDate(int, int, int);

int main()
{
	// Declare variables
	string date;
	vector<string> dateComponents;
	int dayNum, monthNum, yearNum;

	// Run an infinite loop to validate user's input
	while (true)
	{
		cout << "Enter a date (format - 07/21/2003): ";
		cin >> date;

		// Call the splitDate function to get an array component of the dates so we can easily work with the day, month and year
		dateComponents = splitDate(date, '/');

		// Since the input came as strings, we convert it to integers so we can use in the app
		monthNum = stoi(dateComponents[0]);
		dayNum = stoi(dateComponents[1]);
		yearNum = stoi(dateComponents[2]);

		// Run series of validations
		if (dateComponents.size() == 3 && // array component must be 3, representing day, month and year
			dateComponents[0].length() == 2 && // The month must contain 2 characters (like 07)
			dateComponents[1].length() == 2 && // The day must contain 2 characters (like, 21)
			dateComponents[2].length() == 4 && // The year must contain 4 character (like, 2003)
			(monthNum >= 1 && monthNum <= 12) && // Check that the month is between 1 and 12, because there's no month as 13 or 0, etc.
			(dayNum >= 1 && dayNum <= 31)) // Check that date is between 1 and 31
		{
			break; // If all checks are passed, then get out of the loop
		}
		else {
			cout << "Invalid date format.\n\n"; // If checks failed, we continue the loop until it passes
		}
	}

	cout << "\n================================================" << endl;

	// Call the function that formats the date and output it
	cout << date << " is formatted into " << formatDate(dayNum, monthNum, yearNum) << endl;

	cout << "================================================" << endl;

	return 0;
}

vector<string> splitDate(string date, char delimiter) {
	vector<string> data; // Vector variable
	stringstream ssDate(date); // convert the date to a stream so we can perform extraction operations on it
	string dateString;

	// In the while loop below, additional data (delimiter) is passed to the getline function
	// This reads the date stream up to the delimiter, stores it in the dateString function and adds to the vector, then continue reading
	while (getline(ssDate, dateString, delimiter)) {
		data.push_back(dateString); // Add new element to the data vector
	}

	return data;
}

string monthNumberToName(int month)
{
	// Create a string vector containing all the months
	vector<string> months = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	return months[month - 1];
}

string formatDate(int day, int month, int year)
{
	// Get the month name
	string monthName = monthNumberToName(month);

	// Return the newly formatted date
	return monthName + " " + to_string(day) + ", " + to_string(year);
}
