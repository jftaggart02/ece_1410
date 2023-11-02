#ifndef LOAN_HPP
#define LOAN_HPP

#include "Account.hpp"

class Loan : public Account {

    protected:

        

    public:

        Loan(int acc_number, string acc_name, float balance, float check_fee);

        void update();
        void transaction(float trans);

};

Loan::Loan(int acc_number, string acc_name, float balance, float interest)
 : Account(acc_number, acc_name, balance, interest)
{

    

}

void Loan::update() {

    // Add accrued interest
    this->balance += this->balance * this->interest;

}

void Loan::transaction(float trans) {

    // If the payment is less than or equal to the outstanding balance
    if (this->balance - trans >= 0) {

        this->balance -= trans;
        
    }

    // If the payment is greater than balance
    else {

        cout << "Transaction declined: payment too much." << endl;

    }

}

#endif // LOAN_HPP