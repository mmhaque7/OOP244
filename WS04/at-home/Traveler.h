// TODO: add file header comments here
/*Md Mehedi Haque
 * 154908172
 * Feb 06 2019
 * mmhaque7@myseneca.ca
 * */
// TODO: add header file guard here
#ifndef TRAVELER_H
#define TRAVELER_H
// TODO: declare your namespace here
namespace sict {

    // TODO: define the constants here
const int max_destination_size = 33;
const int max_name_size = 17;
    // TODO: define the Traveler class here
class Traveler{
private:
    char p_firstName[max_name_size];
    char p_lastName[max_name_size];
    char p_destination[max_destination_size];
    int p_year;
    int p_month;
    int p_day;
public:
    Traveler();
    Traveler(const char*, const char*,const char*);
    Traveler(const char*, const char*, const char*, int, int, int);
    const  char* name() const;
    bool canTravelWith(const Traveler&) const ;
    bool  isEmpty() const;
    void display()const;

};
}
#endif