/*
*  PolynomUeb3.cpp
*  Programmieren IIb - Projekt 1
*/

#include "PolynomUeb3.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "IndexFehler.h"

using namespace std;

// Standardkonstruktor erzeugt die Nullfunktion p(x) = 0
PolynomUeb3::PolynomUeb3() : grad(0) {
	koeffizienten = new double[1];
	koeffizienten[0] = 0;
}

/*
// Konstruktor fuer ein PolynomUeb3 g-ten Grades mit Zufall-Koeffizienten
PolynomUeb3::PolynomUeb3(int g): grad(g) {
koeffizienten = new double[grad+1];
for(size_t i = 0; i < grad + 1; i++)
koeffizienten[i] = rand()%10*0.9;
}
*/

// Konstruktor fuer ein PolynomUeb3 g-ten Grades mit gleichen Koeffizienten
PolynomUeb3::PolynomUeb3(int g, const double& a) : grad(g) {
	koeffizienten = new double[grad + 1];
	for (size_t i = 0; i < grad + 1; i++)
		koeffizienten[i] = a;
}

// Typumwandlungskonstruktor einer Zahl in ein PolynomUeb3
PolynomUeb3::PolynomUeb3(const double& d) : grad(0) {
	koeffizienten = new double[1];
	koeffizienten[0] = d;
}

// Kopierkonstruktor 
PolynomUeb3::PolynomUeb3(const PolynomUeb3& p) : grad(p.grad) {
	koeffizienten = new double[grad + 1];
	for (size_t i = 0; i < grad + 1; i++)
		koeffizienten[i] = p.koeffizienten[i];
}

//Destruktor
PolynomUeb3::~PolynomUeb3() {
	if (koeffizienten) {
		delete[] koeffizienten;
		koeffizienten = 0;
	}
}

// Zuweisungsoperator überladen
PolynomUeb3& PolynomUeb3::operator=(const PolynomUeb3& p) {
	if (koeffizienten)
		delete[] koeffizienten;
	koeffizienten = new double[p.grad + 1];
	for (size_t i = 0; i <= p.grad; i++)
		koeffizienten[i] = p.koeffizienten[i];
	grad = p.grad;

	return *this;
}

size_t PolynomUeb3::getGrad() const { return grad; }

/* Operatoren */

// operator[] statt Setter und Getter fuer koeffizienten 
// Er arbeitet wie Index-Operator für koeffizienten
// wir greifen aber mit dem PolynomUeb3-Objekt darauf
// Referenzrückgabe, damit der Operator links vom Zuweisungsoperator stehen kann
double& PolynomUeb3::operator[](size_t i) {
	if (i <= grad) {
		return koeffizienten[i];
	}
	else {
		throw out_of_range(" ");
		//cout << "operator[]: FEHLER: falscher Index!" << endl;
		//return koeffizienten[0]; // wir müssen etwas zurückgeben
	}
}

// damit der Operator auch von konstanten Objekten aufgerufen werden kann
// siehe Operator <<
double& PolynomUeb3::operator[](size_t i) const {
	if (i <= grad) {
		return koeffizienten[i];
	}
	else {
		throw out_of_range(" ");
		//cout << "operator[]: FEHLER: falscher Index!" << endl;
		//return koeffizienten[0]; // wir müssen etwas zurückgeben
	}
}

// Den Wert des PolynomUeb3s an der Stelle x berechnen
// statt wertBerechnen
double PolynomUeb3::operator()(const double& x) const {
	double wert = 0;
	for (size_t i = 0; i < grad + 1; i++) {
		wert += koeffizienten[i] * pow(x, (int)i);
	}
	return wert;
}

// Rechenoperationen
const PolynomUeb3 PolynomUeb3::operator-() const {
	PolynomUeb3 p = *this;
	p *= -1;
	return p;
}

