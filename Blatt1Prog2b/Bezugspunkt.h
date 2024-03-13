/*
*  Bezugspunkt.h
*  Programmieren IIb, uebungsblatt 1, Ü1
*
*  Basisklasse fuer zweidimensionale geometrische Figuren.
*  Bezugspunkt fuer die Lage der Figur auf der Ebene.
*/

#ifndef BEZUGSPUNKT_H
#define BEZUGSPUNKT_H

class Bezugspunkt {
public:
	Bezugspunkt(double xpos, double ypos);

	double getX() const;
	double getY() const;
	void setX(double xpos);
	void setY(double ypos);

	void verschieben(double dx, double dy);
	void ausgeben() const;

protected:
	double x, y;
};

#endif // BEZUGSPUNKT_H

class Kreis : public Bezugspunkt {
public:
	Kreis(double xpos, double ypos, double r);

	double getRadius()const;
	void setRadius(double);
	double flaecheBerechnen() const;
	void ausgeben() const;
private:
	double radius;

};

class Rechteck : public Bezugspunkt {
public:
	Rechteck(double x, double y, double h, double b);
	Rechteck(double x, double y, double h);
	double getHoehe() const;
	double getBreite() const;
	void setHoehe(double);
	void setBreite(double);

	double flaecheBerechnen() const;
	void ausgeben() const;
private:
	double hoehe;
	double breite;


};