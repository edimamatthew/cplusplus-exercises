#include <iostream>

using namespace std;

bool checkString(string, string, int&);

int main()
{
    int num = 0;

    string str1 = "Hello my my my my name is Matthew";
    string str2 = "my";

    if (checkString(str1, str2, num))
    {
        cout << "Found: It occured \"" << num << "\" time(s)." << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}

bool checkString(string str1, string str2, int& num)
{
    cout << string::npos << endl;
    cout << str1.find(str2) << endl;
    cout << str2.length() << endl;

    int pos = 0;
    if (str1.find(str2) != string::npos)
    {
        while ((pos = str1.find(str2, pos)) != string::npos) {
            ++num;
            pos += str2.length() - 1;
        }

        return true;
    }
    else {
        return false;
    }
}
