// List.cpp : définit le point d'entrée de l'application.
//

#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	list<int> l1;
	l1.push_back(12);
	l1.push_back(34);
	l1.push_back(56);
	l1.push_back(78);
	l1.push_back(90);
	afficher(cout, l1);

	/*
	l1.pop_back();
	afficher(cout, l1);
	
	l1.pop_front();
	l1.pop_front();
	afficher(cout, l1);
	//*/
	
	l1.reverse();
	afficher(cout, l1);


	return 0;
}
