#include "Ueb1Rechteck.h"
#define _USE_MATH_DEFINES // Um Konstante M_PI in VisualStudio zu benutzen
#include <math.h>
#include <cfloat>         // DBL_EPSILON
#include <iostream>
using namespace std;

/*
Ueb1Rechteck::Ueb1Rechteck(): hoehe(1.), breite(1.){}

Ueb1Rechteck::~Ueb1Rechteck(){}
*/

Ueb1Rechteck::Ueb1Rechteck(double x, double y, double h, double b)
	: Ueb1Bezugspunkt(x, y), hoehe(h), breite(b) {
}

Ueb1Rechteck::Ueb1Rechteck(double x, double y, double h)
	: Ueb1Bezugspunkt(x, y), hoehe(h), breite(h) {
}

double Ueb1Rechteck::getHoehe() const { return hoehe; }

double Ueb1Rechteck::getBreite() const { return breite; }

void Ueb1Rechteck::setHoehe(double h) {
	if (abs(hoehe - breite) < DBL_EPSILON) { // Ein Quadrat
		breite = hoehe = h;
	}
	else {
		hoehe = h;
	}
}

void Ueb1Rechteck::setBreite(double b) {
	if (abs(hoehe - breite) < DBL_EPSILON) { // Ein Quadrat
		breite = hoehe = b;
	}
	else {
		breite = b;
	}
}

double Ueb1Rechteck::flaecheBerechnen() const {
	return breite * hoehe;
}

void Ueb1Rechteck::ausgeben(ostream& ausgabe) const {
	if (abs(hoehe - breite) < DBL_EPSILON) { // Ein Quadrat
		cout << endl << "--- Quadrat: " << endl << "Linke obere Ecke: ";
		Ueb1Bezugspunkt::ausgeben( ausgabe);
		cout << "   Seite: " << hoehe << endl;
	}
	else {
		cout << endl << "--- Rechteck: " << endl << "Linke obere Ecke: ";
		Ueb1Bezugspunkt::ausgeben( ausgabe);
		cout << "   Hoehe: " << hoehe << "   Breite: " << breite << endl;
	}
}

