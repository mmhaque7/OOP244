/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <iomanip>
#include "AmaApp.h"

using namespace std;



namespace ama {

    int AmaApp::menu() const {
        int choice;
        cout << "Disaster Aid Supply Management Program" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1- List products" << endl;
        cout << "2- Search product" << endl;
        cout << "3- Add non-perishable product" << endl;
        cout << "4- Add perishable product" << endl;
        cout << "5- Add to product quantity" << endl;
        cout << "6- Delete product" << endl;
        cout << "7- Sort products" << endl;
        cout << "0- Exit program" << endl;
        cout << "> ";
        cin >> choice;
        cin.ignore(2000, '\n');

        if (choice >= 0 && choice <= 7) {
            return choice;
        }
        else
        {
            return -1;
        }
    }




    void AmaApp::pause() const {
        cout << "Press Enter to continue...";
        cout << endl;
        cin.ignore(2000, '\n');
    }


    void AmaApp::addQty(iProduct* prod) {
        int num;
        prod->write(cout, write_human);
        cout << endl << endl << "Please enter the number of purchased items: ";
        cin >> num;
        if (!cin.fail()) {
            if (num <= (prod->qtyNeeded() - prod->qtyAvailable())) {
                *prod += num;
                saveProductRecords();
            }
            else
            {
                cout << "Too many items; only " << (prod->qtyNeeded() - prod->qtyAvailable()) << " is needed. Please return the extra " << (num - (prod->qtyNeeded() - prod->qtyAvailable())) << " items." << endl;
                *prod += (prod->qtyNeeded() - prod->qtyAvailable());
            }

            cout << endl << "Updated!" << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "Invalid quantity value!" << endl;
        }
    }



    AmaApp::AmaApp(const char* file) {
        strcpy(m_filename, file);
        for (int i = 0; i < 99; i++) {
            m_products[i] = nullptr;
        }
        m_noOfProducts = 0;
        loadProductRecords();
    }


    void AmaApp::loadProductRecords() {

        int index = 0;
        char tag;

        for (int i = 0; i < 100; i++) {

            if (m_products[i] != nullptr) {
                delete m_products[i];
            }
        }



        fstream input(m_filename, ios::in);


        if (input) {
            do {
                input >> tag;
                if (input) {
                    iProduct* prod = createInstance(tag);

                    if (prod != nullptr) {
                        m_products[index] = prod;
                        input.get();
                        prod->read(input, false);
                        index++;
                    }

                }
            } while (input);
            {
                m_noOfProducts = index;
                input.close();
            }
        }
        else
        {
            fstream fout(m_filename, ios::out);
            fout.close();
        }

    }

    void AmaApp::saveProductRecords() const {
        ofstream output(m_filename, ios::out);
        if (output) {
            for (int i = 0; i < m_noOfProducts; i++) {
                if (m_products[i] != nullptr) {
                    m_products[i]->write(output, write_condensed);
                    output << endl;
                }

            }

        }


        output.close();
    }

    void AmaApp::listProducts() const {
        double tot = 0;
        cout << "------------------------------------------------------------------------------------------------" << endl
             << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl
             << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

        for (int i = 0; i < m_noOfProducts; i++) {
            if (m_products[i] != nullptr) {
                cout << "|";
                cout.width(4);
                cout << i + 1 << " |";
                m_products[i]->write(cout, write_table);
                cout << endl;
                tot += *m_products[i];
            }
        }
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|";
        cout.width(82);
        cout << "Total cost of support ($): |";
        cout.width(11);
        cout.setf(ios::right);
        cout.precision(2);
        cout << tot << " |" << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;

    }


    void AmaApp::addProduct(char tag) {
        if (m_noOfProducts < 99) {
            m_products[m_noOfProducts] = createInstance(tag);

            if (m_products[m_noOfProducts] != nullptr) {
                cin >> *m_products[m_noOfProducts];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(2000, '\n');

                    cout << endl << *m_products[m_noOfProducts];

                    delete m_products[m_noOfProducts];
                    m_products[m_noOfProducts] = nullptr;

                }
                else
                {
                    m_noOfProducts++;
                    saveProductRecords();
                    cout << endl << "Success!" << endl;
                }

            }
        }


    }


    iProduct* AmaApp::find(const char* sku) const {
        bool TF = false;
        iProduct* prood = nullptr;

        for (int i = 0; i < m_noOfProducts && !TF; i++) {
            if (*m_products[i] == sku) {
                TF = true;
                prood = m_products[i];
            }
        }

        return prood;

    }

    int AmaApp::run() {
        int choice;
        iProduct* temp = nullptr;
        char sku[max_length_sku] = { '\0' };

        do {
            choice = menu();

            switch (choice) {
                case 1:
                    listProducts();
                    cout << endl;
                    pause();
                    break;
                case 2:
                    cout << "Please enter the product SKU: ";
                    cin.get(sku, max_length_sku - 1, '\n');


                    if (char(cin.get()) == '\n') {
                temp = find(sku);
                if (temp != nullptr) {
                    cout << endl;
                    temp->write(cout, write_human);
                    temp = nullptr;
                    cout << endl;
                }
                else {
                    cout << endl << "No such product!" << endl;
                }


            }
                    else {
                cout << endl << "Invalid SKU!" << endl;
            }
                    pause();
                    break;

                case 3:
                    addProduct('N');
                    loadProductRecords();
                    cout << endl;
                    break;

                case 4:
                    addProduct('P');
                    loadProductRecords();
                    cout << endl;
                    break;

                case 5:
                    cout << "Please enter the product SKU: ";

                    cin.get(sku, max_length_sku - 1, '\n');


                    if (char(cin.get()) == '\n') {
                temp = find(sku);
                if (temp != nullptr) {
                    cout << endl;
                    addQty(temp);
                }
                else {
                    cout << endl << "No such product!" << endl;
                }


            }
                    else {

                cout << endl << "Invalid SKU!" << endl;
            }
                    cout << endl;
                    break;

                case 0:
                    cout << "Goodbye!" << endl;
                    break;

                default:
                    cout << "~~~Invalid selection, try again!~~~" << endl;
                    pause();
                    break;

            }


        } while (choice != 0);
        return 0;
    }


    AmaApp::~AmaApp() {
        for (int i = 0; i < 99; i++) {
            delete m_products[i];
            m_products[i] = nullptr;
        }
    }

}