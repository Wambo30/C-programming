#include "TestCalculator.h"
#include "Error.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int main() {

	TestCalculator c;
	try {
		//TestCalculator c;
		double x, y;
		cout << "x: ";
		cin >> x;
		y = c.wurzel(x);
		cout << "wurzel(x): " << y << endl;
		y *= c.kehrwert(x);
		cout << "kehrwertVon(x): " << y << endl;
	}
	catch (Error& er) { er.meldeFehler(); }
	cout << "ENDE" << endl;




	system("pause");
	return 0;

}