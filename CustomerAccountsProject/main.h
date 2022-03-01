#pragma once

#include <string>
#include <iostream>

struct Address {
	std::string city,
		state,
		street;
	int zip,
		houseNumber;
};

struct Customer {
	std::string name,
		lastPayDate;
	Address address;
	int	phoneNumber = 0,
		accountBalance = 0;
	bool infoEntered = false;
};

void EditData(Customer);
void EnterData(Customer);
Customer ChooseCustomer(Customer[], int, int);
void ViewData(Customer);
void SaveData(Customer[], Customer[], int);
void LoadData(Customer[], Customer[], int);