#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
	//������
	Customer customer{ "��" };
	
	//��ȭ�뿩�׸� ����
	Movie *movie = new REGULAR("�Ϲ�_movie",5);
	Movie *movie1 = new NEW_RELEASE("����_movie", 3);
	Movie *movie2 = new CHILDREN("���_movie", 2);
	Movie *movie3 = new EXAMPLE_GENRE("����_movie", 5);
	customer.addRental1(movie);
	customer.addRental1(movie1);
	customer.addRental1(movie2);
	customer.addRental1(movie3);

	//���������, �׸� ���°� ����
	customer.get_statement();


	//for (int i = 0; i < 1; i++) //��� �迭 ���
	//{
	//	Movie *p = movieList[i]; //p�ȿ� Ŭ���� �Լ� �Է�
	//	int amount = p->GetRentalPrice();
	//	Customer customer{ "��" };

	//	//customer.addRental({ p, 5 });
	//}

 //   Movie regular1{ "�Ϲ� 1", Movie::REGULAR };
 //   Movie regular2{ "�Ϲ� 2", Movie::REGULAR };
 //   Movie newRelease1{ "���� 1", Movie::NEW_RELEASE };
 //   Movie newRelease2{ "���� 2",Movie::NEW_RELEASE };
 //   Movie children1{ "��� 1", Movie::CHILDRENS };
 //   Movie children2{ "��� 2", Movie::CHILDRENS };
	//Movie adult1{ "�1", Movie::ADULT };
	//Movie adult2{ "�2", Movie::ADULT };
 //   Customer customer{ "��" };


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
