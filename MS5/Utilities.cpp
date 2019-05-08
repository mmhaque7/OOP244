/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
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
        iProduct* create = nullptr;
        if (tag == 'N' || tag == 'n') {
            create =new Product();
        } else if(tag =='P'||tag=='p'){
            create =new Perishable();
        }
        return  create;


    }


}