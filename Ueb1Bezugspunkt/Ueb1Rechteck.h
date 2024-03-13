#pragma once
#include "Ueb1Bezugspunkt.h"
class Ueb1Rechteck : public Ueb1Bezugspunkt {
public:
	//Ueb1Rechteck::Ueb1Rechteck();
	//virtual Ueb1Rechteck::~Ueb1Rechteck();
	Ueb1Rechteck(double x, double y, double h, double b);
	Ueb1Rechteck(double x, double y, double h); // Konstruktor fuer ein Quadrat
	double getHoehe() const;
	double getBreite() const;
	void setHoehe(double h);
	void setBreite(double b);
	double flaecheBerechnen() const;
	void ausgeben(ostream&) const;

private:
	double hoehe;
	double breite;
};

