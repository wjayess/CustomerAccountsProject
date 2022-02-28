#pragma once

#include <string>
#include <iostream>

struct Customer {
	std::string name,
		address,
		city,
		state,
		lastPayDate;
	int zip = 0,
		phoneNumber = 0,
		accountBalance = 0;
	bool infoEntered = false;
};

void EditData(Customer);
void EnterData(Customer);
Customer ChooseCustomer(Customer[], int, int);
void ViewData(Customer);
void SaveData(Customer[], Customer[], int);
void LoadData(Customer[], Customer[], int);