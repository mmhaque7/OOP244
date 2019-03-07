/*Md. Mehedi Haque
154908172
mmhaque7@myseneca.ca
Jan 31 2019
*/

#include<iostream>
#include<cstring>
#include <iomanip>
#include"Book.h"

using namespace std;

namespace sict {

	void sict::Book::set(const char *givenName, const char *familyName, const char *title, long long int isbn)
	{	long long int isbnArray[13] = { 0 };
		if (isbn <= max_isbn_value && isbn >= min_isbn_value) {
			long long int ISBN = isbn;
			
			//break the ISBN into single digits!
			for (int i = 13; i >= 0; i--) {
				isbnArray[i] = ISBN % 10;
				ISBN = ISBN / 10;
			}

			int checkNum = isbnArray[12];

			//get and add the even number 
			int firstSum=0;
			for (int i = 0; i <= 12; i += 2) {//0 because we want the even number
				firstSum += isbnArray[i];
			}

			//get and add the even number
			int secondSum=0;
			for (int i = 1; i <= 12; i += 2) {//1 because we want the odd numbers
				secondSum += isbnArray[i];
			}
			
			secondSum *= 3;

			int totalSum;
			if ((firstSum + secondSum) % 10 == 0) {
				totalSum = firstSum + secondSum;
			}
			else {
				int remainder = (firstSum + secondSum) % 10;
				int createMultiple = 10 - remainder;

				totalSum = firstSum + secondSum + createMultiple;
			}
			int chkDigit = totalSum - (firstSum + secondSum);

			if (chkDigit == checkNum) {
				p_isbn = isbn;
				strncpy(p_familyName, familyName, max_name_size);
				p_familyName[max_name_size - 1] = '\0';
				strncpy(p_giveName, givenName, max_name_size);
				p_giveName[max_name_size - 1] = '\0';
				strncpy(p_title, title, max_title_size);
				p_title[max_title_size - 1] = '\0';
			}
			else {
				p_isbn = 0;
			}



		}
		else {
			p_isbn = 0;//default empty state
		}

	}
		

	void sict::Book::set(int year, double price)
	{
		if (!isEmpty()) {
			p_year = year;
			p_price = price;


		}
	}


	bool Book::isEmpty() const
	{
		if (p_isbn == 0) {
			return true;
		}
		else {
			return false;
		}

	}

	void sict::Book::display(bool hello) const
	{
		//cout << "mysadj: " << p_familyName << ", " << p_giveName << endl;

		if (hello == false && isEmpty()) {
			 
				cout << "the book object is empty!" << endl;
		}
		else if (hello==false && !isEmpty()) {
			cout << "Author: " << p_familyName << ", " << p_giveName << endl;
			cout << "Title: " << p_title << endl;
			cout << "ISBN-13: " << p_isbn << endl;
			cout << "publication year: " << p_year << endl;
			cout << "PriPubce: " << p_price << endl;
		}
		else if (hello==true && isEmpty()) {
			cout << "The book object is empty!" << endl;
		}
		else if(!isEmpty() && hello==true) {
			cout << right << setw(max_name_size) << p_familyName << "|" \
				<< right << setw(max_name_size) << p_giveName
				<< left << setw(max_title_size)<<"|" << p_title
				<< right << setw(13) << p_isbn <<"|"
				<< right << setw(4) << p_year<<"|"
				<< right << setw(6) << setprecision(2) << p_price<<"|" << endl;
		}

		
		
	}



}