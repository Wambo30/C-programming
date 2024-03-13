/*
*  Bezugspunkt.h
*  Programmieren IIb, Übungsblatt 1, Ü1
*
*  Bezugspunkt - Basisklasse fuer zweidimensionale geometrische Figuren.
*  Bezugspunkt fuer die Lage der Figur auf der Ebene.
*
*  Abgeleitete Klassen:
*  Kreis - um den Bezugspunkt
*  Rechteck - mit dem Bezugspunkt in der linken oberen Ecke
*/

#ifndef Ueb1BEZUGSPUNKT_H
#define Ueb1BEZUGSPUNKT_H
#include <iostream>
using namespace std;

class Ueb1Bezugspunkt {
	friend ostream& operator<< (ostream& ausgabe, const Ueb1Bezugspunkt& b);

public:

	//friend ostream& operator<< (ostream& ausgabe, const Ueb1Bezugspunkt& b);
	Ueb1Bezugspunkt(double xpos, double ypos);
	virtual ~Ueb1Bezugspunkt();

	double getX() const;
	double getY() const;
	void setX(double xpos);
	void setY(double ypos);

	void verschieben(double dx, double dy);
	virtual void ausgeben(ostream&) const;

	virtual double flaecheBerechnen() const;
	// durch virtual entsteht dynamische bindung

private:
	double x, y;
};



#endif // BEZUGSPUNKT_H

