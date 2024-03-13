/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

/* Polynom-main.cpp */
#include "PolynomHA02.h"
#include <iostream>
using namespace std;

int main(void) {
	Polynom p1;
	Polynom p2(3); // zufallskoeffizient wird erstellt-->spezieller konstruktor
	Polynom p3 = p2;    // Kopierkonstruktor
	Polynom p4(3, 1.);

	p1 = p4;

	cout << "p1: " << p1.toString() << endl;
	cout << "p2: " << p2.toString() << endl;
	cout << "p3: " << p3.toString() << endl;
	cout << "p4: " << p4.toString() << endl;


	cout << "p4(3.) = " << p4.wertBerechnen(3.) << endl;

	// So kann auch ein Array mit Nicht-Standardkonstruktoren
	// gebildet werden
	Polynom pliste[] = { Polynom(), Polynom(3), Polynom(3,1.) };

	pliste[0] = pliste[1]; // Zuweisungsoperator:
						   // pliste[0] und pliste[1]
						   // sind Objekte vom Typ Polynom!

	for (int i = 0; i < 3; i++) {
		cout << pliste[i].toString() << endl;
	}

	// Aufaddieren
	cout << endl << "p4*(-1) + p1 = p1 " << endl;
	p4.multiplizieren(-1);
	p1.addieren(p4);
	cout << p1.toString() << endl;

	cout << endl << "Polynommultiplikation" << endl;
	Polynom p5(3, 1.), p6(2, 1.);
	cout << "p5: " << p5.toString() << endl;
	cout << "p6: " << p6.toString() << endl;
	p5.multiplizieren(p6);
	cout << "p5*p6: " << p5.toString() << endl;
	cout << endl;

	// testen operator + und +=
	cout << "HIER werden operatoren getestet!!!" << endl;
	Polynom p10;
	Polynom p11(2, 1);//grad=2, koeffizient= 1
	Polynom p12(2, 2);
	cout << "ausgabe p10: " << p10.toString() << endl;
	cout << "ausgabe p11: " << p11.toString() << endl;
	cout << "ausgabe p12: " << p12.toString() << endl;
	p12 += p11;
	cout << "ausgabe p12+=p11: " << p12.toString() << endl;
	p10 + p11;
	cout << "Ausgabe p10 + p11 mit operator +" << p10.toString() << endl;
	p10 += p11;
	cout << "ausgabe von p10 += p11:  " << p10.toString() << endl;
	cout << endl;

	// testen operator -, -=
	Polynom p13;
	Polynom p14(2, 3);
	Polynom p15(1, 3);
	cout << "ausgabe p13: " << p13.toString() << endl;
	cout << "ausgabe p14: " << p14.toString() << endl;
	cout << "ausgabe p15: " << p15.toString() << endl;
	p13 - p14;
	cout << "ausgabe p13-p14: " << p13.toString() << endl;
	p15 -= p14;
	cout << "ausgabe p15-=p14: " << p15.toString() << endl;
	cout << "ausgabe p13: " << p13.toString() << endl; //p13(2,-3)
	p13 -= p14;
	cout << "ausgabe p13-=p14: " << p13.toString() << endl;
	cout << endl;

	//testen *, *=
	Polynom p16;
	Polynom p17(2, -4);
	Polynom p18(2, 3);
	Polynom p19(2, -2);
	cout << "ausgabe p16: " << p16.toString() << endl;
	cout << "ausgabe p17: " << p17.toString() << endl;
	cout << "ausgabe p18: " << p18.toString() << endl;
	cout << "ausgabe p19: " << p19.toString() << endl;
	p17*p16;
	cout << "ausgabe p17*p16: " << p17.toString() << endl;
	p19 *= p17;
	cout << "ausgabe p19*p18: " << p19.toString() << endl;
	cout << endl;

	//testen multiplikation von polynom mit ganzer zahl
	Polynom p20(2, 3);
	cout << "ausgabe p20: " << p20.toString() << endl;
	p20 = p20*-1;
	cout << "ausgabe p20: " << p20.toString() << endl;
	cout << endl;

	//testen unäres minus
	Polynom p21(3, 2);
	cout << "ausgabe p21: " << p21.toString() << endl;
	//-p21;
	cout << "ausgabe -p21 also mit unaeren minus: " << p21.toString() << endl;
	cout << endl;

	//testen typumwandlungskonstruktor
	Polynom p22(1, 2);
	cout << "ausgabe zahl welches in polynom umgewandelt wird: " << p22.toString() << endl;
	cout << endl;

	// testen ausgabe methode
	Polynom p23(2, 2);
	/*
	cout << "ausgabe p23: " << p23.toString() << endl;
	cout <<"ausgabe p23 OHNE toString(): " <<p23 << endl;
	cout << "ausgabe p22: " << p22.toString() << endl;
	cout << "ausgabe p22 OHNE toString(): " << p22 << endl;
	cout << "ausgabe p19: " << p19.toString() << endl;
	cout << "ausgabe p19 OHNE toString(): " << p19 << endl;
	cout << "ausgabe p21: " << p21.toString() << endl;
	cout << "ausgabe p21 OHNE toString(): " << p21 << endl;
	*/

	//testen index
	Polynom p24(2, 3);
	Polynom p25(2, 4);
	cout << p24 << endl;
	//olynom p25;
	cin >> p25;
	cout << p25 << endl;
	//Test für eckige Klammerfunktion
	cout << "Der Koeffizient der Position 0 lautet " << p25[0] << endl;

	system("pause");
	return 0;
}

