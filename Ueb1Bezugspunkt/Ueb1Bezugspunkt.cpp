/*
*  Bezugspunkt.cpp
*  Programmieren IIb, Übungsblatt 2, Ü1
*/

#include "Ueb1Bezugspunkt.h"

#define _USE_MATH_DEFINES // Um Konstante M_PI in VisualStudio zu benutzen
#include <math.h>
#include <cfloat>         // DBL_EPSILON
#include <iostream>
using namespace std;

Ueb1Bezugspunkt::Ueb1Bezugspunkt(double xpos, double ypos)
	: x(xpos), y(ypos) {}

Ueb1Bezugspunkt::~Ueb1Bezugspunkt(){}

double Ueb1Bezugspunkt::getX() const { return x; }

double Ueb1Bezugspunkt::getY() const { return y; }

void Ueb1Bezugspunkt::setX(double xpos) { x = xpos; }

void Ueb1Bezugspunkt::setY(double ypos) { y = ypos; };

void Ueb1Bezugspunkt::verschieben(double dx, double dy) {
	x += dx;
	y += dy;
}

void Ueb1Bezugspunkt::ausgeben(ostream& ausgabe) const {
	cout << "(" << x << ", " << y << ")";
}




double Ueb1Bezugspunkt::flaecheBerechnen() const {

	return 0;
}


ostream& operator<< (ostream& ausgabe, const Ueb1Bezugspunkt& bp) {
	bp.ausgeben(ausgabe);
	return ausgabe;

}