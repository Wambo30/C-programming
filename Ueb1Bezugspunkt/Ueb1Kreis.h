#pragma once
#include "Ueb1Bezugspunkt.h"
class Ueb1Kreis : public Ueb1Bezugspunkt {

public:
	Ueb1Kreis(double xpos, double ypos, double r);

	double getRadius() const;
	void setRadius(double r);
	double flaecheBerechnen() const;
	void ausgeben(ostream&) const;

private:
	double radius;

};

