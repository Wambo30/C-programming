//  Rational.cpp
//  prog2A-uebung-2-Rational


#include "Rational2.h"

#include <cmath>
#include <iostream>
using namespace std;

// Konstruktoren
Rational2::Rational2() : zaehler(0), nenner(1) {}

Rational2::Rational2(long z, long n) : zaehler(z), nenner(n) {
	if (nenner != 0) {
		kuerzen();
	}
	else {
		cout << "FEHLER: Nenner kann nicht 0 sein!" << endl;
	}
}

Rational2::Rational2(long z) : zaehler(z), nenner(1) {} // typumwandlungskonstruktor


// Setter und Getter
void Rational2::setZaehler(long z) {
	zaehler = z;
	kuerzen();
}

void Rational2::setNenner(long n) {
	if (n != 0) {
		nenner = n;
		kuerzen();
	}
	else {
		cout << "FEHLER: Nenner kann nicht 0 sein!" << endl;
	}
}

long Rational2::getZaehler() const { return zaehler; }
long Rational2::getNenner() const { return nenner; }

// Weitere Methoden
void Rational2::umkehren() {
	if (zaehler != 0) {
		long temp = zaehler;
		zaehler = nenner;
		nenner = temp;
	}
	else {
		cout << "FEHLER: Division durch 0!" << endl;
		// um den gleichen Fehler bei der Ausfuehrung wir bei int/0 zu erreichen
		// Probieren Sie selber aus, schreiben Sie in main-Funktion b1 /= 0;
		cout << nenner / zaehler << endl;
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
void Rational2::kuerzen() {
	// 1. Der Nenner muss positiv sein
	if (nenner  < 0) {
		nenner *= -1;
		zaehler *= -1;
	}
	long teiler = ggt(abs(zaehler), nenner);
	zaehler /= teiler;
	nenner /= teiler;
}



/* OPERATOREN */

// Rational += Rational
Rational2& Rational2::operator+=(const Rational2& r) {
	
	zaehler = zaehler*r.nenner + r.zaehler*nenner;
	nenner = nenner*r.nenner;
	kuerzen();
	return *this;

	// wenn man const 3 hätte
	//Rational2 k = *this;
	//k.zaehler = k.zaehler*r.nenner + r.zaehler*k.nenner;
	//k.nenner = k.nenner*r.nenner;
	//kuerzen();
	//return k;

}

// Rational -= Rational
Rational2& Rational2::operator-=(const Rational2& r) {
	Rational2 s = r;
	s.zaehler *= -1;
	*this += s;
	return *this;
}

// Rational *= Rational
Rational2& Rational2::operator*=(const Rational2& r) {
	zaehler = zaehler * r.zaehler;
	nenner = nenner * r.nenner;
	kuerzen();
	return *this;
}

// Rational /= Rational
Rational2& Rational2::operator/=(const Rational2& r) {
	Rational2 s = r;
	s.umkehren();
	*this *= s;
	return *this;
}


// s = *this + r
const Rational2 Rational2::operator+(const Rational2& r) const {	
	Rational2 s = *this;
	s += r; // s= s+r also def aus += benutzt
	return s;
	
	//wenn const nr 3 wegfällt
	//*this = *this + r;
	//return *this;

	//wenn const nr 2 bleibt 
	//r = r +  *this;
	//return r;

}

// s = *this - r
const Rational2 Rational2::operator-(const Rational2& r) const {
	Rational2 s = *this;
	s -= r;
	return s;
}

// s = *this * r
const Rational2 Rational2::operator*(const Rational2& r) const {
	Rational2 s = *this;
	s *= r;
	return s;
}

// s = *this / r
const Rational2 Rational2::operator/(const Rational2& r) const {
	Rational2 s = *this;
	s /= r;
	return s;
}

// ++r
Rational2& Rational2::operator++() {
	*this += 1;
	return *this;
}

// r++
const Rational2 Rational2::operator++(int) {
	Rational2 kopie = *this;
	*this += 1;
	return kopie;
}

// --r
Rational2& Rational2::operator--() {
	*this -= 1;
	return *this;
}

// r--
const Rational2 Rational2::operator--(int) {
	Rational2 kopie = *this;
	*this -= 1;
	return kopie;
}

// unaerer Minus
const  Rational2 Rational2::operator-() {
	//Rational2 v = *this;
	//v.zaehler *= -1;
	//return v;
	zaehler *= -1;
	return *this;
}

// Vergleichsoperatoren
bool Rational2::operator==(const Rational2& r) { // Rational == Rational/long
	return zaehler == r.zaehler && nenner == r.nenner;
}
bool Rational2::operator!=(const Rational2& r) { // Rational != Rational/long
	return !(*this == r);
}

bool Rational2::operator<(const Rational2& r) { // Rational <= Rational/long
	Rational2 s = *this - r;
	return s.zaehler < 0;
}

bool Rational2::operator>(const Rational2& r) { // Rational > Rational/long
	Rational2 s = *this - r;
	return s.zaehler > 0;
}


bool Rational2::operator<=(const Rational2& r) { // Rational <= Rational/long
	Rational2 s = *this - r;
	return s.zaehler <= 0;
}

bool Rational2::operator>=(const Rational2& r) { // Rational >= Rational/long
	Rational2 s = *this - r;
	return s.zaehler >= 0;
}


/* Globale Funktionen */
//!!! Wichtig !!! ohne "Rational::"


// long + Rational
const Rational2 operator+(long z, const Rational2& r) {
	Rational2 s(z);  // z in Rational umwandeln
	return s + r;   // Rational + Rational
}

/*
const long Rational2::operator+(const Rational2& r) {
	Rational2 k = *this;
	*this kann man NICHT außerhalb einer klasse nutzen! das würde dann wieder im widerspruch 
	zum oberen + stehen!!
}
*/

// long - Rational
const Rational2 operator-(const long z, const Rational2& r) {
	Rational2 s(z);  // z in Rational umwandeln
	return s - r;   // Rational - Rational
}

// long * Rational
const Rational2 operator*(const long z, const Rational2& r) {
	Rational2 s(z);  // z in Rational umwandeln
	return s * r;   // Rational * Rational
}
// long / Rational
const Rational2 operator/(const long z, const Rational2& r) {
	Rational2 s(z);  // z in Rational umwandeln
	return s / r;   // Rational / Rational
}

// Vergleichsoperatoren
// long == Rational
bool operator==(long z, const Rational2& r) {
	Rational2 s(z);
	return s == r;
}


// long != Rational
bool operator!=(long z, const Rational2& r) {
	Rational2 s(z);
	return s != r;
}

// long < Rational
bool operator<(long z, const Rational2& r) {
	Rational2 s(z);
	return s < r;
}

// long > Rational
bool operator>(long z, const Rational2& r) {
	Rational2 s(z);
	return s > r;
}

// long <= Rational
bool operator<=(long z, const Rational2& r) {
	Rational2 s(z);
	return s <= r;
}

// long >= Rational
bool operator>=(long z, const Rational2& r) {
	Rational2 s(z);
	return s >= r;
}

// Globale friend-Funktionen
// Ueberladen von Aus- und Eingabe-Operatoren <<, >>
ostream& operator<<(ostream& ausgabe, const Rational2& r) {
	if (r.nenner != 1) {
		ausgabe << r.zaehler << "/" << r.nenner;
	}
	else {
		ausgabe << r.zaehler;
	}
	return ausgabe;
}

istream& operator >> (istream& eingabe, Rational2& r) {
	long z, n;
	cout << "Zaehler: ";
	eingabe >> z;
	r.zaehler = z;
	if (z != 0) {
		do {
			cout << "Nenner: ";
			eingabe >> n;
		} while (n == 0);
		r.nenner = n;
	}
	r.kuerzen();
	return eingabe;
}

