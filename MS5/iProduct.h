/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */

#ifndef MS4_IPRODUCT_H
#define MS4_IPRODUCT_H

#include <fstream>
#include <iostream>

namespace ama {

    const int max_length_label = 30;
    const int max_length_sku = 7;
    const int max_length_name = 75;
    const int max_length_unit = 10;


    const int write_table = 1;
    const double tax_rate = 0.13;
    const int write_human = 2;
    const int write_condensed = 0;

    class iProduct {
    public:
        virtual ~iProduct() {}

        virtual std::ostream &write(std::ostream &os, int writeMode) const = 0;

        virtual std::istream &read(std::istream &is, bool interractive) = 0;

        virtual bool operator==(const char *sku) const = 0;

        virtual int qtyAvailable() const = 0;

        virtual int qtyNeeded() const = 0;

        virtual const char *name() const = 0;

        virtual double total_cost() const = 0;

        virtual bool operator>(const iProduct &other) const = 0;

        virtual int operator+=(int qty) = 0;
    };

}




#endif //MS4_IPRODUCT_H
