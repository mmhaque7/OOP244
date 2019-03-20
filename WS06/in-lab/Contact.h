/* Md Mehedi Haque
 * 154908172
 * March 5 2019
 * Workshop 6 in-lab*/

#ifndef PROJECT_CONTACT_H
#define PROJECT_CONTACT_H

namespace  sict{
    const int max_name_size = 16;
    class Contact{
    private:
        char p_name[max_name_size];
        long long* p_phone = nullptr;
        int numPhone = 0;
    public:
        Contact();
        Contact(const char*, const long long*, int);
        ~Contact();
        bool isEmpty() const;
        void display() const;
    };
}

#endif //PROJECT_CONTACT_H
