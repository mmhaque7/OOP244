/*
 * Mehedi Haque
 * 154908172
 * March 14, 2019
 * Milestone 1
 * section A
 * */
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;
namespace ama {
    //mdays function
    int Date::mdays(int year, int mon) const {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    //This function sets the status of the date object to the value of the parameter.
    void Date::status(int newStatus) {
        ErrorStatus = newStatus;
    }

    //isGood returns true if all the year, month and dates are valid.
    bool Date::isGood() const {
        bool flag = false;
        if (m_year != 0 && m_month != 0 && m_day != 0 && status() == no_error) {
            flag = true;
        }
        return flag;


    }
///isValid checks the data is valid and halps initilize the data members of the object

    void Date::isValid(int year, int month, int day) {
        if (year >= min_year && year <= max_year) {
            m_year = year;
            if (month >= 1 && month <= 12) {
                m_month = month;
                if (day >= 1 && day <= mdays(m_year, m_month)) {
                    m_day = day;
                    status(no_error);
                } else {
                    m_year = 0;
                    m_month = 0;
                    m_day = 0;
                    status(error_day);
                }
            } else {
                m_year = 0;
                m_month = 0;
                m_day = 0;
                status(error_mon);
            }
        } else {
            m_year = 0;
            m_month = 0;
            m_day = 0;
            status(error_year);
        }
    }


//default constructor set to  empty state
    Date::Date() {
        m_year = 00;
        m_month = 00;
        m_day = 00;
        status(no_error);

    }

//constructor with 3 parameters
    Date::Date(int year, int month, int day) {
        isValid(year, month, day);

    }

    //A query that returns an integer representing the status of the current object.
    int Date::status() const {
        return ErrorStatus;
    }


    //A modifier that resets the status of an object to no_error. This function should not update the date stored in the object.
    //This function should return nothing.
    void Date::clearError() {
        status(no_error);
        //ErrorStatus = no_error;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //    A modifier that adds to the date stored by the object the number of days specified in the parameter.
    Date &Date::operator+=(int days) {
        if (isGood()) {
            if (((m_day + days) >= 1) && ((m_day + days) <= mdays(m_year, m_month))) {
                m_day += days;
            } else {
                status(error_invalid_operation);
            }
        } else {
            status(error_invalid_operation);
        }
        return *this;
    }

    //A modifier that adds one day to the date stored by the object (prefix).
    Date &Date::operator++() {

        (*this) += 1;
        return *this;


    }

    //A modifier that adds one day to the date stored by the object (postfix).
    Date Date::operator++(int) {
        Date daynew = *this;

        ++(*this);

        return daynew;
    }

    Date Date::operator+(int days) const {
        Date daynew;

        if (!isGood() && ((m_day + days) < 1) && ((m_day + days) > mdays(m_year, m_month))) {
            daynew = *this;
            daynew.status(error_invalid_operation);
        } else {
            daynew = *this;
            daynew += days;
        }
        return daynew;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////
    bool Date::operator==(const ama::Date &rhs) const {
        bool flag = false;
        flag = m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day;
        return flag;
    }

    bool Date::operator!=(const ama::Date &rhs) const {
        bool flag = false;
        flag = !(*this == rhs);

        return flag;

    }

    bool Date::operator<(const ama::Date &rhs) const {
        bool flag = false;
        if (m_year < rhs.m_year) {
            flag = true;
        } else if (m_year == rhs.m_year) {
            if (m_month < rhs.m_month) {
                flag = true;
            } else if (m_month == rhs.m_month) {
                if (m_day < rhs.m_day) {
                    flag = true;
                }
            }

        }
        return flag;
    }

    bool Date::operator>(const Date &rhs) const {
        bool flag = false;
        if (m_year > rhs.m_year) {
            flag = true;
        } else if (m_year == rhs.m_year) {
            if (m_month > rhs.m_month) {
                flag = true;
            } else if (m_month == rhs.m_month) {
                if (m_day > rhs.m_day) {
                    flag = true;
                }
            }

        }
        return flag;
    }

    bool Date::operator<=(const Date &rhs) const {
        return ((*this < rhs) || (*this == rhs));
    }

    bool Date::operator>=(const Date &rhs) const {
        return ((*this > rhs) || (*this == rhs));
    }


////////////////////////////////////////////////////////////////////////////////////////////
    std::istream &Date::read(std::istream &is) {

        char slash = '/';
        is.clear();

        is >> m_year >> slash >> m_month >> slash >> m_day;

        if (is.fail()) {
            isValid(00, 00, 00);
            status(error_input);
        } else {
            isValid(m_year, m_month, m_day);
        }


        return is;


    }

    std::ostream &Date::write(std::ostream &os) const {

        if (m_year != 0 && m_month != 0 && m_day != 0) {

            if (m_month < 10 && m_day < 10) {
                os << m_year << "/" << "0" << m_month << "/" << "0" << m_day;
            } else if (m_month < 10 && m_day >= 10) {
                os << m_year << "/" << "0" << m_month << "/" << m_day;
            } else if (m_month >= 10 && m_day < 10) {
                os << m_year << "/" << m_month << "/" << "0" << m_day;
            } else {
                os << m_year << '/' << m_month << '/' << m_day;
            }
        } else {
            os << "0000" << "/" << "00" << "/" << "00";
        }

        return os;
    }


    std::ostream &operator<<(std::ostream &os, const Date &date) {
        date.write(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Date &date) {
        date.read(is);
        return is;
    }

}
