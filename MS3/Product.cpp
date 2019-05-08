/*
 * Md Mehedi Haque
 * 154908172
 * Milestone 3
 * March 22 2019
 * Section A
 * */
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Product.h"
#include "ErrorState.h"

namespace ama {
    Product::Product(char p_productType) :productType(p_productType){
        setdData(nullptr, nullptr, nullptr, 0, 0, 0, false);

    }
    Product::Product(const char* pSku, const char* p_name, const char* p_unit, double p_pricebefore,
                     int p_qtyneeed, int p_qtyhand, bool tax):productType('N') {
        setdData(pSku,p_name,p_unit,p_pricebefore,p_qtyneeed,p_qtyhand,tax);

    }
    void Product::setdData(const char* pSku, const char* p_name, const char* unit, double pricebefore, int qtyneeded,
                           int qtyonHand, bool tax) {

        if(p_name != nullptr && p_name[0]!= '\0'){
            name(p_name);

            strncpy(productSku, pSku, max_length_sku);
            productSku[max_length_sku] = '\0';

            strncpy(productUnit, unit, max_length_unit);
            productUnit[max_length_unit] = '\0';

            priceBefore = pricebefore;
            productHand = qtyonHand;
            productNeed = qtyneeded;
            taxable = tax;

        }else{
            productName = nullptr;
            priceBefore = 0;
            productNeed = 0;
            productHand = 0;
            taxable = false;
            strncpy(productSku,"\0", max_length_sku);
            strncpy(productUnit,"\0", max_length_unit);
        }
    }
    void Product::message(const char* pText) {
        errObject.message(pText);
    }



    Product::Product(const ama::Product& prod):productType('N') {
        setdData(prod.productSku,prod.productName,prod.productUnit,prod.priceBefore,
                 prod.productNeed,prod.productHand,prod.taxable);

    }

    Product::~Product() {
        delete[] productName;
        productName = nullptr;
    }

/////////////////////////////////////////////////////////////////////////////////
    Product &Product::operator=(const ama::Product& prod) {

        if(this != &prod) {
            productType = prod.productType;

            name(prod.productName);

            strncpy(productSku, prod.productSku, max_length_sku);
            productSku[max_length_sku] = '\0';

            strncpy(productUnit, prod.productUnit, max_length_unit);
            productUnit[max_length_unit] = '\0';

            priceBefore = prod.priceBefore;
            productHand = prod.productHand;
            productNeed = prod.productNeed;
            taxable = prod.taxable;
        }
        return *this;
    }

    bool Product::operator==(const char *sku) const {
        return strcmp(productSku, sku) == 0;

    }

    int Product::operator+=(int cnt) {
        if (cnt > 0){
            productHand += cnt; }
        return productHand;
    }

    bool Product::operator>(const char *sku) const {
        return strcmp(productSku, sku) > 0;
    }

    bool Product::operator>(const ama::Product &p_prod) const {
        if (strcmp(productName, p_prod.productName) > 0) {
            return true;
        } else {
            return false;
        }
    }

    int Product::qtyAvailable() const {
        return productHand;

    }

    int Product::qtyNeeded() const {
        return productNeed;
    }

    double Product::total_cost() const {
        return  taxable == true ? ( productHand * priceBefore) * (1.00 + tax_rate) :  productHand * priceBefore;
    }

    bool Product::isEmpty() const {
        if (productName == nullptr) {
            return true;
        } else {
            return false;
        }
    }




    void Product::name(const char *p_prodName) {
        if (p_prodName != nullptr) {
            int i;
            // Find number of characters in string
            for (i = 0; p_prodName[i] != '\0' || i <= max_length_name; i++);

            productName = new char[i + 1];

            strncpy(productName, p_prodName, i);
            productName[i] = '\0';
        } else {
            delete[] productName;
        }
    }




