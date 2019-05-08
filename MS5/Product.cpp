/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Product.h"
#include "ErrorState.h"



using namespace std;

namespace ama {
    Product::Product(char type) : productType(type) {
        m_sku[0] = '\0';
        units[0] = '\0';

        names[0] = '\0';
        quantHave= 0;
        quantNeed = 0;
        prices = 0.0;
        taxed = true;
    }

    Product &Product::operator=(const Product& prod) {
        if (this != &prod) {
            strncpy(m_sku, prod.m_sku, max_length_sku);
            m_sku[max_length_sku] = '\0';
            strncpy(names, prod.names, max_length_name);
            names[max_length_name] = '\0';

            strncpy(units, prod.units, max_length_unit);
            units[max_length_unit] = '\0';
            quantHave = prod.quantHave;
            quantNeed = prod.quantNeed;
            prices = prod.prices;
            taxed = prod.taxed;
            error.message(prod.error.message());
        }
        return *this;
    }


    Product::Product(const char* mySku, const char* addressPtr, const char* unit, double pricebfTax, int qntyNeeded, int qntyOnHand, bool taxable) {
        strncpy(m_sku, mySku, max_length_sku);
        m_sku[max_length_sku] = '\0';
        strncpy(names, addressPtr, max_length_name);
        names[max_length_name] = '\0';

        strncpy(units, unit, max_length_unit);
        units[max_length_unit] = '\0';

        quantHave= qntyOnHand;
        quantNeed = qntyNeeded;
        prices = pricebfTax;
        taxed = taxable;
    }

    Product::~Product() {}

    Product::Product(const Product& prod) : productType('N') {
        prod.name();
        strncpy(m_sku, prod.m_sku, max_length_sku);
        m_sku[max_length_sku] = '\0';
        strncpy(units, prod.units, max_length_unit);
        units[max_length_unit] = '\0';

        quantHave= prod.quantHave;
        quantNeed = prod.quantNeed;

        prices = prod.prices;
        taxed = prod.taxed;
        error.message(prod.error.message());
    }


    const char* Product::name() const {
        return (names[0] == '\0' || names == nullptr) ? nullptr : names;
    }

    void Product::message(const char* pText) {
        error = pText;
    }

    bool Product::isClear() const {
        return (error.message() == nullptr) ? true : false;
    }

    double Product::total_cost() const {
        double total;
        if (taxed) {


            total = prices * (1 + tax_rate);
        }
        else {


            total = prices;
        }
        return static_cast<double>(quantHave* total);
    }

    int Product::qtyAvailable() const {
        return quantHave;
    }

    int Product::operator+=(int cnt) {
        return cnt > 0 ? quantHave += cnt : quantHave;
    }

    bool Product::operator==(const char* sku) const {
        return (strcmp(m_sku, sku) == 0) ? true : false;
    }

    bool Product::operator>(const char* sku) const {
        return (strcmp(m_sku, sku) > 0) ? true : false;
    }

    bool Product::operator>(const iProduct& prod) const {
        return (strcmp(name(), prod.name()) > 0) ? true : false;
    }


    int Product::qtyNeeded() const {
        return quantNeed;
    }

    bool Product::isEmpty() const {
        return (names[0] == '\0') ? true : false;
    }




