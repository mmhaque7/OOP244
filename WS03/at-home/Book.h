/*Md. Mehedi Haque
154908172
mmhaque7@myseneca.ca
Jan 31 2019
*/
#ifndef BOOK_H
#define BOOK_H

namespace sict {
	const int max_title_size = 33;
	const int max_name_size = 17;
	const long long int min_isbn_value = 1000000000000LL;
	const long long int max_isbn_value = 9999999999999LL;


	class Book
	{
	private:
		char p_familyName[max_name_size];
		char p_giveName[max_name_size];
		char p_title[max_title_size];
		long long int p_isbn;
		int p_year;
		double p_price;

	
	
	public:
		void set(const char* , const char* , const char* , long long int );
		void set(int, double);
		bool isEmpty() const;
		void display(bool hello = false ) const;
	

	};




}






#endif // !BOOK_H

#pragma once
