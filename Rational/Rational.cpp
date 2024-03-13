//  Rational.cpp
//  prog2A-uebung-2-Rational


#include "Rational.h"

#include <cmath>
#include <iostream>
using namespace std;

// Konstruktoren
Rational::Rational() : zaehler(0), nenner(1) {}

Rational::Rational(long z, long n) : zaehler(z), nenner(n) {
	if (nenner != 0) {
		kuerzen();
	}
	else {
		cout << "FEHLER: Nenner kann nicht 0 sein!" << endl;
	}
}

Rational::Rational(long z) : zaehler(z), nenner(1) {}

Rational::~Rational(){}

// Setter und Getter
void Rational::setZaehler(long z) {
	zaehler = z;
	kuerzen();
}

void Rational::setNenner(long n) {
	if (n != 0) {
		nenner = n;
		kuerzen();
	}
	else {
		cout << "FEHLER: Nenner kann nicht 0 sein!" << endl;
	}
}

long Rational::getZaehler() const { return zaehler; }
long Rational::getNenner() const { return nenner; }

// Weitere Methoden
void Rational::umkehren() {
	if (zaehler != 0) {
		long temp = zaehler;
		zaehler = nenner;
		nenner = temp;
	}
	else {
		cout << "FEHLER: Disvision durch 0!" << endl;
	}
}

// Eine rationale Zahl mit einer ganzen Zahl multiplizieren
void Rational::multiplizieren(long z) {
	zaehler *= z;
	kuerzen();
}

// Eine Ausgabe-Methode
void Rational::ausgeben() const {
	if (nenner != 1) { // dann ist auch zaehler != 0
		cout << zaehler << "/" << nenner << endl;
	}
	else { // als Zahl
		cout << zaehler << endl;
	}
}

// Eine lokale Hilfsfunktion für die Methode kuerzen()
// Sie berechnet den größten gemeinsamen Teiler zweier positiven
// ganzen Zahlen
long ggt(long a, long b) {
	if (b == 0) {
		return a;
	}
	else {
		return ggt(b, a % b);
	}
}

// Die Methode kurzen() bring einen Bruch in die Grunddarstellung
// Der Nenner ist immer positiv
void Rational::kuerzen() {
	// 1. Der Nenner muss positiv sein
	if (nenner  < 0) {
		nenner *= -1;
		zaehler *= -1;
	}
	else {
		long teiler = ggt(abs(zaehler), nenner);
		zaehler /= teiler;
		nenner /= teiler;
	}
}

// Zu einer rationalen Zahl wird eine andere rationale Zahl aufaddiert
// methode bezieht sich natürlich auf objekt
void Rational::addieren(const Rational& r) {
	zaehler = zaehler*r.nenner + r.zaehler*nenner;
	nenner *= r.nenner; // nenner= nenner * r.nenner
	kuerzen();
}

void Rational::subtrahieren(const Rational& s) {
	Rational r = s;
	r.zaehler *= -1;
	addieren(r);
}

//  Die Methode multipliziere(int zahl) wird ueberladen
void Rational::multiplizieren(const Rational& r) {
	zaehler = zaehler*r.zaehler;
	nenner = nenner *r.nenner;
	kuerzen();
}

void Rational::dividieren(const Rational& n) {
	Rational r = n;
	r.umkehren();
	multiplizieren(r);
}

