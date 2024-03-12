/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
// PolynomHA01-main.cpp 

#include "PolynomHA01.h"
#include "Quadratisch.h"
#include "Linear.h"
#include <iostream>
using namespace std;

int main(void) {

	PolynomHA01 p1(3);
	// Auswertung mit Zufallsvariablen
	cout << "p1: " << p1.toString() << endl;
	cout << "p(x): " << p1(5) << endl;

	cout << endl << "selbst ausgewählte Variablen zur besseren Auswertung" << endl;
	p1[0] = 1;
	p1[1] = 1;
	p1[2] = -1;
	p1[3] = 1;
	cout << "p1 eigene werte: " << p1.toString() << endl;
	cout << "p(x): " << p1(2) << endl;
	cout << "ableitung p(x) = " << p1.ableitung(2) << endl;

	// PolynomHA01 mit eigenen werten
	PolynomHA01 p2(1);
	p2[0] = 1;
	p2[1] = 2;
	cout << "p2 eigene werte: " << p2.toString() << endl;
	double* x = new double(2.0);
	p2.nullstellenFinden(x);
	cout << "Nullstellen von p(x) = " << *x << endl;

	double* x3 = new double(2.0);
	// PolynomHA01 ohne nullstelle
	PolynomHA01 p3(2);
	p3[0] = 1;
	p3[1] = 0;
	p3[2] = 3;
	cout << "p3 eigene werte: " << p3.toString() << endl;
	p3.nullstellenFinden(x3);
	if (x3 == nullptr) {
		cout << " keine Nullstelle vorhanden" << endl;
	}
	else cout << "Nullstellen von p3(x) = " << *x3 << endl;

	double* x4 = new double(2.0);
	//quadratisch zufallspolynom
	cout << "q(x) = " << endl;
	Quadratisch q1;
	cout << "q1(x)=  " << q1.toString() << endl;
	q1.nullstellenFinden(x4);

	if (x4 == nullptr) {
		cout << " keine Nullstelle vorhanden" << endl;
	}
	else cout << "Nullstellen von q1(x) = " << *x4 << endl;

	// quadratisches polynom mit eigenen werten
	Quadratisch q2;
	q2[0] = 1;
	q2[1] = 0;
	q2[2] = 1;
	double* x2 = new double(2.0);
	cout << "q2(x)=  " << q2.toString() << endl;
	q2.nullstellenFinden(x2);
	if (x2 == nullptr) {
		cout << " keine Nullstelle vorhanden" << endl;
	}
	else cout << "Nullstellen von q2(x) = " << *x2 << endl;

	//Lineare PolynomHA01e
	double* x5 = new double(2.0);
	Linear L;
	L[0] = 1;
	L[1] = 1;
	cout << "L(x) " << L.toString() << endl;
	L.nullstellenFinden(x5);
	if (x5 == nullptr) {
		cout << " keine Nullstelle vorhanden" << endl;
	}
	else cout << "Nullstellen von L(x) = " << *x5 << endl;

	//Lineare PolynomHA01e ohne nullstelle

	Linear L2;
	L2[0] = 1;
	L2[1] = 0;
	cout << "L2(x) " << L2.toString() << endl;
	L2.nullstellenFinden(x5);
	if (x5 == nullptr) {
		cout << " keine Nullstelle vorhanden" << endl;
	}
	else cout << "Nullstellen von L2(x) = " << *x5 << endl;

	delete x;
	delete x2;
	delete x3;
	delete x4;

	system("PAUSE");
	return 0;
}
//*/
