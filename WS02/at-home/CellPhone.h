/*
	Md Mehedi Haque
	154908172
	mmhaque7@myseneca.ca
*/
// TODO: header safeguards
#ifndef CELLPHONE_H
#define CELLPHNE_H


// TODO: sict namespace
namespace sict {
	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone
	{
		char m_model[33];
		float m_price;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace

	void display(CellPhone& phone);
	void display(const CellPhone arr[], int j);

}


#endif // !CELLPHONE_H