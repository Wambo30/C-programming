/* rechnen.cpp */
#include <string>
#include <iostream>
#include <cmath>
#include "Error.h"


using namespace std;

double wurzelBerechnen(double x) {
	if (x >= 0.) {
		return sqrt(x);
	}
	throw NegativeNumberError(x);
}

double kehrwertVon(double x) {
	if (abs(x) > DBL_EPSILON) {
		return 1. / x;
	}
	throw  NullDivisionError();
}

int main(void) {
	try {
		double x, y;
		cout << "x eingeben: ";
		cin >> x;
		y = wurzelBerechnen(x);		//sqrt(x);
		cout << "Wurzel: y = " << y << endl;
		y += kehrwertVon(x);		// 1. / x;
		cout << "Kehrwert: y = " << y << endl;
	}
	catch (exception& e) {  // catch fuer wurzelBerechnen()
										   //cout << "FEHLER: " << d << " ist negativ!" << endl;
		e.meldeFehler();
	}

	cout << "ENDE" << endl;

	system("pause");
	return 0;
}






