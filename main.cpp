#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "일반 1",5,Movie::REGULAR };
    Movie regular2{ "일반 2", 3,Movie::REGULAR };
    Movie newRelease1{ "신작 1", 1,Movie::NEW_RELEASE };
    Movie newRelease2{ "신작 2", 2,Movie::NEW_RELEASE };
    Movie children1{ "어린이 1", 3,Movie::CHILDRENS };
    Movie children2{ "어린이 2", 4,Movie::CHILDRENS };
	Movie adult1{ "어른1", 3,Movie::ADULT };
	Movie adult2{ "어른2", 9,Movie::ADULT };
    Customer customer{ "고객" };


    customer.addRental({ regular1, 5 });
    customer.addRental({ regular2, 3 });
    customer.addRental({ newRelease1, 1 });
    customer.addRental({ newRelease2, 2 });
    customer.addRental({ children1, 3 });
    customer.addRental({ children2, 4 });
	customer.addRental({ adult1, 3 });
	customer.addRental({ adult2, 9 });

    cout << customer.statement() << endl;


	//고객설정
	Customer customer1{ "고객1" };

	//영화대여항목 설정
	Movie *movie = new REGULAR("일반_movie", 5);
	Movie *movie1 = new REGULAR("일반1_movie", 3);
	Movie *movie2 = new NEW_RELEASE("신작_movie", 1);
	Movie *movie3 = new NEW_RELEASE("신작_movie", 2);
	Movie *movie4 = new CHILDREN("어린이_movie", 3);
	Movie *movie5 = new CHILDREN("어린이_movie", 4);
	Movie *movie6 = new EXAMPLE_GENRE("성인_movie", 3);
	Movie *movie7 = new EXAMPLE_GENRE("성인_movie", 9);
	customer1.addRental1(movie);
	customer1.addRental1(movie1);
	customer1.addRental1(movie2);
	customer1.addRental1(movie3);
	customer1.addRental1(movie4);
	customer1.addRental1(movie5);
	customer1.addRental1(movie6);
	customer1.addRental1(movie7);

	//영수증출력, 항목 상태값 변경
	customer1.get_statement();

    return 0;
}
