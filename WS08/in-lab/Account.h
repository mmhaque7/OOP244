/*
 * Mehedi Haque
 * 154908172
 * WS08-in_lab
 * March 20 2019
 * Section A
 * */

#ifndef IN_LAB_ACCOUNT_H
#define IN_LAB_ACCOUNT_H

#include "iAccount.h"

namespace sict {
    class Account : public iAccount {
    protected:
        double balance() const;

        double currentBalance;
    public:
        Account() = default;

        Account(double balance);

        bool credit(double amount);

        bool debit(double ammount);


    };
}
#endif //IN_LAB_ACCOUNT_H
