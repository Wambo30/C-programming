/*
 *  Polynom.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 4
 */

#include "Polynom.h"
#include "RangeError.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Standardkonstruktor erzeugt die Nullfunktion p(x) = 0
Polynom::Polynom(): grad(0) {
	koeffizienten = new double[1];
	koeffizienten[0] = 0;
}

// Konstruktor fuer ein Polynom g-ten Grades mit gleichen Koeffizienten
Polynom::Polynom(int g, const double& a): grad(g) {
	koeffizienten = new double[grad+1];
	for(size_t i = 0; i < grad + 1; i++)
		koeffizienten[i] = a;
}

// Typumwandlungskonstruktor einer Zahl in ein Polynom
Polynom::Polynom(const double& d): grad(0) {
    koeffizienten = new double[1];
	koeffizienten[0] = d;
}

// Kopierkonstruktor 
Polynom::Polynom(const Polynom& p) : grad(p.grad) {
	koeffizienten = new double[grad+1];
	for(size_t i = 0; i < grad + 1; i++)
		koeffizienten[i] = p.koeffizienten[i];
}

//Destruktor
Polynom::~Polynom() {
    if( koeffizienten ) {
        delete[] koeffizienten;
        koeffizienten = 0;
    }
}

// Zuweisungsoperator überladen
Polynom& Polynom::operator=(const Polynom& p) {	
	if( koeffizienten )
		delete[] koeffizienten;
	koeffizienten = new double[p.grad+1];
	for(size_t i = 0; i <= p.grad; i++)
		koeffizienten[i] = p.koeffizienten[i];
	grad = p.grad;
	
	return *this;
}

size_t Polynom::getGrad() const { return grad; }

/* Operatoren */

// operator[] statt Setter und Getter fuer koeffizieneten 
// Er arbeitet wie Index-Operator für koeffizienten
// wir greifen aber mit dem Polynom-Objekt darauf
// Referenzrückgabe, damit der Operator links vom Zuweisungsoperator stehen kann
double& Polynom::operator[](size_t i) {
    if( i <= grad && i >= 0) {
        return koeffizienten[i];
    }
    else {
        throw RangeError();
    }
}

// damit der Operator auch von konstanten Objekten aufgerufen werden kann
// siehe Operator <<
const double& Polynom::operator[](size_t i) const {
   if( i <= grad && i >= 0) {
        return koeffizienten[i];
    }
    else {
        throw RangeError();
    }
}

// Den Wert des Polynoms an der Stelle x berechnen
// statt wertBerechnen
double Polynom::operator()(const double& x) const {
	double wert = 0;
	for(size_t i = 0; i < grad + 1; i++) {
		wert += koeffizienten[i] * pow(x,(int)i);
    }
	return wert;
}

// Rechenoperationen
const Polynom Polynom::operator-() const {
    Polynom p = *this;
    p *= -1;
    return p;
}

Polynom& Polynom::operator+=(const Polynom& p) {
    if( grad == p.grad) {
        for(size_t i = 0; i < grad + 1; i++) {
            koeffizienten[i] += p.koeffizienten[i];
        }
        // Es kann passieren, dass die führenden Koeffizienten 
        // gleich 0 sind - diese müssen wie folgt eliminiert werden
        
        // Anzahl der führenden Nullen berechnen
        size_t anzahl = grad;
        for(size_t i = grad; i > 0 ; i--) {
            if( koeffizienten[i] != 0) {
                break;
            } 
            else {
                anzahl--;
            }
        }
        // Ein neues Polynom mit anzahl Koeffizienten erstellen
        // anzhal ist jetzt der neue Grad
        Polynom pol((int)anzahl, 0);
        
        // Die Koeffizienten ohne führende Nullen reinkopieren
        for(size_t i = 0; i < anzahl + 1; i++) {
            pol.koeffizienten[i] = koeffizienten[i];
        }
        // Unser Objekt mit pol nun ersetzen
        *this = pol;
        
    }
    else if ( grad > p.grad ) {
        for(size_t i = 0; i < p.grad + 1; i++) {
            koeffizienten[i] += p.koeffizienten[i];
        }
    }
    else  { //(grad < p.grad )
        // Kopie gleich dem Parameter p erstellen
        // zur Kopie unser aktuelles Objekt aufsumieren
        Polynom pol = p;
        for(size_t i = 0; i < grad + 1; i++) {
            pol.koeffizienten[i] += koeffizienten[i];
        }
        // unser Objekt mit der Kopie ersetzen
        *this = pol;
    }
    return *this;
}

Polynom& Polynom::operator-=(const Polynom& p) {
    *this += -p;
    return *this;
}

Polynom& Polynom::operator*=(const Polynom& p) {
	if( p.grad >  0) { 
		Polynom t(grad + p.grad, 0.);
		for(size_t i = 0; i <= grad; i++) {
			for(size_t j = 0; j <= p.grad; j++) {
				t.koeffizienten[i+j] += koeffizienten[i] * p.koeffizienten[j];
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
Polynom& Polynom::operator+=(const double& x) {
        koeffizienten[0] += x;
        return *this;
}

Polynom& Polynom::operator-=(const double& x) {
      koeffizienten[0] -= x;
      return *this;
}

Polynom& Polynom::operator*=(const double& x) {
    for(size_t i = 0; i < grad + 1; i++) {
        koeffizienten[i] *= x;
    }
    return *this;
}

const Polynom Polynom::operator+(const Polynom& p) {
    Polynom r = *this;
    r += p;
    return r;
}

const Polynom Polynom::operator-(const Polynom& p) {
    Polynom r = *this;
    r -= p;
    return r;
}

const Polynom Polynom::operator*(const Polynom& p) {
    Polynom r = *this;
    r *= p;
    return r;
}

    
/* globale Operatorfunktionen */

const Polynom operator+(const double& d, const Polynom& p) {
    Polynom r(d);
    r += p;
    return r;
}

const Polynom operator-(const double& d, const Polynom& p) {
    Polynom r(d);
    r -= p;
    return r;
}

const Polynom operator*(const double& d, const Polynom& p) {
    Polynom r(d);
    r *= p;
    return r;
}

/* globale Operatorfunktion zur Ausgabe */
ostream& operator<<(ostream& ausgabe, const Polynom& p) { 
	cout << "p(x) = ";
	for(size_t i = p.getGrad(); i > 0; i--) {
		ausgabe << p[i] << " * x^ " << i << " + ";
    }
	ausgabe << p[0] << endl;
    return ausgabe;
}
