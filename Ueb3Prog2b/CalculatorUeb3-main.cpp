/*
*  Calculator-Main.cpp
*  Programmieren IIb - Uebung 4, Aufgabe 1
*
*/

#include "CalculatorUeb3.h"
#include <iostream>
using namespace std;

int main(void) {
	CalculatorUeb3 c;
	try {
		double x, y;
		cout << "x : ";
		cin >> x;

		y = -c.wurzel(x);
		cout << "wurzel(x) = " << -y << endl;

		y = c.logarithmus(y);
		cout << "log(1/wurzel(x)) = " << y << endl;

		y = c.kehrwert(y);
		cout << "1/wurzel(x) = " << y << endl;
	}
	catch (ErrorUeb3& fehler) {
		fehler.meldeFehler();
	}

	cout << "ENDE" << endl;
	system("pause");
	return 0;
}