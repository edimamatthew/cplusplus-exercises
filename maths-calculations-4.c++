/*
* Mathematics calculations
*/

#include <cmath>
#include <iostream>

using namespace std;

int main()

{
    //Declare variables
    double x, z;
    char variant;

    //Get the variant
    cout << "Enter a variant (options: a, b or c): ";
    cin >> variant;

    //Get the value of x from the user 
    cout << "Enter value of x: ";
    cin >> x;

    switch (variant)
    {
        //Actions of case a
        case 'a':
            z = sin(pow(x, 5));
            cout << "Variant = " << variant << "; X = " << x << "; Z = " << z << endl;
        break;

        //Action of case b
        case 'b':
            if (x > 0) // must be greater than 0 to proceed 
            {
                z = log(x);
                cout << "Variant = " << variant << "; X = " << x << "; Z = " << z << endl;
            }
            else
                cout << "Variant = " << variant << "; X = " << x << " cannot be calculated" << endl;
        break;

        //Action of case c
        case 'c':
            z = pow(x, 3);
            cout << "Variant = " << variant << "; X = " << x << "; Z = " << z << endl;
        break;

        //Case if variant is not described above
        default:
            cout << "Invalid variant: " << variant << endl;
        break;
    }

    return 0;
}