// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;
  static const int ADULT = 3;

 Movie( const std::string& title, int rentday , int priceCode = REGULAR);

  Movie( const char* title, int rentday);

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;
  std::string getTitle1();

  virtual const char* GetVideoGenre() const
  {
	  return "비디오장르";
  }
  virtual double GetRentalPrice() const
  {
	  return 0;
  }
  virtual int GetRentalPoint() const 
  {
	  int frequentRenterPoints = 0;
	  frequentRenterPoints++;
	  return frequentRenterPoints;
  }
  virtual int GetRentDay()
  {
	  return rentDay;
  }

private:
  std::string movieTitle;
  const char *Title;
  int moviePriceCode;
  int rentDay;
};

inline Movie::Movie(const std::string& title, int rentday, int priceCode ) :
	movieTitle(title),
	moviePriceCode(priceCode)
{}

inline Movie::Movie( const char* title, int rentday)
{
	Title = title;
	rentDay = rentday;
}

inline int Movie::getPriceCode() const { return moviePriceCode; }

inline void Movie::setPriceCode( int arg ) { moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return movieTitle; }
inline std::string Movie::getTitle1() { return Title; }


#pragma region Movie Genre
class REGULAR : public Movie
{
public:
	REGULAR(const char *title, int rentday) :Movie(title, rentday)
	{
		r_rentday = rentday;
	}

	virtual const char* GetVideoGenre() const
	{
		return "일반";
	}
	virtual double GetRentalPrice() const
	{
		double thisAmount = 0.;
		thisAmount += 2.;
		if (r_rentday > 2)
			thisAmount += (r_rentday - 2) * 1.5;
		return thisAmount;
	}
private:
	int r_rentday;
};

class NEW_RELEASE : public Movie
{
public:
	NEW_RELEASE(const char* title, int rentday) :Movie(title,rentday)
	{
		r_rentday = rentday;
	}

	virtual const char* GetVideoGenre() const
	{
		return "신작";
	}
	virtual double GetRentalPrice() const
	{
		double thisAmount = 0.;
		thisAmount += r_rentday * 3;
		return thisAmount;
	}

	virtual int GetRentalPoint() const
	{
		int frequentRenterPoints = 0;
		frequentRenterPoints++;
		if (r_rentday > 1) frequentRenterPoints++;
		return frequentRenterPoints;
	}
private:
	int r_rentday;
};

class CHILDREN : public Movie
{
public:
	CHILDREN(const char* title, int rentday) :Movie(title, rentday)
	{
		r_rentday = rentday;
	}

	virtual const char* GetVideoGenre() const
	{
		return "어린이";
	}
	virtual double GetRentalPrice() const
	{
		double thisAmount = 0.;
		thisAmount += 1.5;
		if (r_rentday > 3)
			thisAmount += (r_rentday - 3) * 1.5;
		return thisAmount;
	}
private:
	int r_rentday;
};


///새장르추가 
class EXAMPLE_GENRE : public Movie
{
public:
	EXAMPLE_GENRE(const char* title, int rentday) :Movie(title, rentday)
	{
		//r_title = title;
		r_rentday = rentday;
	}

	virtual const char* GetVideoGenre() const
	{
		return "EXAMPLE_GENRE";
	}
	virtual double GetRentalPrice() const
	{
		//대여료가 기본료가 $1, 1일 초과 시 $1달러의 추가 요금이 붙지만, 최대 5일까지만 추가 요금이 붙습니다.
		double thisAmount = 0.;
		thisAmount += 1;
		if (r_rentday <= 5)
			thisAmount += r_rentday;
		else
			thisAmount += 5;
		return thisAmount;
	}

	virtual int GetRentalPoint() const
	{
		//대여 포인트는 기본 1포인트, 대여기간이 2일 이상일 때 1포인트, 4일 이상이면 2포인트를 적립합니다.
		int frequentRenterPoints = 0;
		frequentRenterPoints++;
		if (r_rentday >= 2 && r_rentday < 4) frequentRenterPoints++;
		else if (r_rentday >= 4) frequentRenterPoints += 2;
		return frequentRenterPoints;
	}
private:
	int r_rentday;
};
#pragma endregion
#endif // MOVIE_H
