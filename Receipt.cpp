#include "Receipt.h"
#include <iostream>

//영수증 출력물 형식 
void RECEIPT::setRecept()
{
	cout << "----------------------------------------" << "\n";
	cout << "Video Rental Shop Receipt" << "\n\n";
	cout << "Rental Record for " << customer << "\n\n";

	std::vector< RentalInfo>::iterator iter = rec.begin();
	std::vector< RentalInfo>::iterator iter_end = rec.end();

	for (; iter != iter_end; ++iter)
	{
		RentalInfo rentaldata = *iter;
		cout << "Name : " << rentaldata.title << "\n";
		cout << "Genre : " << rentaldata.genre << "\n";
		cout << "RentDay : " << rentaldata.rentday << "\n";
		cout << "Amount : " << rentaldata.amount << "\n";
		cout << "Point : " << rentaldata.point << "\n\n";
	}

	cout << "\n-Total Amount : " << totalamount << "\n";
	cout << "-Total Point : " << totalpoint << "\n";
	cout << "----------------------------------------" << "\n";
}