/*
 * Mehedi Haque
 * 154908172
 * Milestone 5
 * April 8 2019
 * Section A
 * */
#ifndef MS2_ERRORSTATE_H
#define MS2_ERRORSTATE_H

#include <iostream>

namespace ama {
    class ErrorState {
        char *msgError;

        void clear();
        void setData(const char* errorMessage);

    public:
        explicit ErrorState(const char *errorMessage = nullptr);

        ErrorState(const ErrorState &em) = delete;

        ErrorState &operator=(const ErrorState &other) = delete;

        ~ErrorState();

        operator bool() const;

        ErrorState &operator=(const char *pText);

        void message(const char *pText);

        const char *message() const;
    };

    std::ostream &operator<<(std::ostream &, const ErrorState &);

}

#endif //MS2_ERRORSTATE_H
