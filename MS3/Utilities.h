/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 3
 * March 22 2019
 * Section A
 * */

#ifndef MS3_UTILITIES_H
#define MS3_UTILITIES_H

#include "Product.h"
#include <iostream>

namespace ama{
    std::ostream& operator<< (std::ostream&, const Product&);
    std::istream& operator>> (std::istream&, Product&);
    double operator+=(double& , const Product&);

}


#endif //MS3_UTILITIES_H
