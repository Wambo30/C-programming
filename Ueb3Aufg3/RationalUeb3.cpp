//  RationalUeb3.cpp
//  prog2A-uebung-2-RationalUeb3


#include "RationalUeb3.h"
#include "FractionError.h"
#include <exception>
#include <cmath>
#include <iostream>
using namespace std;

// Konstruktoren
RationalUeb3::RationalUeb3() : zaehler(0), nenner(1) {}

RationalUeb3::RationalUeb3(long z, long n) : zaehler(z), nenner(n) {
	if (nenner != 0) {
		kuerzen();
	}
	else {
		throw NullDenominatorError();
	}
}

RationalUeb3::RationalUeb3(long z) : zaehler(z), nenner(1) {}

// Setter und Getter
void RationalUeb3::setZaehler(long z) {
	zaehler = z;
	kuerzen();
}

void RationalUeb3::setNenner(long n) {
	if (n != 0) {
		nenner = n;
		kuerzen();
	}
	else {
		throw NullDenominatorError();
	}
}

long RationalUeb3::getZaehler() const { return zaehler; }
long RationalUeb3::getNenner() const { return nenner; }

// Weitere Methoden
void RationalUeb3::umkehren() {
	if (zaehler != 0) {
		long temp = zaehler;
		zaehler = nenner;
		nenner = temp;
	}
	else {
		throw NullDivisionError();
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
void RationalUeb3::kuerzen() {
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

// RationalUeb3 += RationalUeb3
RationalUeb3& RationalUeb3::operator+=(const RationalUeb3& r) {
	zaehler = zaehler*r.nenner + r.zaehler*nenner;
	nenner = nenner*r.nenner;
	kuerzen();
	return *this;
}

// RationalUeb3 -= RationalUeb3
RationalUeb3& RationalUeb3::operator-=(const RationalUeb3& r) {
	RationalUeb3 s = r;
	s.zaehler *= -1;
	*this += s;
	return *this;
}

// RationalUeb3 *= RationalUeb3
RationalUeb3& RationalUeb3::operator*=(const RationalUeb3& r) {
	zaehler = zaehler * r.zaehler;
	nenner = nenner * r.nenner;
	kuerzen();
	return *this;
}

// RationalUeb3 /= RationalUeb3
RationalUeb3& RationalUeb3::operator/=(const RationalUeb3& r) {
	RationalUeb3 s = r;
	s.umkehren();
	*this *= s;
	return *this;
}


// s = *this + r
const RationalUeb3 RationalUeb3::operator+(const RationalUeb3& r) const {
	RationalUeb3 s = *this;
	s += r;
	return s;
}

// s = *this - r
const RationalUeb3 RationalUeb3::operator-(const RationalUeb3& r) const {
	RationalUeb3 s = *this;
	s -= r;
	return s;
}

// s = *this * r
const RationalUeb3 RationalUeb3::operator*(const RationalUeb3& r) const {
	RationalUeb3 s = *this;
	s *= r;
	return s;
}

// s = *this / r
const RationalUeb3 RationalUeb3::operator/(const RationalUeb3& r) const {
	RationalUeb3 s = *this;
	s /= r;
	return s;
}

// ++r
RationalUeb3& RationalUeb3::operator++() {
	*this += 1;
	return *this;
}

// r++
const RationalUeb3 RationalUeb3::operator++(int) {
	RationalUeb3 kopie = *this;
	*this += 1;
	return kopie;
}

// --r
RationalUeb3& RationalUeb3::operator--() {
	*this -= 1;
	return *this;
}

// r--
const RationalUeb3 RationalUeb3::operator--(int) {
	RationalUeb3 kopie = *this;
	*this -= 1;
	return kopie;
}

// unaerer Minus
const RationalUeb3 RationalUeb3::operator-() {
	RationalUeb3 v = *this;
	v.zaehler *= -1;
	return v;
}

// Vergleichsoperatoren
bool RationalUeb3::operator==(const RationalUeb3& r) { // RationalUeb3 == RationalUeb3/long
	return zaehler == r.zaehler && nenner == r.nenner;
}
bool RationalUeb3::operator!=(const RationalUeb3& r) { // RationalUeb3 != RationalUeb3/long
	return !(*this == r);
}

bool RationalUeb3::operator<(const RationalUeb3& r) { // RationalUeb3 <= RationalUeb3/long
	RationalUeb3 s = *this - r;
	return s.zaehler < 0;
}

bool RationalUeb3::operator>(const RationalUeb3& r) { // RationalUeb3 > RationalUeb3/long
	RationalUeb3 s = *this - r;
	return s.zaehler > 0;
}


bool RationalUeb3::operator<=(const RationalUeb3& r) { // RationalUeb3 <= RationalUeb3/long
	RationalUeb3 s = *this - r;
	return s.zaehler <= 0;
}

bool RationalUeb3::operator>=(const RationalUeb3& r) { // RationalUeb3 >= RationalUeb3/long
	RationalUeb3 s = *this - r;
	return s.zaehler >= 0;
}


/* Globale Funktionen */
//!!! Wichtig !!! ohne "RationalUeb3::"

// long + RationalUeb3
const RationalUeb3 operator+(const long z, const RationalUeb3& r) {
	RationalUeb3 s(z);  // z in RationalUeb3 umwandeln
	return s + r;   // RationalUeb3 + RationalUeb3
}

// long - RationalUeb3
const RationalUeb3 operator-(const long z, const RationalUeb3& r) {
	RationalUeb3 s(z);  // z in RationalUeb3 umwandeln
	return s - r;   // RationalUeb3 - RationalUeb3
}

// long * RationalUeb3
const RationalUeb3 operator*(const long z, const RationalUeb3& r) {
	RationalUeb3 s(z);  // z in RationalUeb3 umwandeln
	return s * r;   // RationalUeb3 * RationalUeb3
}
// long / RationalUeb3
const RationalUeb3 operator/(const long z, const RationalUeb3& r) {
	RationalUeb3 s(z);  // z in RationalUeb3 umwandeln
	return s / r;   // RationalUeb3 / RationalUeb3
}

// Vergleichsoperatoren
// long == RationalUeb3
bool operator==(long z, const RationalUeb3& r) {
	RationalUeb3 s(z);
	return s == r;
}

// long != RationalUeb3
bool operator!=(long z, const RationalUeb3& r) {
	RationalUeb3 s(z);
	return s != r;
}

// long < RationalUeb3
bool operator<(long z, const RationalUeb3& r) {
	RationalUeb3 s(z);
	return s < r;
}

// long > RationalUeb3
bool operator>(long z, const RationalUeb3& r) {
	RationalUeb3 s(z);
	return s > r;
}

// long <= RationalUeb3
bool operator<=(long z, const RationalUeb3& r) {
	RationalUeb3 s(z);
	return s <= r;
}

// long >= RationalUeb3
bool operator>=(long z, const RationalUeb3& r) {
	RationalUeb3 s(z);
	return s >= r;
}

// Globale friend-Funktionen
// Ueberladen von Aus- und Eingabe-Operatoren <<, >>
ostream& operator<<(ostream& ausgabe, const RationalUeb3& r) {
	if (r.nenner != 1) {
		ausgabe << r.zaehler << "/" << r.nenner;
	}
	else {
		ausgabe << r.zaehler;
	}
	return ausgabe;
}

istream& operator >> (istream& eingabe, RationalUeb3& r) {
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

