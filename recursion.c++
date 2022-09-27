// This program uses recursion to check if an item is in an array

#include <iostream>
#include <iomanip>
using namespace std;

bool isMember(int [], int, int);

int main()
{
    const int SIZE = 6;
    int arr[SIZE] = { 10,20,30,40,50,60 };

    if (isMember(arr, SIZE, 10))
    {
        cout << "The item is a member of the function" << endl;
    }
    else {
        cout << "The item is NOT a member of the function" << endl;
    }

	return 0;
}

bool isMember(int arr[], int size, int item)
{
    size--;
    
    if (size >= 0)
    {
        if (arr[size] == item)
        {
            return true;
        }
        else {
            isMember(arr, size, item);
        }
    }
    else {
        return false;
    }
}
