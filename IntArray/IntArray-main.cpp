// IntArray-main.cpp

#include "IntArray.h"
#include <iostream>
using namespace std;

int main() {
	IntArray a(3, -2), b(2,3);
	/*
	cout << a[2] << endl;
	a[2] = 4;
	cout << a[4] << endl;
	*/

	cout << &a << endl;
	cout << &b << endl;


	system("pause");
	return 0;
}
