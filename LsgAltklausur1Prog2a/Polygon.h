
#ifndef polygon.h
#define polygon.h

#include <iostream>
#include "Punkt.h"
using namespace std;


class Polygon {

public:
	Polygon();
	Polygon(int n);
	~Polygon();

	//setter und getter
	void setNecken(int);
	int getNecken() const;

	//kopierkonstruktor
	Polygon(const Polygon&);
	//zuweisungsoperator
	Polygon& operator=(const Polygon&);

	Punkt getEcke(const Punkt& p) const;

	void Polygon::verschieben(double, double);


private:
	int necken;
	int* ecken;


};
#endif // !polygon.h