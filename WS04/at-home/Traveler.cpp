// TODO: add file header comments here
// /*Md Mehedi Haque
// * 154908172
// * Feb 06 2019
// * mmhaque7@myseneca.ca
// * */
// TODO: add your headers here
#include "Traveler.h"
#include <iostream>
#include <cstring>
#include <iomanip>
// TODO: continue your namespace here
using namespace std;
namespace sict{

    // TODO: implement the default constructor here
    Traveler::Traveler(){
     p_firstName[0] ='\0';
     p_lastName[0] = '\0';
     p_destination[0] = '\0';
     p_year =0;
     p_month =0;
     p_day = 0;

    }
    // TODO: implement the constructor with 3 parameters here
   Traveler::Traveler(const char *firstName, const char *lastName, const char *dest) {
        if(firstName == nullptr||lastName==nullptr||dest== nullptr){
            p_firstName[0] ='\0';
            p_lastName[0] = '\0';
            p_destination[0] = '\0';
            p_year = 0;
            p_month = 0;
            p_day=0;
        }
        else{
         strncpy(p_firstName,firstName,max_name_size);
         p_firstName[max_name_size]= '\0';
         strncpy(p_lastName,lastName,max_name_size);
         p_lastName[max_name_size]='\0';
         strncpy(p_destination,dest,max_destination_size);
         p_destination[max_destination_size]='\0';

         p_year = 2019;
         p_month= 7;
         p_day= 1;
        }
    }
    // TODO: implement the constructor with 6 parameters here
    Traveler::Traveler(const char *firstName, const char *lastName, const char *dest, int year, int month, int day) {
       if(firstName == nullptr || lastName == nullptr || dest ==nullptr|| firstName[0] == '\0'||lastName[0]==
       '\0' || dest[0]=='\0'||year >2022 || year < 2019 || month> 12 ||month < 1||day >31 ||day <1){
           p_firstName[0] ='\0';
           p_lastName[0] = '\0';
           p_destination[0] = '\0';
           p_year = 0;
           p_month = 0;
           p_day=0;
       }else{
           strncpy(p_firstName,firstName,max_name_size);
           p_firstName[max_name_size]= '\0';
           strncpy(p_lastName,lastName,max_name_size);
           p_lastName[max_name_size]='\0';
           strncpy(p_destination,dest,max_destination_size);
           p_destination[max_destination_size]='\0';

           p_year = year;
           p_month= month;
           p_day= day;
       }
    }
    // TODO: implement name query here
    const  char* Traveler::name() const {
        return !isEmpty() ? p_firstName : nullptr;
    }

    // TODO: implement canTravelWith query here
  bool Traveler::canTravelWith(const Traveler & person) const {
        bool canTravel = false;

        if((strcmp(this->p_destination,person.p_destination))==0){
            if(this->p_year==person.p_year && this->p_month == person.p_month && this->p_day == person.p_day){
                canTravel = true;
            }
        }
        return  canTravel;
    }
    // TODO: implement isEmpty query here
    bool Traveler::isEmpty() const {
        if(p_firstName[0]=='\0' && p_lastName[0] =='\0'&& p_destination[0]=='\0' && p_year ==0 && p_month ==0 && p_day == 0){
            return true;
        }
        else{
            return false;
        }
    }
    // TODO: implement display query here
    void Traveler::display() const {
        if(!isEmpty()){
            cout<<p_lastName<<", "<<p_firstName<<" goes to "<<p_destination<< " on " <<p_year<<"/"<<setw(2)<<setfill('0')
            <<p_month<<"/"<<setw(2)<<setfill('0')<<p_day<<endl; }
        else{

        }
    }
    }
