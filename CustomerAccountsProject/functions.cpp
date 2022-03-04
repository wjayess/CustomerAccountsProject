#include "main.h"

using namespace std;

// Displays all of the customer's information. Very simple, just a lot of cout statements
void ViewData(Customer& customerView)
{
	// If the customer we're trying to view has no information in the system, make the user enter said information.
	if (customerView.infoEntered == false)
	{
		customerView = EnterData();

		return;
	}

	cout << "Customer's name: " << customerView.name << endl;
	cout << customerView.name << "'s street address: " << customerView.address << endl;
	cout << customerView.name << "'s city: " << customerView.city << endl;
	cout << customerView.name << "'s state: " << customerView.state << endl;
	cout << customerView.name << "'s zip: " << customerView.zip << endl;
	cout << customerView.name << "'s phone number: " << customerView.phoneNumber << endl;
	cout << customerView.name << "'s account balance: " << customerView.accountBalance << endl;
	cout << customerView.name << "'s last pay date: " << customerView.lastPayDate << endl;
}

// Allows user to pick something from the customer's data to edit.
void EditData(Customer& customerEdit)
{
	int choice;
	bool enteringData = false;

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

	if (!(choice >= 1) || !(choice <= 8))
	{
		cout << "Please enter a valid option.";
		return;
	}

	switch (choice)
	{
	case 1:
		cout << "Enter the customer's new name:\n";
		cin >> customerEdit.name;

		break;
	case 2:
		// Check if the line is empty. If so, throw an "error".
		EmptyCheck(customerEdit.address, "street address");

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
		// While loop so the program doesn't end if the user enters a negative number.
		// Allows the user to retry.
		while (!enteringData)
		{
			enteringData = true;

			cout << "Enter " << customerEdit.name << "'s new account balance:\n";
			cin.ignore();
			cin >> customerEdit.accountBalance;

			if (customerEdit.accountBalance < 0)
				cout << "Please enter a positive number.\n";
			else
				break;

			enteringData = false;
		}

		break;
	case 8:
		EmptyCheck(customerEdit.lastPayDate, "last payment date");

		break;
	}
}

// Very similar to EditData(). This one, however, forces you to enter all data.
Customer EnterData()
{
	Customer tempCustomer;
	bool enteringData = false;

	cout << "This customer currently has no information within the system.\nPlease enter their data.\n";

	cout << "Enter the customer's name:\n";
	cin >> tempCustomer.name;
	EmptyCheck(tempCustomer.address, "street address");
	cout << "Enter the customer's city:\n";
	cin >> tempCustomer.city;
	cout << "Enter the customer's state:\n";
	cin >> tempCustomer.state;
	cout << "Enter the customer's zip:\n";
	cin >> tempCustomer.zip;
	cout << "Enter the customer's phone number:\n";
	cin >> tempCustomer.phoneNumber;

	while (!enteringData)
	{
		enteringData = true;

		cout << "Enter the customer's account balance:\n";
		cin.ignore();
		cin >> tempCustomer.accountBalance;

		if (tempCustomer.accountBalance < 0)
			cout << "Please enter a positive number.\n";
		else
			break;

		enteringData = false;
	}

	EmptyCheck(tempCustomer.lastPayDate, "last payment date");

	tempCustomer.infoEntered = true;

	return tempCustomer;
}

// Copies an array to another array.
void CopyData(Customer originalData[], Customer tempData[], int arrayAmount)
{
	for (int count = 0; count < arrayAmount - 1; count++)
	{
		tempData[count].name = originalData[count].name;
		tempData[count].address = originalData[count].address;
		tempData[count].city = originalData[count].city;
		tempData[count].state = originalData[count].state;
		tempData[count].zip = originalData[count].zip;
		tempData[count].phoneNumber = originalData[count].phoneNumber;
		tempData[count].accountBalance = originalData[count].accountBalance;
		tempData[count].lastPayDate = originalData[count].lastPayDate;
	}
}

// Input validation for getline() inputs.
void EmptyCheck(std::string& validationString, std::string dataName)
{
	bool enteringData = false;

	// If the user didn't put anything on the line, throw an "error".
	// Again, allowing the user to retry as many times as they'd like.
	while (!enteringData)
	{
		enteringData = true;

		cout << "Enter the customer's " << dataName << ":\n";
		cin.ignore();
		getline(cin, validationString);

		if (validationString == "")
			cout << "Please enter data.\n";
		else
			break;

		enteringData = false;
	}
}