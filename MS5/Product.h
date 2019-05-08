/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <fstream>
#include <limits>
#include "ErrorState.h"
#include "iProduct.h"


namespace ama {
    class Product : public iProduct {
    private:

        char m_sku[max_length_sku + 1];
        char units[max_length_unit + 1];
        char names[max_length_name];



        int quantHave;
        int quantNeed;
        char productType;
        double prices;
        bool taxed;
        char tax;


        ErrorState error;

    protected:

        bool isClear() const;
        void message(const char* pText);

    public:



        Product(const char* sku, const char* name, const char* unit, double price = 0.0, int qtyN = 0, int qtyH = 0, bool tax = true);

        //const
        Product(char = 'N');


        Product(const Product&);

        Product& operator=(const Product&);



        bool operator>(const iProduct& prod) const;
        bool operator==(const char* sku) const;
        bool operator>(const char* sku) const;
        int operator+=(int cnt);

        int qtyAvailable() const;
        int qtyNeeded() const;
        double total_cost() const;


        bool isEmpty() const;
        const char* name() const;


        std::istream& read(std::istream& in, bool interractive);
        std::ostream& write(std::ostream& os, int writeMode) const;

        ~Product();
    };
    iProduct* createInstance(char tag);
}
#endif







