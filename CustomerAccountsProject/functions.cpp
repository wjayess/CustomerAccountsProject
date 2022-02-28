#include "main.h"

using namespace std;

Customer ChooseCustomer(Customer customers[], int customerChoice, int customerAmount)
{
	Customer customer;

	for (int count = 0; count < customerAmount; count++)
	{
		if (customerChoice == count)
			customer = customers[count];
	}

	return customer;
}

void ViewData(Customer customerView)
{
	if (customerView.infoEntered == false)
	{
		EnterData(customerView);

		return;
	}

	cout << "Customer's name: " << customerView.name << endl;
	cout << customerView.name << "'s address: " << customerView.address << endl;
	cout << customerView.name << "'s city: " << customerView.city << endl;
	cout << customerView.name << "'s state: " << customerView.state << endl;
	cout << customerView.name << "'s zip: " << customerView.zip << endl;
	cout << customerView.name << "'s phone number: " << customerView.phoneNumber << endl;
	cout << customerView.name << "'s account balance: " << customerView.accountBalance << endl;
	cout << customerView.name << "'s last pay date: " << customerView.lastPayDate << endl;
}

void EditData(Customer customerEdit)
{
	int choice;

	cout << "What about " << customerEdit.name << "'s profile would you like to edit?\n";
	cout << "1. Name\n";
	cout << "2. Street address\n";
	cout << "3. City\n";
	cout << "4. State\n";
	cout << "5. Zip\n";
	cout << "6. Phone number\n";
	cout << "7. Account balance\n";
	cout << "8. Last payment date\n";

	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Enter the customer's new name:\n";
		cin >> customerEdit.name;
		break;
	case 2:
		cout << "Enter " << customerEdit.name << "'s new street address:\n";
		getline(cin, customerEdit.address);
		break;
	case 3:
		cout << "Enter " << customerEdit.name << "'s new city:\n";
		cin >> customerEdit.city;
		break;
	case 4:
		cout << "Enter " << customerEdit.name << "'s new state:\n";
		cin >> customerEdit.state;
		break;
	case 5:
		cout << "Enter " << customerEdit.name << "'s new zip:\n";
		cin >> customerEdit.zip;
		break;
	case 6:
		cout << "Enter " << customerEdit.name << "'s new phone number:\n";
		cin >> customerEdit.phoneNumber;
		break;
	case 7:
		cout << "Enter " << customerEdit.name << "'s new account balance:\n";
		cin >> customerEdit.accountBalance;
		break;
	case 8:
		cout << "Enter " << customerEdit.name << "'s new last payment date:\n";
		getline(cin, customerEdit.lastPayDate);
		break;
	}
}

void EnterData(Customer customerEnter)
{
	cout << "This customer currently has no information within the system.\nPlease enter their data.\n";

	cout << "Enter the customer's name:\n";
	cin >> customerEnter.name;
	cout << "Enter the customer's street address:\n";
	getline(cin, customerEnter.address);
	cout << "Enter the customer's city:\n";
	cin >> customerEnter.city;
	cout << "Enter the customer's state:\n";
	cin >> customerEnter.state;
	cout << "Enter the customer's zip:\n";
	cin >> customerEnter.zip;
	cout << "Enter the customer's phone number:\n";
	cin >> customerEnter.phoneNumber;
	cout << "Enter the customer's account balance:\n";
	cin >> customerEnter.accountBalance;
	cout << "Enter the customer's last payment date:\n";
	getline(cin, customerEnter.lastPayDate);

	customerEnter.infoEntered = true;
}

void SaveData(Customer originalCustomers[], Customer customersTemp[], int customerAmount)
{
	for (int count = 0; count < customerAmount - 1; count++)
	{
		customersTemp[count].name = originalCustomers[count].name;
		customersTemp[count].address = originalCustomers[count].address;
		customersTemp[count].city = originalCustomers[count].city;
		customersTemp[count].state = originalCustomers[count].state;
		customersTemp[count].zip = originalCustomers[count].zip;
		customersTemp[count].phoneNumber = originalCustomers[count].phoneNumber;
		customersTemp[count].accountBalance = originalCustomers[count].accountBalance;
		customersTemp[count].lastPayDate = originalCustomers[count].lastPayDate;
	}
}

void LoadData(Customer originalCustomers[], Customer customersTemp[], int customerAmount)
{
	for (int count = 0; count < customerAmount - 1; count++)
	{
		originalCustomers[count].name = customersTemp[count].name;
		originalCustomers[count].address = customersTemp[count].address;
		originalCustomers[count].city = customersTemp[count].city;
		originalCustomers[count].state = customersTemp[count].state;
		originalCustomers[count].zip = customersTemp[count].zip;
		originalCustomers[count].phoneNumber = customersTemp[count].phoneNumber;
		originalCustomers[count].accountBalance = customersTemp[count].accountBalance;
		originalCustomers[count].lastPayDate = customersTemp[count].lastPayDate;
	}
}