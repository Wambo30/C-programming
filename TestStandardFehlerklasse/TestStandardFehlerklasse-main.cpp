
#include <iostream>

#include "TestStandardFehlerklasse.h"
#include <exception>
using namespace std;

int main() {
	Berechnungsklasse c;
	try {
		double x, y;
		cout << "x: ";
		cin >> x;
		y = c.wurzel(x);
		cout << "wurzel(x): " << y << endl;
		y += c.kehrwert(x);
		cout << "1./x : " << y << endl;
	}
	catch (exception& er) { 
		cout << er.what() << endl;
	}
	cout << "Ende" << endl;


	system("pause");
	return 0;
}