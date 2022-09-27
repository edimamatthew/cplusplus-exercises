// This program is a converter for 3 currencies

#include <iostream>
#include <iomanip>
using namespace std;

// create function prototypes
bool currencyConverter(int, double, double, double&, double&, double&);

int main()
{
	// Declare variables
	const int USD_TO_EUR = 1,
		EUR_TO_USD = 2,
		EUR_TO_UAH = 3,
		UAH_TO_EUR = 4,
		USD_TO_UAH = 5,
		UAH_TO_USD = 6,
		EXIT_CODE = 7;

	const double USD_TO_EUR_RATE = 0.92,
		EUR_TO_USD_RATE = 1.08,
		EUR_TO_UAH_RATE = 32.09,
		UAH_TO_EUR_RATE = 0.031,
		USD_TO_UAH_RATE = 29.66,
		UAH_TO_USD_RATE = 0.034;

	double usd_reserve = 5000,
		eur_reserve = 4000,
		uah_reserve = 10000;

	int operation_code;
	double amount_to_convert;
	bool result_check;
	string from_currency, to_currency;
	double result = 0;

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

		

		// Check if user entered wrong operation code or operation code that is not among the listed options
		do {
			cout << "Enter a code from the list above: ";
			cin >> operation_code;
			if (cin.fail() || (operation_code < USD_TO_EUR || operation_code > EXIT_CODE))
			{
				cin.clear(); cin.ignore();
				cout << "Operation code must be an integer between \"" << USD_TO_EUR << "\" and \"" << EXIT_CODE << "\"\n\n";
			}
			else break;
		} while (!cin.fail());

		// If the operation code is within the range of conversion codes, take amount input and validate it
		if (operation_code >= USD_TO_EUR && operation_code <= UAH_TO_USD) {
			do {
				cout << "\nEnter the amount to convert: ";
				cin >> amount_to_convert;
				if (cin.fail() || amount_to_convert < 1)
				{
					cin.clear(); cin.ignore();
					cout << "Kindly enter a valid amount.\n";
				}
				else break;
			} while (!cin.fail());

			// Convert input to a double since the function expects amount as double
			amount_to_convert = static_cast<double>(amount_to_convert);
			
			// Switch statement to check requested operation and perform conversion based on that
			switch (operation_code)
			{
			case USD_TO_EUR:
				result_check = currencyConverter(USD_TO_EUR, amount_to_convert, USD_TO_EUR_RATE, usd_reserve, eur_reserve, result);
				from_currency = "USD";
				to_currency = "EUR";
				break;

			case EUR_TO_USD:
				result_check = currencyConverter(EUR_TO_USD, amount_to_convert, EUR_TO_USD_RATE, eur_reserve, usd_reserve, result);
				from_currency = "EUR";
				to_currency = "USD";
				break;

			case EUR_TO_UAH:
				result_check = currencyConverter(EUR_TO_UAH, amount_to_convert, EUR_TO_UAH_RATE, eur_reserve, uah_reserve, result);
				from_currency = "EUR";
				to_currency = "UAH";
				break;

			case UAH_TO_EUR:
				result_check = currencyConverter(UAH_TO_EUR, amount_to_convert, UAH_TO_EUR_RATE, uah_reserve, eur_reserve, result);
				from_currency = "UAH";
				to_currency = "EUR";
				break;

			case USD_TO_UAH:
				result_check = currencyConverter(USD_TO_UAH, amount_to_convert, USD_TO_UAH_RATE, usd_reserve, uah_reserve, result);
				from_currency = "USD";
				to_currency = "UAH";
				break;

			case UAH_TO_USD:
				result_check = currencyConverter(UAH_TO_USD, amount_to_convert, UAH_TO_USD_RATE, uah_reserve, usd_reserve, result);
				from_currency = "UAH";
				to_currency = "USD";
				break;

			default:
				break;
			}

			// Check if conversion was successfully processed or not
			if (result_check)
			{
				// Set outputs to have 2 decimal points as money's normal format
				cout << fixed << setprecision(2);

				// Show final output, specifiying the currency converted from, and the currency converted to
				cout << "\n" << amount_to_convert << " " << from_currency << " is " << result << " " << to_currency << "\n\n=============\n\n";
			}
			else {
				cout << "\nThe amount provided is greater than our reserve and cannot be converted.\n\n=============\n\n";
			}

		}
		else {
			cout << "Thank you for using our program. See you next time.\n";
			break;
		}
		
	} while (operation_code != EXIT_CODE);

	return 0;
}

bool currencyConverter(int operation_code, double amount, double conversion_rate, double& first_currency_reserve, double& second_currency_reserve, double& result)
{
	double converted_amount = 0;
	converted_amount = amount * conversion_rate; // Process the conversion

	// Check if the money in the reserve is sufficient to process the conversion

	if (converted_amount > second_currency_reserve)
	{
		return false;
	}

	result = converted_amount;
	first_currency_reserve -= amount; // Subtract the amount from the currency reserve
	second_currency_reserve += result; // Add the converted amount to the converted reserve

	return true;
}
