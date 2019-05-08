/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 3
 * March 22 2019
 * Section A
 * */


#ifndef MS3_PRODUCT_H
#define MS3_PRODUCT_H

#include <iostream>
#include "ErrorState.h"

namespace ama {

    const int max_length_label = 30;
    const int max_length_sku = 7;
    const int max_length_name = 75;
    const int max_length_unit = 10;
    const int write_condensed = 0;
    const int write_table = 1;
    const int write_human = 2;
    const double tax_rate = 0.13;

    class Product {
        char productType;
        char productSku[max_length_sku + 1];
        char productUnit[max_length_unit + 1];
        char *productName;
        int productHand;
        int productNeed;
        double priceBefore;
        double priceTax;
        bool taxable;
        ErrorState errObject;

        //////////////////////////////////////////




        void name(const char *);

        void setdData(const char *SKU, const char *name, const char *unit, double price, int qntityNeeded, int qntityOnHand,bool taxStatus);

    protected:
        void message(const char *pText);

        bool isClear() const;

    public:
        Product(char p_productType = 'N');

        Product(const char *pSku, const char *p_name, const char *p_unit, double p_pricebefore = 0.0,
                int p_qtyneeed = 0, int p_qtyhand = 0, bool tax = true);

        Product(const Product &p_prod);

        ~Product();

        /////
        Product &operator=(const Product &);

        int operator+=(int cnt);

        bool operator==(const char* sku) const;

        bool operator>(const char* sku) const;

        bool operator>(const Product &) const;

        int qtyAvailable() const;

        int qtyNeeded() const;

        double total_cost() const;

        bool isEmpty() const;

        ///
        std::istream &read(std::istream &in, bool interractive);

        std::ostream &write(std::ostream &out, int writeMode) const;

    };
}
#endif //MS3_PRODUCT_H
