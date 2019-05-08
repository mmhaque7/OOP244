/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 4
 * March 22 2019
 * Section A
 * */

#ifndef MS3_UTILITIES_H
#define MS3_UTILITIES_H

#include "Product.h"
#include <iostream>

namespace ama{
    std::ostream& operator<< (std::ostream&, const iProduct&);
    std::istream& operator>> (std::istream&, iProduct&);
    double& operator+=(double& total, const iProduct& prod);
    iProduct* createInstance(char tag);
}


#endif //MS3_UTILITIES_H
