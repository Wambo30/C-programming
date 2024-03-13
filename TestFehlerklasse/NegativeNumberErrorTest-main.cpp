
#include "NegativeNumberErrorTest.h"
#include <iostream>
#include <cmath>
using namespace std;

double WurzelVon(double d) {
	if (d >= 0.0)
		return sqrt(d);
	else
		throw NegativeNumberErrorTest(d);
}


int main() {

	try {
		double x, y;
		cout << "x: ";
		cin >> x;
		y = WurzelVon(x);
		cout << "wurzel(x): " << y << endl;
	}
	catch (NegativeNumberErrorTest& er) {
		er.meldeFehler();
	}
	

	cout << "ENDE" << endl;



	system("pause");
	return 0;
}