#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "Account.hpp" // ONLY BARE minimum skeleton provided


// CREATE these files ...
#include "Checking.hpp"
#include "Savings.hpp"
#include "Loan.hpp"
using namespace std;


// #define DEBUG


// FEEL FREE to ADD/DELETE Anything, but make sure it does not fail compilation of UNMODIFIED test.cpp
class Bank {
private:
	int accounts = 0;										//starts with no accounts
	Account* head;
	Account* end;
	Account* temp;

	public:
		Bank(); // Constructor
		void account(char f_letter, int acc_number, string acc_name, float balance, float interest);//creates an account
		int process(string line); //processes the input file text
		Account* findNumber(int acc_num); // Finds the account Number
		int getCount()
		{
			return accounts; 
		}
		// Provided for YOU :-)
		Account* operator[](int acc_num)
		{
			return findNumber(acc_num);										//overloads the [] operator to find the account
		}


		// ADD any other functions you deem necessary

};

// ALL IMPLEMENTATION Goes Here

Bank::Bank() {
	// Initialize head to nullptr
	this->head = nullptr;
}

int Bank::process(string line) {
	#ifdef DEBUG
	cout << "processing line.\n";
	#endif

	// Initialize stringstream with given line
	stringstream line_stream(line);

	char action_type;

	line_stream >> action_type;
	#ifdef DEBUG
	cout << "Action type is:" << action_type << endl;
	#endif

	int acc_number;
	string acc_name; 
	float balance; 
	float interest;
	float check_fee;
	float trans_amount;

	switch(action_type) {
		case 's': // Create Savings acct
			// Get account info
			line_stream >> acc_number;
			line_stream >> acc_name;
			line_stream >> balance;
			line_stream >> interest;
			// Create savings account with given info
			#ifdef DEBUG
			cout << "Creating Savings Account" << endl;
			#endif
			account('s', acc_number, acc_name, balance, interest);
			return 1;
			break;
		case 'c': // Create Checking acct
			// Get account info
			line_stream >> acc_number;
			line_stream >> acc_name;
			line_stream >> balance;
			line_stream >> check_fee;
			// Create checking account with given info
			#ifdef DEBUG
			cout << "Creating Checking Account" << endl;
			#endif
			account('c', acc_number, acc_name, balance, check_fee);
			return 1;
			break;
		case 'l': // Create Loan acct
			// Get account info
			line_stream >> acc_number;
			line_stream >> acc_name;
			line_stream >> balance;
			line_stream >> interest;
			// Create loan account with given info
			#ifdef DEBUG
			cout << "Creating Loan Account" << endl;
			#endif
			account('l', acc_number, acc_name, balance, interest);
			return 1;
			break;
		case 't': // transaction
			// Get transaction info
			line_stream >> acc_number;
			line_stream >> trans_amount;
			// Perform transaction on amount
			#ifdef DEBUG
			cout << "Performing transaction" << endl;
			#endif
			this->findNumber(acc_number)->transaction(trans_amount);
			return 1;
			break;
		case 'u': // update
			// Get account number
			line_stream >> acc_number;
			// Update account
			#ifdef DEBUG
			cout << "Updating account" << endl;
			#endif
			this->findNumber(acc_number)->update();
			return 1;
			break;
		default:
			// Not sure what to do. Probably don't need this
			return 0;
	}

}


void Bank::account(char f_letter, int acc_number, string acc_name, float balance, float interest) {

	Account * new_account;

	float check_fee = interest;

	switch (f_letter) {

		case 's':
			// dynamically allocate memory to construct account with info
			new_account = new Savings(acc_number, acc_name, balance, interest);
			break;

		case 'c':
			// dynamically allocate memory to construct account with info
			new_account = new Checking(acc_number, acc_name, balance, check_fee);
			break;

		case 'l':
			new_account = new Loan(acc_number, acc_name, balance, interest);
			break;

		default:
			// Not sure what to do. Probably don't need this
			new_account = nullptr;

	}

	// Add account to head of linked list
	new_account->setNext(head);
	this->head = new_account;

	// Increment account count
	this->accounts ++;

}

Account *Bank::findNumber(int acc_num) {

	// Start at head of list
	Account * current = this->head;

	// Sift through list until we find the right account
	do {

		if (current->getAccNum() == acc_num) {
			// Return pointer to found account
			return current;
		}
		else {
			current = current->getNext();
		}

	}
	while (current != nullptr);

	// If we made it to the end,
	return nullptr;

}

#endif