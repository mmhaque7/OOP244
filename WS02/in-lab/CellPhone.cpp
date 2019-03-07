/*
	Md Mehedi Haque
	154908172
	mmhaque7@myseneca.ca
*/

// TODO: include the necessary headers
#include"CellPhone.h"
#include<iostream>
#include<iomanip>
using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO: definition for display(...)
	void display(CellPhone & phone)
	{

		cout << "Phone " << phone.m_model << " costs $" << /*setprecision(2) << fixed<<*/ phone.m_price << "!" << endl;
	}

}	