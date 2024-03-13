#include "Bezugspunkt"

class Rechteck : public Bezugspunkt {
public:
	Rechteck(double&, double&);
	double getRadius()const;
	void setRadius(double);
	double flaecheBerechnen(Kreis&);
private:
	double hoehe;
	double breite;


};