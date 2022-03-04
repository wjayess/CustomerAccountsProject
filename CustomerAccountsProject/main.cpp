// William Smith, CISP 1020, Structure Program, 03/04/2022

// This program allows users to enter data about customers, view data regarding customers, and edit customer's data.

#include "main.h"

using namespace std;

int main()
{
	// Having these variables, along with a lot of other functionality in main function, 
	// as there's a lot of moving parts.
	int customerAmount = 10;
	std::string customerChoice;
	int customerChoiceIndex;
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

		// Input validation
		if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3)
		{
			switch (menuChoice)
			{
			case 1:
				cout << "What customer would you like to view?\n";
				cin >> customerChoice;

				// Loop through and find the names of customers. If one matches, select that data.
				// If we can't find the data, have the user enter a new person's data.
				for (int count = 0; count < customerAmount; count++)
				{
					if (customers[count].name == customerChoice)
						customerChoiceIndex = count;
					else if (count == (customerAmount - 1))
					{
						customerChoiceIndex = count;
						customers[customerChoiceIndex] = EnterData();
					}
				}

				// Pass customer info to ViewData()
				ViewData(customers[customerChoiceIndex]);

				break;
			case 2:
				cout << "What customer would you like to edit?\n";
				cin >> customerChoice;

				for (int count = 0; count < customerAmount; count++)
				{
					if (customers[count].name == customerChoice)
						customerChoiceIndex = count;
					else if (count == (customerAmount - 1))
					{
						customerChoiceIndex = count;
						customers[customerChoiceIndex] = EnterData();
					}
				}

				// Member variable that allows us to see if the customer has been edited before.
				// If not, the person is obviously new, so lets edit their data.
				if (customers[customerChoiceIndex].infoEntered == true)
				{
					EditData(customers[customerChoiceIndex]);
				}
				else
				{
					// EnterData() returns the customer data we need to give to the current customer choice.
					customers[customerChoiceIndex] = EnterData();
				}

				break;
			case 3:
				// Above all else, this is my favorite part.
				// Increase the amount of elements.
				customerAmount++;

				// Create another DAM array
				Customer* customersTemp = nullptr;
				customersTemp = new Customer[customerAmount];

				// Copy all the data from the customers array to the new temporary array.
				CopyData(customers, customersTemp, customerAmount);

				// Delete original DAM array, and recreate it with the new element amount
				delete[] customers;
				customers = nullptr;
				customers = new Customer[customerAmount];

				// Copy all data from the temporary to the newly "refreshed" customers array
				CopyData(customersTemp, customers, customerAmount);

				// Enter the data on the last person
				customers[customerAmount - 1] = EnterData();

				// Delete the temporary DAM array.
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

	// get outta here, you DAM array! sorry i had to
	delete[] customers;
}