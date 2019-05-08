#include <iostream>
#include <iomanip>

#include "SavingsAccount.h"

using namespace std;

namespace sict {
    // This custom constructor receives the initial account balance and the interest rate to be applied to the balance.
    sict::SavingsAccount::SavingsAccount(double balance, double interestRate) {
        if (interestRate > 0) {
            currentBalance = balance;
        } else {
            currentBalance = 0.0;
        }
        if (interestRate > 0) {
            rate = interestRate;
        } else {
            rate = 0.0;
        }
    }

//This modifier calculates the interest earned on the current balance and credits the account with that interest
    void SavingsAccount::monthEnd() {
        currentBalance *= (rate + 1);
    }

//This function inserts in the stream received as parameter the content
    void SavingsAccount::display(std::ostream &out) const {
        out << "Account type: Savings" << std::endl
            << std::fixed << std::setprecision(2)
            << "Balance: $" << currentBalance << std::endl
            << "Interest Rate (%): " << rate * 100 << std::endl;


    }
}