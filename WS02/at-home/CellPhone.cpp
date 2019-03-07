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

	void display(const CellPhone arr[], int j)
	{
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < j; i++) {
			cout << i + 1 << ". " << "Phone " << arr[i].m_model << " costs " <<"$" << arr[i].m_price << "!" << endl;
		}

		float small;
		float temp;
		
		cout << "------------------------------" << endl;
		small = arr[0].m_price;
		for (int i = 0; i < j; i++) {
			temp = arr[i].m_price;
			if (temp < small) {
				small = temp;
				cout << "The cheapest phone costs " << "$" << small<< setprecision(2) <<"."<< endl;
			}
		}
		cout << "------------------------------" << endl;

	}

}	