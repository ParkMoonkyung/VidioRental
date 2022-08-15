// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Receipt.h"

using std::ostringstream;
using std::vector;

class RentFee 
{
};

//사용안함
std::string Customer::statement()
{
  double totalAmount = 0.;
  int frequentRenterPoints = 0;

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();

  // result will be returned by statement()
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";

  // Loop over customer's rentals
  for ( ; iter != iter_end; ++iter ) {

    double thisAmount = 0.;
    Rental each = *iter;

    // Determine amounts for each rental
    switch ( each.getMovie().getPriceCode() ) {

      case Movie::REGULAR:
        thisAmount += 2.;
        if ( each.getDaysRented() > 2 )
          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
        break;

      case Movie::NEW_RELEASE:
        thisAmount += each.getDaysRented() * 3;
        break;

      case Movie::CHILDRENS:
        thisAmount += 1.5;
        if ( each.getDaysRented() > 3 )
          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
        break;

	  case Movie::ADULT:
		  thisAmount += 1;
		  if (each.getDaysRented() <= 5)
			  thisAmount += each.getDaysRented();
		  else
			  thisAmount += 5;
    }

    // Add frequent renter points
    frequentRenterPoints++;

    // Add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

	if (each.getMovie().getPriceCode() == Movie::ADULT)
	{
		if (each.getDaysRented() >=2 && each.getDaysRented() < 4) frequentRenterPoints++;
		else if (each.getDaysRented() >= 4) frequentRenterPoints = frequentRenterPoints + 2;
	}
	

    // Show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << std::endl;
    totalAmount += thisAmount;
  }

  // Add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";

  return result.str();
}


///신규 
void Customer::get_statement()
{
	double totalAmount = 0.;
	int frequentRenterPoints = 0;

	std::vector< Movie* >::iterator iter = customerRentals1.begin();
	std::vector< Movie* >::iterator iter_end = customerRentals1.end();
	
	//RECEIPT::
	std::vector<RECEIPT::RentalInfo> retalinfo;
	// Loop over customer's rentals
	for (; iter != iter_end; ++iter) {
		
		double thisAmount = 0.;
		Movie* each = *iter;
		
		totalAmount += each->GetRentalPrice();
		frequentRenterPoints += each->GetRentalPoint();

		 //제목, 장르, 대여기간, 가격, 포인트
		RECEIPT::RentalInfo Receiptdaya = { each->getTitle1(), each->GetVideoGenre(),each->GetRentDay(), each->GetRentalPrice(), each->GetRentalPoint()};
		retalinfo.push_back(Receiptdaya);
	}
	//고객명, 렌트정보, 총계금액, 총계포인트
	RECEIPT * receipt = new RECEIPT(getName(), retalinfo, totalAmount, frequentRenterPoints);
	receipt->setRecept();
	
}
