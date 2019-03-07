/*Md. Mehedi Haque
154908172
mmhaque7@myseneca.ca
Feb 04 2019
*/

#include<iostream>
#include<cstring>
#include <iomanip>
#include"Book.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

	void Book::set(const char* givenName, const char* familyName, const char* title, long long int isbn) {

		if (isbn >= min_isbn_value && isbn <= max_isbn_value) {
			long long int ISBN = isbn;
			long long isbnArray[14] = { 0 };
			

			int firstSum = 0;
			int secondSum = 0;
			int checkDigit = 0;
			int totalSum = 0;
			int checkNum = 0;
			//making ISBN into an array.
			for (int i = 0; i < 13; i++) {
				isbnArray[i] = ISBN % 10;
					ISBN = ISBN / 10;
				
				}
			

			checkNum = isbnArray[12];
			//even
			for (int j = 0; j < 12; j += 2) {
				firstSum += isbnArray[j];
			}
			//odd
			for (int j = 1; j < 12; j += 2) {
				secondSum += isbnArray[j];
			}

			secondSum *= 3;
	
			totalSum = firstSum + secondSum;
			int createMultiple = ((totalSum + 9) / 10) * 10;
			
			checkDigit = createMultiple - totalSum;
				
				
			

			if (checkNum == checkDigit) {
				//ignore the strncpy_s --visual studio---
				p_isbn = isbn;
				//strncpy_s(p_familyName, familyName, max_name_size);
				strncpy(p_familyName, familyName, max_name_size);
				p_familyName[max_name_size - 1] = '\0';
				//strncpy_s(p_giveName, givenName, max_name_size);
				strncpy(p_giveName, givenName, max_name_size);
				p_giveName[max_name_size - 1] = '\0';
				//strncpy_s(p_title, title, max_title_size);
				strncpy(p_title, title, max_title_size);
				p_title[max_title_size - 1] = '\0';
			}
			else {
				p_isbn = 0;
			}
			
		}
		else {
			p_isbn = 0; 
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
		//cout << "did i screw up?:" << p_familyName << ", " << p_giveName << endl;--igone this

		if (hello == false && isEmpty()) {
			 
				cout << "The book object is empty!" << endl;
		}
		else if (hello==false && !isEmpty()) {
			cout << "Author: " << p_familyName << ", " << p_giveName << endl;
			cout << "Title: " << p_title << endl;
			cout << "ISBN-13: " << p_isbn << endl;
			cout << "Publication Year: " << p_year << endl;
			cout << "Price: " << p_price << endl;
		}
		else if (hello==true && isEmpty()) {
			cout << "|";
			cout << left;
			cout.width(92);
			cout << "The book object is empty!" ;
			cout << left;
			cout<<"|"<<endl;
		}
		else if (!isEmpty() && hello == true) {
			cout << "|";
			cout << right;
			cout.width(max_name_size);
			cout << p_familyName;
			cout << "|";

			cout.width(max_name_size);
			cout << right;
			cout << p_giveName;
			cout << "|";

			
			cout.width(max_title_size);
			cout<<left;
			cout << p_title;
			cout << "|";

			cout << right;
			cout.width(13);
			cout << p_isbn;
			cout << "|";

			cout.width(4);
			cout << right;
			cout << p_year;
			cout << "|";

			cout.width(6);
			cout << right;
			cout << fixed;
			cout.precision(2);
			cout << p_price;
			cout << "|" << endl;

			cout.unsetf(ios::fixed);
			cout.precision(6);
		}

		
		
	}



}