/* 
* This program has an account balance, then the user pays school fees using half the amount, and returns the balance
*/

#include <iostream>

using namespace std;

int main()
{
	double account_balance = 3000.00;

	cout << "Hello, your bank account balance is $" << account_balance << "\n\n";

	//use half of the money to pay tuition at Sumy State University

	account_balance /= 2;

	cout << "You have successfully paid your tuition. Your balance is $" << account_balance << endl;

	return 0;
}