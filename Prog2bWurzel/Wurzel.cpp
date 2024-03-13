/* rechnen.cpp */
#include <iostream>
#include <cmath>
using namespace std;


int main(void) {
		double x, y;

		cout << "x eingeben: ";
		cin >> x;
		y = sqrt(x);
		cout << "Wurzel: y = " << y << endl;
		y += 1. / x;
		cout << "Kehrwert: y = " << y << endl;
		cout << "ENDE" << endl;
	
	

	system("pause");
	return 0;
}
