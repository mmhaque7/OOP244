/*
 * Mehedi Haque
 * 154908172
 * WS08-in_lab
 * March 20 2019
 * Section A
 * */
#ifndef IN_LAB_SAVINGSACCOUNT_H
#define IN_LAB_SAVINGSACCOUNT_H

#include <ostream>
#include "Account.h"

namespace sict {
    class SavingsAccount : public Account {
        double rate;
    public:
        SavingsAccount(double balance, double interestRate);

        void monthEnd();

        void display(std::ostream &out) const;
    };
}


#endif //IN_LAB_SAVINGSACCOUNT_H
