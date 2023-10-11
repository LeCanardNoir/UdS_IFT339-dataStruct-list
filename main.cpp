// List.cpp : définit le point d'entrée de l'application.
//

#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	list<int> l1;
	l1.push_back(0);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);
	l1.push_back(10);
	l1.push_back(11);
	l1.push_back(12);
	l1.push_back(13);
	afficher(cout, l1);


	return 0;
}
