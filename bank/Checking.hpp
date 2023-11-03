#ifndef CHECING_HPP
#define CHECKING_HPP

#include "Account.hpp"
#include <iostream>
using namespace std;

/*
Checks:
    Transactions reflect immediately on balance
    Check fees are processed at next udpate
*/

class Checking : public Account {

    protected:

        float check_fee;
        int num_fees = 0;

    public:

        Checking(int acc_number, string acc_name, float balance, float check_fee);

        void update();
        void transaction(float trans);

};

Checking::Checking(int acc_number, string acc_name, float balance, float check_fee)
 : Account(acc_number, acc_name, balance, check_fee)
{

    // Calling the Account constructor sets interest rate to check fee, so I need to fix that:
	this->check_fee = this->interest;

}

void Checking::update() {

    // If there are fees to process
    if (this->num_fees) {

        // Subtract num_fees times the check fee from balance
        this->balance -= (float) this->num_fees * this->check_fee;

    }

    // Reset num_fees to 0
    this->num_fees = 0;

}

void Checking::transaction(float trans) {

    // If there are enough funds for transaction
    if (this->balance + trans >= 0) {

        this->balance += trans;
        
        // Add a check fee at next update
        this->num_fees++;

    }

    // If there aren't
    else {

        cout << "Check bounced. Insufficient funds." << endl;

        // If there is at least enough for bounced check fee
        if (this->balance >= (25 /*+ this->check_fee*/)) {

            // Immediately subtract bounced check fee plus regular check fee
            this->balance -= (25 /*+ this->check_fee*/);

        }
        
        // Else, subtract remaining money
        else {

            // this->balance = 0;

        }

    }

}

#endif // CHECKING_HPP