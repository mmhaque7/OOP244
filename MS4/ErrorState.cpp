/*
 * Mehedi Haque
 * 154908172
 * Milestone 2
 * March 17 2019
 * Section A
 * */
#include <iostream>
#include <cstring>
#include "ErrorState.h"


namespace ama {

    ///helps initiliziling the data members for the default constructor and elsewhere
    void ErrorState::setData(const char *errorMessage) {
        int count = 0;
        if (errorMessage == nullptr || errorMessage[0] == '\0') {
            msgError = nullptr;
        } else {
            //checking the string in ErrorMessage
            for (int i = 0; errorMessage[i] != '\0'; i++) {
                count++;
            }
            msgError = new char[count + 1];
            strncpy(msgError, errorMessage, count);
            msgError[count] = '\0';

        }

    }

    //this function helps with clearing memory when called.
    void ErrorState::clear() {
        delete[] msgError;
        msgError = nullptr;
    }


    //default constructor
    ErrorState::ErrorState(const char *errorMessage) {
        setData(errorMessage);
    }

    //destructor-->deallocate  the memory
    ErrorState::~ErrorState() {
        delete[] msgError;
        msgError = nullptr;
    }

    ///this function return true if the current instance is storing a valid message
    ErrorState::operator bool() const {

        bool flag = false;
        if(msgError!= nullptr){
            flag = true;
        }
        return flag;
    }

    //Stores a copy the text received in the parameter
    ErrorState &ErrorState::operator=(const char *pText) {
        message(pText);
        return *this;
    }

    //this query returns the address of the message stored in the current object
    const char *ErrorState::message() const {
        return *this ? msgError: nullptr;
    }





    //stores a copy the text received in the parameter.
    void ErrorState::message(const char* pText) {
        clear();
        setData(pText);
    }


    ////os helper function
    std::ostream &operator<<(std::ostream &os, const ErrorState &err) {

        if (err) {
            os << err.message();
        }

        return os;
    }
}