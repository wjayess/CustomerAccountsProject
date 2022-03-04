#pragma once

#include <string>
#include <iostream>

// main struct for Customer
struct Customer {
	std::string name,
		address,
		city,
		state,
		lastPayDate,
		phoneNumber;
	int zip = 0,
		accountBalance = 0;
	bool infoEntered = false;
};

// function prototypes
void EditData(Customer&);
Customer EnterData();
void ViewData(Customer&);
void CopyData(Customer[], Customer[], int);
void EmptyCheck(std::string&, std::string);