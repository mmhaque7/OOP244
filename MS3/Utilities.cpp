/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 3
 * March 22 2019
 * Section A
 * */

#include "Utilities.h"
using  namespace std;
namespace  ama{
    double operator+=(double& total, const Product& prod){
        total += prod.total_cost();
        return  total;
    }
    ostream& operator<<(ostream& out, const Product& prod) {
        prod.write(out, write_human);
        return out;
    }

    istream& operator>>(istream& in, Product& prod) {
        prod.read(in, true);
        return in;
    }


}