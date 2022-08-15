#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
	//고객설정
	Customer customer{ "고객" };
	
	//영화대여항목 설정
	Movie *movie = new REGULAR("일반_movie",5);
	Movie *movie1 = new NEW_RELEASE("신작_movie", 3);
	Movie *movie2 = new CHILDREN("어린이_movie", 2);
	Movie *movie3 = new EXAMPLE_GENRE("성인_movie", 5);
	customer.addRental1(movie);
	customer.addRental1(movie1);
	customer.addRental1(movie2);
	customer.addRental1(movie3);

	//영수증출력, 항목 상태값 변경
	customer.get_statement();


	//for (int i = 0; i < 1; i++) //모든 배열 출력
	//{
	//	Movie *p = movieList[i]; //p안에 클래스 함수 입력
	//	int amount = p->GetRentalPrice();
	//	Customer customer{ "고객" };

	//	//customer.addRental({ p, 5 });
	//}

 //   Movie regular1{ "일반 1", Movie::REGULAR };
 //   Movie regular2{ "일반 2", Movie::REGULAR };
 //   Movie newRelease1{ "신작 1", Movie::NEW_RELEASE };
 //   Movie newRelease2{ "신작 2",Movie::NEW_RELEASE };
 //   Movie children1{ "어린이 1", Movie::CHILDRENS };
 //   Movie children2{ "어린이 2", Movie::CHILDRENS };
	//Movie adult1{ "어른1", Movie::ADULT };
	//Movie adult2{ "어른2", Movie::ADULT };
 //   Customer customer{ "고객" };


 //   customer.addRental({ regular1, 5 });
 //   customer.addRental({ regular2, 3 });
 //   customer.addRental({ newRelease1, 1 });
 //   customer.addRental({ newRelease2, 2 });
 //   customer.addRental({ children1, 3 });
 //   customer.addRental({ children2, 4 });
	//customer.addRental({ adult1, 3 });
	//customer.addRental({ adult2, 9 });

 //   cout << customer.statement() << endl;

    return 0;
}
