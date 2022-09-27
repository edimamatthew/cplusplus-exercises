#include <iostream>
using namespace std;


int main()
{
    int age = 112;
    int* ptr = &age;

    cout << "Variable by name: " << age << endl;
    cout << "Variable by pointer: " << *ptr << endl << endl;

    const int SIZE = 3;
    int ids[SIZE] = { 7,8,9 }, *valptr;
    valptr = ids;

    // Output array by name

    cout << "Array data by name: ";

    for (int i = 0; i < SIZE; i++)
    {
        cout << ids[i] << " ";
    }

    cout << "\n";

    // Output array by pointer

    cout << "Array data by pointer: ";

    for (int i = 0; i < SIZE; i++)
    {
        cout << valptr[i] << " ";
    }

    cout << "\n";

    return 0;
}
