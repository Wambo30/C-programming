#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double WurzelVon(double d) {
	if (d >= 0.0)
		return sqrt(d);
	else
		throw d;
}

double kehrwertVon(double d) {
	if (d) // d!=0
		return 1. / d;
	else
		throw string("FEHLER: Division durch Null");
}


int main() {
	try {
		double x, y;
		cout << "x: ";
		cin >> x;
		y = WurzelVon(x);
		cout << "wurzel(x) = " << y << endl;
		y += kehrwertVon(x);
		cout << "wurzel(x) + 1/x = " << y << endl;
	}
	catch (double z) { cout << "FEHLER: " << z << "ist negativ" << endl; }
	catch (string s) { cout << s << endl; }

	cout << "ENDE" << endl;


	system("pause");
	return 0;
}