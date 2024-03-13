/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
#ifndef FUNKTION_H
#define FUNKTION_H

#include <iostream>
using namespace std;

class Funktion
{
public:
	Funktion(size_t); //konstruktor mit zufallskoeffizienten
	Funktion (const Funktion& p); //Kopierkonstruktor
	Funktion& operator=(const Funktion& p);	//zuweisungsoperator
	virtual ~Funktion();

	bool istGerade();
	bool istUngerade();

	virtual const double operator()(double) const;	// p(x)
	double ableitung(double) const;
	double betrag(double x) const;
	void nullstellenFinden(double*&) const;	//Newton- Verfahren
	string toString() const;

protected:
	size_t grad;
	double* koeffizienten;

};
#endif





