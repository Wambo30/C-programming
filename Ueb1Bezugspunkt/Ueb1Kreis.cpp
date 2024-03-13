#include "Ueb1Kreis.h"
#define _USE_MATH_DEFINES // Um Konstante M_PI in VisualStudio zu benutzen
#include <math.h>
#include <cfloat>         // DBL_EPSILON
#include <iostream>
using namespace std;

Ueb1Kreis::Ueb1Kreis(double xpos, double ypos, double r)
	: Ueb1Bezugspunkt(xpos, ypos), radius(r) {
}

double Ueb1Kreis::getRadius() const { return radius; }

void Ueb1Kreis::setRadius(double r) {
	radius = r;
}

double Ueb1Kreis::flaecheBerechnen() const {
	return M_PI * radius * radius;
}

void Ueb1Kreis::ausgeben(ostream& ausgabe) const {
	cout << endl << "--- Kreis: " << endl << "Mittelpunkt: ";
	Ueb1Bezugspunkt::ausgeben(ausgabe);
	cout << "   Radius: " << radius << endl;
}
