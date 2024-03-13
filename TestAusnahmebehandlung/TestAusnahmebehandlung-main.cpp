

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x, y = 0;
	cout << "x: ";
	cin >> x;

	y = sqrt(x);
	cout << "Wurzel: y= " << y << endl;

	y += 1. / x;
	cout << "Kehrwert: y = " << y << endl;

	cout << "ENDE" << endl;
	system("pause");
	return 0;
}
