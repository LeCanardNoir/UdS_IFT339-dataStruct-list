// List.cpp : définit le point d'entrée de l'application.
//

#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	list<int> list_simple;
	list<int> list_data({1,2,3,4,5,6,7,8,9,0});
	afficher(cout, list_data);
	cout << endl;
	for (auto it = list_data.begin(); it != list_data.end(); it++) {
		cout << *it << ", ";
	}
	for (auto it = list_data.rbegin(); it != list_data.rend(); it++) {
		cout << *it << endl;
	}
	return 0;
}