/*
*  Bezugspunkt.cpp
*  Programmieren IIb, Übungsblatt 2, Ü1
*/

#include "Bezugspunkt.h"

#define _USE_MATH_DEFINES // Um Konstante M_PI in VisualStudio zu benutzen
#include <math.h>
#include <cfloat>         // DBL_EPSILON
#include <iostream>
using namespace std;

Bezugspunkt::Bezugspunkt(double xpos, double ypos)
	: x(xpos), y(ypos) {}

double Bezugspunkt::getX() const { return x; }

double Bezugspunkt::getY() const { return y; }

void Bezugspunkt::setX(double xpos) { x = xpos; }

void Bezugspunkt::setY(double ypos) { y = ypos; };

void Bezugspunkt::verschieben(double dx, double dy) {
	x += dx; // wenn dx negativ ist dann wird nach links bei pos. nach rechts versch.
	y += dy; //analog
}

void Bezugspunkt::ausgeben() const {
	cout << "(" << x << ", " << y << ")";
}


/*************Kreis*********************/


Kreis::Kreis(double xpos, double ypos, double r)
	: Bezugspunkt(xpos, ypos), radius(r) {
}

double Kreis::getRadius() const { return radius; }

void Kreis::setRadius(double r) {
	radius = r;
}

double Kreis::flaecheBerechnen() const {
	return M_PI * radius * radius;
}

void Kreis::ausgeben() const {
	cout << endl << "--- Kreis: " << endl << "Mittelpunkt: ";
	//mittelpunkt == bezugspunkt gemeint! also wovon man ausgeht
	Bezugspunkt::ausgeben();
	cout << "   Radius: " << radius << endl;
}

/********** Rechteck *********************************/

Rechteck::Rechteck(double x, double y, double h, double b)
	: Bezugspunkt(x, y), hoehe(h), breite(b) {
}

Rechteck::Rechteck(double x, double y, double h)
	: Bezugspunkt(x, y), hoehe(h), breite(h) {
}// einfach konstr wo breite durch stanni wert schon festgelegt wurde

double Rechteck::getHoehe() const { return hoehe; }

double Rechteck::getBreite() const { return breite; }

void Rechteck::setHoehe(double h) {
	if (abs(hoehe - breite) < DBL_EPSILON) { // Ein Quadrat
		breite = hoehe = h;
	}
	else {
		hoehe = h;
	}
}

void Rechteck::setBreite(double b) {
	if (abs(hoehe - breite) < DBL_EPSILON) { // Ein Quadrat
		breite = hoehe = b;
	}
	else {
		breite = b;
	}
}

double Rechteck::flaecheBerechnen() const {
	return breite * hoehe;
}

void Rechteck::ausgeben() const {
	if (abs(hoehe - breite) < DBL_EPSILON) { // Ein Quadrat
		cout << endl << "--- Quadrat: " << endl << "Linke obere Ecke: ";
		Bezugspunkt::ausgeben();
		cout << "   Seite: " << hoehe << endl;
	}
	else {
		cout << endl << "--- Rechteck: " << endl << "Linke obere Ecke: ";
		Bezugspunkt::ausgeben();
		cout << "   Hoehe: " << hoehe << "   Breite: " << breite << endl;
	}
}


