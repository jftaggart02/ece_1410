#ifndef SAVINGS_HPP
#define SAVINGS_HPP

#include "Account.hpp"

class Savings : public Account {
    
    protected:

        

    public:

        Savings(int acc_number, string acc_name, float balance, float check_fee);

        void update();
        void transaction(float trans);

};

Savings::Savings(int acc_number, string acc_name, float balance, float interest)
 : Account(acc_number, acc_name, balance, interest)
{

    

}

void Savings::update() {

    // Add accrued interest
    this->balance += this->balance * this->interest;

}

void Savings::transaction(float trans) {

    // If there are enough funds for transaction
    if (this->balance + trans >= 0) {

        this->balance += trans;
        
    }

    // If there aren't, reject transaction
    else {

        cout << "Transaction declined: insufficient funds." << endl;

    }

}

#endif // SAVINGS_HPP