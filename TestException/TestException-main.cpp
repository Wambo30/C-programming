
#include <iostream>
#include <string>
#include "TestMod.h"
using namespace std;



int main() {
	// test modulo rechnung

/*
	if (3 % 3) {
		cout << "rest ist groesser 0" << endl;
	}
	else {
		//throw 17;
		cout << "rest gleich 0" << endl;
	}
*/

/*
	//test switch case
	int i;
	switch (7 % 3) {
	case 0:
		cout <<"i ist null"<< endl;
		break;
	case 1:
		cout << "i ist eins" << endl;
		break;
	case -9:
		cout << "i ist minus 9" << endl;

		break;
	case 3:
		cout << "i ist 3" << endl;
		break;
	case 10:
		cout << "i ist 10" << endl;
		break;
	default:
		cout << "standardnachricht" << endl;

	}
*/

	// test string append befehl
	string b = "hallo";
	b.append(" ,wie gehts?");
	cout << b << endl;
	cout << endl;

	//2.variante mit append befehl und dessen ausgabe
	string b = "hallo";
	string a = ",wie gehts?";
	b.append(a) ; // klappt nicht


	system("pause");
	return 0;
}