    bool Product::isClear() const {
        return errObject;
    }
    std::istream& Product::read(std::istream& in, bool interractive) {

        char SKU[max_length_sku + 1];
        char name[max_length_name + 1];
        char unit[max_length_unit + 1];
        double price ;
        int qntityNeeded ;
        int qntityOnHand ;
        bool taxStatus = false;
        char yesOrNo;
        char singleChar;

        in.clear();

        if (!interractive) {

            in.getline(SKU, max_length_unit, ',');
            in.getline(name, max_length_name, ',');
            in.getline(unit, max_length_unit, ',');
            in >> price >> singleChar;
            in >> taxStatus >> singleChar;
            in >> qntityOnHand >> singleChar;
            in >> qntityNeeded;

            if (in.fail() != 0) {

                in.ignore(2000, '\n');
                setdData(nullptr, nullptr, nullptr, 0, 0, 0, false);
            }
            else {
                setdData(SKU, name, unit, price, qntityNeeded, qntityOnHand, taxStatus);
            }
        }
        else {

            int i = 1;

            do {

                if (i == 1) {
                    std::cout << std::right << std::setw(max_length_label) << "Sku: ";
                    in >> SKU;
                }
                else if (i == 2) {
                    std::cout << std::right << std::setw(max_length_label) << "Name (no spaces): ";
                    in >> name;
                }
                else if (i == 3) {
                    std::cout << std::right << std::setw(max_length_label) << "Unit: ";
                    in >> unit;
                }
                else if (i == 4) {
                    std::cout << std::right << std::setw(max_length_label) << "Taxed? (y/n): ";

                    in >> yesOrNo;

                    if (yesOrNo == 'y' || yesOrNo == 'Y') {
                        taxStatus = true;
                    }
                    else if (yesOrNo == 'n' || yesOrNo == 'N') {
                        taxStatus = false;
                    }
                    else {
                        in.setstate(std::ios::failbit);
                        taxStatus = false;
                    }
                }
                else if (i == 5) {
                    std::cout << std::right << std::setw(max_length_label) << "Price: ";
                    in >> price;
                }
                else if (i == 6) {
                    std::cout << std::right << std::setw(max_length_label) << "Quantity on hand: ";
                    in >> qntityOnHand;
                }
                else if (i == 7) {
                    std::cout << std::right << std::setw(max_length_label) << "Quantity needed: ";
                    in >> qntityNeeded;
                }

                if (in.fail() == 0) { ++i; }

            } while (i <= 7 && in.fail() == 0);


            if (in.fail() != 0) {

                if (i == 4) {
                    errObject.message("Only (Y)es or (N)o are acceptable!");
                }
                else if (i == 5) {
                    errObject.message("Invalid Price Entry!");
                }
                else if (i == 6) {
                    errObject.message("Invalid Quantity Available Entry!");
                }
                else if (i == 7) {
                    errObject.message("Invalid Quantity Needed Entry!");
                }

                in.ignore(2000, '\n');
                setdData(nullptr, nullptr, nullptr, 0, 0, 0, false);
            }
            else {
                setdData(SKU, name, unit, price, qntityNeeded, qntityOnHand, taxStatus);
            }
        }

        return in;
    }
    std::ostream& Product::write(std::ostream& out, int writeMode) const {

        if (errObject) {
            out << errObject;
        }
        else if (!isEmpty()) {

            if (writeMode == write_condensed) {

                out << productType << ",";
                out << productSku << ",";
                out << productName << ",";
                out << productUnit << ",";
                out << std::fixed << std::setprecision(2) << priceBefore <<  ",";
                out << (taxable == true ? 1 : 0) << ",";
                out << productHand << ",";
                out << productNeed/* << std::endl */;
            }
            else if (writeMode == write_table) {

                out << " " << std::right << std::setw(max_length_sku) << productSku << " " << "|";

                if (strlen(productName) <= 16) {
                    out << " " << std::left << std::setw(16) << productName << " " << "|";
                }
                else {

                    char tempName[16 + 1];
                    strncpy(tempName, productName, 13);
                    tempName[13] = '\0';
                    strcat(tempName, "...");
                    tempName[16] = '\0';

                    out << " " << std::left << std::setw(16) << tempName << " " << "|";
                }

                out << " " << std::left << std::setw(10) << productUnit << " " << "|";
                out << " " << std::right << std::setw(7) << std::fixed << std::setprecision(2) << priceBefore << " " << "|";
                out << " " << std::right << std::setw(3) << (taxable == true ? "yes" : "no") << " " << "|";
                out << " " << std::right << std::setw(6) << productHand << " " << "|";
                out << " " << std::right << std::setw(6) << productNeed << " " << "|";
            }
            else if (writeMode == write_human) {

                out << std::right << std::setw(max_length_label) << "Sku: " << productSku << std::endl;
                out << std::right << std::setw(max_length_label) << "Name: " << productName << std::endl;
                out << std::right << std::setw(max_length_label) << "Price: " << std::fixed << std::setprecision(2) << priceBefore <<  std::endl;
                out << std::right << std::setw(max_length_label) << "Price after Tax: " << std::fixed << std::setprecision(2) << (taxable == true ? (double)(priceBefore * (1.00 + tax_rate)) : priceBefore) <<  std::endl;
                out << std::right << std::setw(max_length_label) << "Quantity Available: " << productHand << " " << productUnit << std::endl;
                out << std::right << std::setw(max_length_label) << "Quantity Needed: " << productNeed << " " << productUnit << std::endl;
            }
        }

        return out;
    }


}
