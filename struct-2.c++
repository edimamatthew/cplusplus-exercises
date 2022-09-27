#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Church
{
    string name;
    string address;
    string city;
    string pastor;
};

void showChurch(Church*);

int main()
{
    const int NO_OF_CHURCHES = 5;
    Church churches[NO_OF_CHURCHES];
    int church_count;

    for (int count = 0; count < NO_OF_CHURCHES; count++)
    {
        cout << "Enter Church " << count + 1 << " name: ";
        getline(cin, churches[count].name);

        cout << "Enter Church " << count + 1 << " address: ";
        getline(cin, churches[count].address);

        cout << "Enter Church " << count + 1 << " city: ";
        getline(cin, churches[count].city);

        cout << "Enter Church " << count + 1 <<  " pastor's name: ";
        getline(cin, churches[count].pastor);

        cout << "\n\n";
    }

    for (int count = 0; count < NO_OF_CHURCHES; count++)
    {
        cout << "\n";
        cout << "Details for Church " << count + 1<< endl;
        cout << "-----------------" << endl;

        showChurch(&churches[count]);

        cout << "\n";
    }

    cout << "End of program. Bye." << endl;

    return 0;
}

void showChurch(Church *church)
{
    cout << "Church name: " << church->name << endl;
    cout << "Church address: " << church->address << endl;
    cout << "Church city: " << church->city << endl;
    cout << "Church pastor: " << church->pastor << endl;
}
