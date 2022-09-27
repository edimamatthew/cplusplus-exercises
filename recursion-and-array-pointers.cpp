/ This program uses recursion to check if an item is in an array, using the array pointer

#include <iostream>
#include <iomanip>
using namespace std;

bool isMember(int*, int, int);

int main()
{
    const int SIZE = 6;
    int arr[SIZE] = { 10,20,30,40,50,60 };
    int itemToCheck = 10;
    int *ptr = &arr[0];

    if (isMember(ptr, SIZE, itemToCheck))
    {
        cout << "The item is a member of the function" << endl;
    }
    else {
        cout << "The item is NOT a member of the function" << endl;
    }

    return 0;
}

bool isMember(int* arr, int size, int item)
{
    size--;

    if (size < 0)
    {
        return false;
    }

    if (*(arr + size) == item)
    {
        return true;
    }
    else {
        isMember(arr, size, item);
    }
}
