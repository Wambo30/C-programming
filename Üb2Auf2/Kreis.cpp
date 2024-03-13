//  Kreis.cpp
//  prog2A-uebung2-PunktUndKreis

#include "Kreis.h"
#include <iostream>

#define _USE_MATH_DEFINES   // wegen Konstante M_PI
#include <cmath>

const double M_PI = 3.141592;

using namespace std;

// Konstruktoren und Destruktor
Kreis::Kreis() : radius(1.) {}
// Der Mittelpunkt wird durch den automatischen Aufruf des
// Standardkonstruktors von Punkt auf (0,0) gesetzt

Kreis::Kreis(double r, const Punkt& m) : mittelpunkt(m) {
	setRadius(r);
}

Kreis::~Kreis() {}

// Setter
void  Kreis::setRadius(double r) {
	if (r >= 0) {
		radius = r;
	}
	else {
		cout << "FEHLER: Negativer Radius " << r << endl;
	}
}

void  Kreis::setMittelpunkt(const Punkt& pm) {
	mittelpunkt = pm;
}

// Getter
double Kreis::getRadius() const { return radius; }
Punkt Kreis::getMittelpunkt() const { return mittelpunkt; }


// Kreis um einen Vektor (dx,dy) auf der Ebene verschieben
void  Kreis::verschieben(double x, double y) {
	mittelpunkt.verschieben(x, y);
}

// Flaechenberechung
double Kreis::flaecheBerechnen() const {
	return radius * radius * M_PI;
}

// einen Kreis im Format K[r, (x,y)] ausgeben
void Kreis::ausgeben() const {
	cout << "K[ " << radius << ", (";
	cout << mittelpunkt.getX() << ",";
	cout << mittelpunkt.getY() << ")]" << endl;
}

