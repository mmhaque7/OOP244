/*
 * Mehedi Haque
 * 154908172
 * WS08-in_lab
 * March 20 2019
 * Section A
 * */

#ifndef IN_LAB_IACCOUNT_H
#define IN_LAB_IACCOUNT_H

#include <ostream>

namespace sict {
    class iAccount {
    public:
        virtual bool credit(double amount) = 0;

        virtual bool debit(double amount) = 0;

        virtual void monthEnd() = 0;

        virtual void display(std::ostream &out) const = 0;

        virtual ~iAccount() = default;

    };

    iAccount *CreateAccount(const char *, double);
}
#endif //IN_LAB_IACCOUNT_H
