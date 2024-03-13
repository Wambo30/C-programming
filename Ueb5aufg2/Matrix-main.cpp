/*
*  Matrix-main.cpp
*/

#include "Matrix.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {

	srand(time(NULL));

	Matrix m1(3, 4), m2(3, 4), m3(4, 2);

	cout << endl << "m1 :" << endl;
	cout << m1 << endl;
	cout << endl << "m2 :" << endl;
	cout << m2 << endl;
	m1 += m2;
	cout << endl << "m1 += m2" << endl;
	cout << m1 << endl;

	cout << endl << "m2 :" << endl;
	cout << m2 << endl;
	cout << endl << "m3 :" << endl;
	cout << m3 << endl;
	cout << endl << "m2 *= m3" << endl;
	m2 *= m3;
	cout << m2 << endl;

	system("pause");

	return 0;
}
