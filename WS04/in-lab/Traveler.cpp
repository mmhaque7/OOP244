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
// TODO: continue your namespace here
using namespace std;
namespace sict{

    // TODO: implement the default constructor here
    Traveler::Traveler(){
     p_firstName[0] ='\0';
     p_lastName[0] = '\0';
     p_destination[0] = '\0';
    }
    // TODO: implement the constructor with 3 parameters here
   Traveler::Traveler(const char *firstName, const char *lastName, const char *dest) {
        if(firstName == nullptr||lastName==nullptr||dest== nullptr){
            *this = Traveler();
        }
        else{
         strncpy(p_firstName,firstName,max_name_size);
         p_firstName[max_name_size-1]= '\0';
         strncpy(p_lastName,lastName,max_name_size);
         p_lastName[max_name_size-1]='\0';
         strncpy(p_destination,dest,max_destination_size);
         p_destination[max_destination_size-1]='\0';
        }
    }
    // TODO: implement isEmpty query here
    bool Traveler::isEmpty() const {
        if(strlen(p_firstName)>0 && strlen(p_lastName)>0 && strlen(p_destination)>0){
            return false;
        }
        else{
         return true;
        }
    }
    // TODO: implement display query here
    void Traveler::display() const {
        if(!isEmpty()){
            cout<<p_firstName<<" "<<p_lastName<<" goes to "<<p_destination<<endl;        }
        else{

            cout << "--> Not a valid traveler! <--" <<endl;
        }
    }
}