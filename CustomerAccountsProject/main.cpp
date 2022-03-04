// William Smith, CISP 1020, Structure Program, 03/04/2022

// This program allows users to enter data about customers, view data regarding customers, and edit customer's data.

#include "main.h"

using namespace std;

int main()
{
	// Having these variables, along with a lot of other functionality in main function, 
	// as there's a lot of moving parts.
	int customerAmount = 10;
	int customerChoice;
	int menuChoice;

	// DAM array for customers. This can be edited during runtime.
	// delete later!
	Customer* customers = nullptr;
	customers = new Customer[customerAmount];

	// Infinite loop, so user can do multiple things in one session with the program.
	// If I want to view someone's data, the program won't end. It'll restart the menu
	// and let me do something else.
	while (true)
	{
		cout << "There are currently " << customerAmount << " customers in the system.\n";
		cout << "What would you like to do with said customers?\n";
		cout << "1. View data\n";
		cout << "2. Edit data\n";
		cout << "3. Enter new account\n";

		cin >> menuChoice;

		// input validation
		if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3)
		{
			switch (menuChoice)
			{
			case 1:
				cout << "What customer number's data would you like to view?\n";
				cout << "(Remember, this number is zero-indexed!)\n";
				cin >> customerChoice;

				// more input validation
				if ((customerChoice <= (customerAmount - 1)) && customerChoice >= 0)
				{
					// Pass customer info to ViewData()
					ViewData(customers[customerChoice]);
				}
				else
				{
					cout << "Please enter a number from 0 to " << customerAmount - 1 << ".\n";
				}

				break;
			case 2:
				cout << "What customer number would you like to edit?\n";
				cin >> customerChoice;

				// as you can see, there's a LOT of input validation.
				if ((customerChoice <= (customerAmount - 1)) && customerChoice >= 0)
				{
					if (customers[customerChoice].infoEntered == true)
					{
						// very chunky function. main() wouldn't be the best place for it lol
						EditData(customers[customerChoice]);
					}
					else
					{
						// EnterData() returns the customer data we need to give to the current customer choice.
						customers[customerChoice] = EnterData();
					}
				}
				else
				{
					cout << "Please enter a number from 0 to " << customerAmount - 1 << ".\n";
				}

				break;
			case 3:
				// Above all else, this is my favorite part.
				// increase the amount of elements
				customerAmount++;

				// create another DAM
				Customer* customersTemp = nullptr;
				customersTemp = new Customer[customerAmount];

				// Copy all the data from the customers array to the new temporary array.
				CopyData(customers, customersTemp, customerAmount);

				// delete original DAM array, and recreate it with the new element amount
				delete[] customers;
				customers = nullptr;
				customers = new Customer[customerAmount];

				// Copy all data from the temporary to the newly "refreshed" customers array
				CopyData(customersTemp, customers, customerAmount);

				// enter the data on the last person
				customers[customerAmount - 1] = EnterData();

				// delete the temporary DAM array.
				delete[] customersTemp;
				customersTemp = nullptr;

				break;
			}
		}
		else
		{
			cout << "Please choose a valid option.\n";
		}

	}

	// get outta here
	delete[] customers;
}