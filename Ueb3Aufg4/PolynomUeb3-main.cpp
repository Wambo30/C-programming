/*
*  Polynom-Main.cpp
*  Programmieren IIb - Uebung 3, Aufgabe 4
*/

#include "PolynomUeb3.h"
#include <stdexcept>
#include "IndexFehler.h"
#include <iostream>
#include <string>
using namespace std;



int main(void) {
	try {
		string text = "Programmieren";
		PolynomUeb3 p1;
		PolynomUeb3 p2(3);
		PolynomUeb3 p3(3, 1.);

		cout << "p1: " << p1 << endl;
		cout << "p2: " << p2 << endl;
		cout << "p3: " << p3 << endl;

		//p3[4] = -7;     // Den Koeffizienten a_4 auf -7 setzen
		string d = p3.[100]
		cout << p3.[100] << endl;
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}
