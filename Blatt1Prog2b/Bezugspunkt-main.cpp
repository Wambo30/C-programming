/*
*  Bezugspunkt-main.cpp
*  Programmieren IIb, Übungsblatt 1, Ü1
*/

//#include "Kreis.h"
//#include "Rechteck.h"
#include "Bezugspunkt.h"
//in bezugspunkt ist kreis, rechteck enthalten
#include <iostream>
using namespace std;

int main(void) {
	Kreis kreis(1., -1., 4);
	Rechteck rechteck(-1., 1., 2., 1.);

	kreis.ausgeben();
	kreis.verschieben(.5, -2.1);
	cout << "Der neue Bezugspunkt des Kreises: ";
	kreis.Bezugspunkt::ausgeben();
	cout << endl;

	rechteck.ausgeben();
	rechteck.Bezugspunkt::ausgeben();

	system("pause");
	return 0;
}


