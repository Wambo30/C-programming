/*
 *  Bezugspunkt.cpp
 *  Programmieren IIb, Übungsblatt 3, Ü1
 */
 
#include "Bezugspunkt.h"
#define _USE_MATH_DEFINES // Um Konstante M_PI in VisualStudio zu benutzen
#include <math.h>
#include <cfloat>        // DBL_EPSILON

Bezugspunkt::Bezugspunkt(double xpos, double ypos) 
	: x(xpos), y(ypos) {}

Bezugspunkt::~Bezugspunkt() {}
	
double Bezugspunkt::getX() const  { return x; }

double Bezugspunkt::getY() const  { return y; }

void Bezugspunkt::setX(double xpos) { x = xpos; }

void Bezugspunkt::setY(double ypos) { y = ypos; };
	
void Bezugspunkt::verschieben(double dx, double dy) 	{ 
    x += dx; 
    y += dy;
}

void Bezugspunkt::ausgeben(ostream& aus) const { 
    aus << "(" << x << "," << y << ")";
}

ostream& operator<<(ostream& aus, const Bezugspunkt& p) {
    p.ausgeben(aus);
    return aus;
}

/* Kreis */
Kreis::Kreis(double xpos, double ypos, double r)
: Bezugspunkt(xpos, ypos), radius(r) {}

Kreis::~Kreis() {}

double Kreis::getRadius() const  { return radius; }

void Kreis::setRadius(double r) {
    radius = r;
}

void Kreis::ausgeben(ostream& aus) const {
    aus << endl << "--- Kreis: " << endl << "Mittelpunkt: ";
    Bezugspunkt::ausgeben(aus);
    aus << "   Radius: " << radius << endl;
}

double Kreis::flaecheBerechnen() const {
    return M_PI * radius * radius;
}

/* Rechteck */

Rechteck::Rechteck(double x, double y, double h, double b)
: Bezugspunkt(x,y), hoehe(h), breite(b) {
}

Rechteck::Rechteck(double x, double y, double h)
: Bezugspunkt(x,y), hoehe(h), breite(h) {
}

Rechteck::~Rechteck() {}

double Rechteck::getHoehe() const   { return hoehe; }

double Rechteck::getBreite() const  { return breite; }

void Rechteck::setHoehe(double h) {
    if ( abs(hoehe - breite) < DBL_EPSILON ) { // Ein Quadrat
        breite = hoehe = h;
    }
    else {
        hoehe = h;
    }
}

void Rechteck::setBreite(double b) {
    if ( abs(hoehe - breite) < DBL_EPSILON ) { // Ein Quadrat
        breite = hoehe = b;
    }
    else {
        breite = b;
    }
}

double Rechteck::flaecheBerechnen() const {
    return breite * hoehe;
}

void Rechteck::ausgeben(ostream& aus) const {
    if ( abs(hoehe - breite) < DBL_EPSILON ) { // Ein Quadrat
        aus << endl << "--- Quadrat: " << endl << "Linke obere Ecke: ";
        Bezugspunkt::ausgeben(aus);
        aus << "   Seite: " << hoehe << endl;
    }
    else {
        aus << endl << "--- Rechteck: " << endl << "Linke obere Ecke: ";
        Bezugspunkt::ausgeben(aus);
        aus << "Hoehe: " << hoehe << "   Breite: " << breite << endl;
    }
}

