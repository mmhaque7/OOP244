/* Md Mehedi Haque
 * 154908172
 * February 21 , 2019*/
// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H
// TODO: create namespace
namespace sict{
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
    private:
	    int nu;
        int deno;
        int max() const;
        // TODO: declare private member functions
        int min() const;
        int gcd() const;
        void reduce();
	public:
		// TODO: declare public member functions
        bool isEmpty() const;
		void display() const;
		Fraction();
		Fraction(int, int);
		// TODO : declare the + operator overload
        Fraction operator+(const Fraction& rhs) const;
	};
}
#endif

