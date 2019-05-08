/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */

#ifndef MS1_DATE_H
#define MS1_DATE_H

#include <iostream>

namespace ama {
    const int min_year = 2019;
    const int max_year = 2028;
    const int no_error = 0;
    const int error_year = 1;
    const int error_mon = 2;
    const int error_day = 3;
    const int error_invalid_operation = 4;
    const int error_input = 5;

    class Date {
    private:
        int m_year;
        int m_month;
        int m_day;

        int ErrorStatus;

        int mdays(int year, int mon) const;
        void isValid(int, int, int);
        void status(int newStatus);



    public:
        Date();

        Date(int year, int month, int day);

        int status() const;

        void clearError();

        bool isGood() const ;

        //operator
        Date &operator+=(int days);

        Date &operator++();

        Date operator++(int);

        Date operator+(int days) const ;

        bool operator==(const Date& rhs) const;

        bool operator!=(const Date& rhs) const;

        bool operator<(const Date& rhs) const;

        bool operator>(const Date& rhs) const;

        bool operator<=(const Date& rhs) const;

        bool operator>=(const Date& rhs) const;

        //istream and ostream
        std::istream& read(std::istream& is);
        std::ostream& write(std::ostream& os) const;
    };

//helper functions
    std::ostream& operator << (std::ostream&, const Date& date);
    std::istream& operator >> (std::istream&, Date& date);

}
#endif //MS1_DATE_H
