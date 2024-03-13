//  main.cpp
//  prog2A-uebung-2-Rational

#include "Rational.h"
#include <iostream>
using namespace std;

int main() {

	/*
	Rational b1, b2(3), b3(8, -24), b4(-15, -20);

	cout << "b1: ";
	b1.ausgeben();
	cout << endl;

	cout << "b2: ";
	b2.ausgeben();
	cout << "b2 umkehren: ";
	b2.umkehren();
	b2.ausgeben();
	cout << endl;

	cout << "b3: ";
	b3.ausgeben();
	cout << "b3 mit -3 multiplizieren: ";
	b3.multiplizieren(-3);
	b3.ausgeben();
	cout << endl;


	cout << "** Aufaddieren ** " << endl;
	cout << " b1: ";
	b1.ausgeben();
	cout << " b2: ";
	b2.ausgeben();
	b1.addieren(b2);  // b1 = b1 + b2
	cout << " b1 + b2 -> b1: ";
	b2.ausgeben();
	cout << endl;

	cout << "** Aufmultiplizieren ** " << endl;
	cout << " b2: ";
	b2.ausgeben();
	cout << " b4: ";
	b4.ausgeben();
	b2.multiplizieren(b4);  // b1 *= b2
	cout << " b2 * b4 -> b2 ";
	b2.ausgeben();
	*/
	// Analog funktionieren die Methoden subtrahiere und dividiere

	// test addieren
	Rational b1(1, 2);
	//cout << "ausgabe von b1: "<< b1<<endl ;
	b1.ausgeben();
	Rational b2(1, 4);
	//Rational erg = b1.multiplizieren(b2);

	cout << "ausgabe b1*b2: " ;
	b1.ausgeben();

	cout << "ausgabe von b1=b1*b2 mit cout alleine: " << b1 << endl;

	cout << "ausgabe b2" << endl;
	b2.ausgeben();
	//cout << b1 << endl;





	system("pause");
	return 0;
}
