/*Md. Mehedi Haque
154908172
mmhaque7@myseneca.ca
Jan 31 2019
*/

#include<iostream>
#include<cstring>
#include"Book.h"

using namespace std;

namespace sict {

void Book::set(const char* givenName, const char* familyName, const char* title, long long int isbn)
{
	//if the first letter of the givenName, familyName and title is not null then we move on to verify the isbn.
	if (givenName[0] != '\0' || familyName != '\0' || title != '\0') {
		//if the isbn is less the the max_isbn_value and greater than the max_isbn_number then we set the data.
		if (isbn <= max_isbn_value && isbn >= min_isbn_value) {
			strncpy(p_familyName, familyName, max_name_size);
			strncpy(p_giveName, givenName, max_name_size);
			strncpy(p_title, title, max_title_size);
			p_isbn = isbn;
		}
		//default value if the isbn is not valid.
		else {
			p_isbn = 1;
		}
	}
	
	return;
	
	}



bool Book::isEmpty() const
{
	// we create a bool empty make that true as the object is  actually empty
	bool empty = true; 

	//here we check the ISBN is has the correct value length, then we say the object is not empty 
	if (p_isbn <= max_isbn_value && p_isbn >= min_isbn_value) {
		empty = false;
	}
	return empty;

}

void Book::display() const
{	//displays this when the object is empty otherwise it displays the author title and ISBN numner
	if (isEmpty()) {
		cout << "The book object is empty!" << endl;

	}
	else {
		cout << "Author: " << p_familyName << ", "<<p_giveName << endl;
		cout << "Title: " << p_title << endl;
		cout << "ISBN-13: " << p_isbn << endl;
	}//displays this when everything works perfectly fine :)

}




}