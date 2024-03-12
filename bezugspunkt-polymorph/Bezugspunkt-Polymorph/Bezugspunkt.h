/*
 *  Bezugspunkt.h
 *  Programmieren IIb, Übungsblatt 3, Ü1
 *
 *  Bezugspunkt - eine abstrakte Basisklasse
 *  fuer zweidimensionale geometrische Figuren.
 *  Bezugspunkt für die Lage der Figur
 */

#ifndef BEZUGSPUNKT_H
#define BEZUGSPUNKT_H
#include <iostream>
using namespace std;

class Bezugspunkt {   
public:
	Bezugspunkt(double xpos, double ypos);
    virtual ~Bezugspunkt();
    
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
    
	// die Methode verschieben muss nicht virtual sein
    // weil sie nicht überschrieben wird
	virtual void verschieben(double dx, double dy); 
            
    // mit Hilfe dieser Methode wird der Operator <<
    // in den abgeleiteten Klassen ueberladen
    virtual void ausgeben(ostream&) const;
    virtual double flaecheBerechnen() const = 0;

private:
	double x, y;   
};

ostream& operator<<(ostream& aus, const Bezugspunkt& p);

/* Kreis */

class Kreis: public Bezugspunkt {
    
public:
    Kreis(double xpos, double ypos, double r);
    virtual ~Kreis();
    
    double getRadius() const;
    void setRadius(double);
    virtual void ausgeben(ostream&) const;
    virtual double flaecheBerechnen() const;
    
private:
    double radius;
};

/* Rechteck */

class Rechteck: public Bezugspunkt {
public:
    Rechteck(double x, double y, double h, double b);
    Rechteck(double x, double y, double h); // Konstruktor fuer ein Quadrat
    virtual ~Rechteck();
    
    double getHoehe() const;
    double getBreite() const;
    void setHoehe(double);
    void setBreite(double);
    
    virtual void ausgeben(ostream&) const;
    virtual double flaecheBerechnen() const;
    
private:
    double hoehe, breite;
};

#endif // BEZUGSPUNKT_H
