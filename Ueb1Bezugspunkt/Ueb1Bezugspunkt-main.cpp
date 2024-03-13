/*
*  Bezugspunkt-main.cpp
*  Programmieren IIb, Übungsblatt 1, Ü1
*/

#include "Ueb1Bezugspunkt.h"
#include "Ueb1Kreis.h"
#include "Ueb1Rechteck.h"

#include <iostream>
using namespace std;

int main(void) {

	/*
	Ueb1Kreis kreis(1., -1., 4);
	Ueb1Rechteck rechteck(-1., 1., 2., 1.);
	Ueb1Rechteck quadrat(3., 2., 4.);

	kreis.ausgeben();
	kreis.verschieben(.5, -2.1);
	cout << "Der neue Bezugspunkt des Kreises: " << endl;
	kreis.Ueb1Bezugspunkt::ausgeben();
	cout << endl;

	rechteck.ausgeben();
	// Auf die Methode der Basisklasse zugreifen
	rechteck.Ueb1Bezugspunkt::ausgeben();

	// Ein Quadrat
	cout << endl << "Quadrat" << endl;
	quadrat.ausgeben();
	*/

	Ueb1Kreis kreis(0., -1., 4);
	Ueb1Rechteck rechteck(-1., 1., 2., 1.);
	Ueb1Rechteck quadrat(0., 0., 2., 2.);

	Ueb1Bezugspunkt* figuren[] = { &kreis, &rechteck, &quadrat };

	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << *figuren[i] << endl;
		cout << "Flaeche: " << figuren[i]->flaecheBerechnen() << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "Bezugspunkt um (-1,1) verschieben:";
		// Die Methode der Basisklasse aufrufen
		figuren[i]->Ueb1Bezugspunkt::ausgeben(cout);
		figuren[i]->verschieben(-1., 1.);
		cout << *figuren[i] << endl;
	}


	system("pause");
	return 0;
}


