#pragma once
//  Kreis.h
//  prog2A-uebung2-PunktUndKreis

#ifndef KREIS_H
#define KREIS_H

#include "Punkt.h"          // Wir verwenden die Klasse Punkt !!!

class Kreis {
public:
	// Konstruktoren und Destruktor
	Kreis();
	Kreis(double r, const Punkt& m);
	~Kreis();

	// Setter und Getter
	void   setRadius(double r);
	void   setMittelpunkt(const Punkt& p);
	double getRadius() const;
	Punkt  getMittelpunkt() const;

	// Weitere Klassenmethoden

	// einen Kreis um einen Vektor (dx,dy) auf der Ebene verschieben
	void verschieben(double x, double y);

	// die Fläche eines Kreises berechnen
	double flaecheBerechnen() const;

	// einen Kreis im Format K[r, (x,y)] ausgeben
	void ausgeben() const;

private:
	double radius;
	Punkt mittelpunkt;
};
#endif //KREIS_H
