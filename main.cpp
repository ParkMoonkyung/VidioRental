#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "�Ϲ� 1",5,Movie::REGULAR };
    Movie regular2{ "�Ϲ� 2", 3,Movie::REGULAR };
    Movie newRelease1{ "���� 1", 1,Movie::NEW_RELEASE };
    Movie newRelease2{ "���� 2", 2,Movie::NEW_RELEASE };
    Movie children1{ "��� 1", 3,Movie::CHILDRENS };
    Movie children2{ "��� 2", 4,Movie::CHILDRENS };
	Movie adult1{ "�1", 3,Movie::ADULT };
	Movie adult2{ "�2", 9,Movie::ADULT };
    Customer customer{ "��" };


    customer.addRental({ regular1, 5 });
    customer.addRental({ regular2, 3 });
    customer.addRental({ newRelease1, 1 });
    customer.addRental({ newRelease2, 2 });
    customer.addRental({ children1, 3 });
    customer.addRental({ children2, 4 });
	customer.addRental({ adult1, 3 });
	customer.addRental({ adult2, 9 });

    cout << customer.statement() << endl;


	//������
	Customer customer1{ "��1" };

	//��ȭ�뿩�׸� ����
	Movie *movie = new REGULAR("�Ϲ�_movie", 5);
	Movie *movie1 = new REGULAR("�Ϲ�1_movie", 3);
	Movie *movie2 = new NEW_RELEASE("����_movie", 1);
	Movie *movie3 = new NEW_RELEASE("����_movie", 2);
	Movie *movie4 = new CHILDREN("���_movie", 3);
	Movie *movie5 = new CHILDREN("���_movie", 4);
	Movie *movie6 = new EXAMPLE_GENRE("����_movie", 3);
	Movie *movie7 = new EXAMPLE_GENRE("����_movie", 9);
	customer1.addRental1(movie);
	customer1.addRental1(movie1);
	customer1.addRental1(movie2);
	customer1.addRental1(movie3);
	customer1.addRental1(movie4);
	customer1.addRental1(movie5);
	customer1.addRental1(movie6);
	customer1.addRental1(movie7);

	//���������, �׸� ���°� ����
	customer1.get_statement();

    return 0;
}