    std::istream& Product::read(std::istream& in, bool interractive) {
        if (interractive) {
            char input[max_length_label];

            cout.setf(ios::right);
            cout.width(max_length_label);

            cout << "Sku: ";
            in.getline(m_sku, max_length_sku);
            cout.width(max_length_label);

            cout << "Name (no spaces): ";
            in.getline(names, max_length_name);
            cout.width(max_length_label);

            cout << "Unit: ";
            in.getline(units, max_length_unit);
            cout.width(max_length_label);

            cout << "Taxed? (y/n): ";
            in >> input;
            if (input[0] == 'y' || input[0] == 'Y') {
                taxed = true;
            }
            else if (input[0] == 'n' || input[0] == 'N') {
                taxed = false;
            }
            if (input[0] != 'Y' && input[0] != 'y' && input[0] != 'N' && input[0] != 'n') {
                in.setstate(ios::failbit);
                message("Only (Y)es or (N)o are acceptable!\n");
            }
            else {
                cout.width(max_length_label);
                cout << "Price: ";
                in >> prices;
                if (prices <= 0.0) {
                    in.setstate(ios::failbit);
                    message("Invalid Price Entry!\n");
                }
                else {
                    cout.width(max_length_label);
                    cout << "Quantity on hand: ";
                    in >> quantHave;
                    if (qtyAvailable() <= 0) {
                        in.setstate(ios::failbit);
                        message("Invalid Quantity Available Entry!\n");
                    }
                    else {
                        cout.width(max_length_label);
                        cout << "Quantity needed: ";
                        in >> quantNeed;
                        if (qtyNeeded() <= 0) {
                            in.setstate(ios::failbit);
                            message("Invalid Quantity Needed Entry!\n");
                        }
                    }
                }
            }
        }
        else {
            in.getline(m_sku, max_length_sku, ',');
            in.getline(names, max_length_name, ',');
            in.getline(units, max_length_unit, ',');
            in >> prices;
            in.ignore();
            in >> taxed;
            in.ignore();
            in >> quantHave;
            in.ignore();
            in >> quantNeed;
        }



        in.ignore();
        return in;
    }


    std::ostream& Product::write(std::ostream& os, int writeMode) const {
        if (!isClear()) {


            os << error.message();
        }
        else if (isEmpty()) {
        }
        else if (writeMode == write_table) {
            os << " ";
            os.width(max_length_sku);
            os.setf(ios::right);
            os <<m_sku << " | ";
            os.unsetf(ios::right);

            os.setf(ios::left);

            if (strlen(names) > 16) {


                char temp[max_length_name] = { '\0' };
                os.width(13);
                strncpy(temp, names, 13);
                os << temp << "..." << " | ";
            }
            else {
                os.width(16);
                os << names << " | ";
            }


            os.unsetf(ios::left);
            os.width(10);
            os.setf(ios::left);
            os << units << " | ";
            os.unsetf(ios::left);
            os.width(7);
            os.setf(ios::right);
            os << std::fixed;
            os.precision(2);
            os << prices << " | ";
            os.unsetf(ios::right);
            os.width(3);
            os.setf(ios::right);
            os << (taxed ? "yes" : "no") << " | ";
            os.unsetf(ios::right);
            os.width(6);
            os.setf(ios::right);
            os << quantHave << " | ";
            os.unsetf(ios::right);
            os.width(6);
            os.setf(ios::right);
            os << quantNeed << " |";
        }
        else if (writeMode == write_human) {
            os.width(max_length_label);
            os.setf(ios::right);
            os << "Sku: " <<m_sku << endl;

            os.width(max_length_label);
            os.setf(ios::right);
            os << "Name: " << names << endl;
            os.width(max_length_label);
            os.setf(ios::right);
            os.setf(ios::fixed);
            os.precision(2);
            os << "Price: " << prices << endl;
            if (taxed) {


                os.width(max_length_label);
                os.setf(ios::right);
                os.setf(ios::fixed);
                os.precision(2);
                os << "Price after Tax: " << prices * (1 + tax_rate) << endl;
            }
            else {


                os.width(max_length_label);
                os.setf(ios::right);
                os.setf(ios::fixed);
                os.precision(2);
                os << "Price after Tax: " << prices << endl;
            }



            os.width(max_length_label);
            os.setf(ios::right);
            os << "Quantity Available: " << quantHave << " " << units << endl;
            os.width(max_length_label);
            os.setf(ios::right);
            os << "Quantity Needed: " << quantNeed << " " << units << endl;
        }
        else if (writeMode == write_condensed) {
            os << productType << "," <<m_sku << ","
               << names << "," << units << ","
               << prices << "," << taxed << ","
               << quantHave << "," << quantNeed;
        }
        return os;
    }

}





