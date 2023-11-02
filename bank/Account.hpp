#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Account 
{
	// YOU MAY MODIFY ANYTHING HERE

	protected:
		Account* next;
		int acc_number;
		string acc_name;
		float balance;
		float interest;
		

	public:

		virtual void update() = 0;
		virtual void transaction(float trans) = 0;											//2 functions for accounts
		string getName();
		
		int getAccNum(); 
		float getBalance();
		
		Account* getNext();
		void setNext(Account* _n);
		Account(int acc_number, string acc_name, float balance, float interest); // Constructor
		
};

Account::Account(int acc_number, string acc_name, float balance, float interest) : 
	acc_number(acc_number), balance(balance), interest(interest)
{

	

}

string Account::getName() {

	return this->acc_name;

}

int Account::getAccNum() {
	
	return this->acc_number;

}

float Account::getBalance() {

	return this->balance;

}

Account* Account::getNext() {

	return this->next;

}

void Account::setNext(Account* _n) {

	this->next = _n;

}

#endif