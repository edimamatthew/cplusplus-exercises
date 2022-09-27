#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char ch;
    char repeatOrQuit;

    do {
        cout << "Enter an input: ";
        cin >> ch;

        if (isdigit(ch))
            cout << "Digit" << endl;
        else
            cout << "Not a digit" << endl;

        cout << "Do you want to repeat the program or quit? (R/Q): ";
        cin >> repeatOrQuit;

        repeatOrQuit = toupper(repeatOrQuit);

        if (repeatOrQuit == 'Q')
            break;

    } while (true);

    return 0;
}
