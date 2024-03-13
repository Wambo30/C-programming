/* Calculator-main.cpp */

#include "Error.h"
#include "Calculator.h"
#include <iostream>
using namespace std;

int main(void) {
	try {
		Calculator c;
		double x, y;
		cout << "x eingeben: ";
		cin >> x;
		y = c.wurzelVon(x);        //sqrt(x);
		cout << "Wurzel: y = " << y << endl;
		y += c.kehrwertVon(x);        // 1. / x;
		cout << "Kehrwert: y = " << y << endl;
	}
	catch (Error& e) {  // catch fuer throw in wurzelVon und kehrwertVon
		e.meldeFehler();
	}
	cout << "ENDE" << endl;

	system("pause");
	return 0;
}


