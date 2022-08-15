// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Rental.h"

// The customer class represents the customer of the store

class Customer {
public:
  Customer();
  explicit Customer( const std::string& name );

  void addRental( const Rental& arg );

  void addRental1(Movie* arg);
  std::string getName() const;

  // Generate a statement for the customer
  std::string statement();

  std::string n_statement();

private:
  std::string customerName;
  std::vector< Rental > customerRentals;

  std::vector< Movie* > customerRentals1;

};


inline Customer::Customer() {}

inline Customer::Customer( const std::string& name ): 
  customerName( name ) {}

inline void Customer::addRental( const Rental& arg ) { customerRentals.push_back( arg ); }
inline void Customer::addRental1( Movie* arg) { customerRentals1.push_back(arg); }

inline std::string Customer::getName() const { return customerName; }

#endif // CUSTOMER_HH
