// This program is a converter for 3 currencies

#include <iostream>
#include <iomanip>
using namespace std;

// Declare constant variables
const int USD_TO_EUR = 1;
const int EUR_TO_USD = 2;
const int EUR_TO_UAH = 3;
const int UAH_TO_EUR = 4;
const int USD_TO_UAH = 5;
const int UAH_TO_USD = 6;
const int EXIT_CODE = 7;

string from_currency, to_currency;

// create function prototypes
double currencyConverter(int, double);
void initializeConverter();

int main()
{
	initializeConverter(); // Call the function to initialize the conversion

	return 0;
}

void initializeConverter()
{
	// Declare local variables
	int operation_code;
	double amount_to_convert;
	double converted_amount;

	cout << "This program is a converter for 3 currencies. See available operations below;\n\n";

	// Start a do ... while loop so the program keeps looping till the user exits
	do {
		// show available operation options and take input
		cout << "List of available operations\n------------\n"
			<< USD_TO_EUR << ": USD to EUR\n"
			<< EUR_TO_USD << ": EUR to USD\n"
			<< EUR_TO_UAH << ": EUR to UAH\n"
			<< UAH_TO_EUR << ": UAH to EUR\n"
			<< USD_TO_UAH << ": USD to UAH\n"
			<< UAH_TO_USD << ": UAH to USD\n"
			<< EXIT_CODE << ": End the program\n\n";

		cout << "Enter a code from the list above: ";
		cin >> operation_code;

		// Check if user entered wrong operation code (maybe a string) and exit if so
		if (cin.fail()) {
			break;
		}
		
		// Check if the input is within the range of allowed operations and take amount input
		if (operation_code >= USD_TO_EUR && operation_code <= UAH_TO_USD) {
			cout << "\nEnter the amount to convert: ";
			cin >> amount_to_convert;

			// Check if user entered wrong amount (maybe a string) and exit if so
			if (cin.fail()) {
				break;
			}

			// Convert input to a double since the function expects amount as double
			amount_to_convert = static_cast<double>(amount_to_convert);

			// Call the converter function and save the result in a variable
			converted_amount = currencyConverter(operation_code, amount_to_convert);

			// Set outputs to have 2 decimal points as money's normal format
			cout << fixed << setprecision(2);

			// Show final output, specifiying the currency converted from, and the currency converted to
			cout << "\n" << amount_to_convert << " " << from_currency << " is " << converted_amount << " " << to_currency << "\n\n=============\n\n";

		}
		else if (operation_code == EXIT_CODE)
		{
			// End the program if the user inputted the code to end program 
			break;
		}
		else {
			// Show a message if the user inputted an operation code that is not within the range of available operations
			cout << "\nSorry, the requested operation is not yet available. You can request for it by sending an email to us\n\n";
		}
	} while (operation_code != EXIT_CODE);
}

double currencyConverter(int operation_code, double amount_to_convert)
{
	// Define exchange rates for the 3 currencies
	double usd_to_eur_rate = 0.88;
	double eur_to_uah_rate = 31.93;
	double usd_to_uah_rate = 28.13;

	// Declare variable to store the converted amount
	double converted_amount = 0;

	// Switch statement to check requested operation and performs conversion based on that
	switch (operation_code)
	{
	case USD_TO_EUR:
		converted_amount = amount_to_convert * usd_to_eur_rate;
		from_currency = "USD";
		to_currency = "EUR";
		break;

	case EUR_TO_USD:
		converted_amount = amount_to_convert / usd_to_eur_rate;
		from_currency = "EUR";
		to_currency = "USD";
		break;

	case EUR_TO_UAH:
		converted_amount = amount_to_convert * eur_to_uah_rate;
		from_currency = "EUR";
		to_currency = "UAH";
		break;

	case UAH_TO_EUR:
		converted_amount = amount_to_convert / eur_to_uah_rate;
		from_currency = "UAH";
		to_currency = "EUR";
		break;

	case USD_TO_UAH:
		converted_amount = amount_to_convert * usd_to_uah_rate;
		from_currency = "USD";
		to_currency = "UAH";
		break;

	case UAH_TO_USD:
		converted_amount = amount_to_convert / usd_to_uah_rate;
		from_currency = "UAH";
		to_currency = "USD";
		break;

	default:
		break;
	}

	// Return converted amount and exit the function
	return converted_amount;
}
