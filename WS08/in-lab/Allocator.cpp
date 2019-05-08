/*
 * Mehedi Haque
 * 154908172
 * WS08-in_lab
 * March 20 2019
 * Section A
 * */

#include "SavingsAccount.h"

namespace sict {
#define INTRATE 0.05

    iAccount *CreateAccount(const char *type, double balance) {
        bool flag = false;
        iAccount *newSaving = nullptr;

        if (type[0] == 'S') {
            flag = true;
            newSaving = new SavingsAccount(balance, INTRATE);
        }

        return flag ? newSaving : nullptr;

    }

}
