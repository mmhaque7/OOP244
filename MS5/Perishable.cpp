/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */
#include <iomanip>
#include <iostream>

#include "Perishable.h"

using namespace std;

namespace ama {
    Perishable::Perishable() : Product('P') {


    }

    std::ostream& Perishable::write(std::ostream& os, int writeMode) const {
        Product::write(os, writeMode);
        if (date.isGood() && !isEmpty()) {
            if (writeMode == write_human) {
                os << setw(max_length_label) << right << "Expiry Date: " << date << endl;
            }
            else if (writeMode == write_table) {
                os << " " << date << " |";
            }
            else if (writeMode == write_condensed){
                os << "," << date;
            }
        }
        return os;
    }

    std::istream& Perishable::read(std::istream& in, bool interact) {
        in.clear();
        Product::read(in, interact);

        if (interact) {
            cout << setw(max_length_label) << right << "Expiry date (YYYY/MM/DD): ";
            in >> date;
            if (date.status() != no_error) {
                in.setstate(std::ios::failbit);
                if (date.status() == error_year) {
                    message("Invalid Year in Date Entry\n");
                }
                else if (date.status() == error_day) {
                    message("Invalid Day in Date Entry\n");
                }
                else if (date.status() == error_mon) {
                    message("Invalid Month in Date Entry\n");
                }
                else
                {
                    message("Invalid Date Entry\n");
                }

            }
        }
        else
        {
            date.read(in);
            in.ignore(2000, '\n');
        }
        return in;
    }

}