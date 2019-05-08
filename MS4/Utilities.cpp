/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 4
 * March 22 2019
 * Section A
 * */

#include "Utilities.h"

using namespace std;
namespace ama {
    double& operator+=(double& total, const iProduct& prod) {
        total += prod.total_cost();
        return total;
    }

    ostream &operator<<(ostream &out, const iProduct &prod) {
        prod.write(out, write_human);
        return out;
    }

    istream &operator>>(istream &in, iProduct &prod) {
        prod.read(in, true);
        return in;
    }


    iProduct* createInstance(char tag) {
        if (tag == 'N' || tag == 'n') {
            return new Product();
        } else {
            return nullptr;
        }

    }


}