#include "Punkt.h"
using namespace std;
#include <iostream>

//konstruktoren

//punkt objekt auf ursprung
Punkt::Punkt() {
	x = y = 0;
}
/*
oder man schreibt standard konstr.
Punkt::Punkt():x(0),y(0){ }
*/

// aufg 2.2 damit können wir NUN selber standard werte vfestlegen inmain
Punkt::Punkt(double xwert, double ywert) {
	x = xwert;// gilt da x der standardwert ist!
	y = ywert;
}


// destruktor
Punkt::~Punkt() {
}


// get und set methoden

void Punkt::setX(double wert) {
	x = wert;
}

void Punkt::setY(double wert) {
	y = wert;
}

double Punkt::getX() const {
	return x;
}

double Punkt::getY() const {
	return y;
}

void Punkt::verschieben(double xwert , double ywert) {
	x += xwert;
	y += ywert;
}

void Punkt::spiegelnAnX() {
	y *= -1; // oder y=-y da spiegelung immer gegenvektor darstellt
}

void Punkt::spiegelnAnY() {
	x = -x; // oder x*=-1

}
// void da wir ja was ändern wollen und nicht lesen!
void Punkt::amUrsprungDrehen(double winkel) {
	double xAlt = x;
	x = x*cos(winkel) - y*sin(winkel);
	y = xAlt*sin(winkel) + y*cos(winkel);

}