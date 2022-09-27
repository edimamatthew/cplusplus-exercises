#include <iostream>
#include <iomanip>
using namespace std;

struct Village
{
    string name;
    int population;
    int men;
    int women;
};

struct Church
{
    string name;
    string address;
    int members;
    string pastor;
};

int main()
{
    Village abak;
    Village uyo;

    // Initialization for village - Abak
    abak.name = "Abak";
    abak.population = 200;
    abak.men = 80;
    abak.women = 120;

    // Initialization for village - Uyo
    uyo.name = "Uyo";
    uyo.population = 400;
    uyo.men = 200;
    uyo.women = 200;

    Church apostolic;
    Church anglican;
    
    // Initialization for church - Apostolic
    apostolic.name = "Apostolic Faith Church";
    apostolic.address = "Ibeju Lekki, Lagos";
    apostolic.members = 250;
    apostolic.pastor = "Rev. Ogunriola";

    // Initialization for church - Anglican
    anglican.name = "Anglican Church";
    anglican.address = "Ikeja, Lagos";
    anglican.members = 150;
    anglican.pastor = "Rev. Daniel Jacob";

    cout << "Village (Abak)\n---------" << endl;
    cout << "Name: " << abak.name << endl;
    cout << "Population: " << abak.population << endl;
    cout << "Men: " << abak.men << endl;
    cout << "Women: " << abak.women << endl << endl;

    cout << "Village (Uyo)\n---------" << endl;
    cout << "Name: " << uyo.name << endl;
    cout << "Population: " << uyo.population << endl;
    cout << "Men: " << uyo.men << endl;
    cout << "Women: " << uyo.women << endl << endl;

    cout << "Church (Apostolic)\n---------" << endl;
    cout << "Name: " << apostolic.name << endl;
    cout << "Address: " << apostolic.address << endl;
    cout << "Members: " << apostolic.members << endl;
    cout << "Pastor: " << apostolic.pastor << endl << endl;

    cout << "Church (Anglican)\n---------" << endl;
    cout << "Name: " << anglican.name << endl;
    cout << "Address: " << anglican.address << endl;
    cout << "Members: " << anglican.members << endl;
    cout << "Pastor: " << anglican.pastor << endl << endl;

    return 0;
}
