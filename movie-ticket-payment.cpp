/*
* This program takes details of sold movie tickets, then calculates the profit and amount to be paid to the distributor
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// Declare variables

	string name_of_movie;
	int adult_tickets_sold, child_tickets_sold;
	double gross_box_profit, net_box_profit, amount_paid;
	double adult_tickets_amount, child_ticket_amount;

	// Initialize variables with data provided in the question

	const double adult_ticket_price = 6.00;
	const double child_ticket_price = 3.00;
	const int gross_box_profit_percent = 20;

	// Allow user to provide name of movie and the number of tickets sold

	cout << "Enter the name of the movie: ";

	// getline() is used here to be able to accept name of movie string with spaces
	getline(cin, name_of_movie);

	cout << "Enter the number of adult tickets sold: ";
	cin >> adult_tickets_sold;

	cout << "Enter the number of child tickets sold: ";
	cin >> child_tickets_sold;

	// Calculate the amount of adult and child tickets sold

	adult_tickets_amount = adult_tickets_sold * adult_ticket_price;

	child_ticket_amount = child_tickets_sold * child_ticket_price;

	// Calculate the total amount of tickets altogether sold

	gross_box_profit = adult_tickets_amount + child_ticket_amount;

	// Calculate percentage profit

	net_box_profit = (gross_box_profit * gross_box_profit_percent) / 100;

	// Calculate total amount paid to distributor

	amount_paid = gross_box_profit - net_box_profit;

	// Format the movie name to have quotes around it

	string formatted_movie_name = "\"" + name_of_movie + "\"";

	// Ensure that double figures show 2 decimal values

	cout << fixed;
	cout << setprecision(2);

	cout << "\n";

	// Display formatted information

	cout << setw(40) << left << "Movie Name: " << formatted_movie_name << endl;
	cout << setw(40) << "Adult Tickets Sold: " << adult_tickets_sold << endl;
	cout << setw(40) << "Child Tickets Sold: " << child_tickets_sold << endl;
	cout << setw(40) << "Gross Box Office Profit: " << "$ " << gross_box_profit << endl;
	cout << setw(40) << "Net Box Office Profit: " << "$ " << net_box_profit << endl;
	cout << setw(40) << "Amount Paid to Distributor: " << "$ " << amount_paid << endl;

	return 0;
}