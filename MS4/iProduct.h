/*
 * Mehedi Haque
 * 154908172
 * Milestone 4
 * April 1 2019
 * Section A
 * */

#ifndef MS4_IPRODUCT_H
#define MS4_IPRODUCT_H

#include <iostream>


namespace ama {
    const int max_length_label = 30;
    const int max_length_sku = 7;
    const int max_length_name = 75;
    const int max_length_unit = 10;
    const int write_condensed = 0;
    const int write_table = 1;
    const int write_human = 2;
    const double tax_rate = 0.13;

    class iProduct {
    public:
        virtual std::istream &read(std::istream &in, bool interractive) = 0;

        virtual std::ostream &write(std::ostream &out, int writeMode) const = 0;

        ////////
        virtual bool operator==(const char *sku) const = 0;

        virtual double total_cost() const = 0;

        virtual int qtyNeeded() const = 0;

        virtual int qtyAvailable() const = 0;

        virtual const char *name() const = 0;

        virtual int operator+=(int qty) = 0;

        virtual bool operator>(const iProduct &) const = 0;

        virtual ~iProduct() {};
    };
}



#endif //MS4_IPRODUCT_H
