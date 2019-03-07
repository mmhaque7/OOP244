/* Md Mehedi Haque
 * 154908172
 * February 21 , 2019*/
// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict{
	// TODO: implement the default constructor
    Fraction::Fraction(){
        nu = 0;
        deno = 0;
    }
	// TODO: implement the two-argument constructor
    Fraction::Fraction(int numerator, int denominator){
        if(numerator > 0 && denominator > 0){
            nu = numerator;
            deno =  denominator;
        }else{
            nu = 0;
            deno = 0;
        }
        reduce();
    }
	// TODO: implement the max query
    int Fraction::max() const {
        if(nu > deno){
            return  nu;
        }else{
            return deno;
        }
    }
    // TODO: implement the min query
    int Fraction::min() const {
        if(deno < nu){
            return deno;
        }else{
            return nu;
        }
    }
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
void Fraction::reduce() {
        float g_cd = gcd();
        nu /= g_cd;
        deno /= g_cd;

    }
    // TODO: implement the display query
    void Fraction::display() const {
        if(!isEmpty() && deno != 1){
            cout<< nu<<"/"<<deno;
        }else if(!isEmpty() && deno == 1){
            cout<<nu;
        }else if(isEmpty() && deno == 0){
            cout << "no fraction stored";
        }

    }
    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
        if(nu == 0 && deno ==0){
            return true;
        }else{
            return false;
        }
    }
    // TODO: implement the + operator

    Fraction Fraction::operator+(const Fraction& rhs) const {
        Fraction current;
        current = *this;
        Fraction result;

        if (current.isEmpty() == false && rhs.isEmpty() == false) {
            result.nu = (current.nu * rhs.deno) + (current.deno * rhs.nu);
            result.deno = current.deno*rhs.deno;

            return result;
        }
        else {
            return Fraction();
        }

    }
}




