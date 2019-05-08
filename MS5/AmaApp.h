/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */

#ifndef MS5_AMAAPP_H
#define MS5_AMAAPP_H

#include "iProduct.h"
#include "Utilities.h"

namespace ama {

    class AmaApp {
        char m_filename[256];

        iProduct* m_products[100];
        int m_noOfProducts;

        void pause() const;
        int menu() const;

        void loadProductRecords();

        void saveProductRecords() const;
        void listProducts() const;

        void addQty(iProduct* product);

        void addProduct(char tag);
        iProduct* find(const char* sku) const;

    public:
        int run();
        AmaApp(const char*);
        ~AmaApp();

        //fer

    };

}
#endif //MS5_AMAAPP_H
