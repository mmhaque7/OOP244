/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */

#ifndef MS5_PERISHABLE_H
#define MS5_PERISHABLE_H

#include <iostream>

#include "Date.h"
#include "Product.h"
#include "ErrorState.h"



namespace ama {

    class Perishable : public Product {

        Date date;
        ErrorState error;

    public:
        Perishable();
        std::istream& read(std::istream& in, bool interact);
        std::ostream& write(std::ostream& os, int writeMode) const;

    };

}

#endif //MS5_PERISHABLE_H
