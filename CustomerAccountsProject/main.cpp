#include "main.h"

using namespace std;

int main()
{
	int customerAmount = 10;
	int customerChoice;
	int menuChoice;

	Customer* customers = nullptr;
	customers = new Customer[customerAmount];

	while (true)
	{
		cout << "There are currently " << customerAmount << " customers in the system.\n";
		cout << "What would you like to do with said customers?\n";
		cout << "1. View data\n";
		cout << "2. Edit data\n";
		cout << "3. Enter new account\n";

		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			cout << "What customer number's data would you like to view?\n";
			cout << "(Remember, this number is zero-indexed!)\n";
			cin >> customerChoice;

			ViewData(customers[customerChoice]);

			break;
		case 2:
			cout << "What customer number would you like to edit?\n";
			cin >> customerChoice;

			if (customers[customerChoice].infoEntered == true)
			{
				EditData(customers[customerChoice]);
			}
			else
			{
				customers[customerChoice] = EnterData();
			}

			break;
		case 3:
			customerAmount++;

			Customer* customersTemp = nullptr;
			customersTemp = new Customer[customerAmount];

			SaveData(customers, customersTemp, customerAmount);

			delete[] customers;
			customers = nullptr;
			customers = new Customer[customerAmount];

			LoadData(customers, customersTemp, customerAmount);

			customers[customerAmount - 1] = EnterData();

			delete[] customersTemp;
			customersTemp = nullptr;
			break;
		}
	}

	delete[] customers;
}