PolynomUeb3& PolynomUeb3::operator+=(const PolynomUeb3& p) {
	if (grad == p.grad) {
		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
		// Es kann passieren, dass die führenden Koeffizienten 
		// gleich 0 sind - diese müssen wie folgt eliminiert werden

		// Anzahl der führenden Nullen berechnen
		size_t anzahl = grad;
		for (size_t i = grad; i > 0; i--) {
			if (koeffizienten[i] != 0) {
				break;
			}
			else {
				anzahl--;
			}
		}
		// Ein neues PolynomUeb3 mit anzahl Koeffizienten erstellen
		// anzhal ist jetzt der neue Grad
		PolynomUeb3 pol((int)anzahl, 0);

		// Die Koeffizienten ohne führende Nullen reinkopieren
		for (size_t i = 0; i < anzahl + 1; i++) {
			pol.koeffizienten[i] = koeffizienten[i];
		}
		// Unser Objekt mit pol nun ersetzen
		*this = pol;

	}
	else if (grad > p.grad) {
		for (size_t i = 0; i < p.grad + 1; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
	}
	else { //(grad < p.grad )
		   // Kopie gleich dem Parameter p erstellen
		   // zur Kopie unser aktuelles Objekt aufsumieren
		PolynomUeb3 pol = p;
		for (size_t i = 0; i < grad + 1; i++) {
			pol.koeffizienten[i] += koeffizienten[i];
		}
		// unser Objekt mit der Kopie ersetzen
		*this = pol;
	}
	return *this;
}

PolynomUeb3& PolynomUeb3::operator-=(const PolynomUeb3& p) {
	*this += -p;
	return *this;
}

PolynomUeb3& PolynomUeb3::operator*=(const PolynomUeb3& p) {
	if (p.grad >  0) {
		PolynomUeb3 t(grad + p.grad, 0.);
		for (size_t i = 0; i <= grad; i++) {
			for (size_t j = 0; j <= p.grad; j++) {
				t.koeffizienten[i + j] += koeffizienten[i] * p.koeffizienten[j];
			}
		}
		*this = t;
	}
	else {
		*this *= p.koeffizienten[0];
	}
	return *this;
}


// Operationen mit einer Gleitkommazahl
PolynomUeb3& PolynomUeb3::operator+=(const double& x) {
	koeffizienten[0] += x;
	return *this;
}

PolynomUeb3& PolynomUeb3::operator-=(const double& x) {
	koeffizienten[0] -= x;
	return *this;
}

PolynomUeb3& PolynomUeb3::operator*=(const double& x) {
	if (!x) {
		PolynomUeb3 p; // Nullpolynom
		*this = p;
	}

	for (size_t i = 0; i < grad + 1; i++) {
		koeffizienten[i] *= x;
	}
	return *this;
}

const PolynomUeb3 PolynomUeb3::operator+(const PolynomUeb3& p) {
	PolynomUeb3 r = *this;
	r += p;
	return r;
}

const PolynomUeb3 PolynomUeb3::operator-(const PolynomUeb3& p) {
	PolynomUeb3 r = *this;
	r -= p;
	return r;
}

const PolynomUeb3 PolynomUeb3::operator*(const PolynomUeb3& p) {
	PolynomUeb3 r = *this;
	r *= p;
	return r;
}


/* globale Operatorfunktionen */

const PolynomUeb3 operator+(const double& d, const PolynomUeb3& p) {
	PolynomUeb3 r(d);
	r += p;
	return r;
}

const PolynomUeb3 operator-(const double& d, const PolynomUeb3& p) {
	PolynomUeb3 r(d);
	r -= p;
	return r;
}

const PolynomUeb3 operator*(const double& d, const PolynomUeb3& p) {
	PolynomUeb3 r(d);
	r *= p;
	return r;
}

/* globale Operatorfunktion zur Ausgabe */
ostream& operator<<(ostream& ausgabe, const PolynomUeb3& p) {
	cout << "p(x) = ";
	for (size_t i = p.getGrad(); i > 0; i--) {
		ausgabe << p[i] << " * x^ " << i << " + ";
	}
	ausgabe << p[0] << endl;
	return ausgabe;
}