/*
 * Mehedi Haque
 * 154908172
 * WS08-in_lab
 * March 20 2019
 * Section A
 * */

#include "Account.h"
#include "iAccount.h"
#include <iostream>

namespace sict {

    //constructor receives either a double holding the initial account balance or nothing
    Account::Account(double balance) {
        if (balance > 0) {
            currentBalance = balance;
        } else {
            currentBalance = 0.0;
        }
    }

    //overrides the credit function from the interface
    bool Account::credit(double amount) {
        bool flag = false;

        if (amount > 0) {
            flag = true;
            currentBalance += amount;
        }
        return flag;

    }

    //overrides the debit function from the interface
    bool Account::debit(double ammount) {
        bool flag = false;

        if (ammount > 0) {
            flag = true;
            currentBalance -= ammount;
        }
        return flag;
    }

    //returns the current balance of the account
    double Account::balance() const {
        return currentBalance;
    }


}