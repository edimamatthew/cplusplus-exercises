#include <iostream>
using namespace std;

enum class TransportMode { BICYCLE, CAR, SHIP, PLANE, FEET };

string getTransportModeName(TransportMode);

int main()
{
	const int AVAILABLE_MODES = 5;
	TransportMode transport = TransportMode::BICYCLE;
	int userSelectedMode;
	int tryAgainOption;
	int modifiedUserSelectedMode;

	while (true)
	{
		cout << "Welcome, we have the following transport modes;" << endl;

		for (int count = static_cast<int>(transport); count < AVAILABLE_MODES; count++)
		{
			cout << count + 1 << ": " << getTransportModeName(static_cast<TransportMode>(count)) << endl;
		}

		cout << "\nEnter a mode from the option above: ";

		cin >> userSelectedMode;
		modifiedUserSelectedMode = userSelectedMode - 1;

		if ((modifiedUserSelectedMode) >= static_cast<int>(TransportMode::BICYCLE) && (modifiedUserSelectedMode) <= static_cast<int>(TransportMode::FEET))
		{
			cout << "Correct! We have the transport mode and you can travel. You are traveling using: \"" << getTransportModeName(static_cast<TransportMode>(modifiedUserSelectedMode)) << "\"" << endl;
			break;
		}
		else
		{
			cout << "Oh, no! We do not have the selected transport mode so you cannot travel.\nCare to try again? (0 => No/1 => Yes): ";
			cin >> tryAgainOption;
			if (tryAgainOption) {
				cout << "\n";
				continue;
			}
			else
				cout << "Sure, bye!" << endl;
				break;
		}
	}

	return 0;
}

string getTransportModeName(TransportMode key)
{
	string value;
	switch (key)
	{
	case TransportMode::BICYCLE:
		value = "Bicycle";
		break;

	case TransportMode::CAR:
		value = "Car";
		break;

	case TransportMode::PLANE:
		value = "Plane";
		break;

	case TransportMode::SHIP:
		value = "Ship";
		break;

	case TransportMode::FEET:
		value = "Feet";
		break;
	}

	return value;
}
