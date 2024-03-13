#include <iostream>
#include "Polygon.h"
#include "Punkt.h"
using namespace std;


Polygon::Polygon():necken(1) {
	ecken = new int[necken];
	ecken[0] = 0;
}

Polygon::Polygon(int n) {
	

}

// konstruktor mit zufälligen ecken
Polygon::Polygon(int e) : necken(e) {
	ecken = new int [necken + 1];
	for (int i = 0; i < necken + 1; i++) {
		ecken[i] = (rand() % 20001 - 10000) / 10000.;
	}
	// warum? wollen zufallszahl zwischen -1 und 1 haben und nehmen einfach 10000 zahl
	//und teulen sie einfach durch 10000--> somit haben wir eine zahl zw -1 und 1

	while (abs(ecken[necken +1] < DBL_EPSILON)) {
		ecken[necken] = (rand() % 20001 - 10000 / 10000.);
	}
}



Polygon::~Polygon() {
	delete[] ecken;
}


//setter und getter
void Polygon::setNecken(int n) {
	necken = n;
}

int Polygon::getNecken() const {
	return necken;
}

//kopierkonstruktor
Polygon::Polygon(const Polygon& p) : necken(p.necken) {
	ecken = new int[necken + 1];
	for (int i = 0; i < necken + 1; i++) {
		ecken[i] = p.ecken[i];
	}
}

//zuweisungsoperator
Polygon& Polygon::operator=(const Polygon& p) {
	if (ecken) {
		delete[] ecken;
	}
	ecken = new int[p.necken+1];
	for (int i = 0; i <= p.necken; i++) {
		ecken[i] = p.ecken[i];
	}
	necken = p.necken;
	return *this;

}


Punkt Polygon::getEcke( const Punkt& p) const {
	cout << p.getX() << "/" << p.getY() << endl;

}

void Polygon::verschieben(double x, double y) {
	

}
