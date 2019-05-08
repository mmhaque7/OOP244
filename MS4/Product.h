/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 4
 * March 22 2019
 * Section A
 * */


#ifndef MS3_PRODUCT_H
#define MS3_PRODUCT_H

#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"

namespace ama {

    /*const int max_length_label = 30;
    const int max_length_sku = 7;
    const int max_length_name = 75;
    const int max_length_unit = 10;
    const int write_condensed = 0;
    const int write_table = 1;
    const int write_human = 2;
    const double tax_rate = 0.13;*/

    class Product : public iProduct {
        char productType;
        char productSku[max_length_sku + 1];
        char productUnit[max_length_unit + 1];
        char productName[max_length_name + 1];
        int productHand;
        int productNeed;
        double priceBefore;
        bool taxable;
        ErrorState errObject;

void setData(const char* sku, const char* name, const char* unit, double price, int qtyNeeded, int qtyhand, bool tax );

    public:
        Product():productType('N'){};

        bool operator==(const char *sku) const;

        double total_cost() const;

        int qtyNeeded() const;

        int qtyAvailable() const;

        const char *name() const;

        int operator+=(int qty);

        bool operator>(const iProduct &) const;


        ///
        std::istream &read(std::istream &in, bool interractive);

        std::ostream &write(std::ostream &out, int writeMode) const;

    };
}
#endif //MS3_PRODUCT_H
