#include "main.h"

using namespace std;

int main()
{
	int customerAmount = 10;
	int customerChoice;
	int choice;
	Customer currentCustomer;

	Customer* customers = nullptr;
	customers = new Customer[customerAmount];

	cout << "There are currently " << customerAmount << " customers in the system.\n";
	cout << "What would you like to do with said customers?\n";
	cout << "1. View data\n";
	cout << "2. Edit data\n";
	cout << "3. Enter new account\n";

	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "What customer number's data would you like to view?\n";
		cin >> customerChoice;
		currentCustomer = ChooseCustomer(customers, customerChoice, customerAmount);

		ViewData(currentCustomer);

		break;
	case 2:
		cout << "What customer number would you like to edit?\n";
		cin >> customerChoice;

		if (currentCustomer.infoEntered == true)
		{
			EditData(currentCustomer);
		}
		else
		{
			EnterData(currentCustomer);
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

		EnterData(customers[customerAmount - 1]);

		delete[] customersTemp;
		customersTemp = nullptr;
		break;
	}

	delete[] customers;
}