/* Md Mehedi Haque
 * 154908172
 * March 5 2019
 * Workshop 6 in-lab*/
#include "Contact.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using  namespace std;
namespace sict{

    Contact::Contact() {
        p_name[0] = '\0';
    }
    Contact::Contact(const char *name, const long long *phoneNumber, int numPh) {
    //set country code, area code and actual number!
    int countryCode = 0;
    int areaCode = 0;
    int resNum = 0;

    //allocate new memory
    int * newNum = nullptr;
    newNum = new int[numPh];

    //copy name!
        if(name == nullptr){
            *p_name = '\0';
        }else{
            strncpy(p_name,name,max_name_size);
            p_name[max_name_size]='\0';
        }
    //validate and copy number!
    if( phoneNumber == nullptr){
        p_phone = nullptr;

    }else{
        for( int i = 0 ;i < numPh;i++){
            //this checks whether the phone number is within 11 or 12 digit
            if ((phoneNumber[i] >= 11001000000 && phoneNumber[i] <= 99999999999) || (phoneNumber[i] >= 111001000000  && phoneNumber[i] <= 999999999999))
            {

                //Isolate potentially invalid digits
                countryCode = (phoneNumber[i] /10000000000);
                areaCode = (phoneNumber[i] %10000000000/10000000);
                resNum = (phoneNumber[i] %10000000);


                // Check if digits are zeros where they shouldn't be
                if (countryCode > 0 && countryCode <= 19 &&
                    areaCode > 0 && areaCode < 999 &&
                    resNum >= 1000000 && resNum <= 99999999)
                {

                    newNum[numPhone] = i;



                    numPhone++;

                }
            }

        }
        p_phone = new long long[numPhone];
        int x = 0;

        for (int i = 0; i < numPh; i++)
        {
            if (newNum[x] == i)
            {
                p_phone[x] = phoneNumber[i];
                x++;
            }
        }

    }

    }

    Contact::~Contact() {
        delete[] p_phone;
    }

    bool Contact::isEmpty() const {
        return *p_name == '\0';
    }
    void Contact::display() const {
        int countryCode;
        int areaCode;
        int RestNum;
        int partOne;
        int partTwo;

        if(isEmpty()){
            cout << "Empty contact!"<<endl;
        }else{
            cout << p_name << endl;
            if( p_phone != nullptr){
                for(int i = 0; i <numPhone;i++){
                    countryCode = (p_phone[i] / 10000000000);
                    areaCode = ( (p_phone[i]%10000000000) / 10000000);
                    RestNum = p_phone[i] % 10000000;
                    //cout << RestNum << endl;
                    //styling @phoneNumber
                    partOne = RestNum / 10000;
                    //cout<<partOne<<endl;
                    partTwo = RestNum%10000;
                    //cout<<partTwo<<endl;

                    cout << "(+" << countryCode << ") " << areaCode << " " << partOne << "-" << setfill('0') << setw(4)<< partTwo << endl;
                }
            }
        }
    }

    Contact& Contact::operator=(const sict::Contact & rhs) {
      if(this != &rhs){
          strncpy(p_name,rhs.p_name,max_name_size);
          p_name[max_name_size]='\0';
          numPhone =rhs.numPhone;

          delete [] p_phone;
          p_phone = new long long[numPhone];
          for(int i = 0; i < numPhone; i++){
              p_phone[i]=rhs.p_phone[i];
          }
      }

        return *this;
    }

    Contact& Contact::operator+=(long long NewNumber) {
        int countryCode = 0;
        int areaCode = 0;
        int resNum = 0;
        if ((NewNumber >= 11001000000 && NewNumber<= 99999999999) || (NewNumber >= 111001000000  && NewNumber <= 999999999999))
        {

            //Isolate potentially invalid digits
            countryCode = (NewNumber/10000000000);
            areaCode = (NewNumber%10000000000/10000000);
            resNum = (NewNumber%10000000);


            // Check if digits are zeros where they shouldn't be
            if (countryCode > 0 && countryCode <= 19 &&
                areaCode > 0 && areaCode < 999 &&
                resNum >= 1000000 && resNum <= 99999999)
            {
                numPhone++;
                long long * newNum1 = new long long[numPhone];

                for(int i = 0; i < numPhone;i++){
                if(p_phone!= nullptr){
                    newNum1[i]=p_phone[i];
                }
                }
                newNum1[numPhone-1]=NewNumber;
                delete [] p_phone;
                p_phone = newNum1;
            }

            }


        return *this;
    }


Contact::Contact(sict::Contact &cpy) {
        *this = cpy;
    }


}

