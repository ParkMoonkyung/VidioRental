
#ifndef RECEIPT_H
#define RECEIPT_H
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
//using std::string;

using std::ostringstream;
using std::vector;
using namespace std;

class RECEIPT {
public:
	struct RentalInfo
	{
		std::string title;
		std::string genre;
		int rentday;
		int amount;
		int point;
	};
	
	RECEIPT(std::string _customer, vector<RentalInfo> _rec, int _totalamount, int _totalpoint)
	{
		customer = _customer;
		rec = _rec;
		totalamount = _totalamount;
		totalpoint = _totalpoint;
	}

	///영수증출력
	void setRecept();

private :
	std::string customer;
	vector<RentalInfo> rec;
	int totalamount;
	int totalpoint;
};


#endif // RECEIPT_H
