//  Rational.cpp
//  prog2A-uebung-2-Rational


#include "Rational.h"
#include "FractionError.h"
#include <cmath>
#include <iostream>
using namespace std;

// Konstruktoren
Rational::Rational() : zaehler(0), nenner(1) {}

Rational::Rational(long z, long n) : zaehler(z), nenner(n) {
    if( nenner != 0) {
        kuerzen();
    }
    else {
        throw NullDenominatorError();
    }
}

Rational::Rational(long z) : zaehler(z), nenner(1) {}

// Setter und Getter
void Rational::setZaehler(long z) {
    zaehler = z;
    kuerzen();
}

void Rational::setNenner(long n) {
    if( n != 0) {
        nenner = n;
        kuerzen();
    }
    else {
        throw NullDenominatorError();
    }
}

long Rational::getZaehler() const { return zaehler;}
long Rational::getNenner() const { return nenner; }

// Weitere Methoden
void Rational::umkehren() {
    if( zaehler != 0 ) {
        long temp = zaehler;
        zaehler = nenner;
        nenner  = temp;
    }
    else {
        throw NullDivisionError();
    }
}

// Eine lokale Hilfsfunktion für die Methode kuerzen()
// Sie berechnet den größten gemeinsamen Teiler zweier positiven
// ganzen Zahlen
long ggt(long a, long b) {
    if( b == 0) {
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
        nenner  *= -1;
        zaehler *= -1;
    }
    long teiler = ggt(abs(zaehler), nenner);
    zaehler /= teiler;
    nenner /= teiler;
}



/* OPERATOREN */

// Rational += Rational
Rational& Rational::operator+=(const Rational& r) {
    zaehler = zaehler*r.nenner + r.zaehler*nenner;
    nenner  = nenner*r.nenner;
    kuerzen();
    return *this;
}

// Rational -= Rational
Rational& Rational::operator-=(const Rational& r) {
    Rational s = r;
    s.zaehler *= -1;
    *this += s;
    return *this;
}

// Rational *= Rational
Rational& Rational::operator*=(const Rational& r) {
    zaehler = zaehler * r.zaehler;
    nenner  = nenner * r.nenner;
    kuerzen();
    return *this;
}

// Rational /= Rational
Rational& Rational::operator/=(const Rational& r) {
    Rational s = r;
    s.umkehren();
    *this *= s;
    return *this;
}


// s = *this + r
const Rational Rational::operator+(const Rational& r) const {
    Rational s = *this;
    s += r;
    return s;
}

// s = *this - r
const Rational Rational::operator-(const Rational& r) const {
    Rational s = *this;
    s -= r;
    return s;
}

// s = *this * r
const Rational Rational::operator*(const Rational& r) const {
    Rational s = *this;
    s *= r;
    return s;
}

// s = *this / r
const Rational Rational::operator/(const Rational& r) const {
    Rational s = *this;
    s /= r;
    return s;
}

// ++r
Rational& Rational::operator++() {
    *this += 1;
    return *this;
}

// r++
const Rational Rational::operator++(int) {
    Rational kopie = *this;
    *this += 1;
    return kopie;
}

// --r
Rational& Rational::operator--() {
    *this -= 1;
    return *this;
}

// r--
const Rational Rational::operator--(int) {
    Rational kopie = *this;
    *this -= 1;
    return kopie;
}

// unaerer Minus
const Rational Rational::operator-() {
    Rational v = *this;
    v.zaehler *= -1;
    return v;
}

// Vergleichsoperatoren
bool Rational::operator==(const Rational& r) { // Rational == Rational/long
    return zaehler == r.zaehler && nenner == r.nenner;
}
bool Rational::operator!=(const Rational& r) { // Rational != Rational/long
    return !(*this == r);
}

bool Rational::operator<(const Rational& r) { // Rational <= Rational/long
    Rational s = *this - r;
    return s.zaehler < 0;
}

bool Rational::operator>(const Rational& r){ // Rational > Rational/long
    Rational s = *this - r;
    return s.zaehler > 0;
}


bool Rational::operator<=(const Rational& r) { // Rational <= Rational/long
    Rational s = *this - r;
    return s.zaehler <= 0;
}

bool Rational::operator>=(const Rational& r){ // Rational >= Rational/long
    Rational s = *this - r;
    return s.zaehler >= 0;
}


/* Globale Funktionen */
//!!! Wichtig !!! ohne "Rational::"

// long + Rational
const Rational operator+(const long z, const Rational& r) {
    Rational s(z);  // z in Rational umwandeln
    return s + r;   // Rational + Rational
}

// long - Rational
const Rational operator-(const long z, const Rational& r) {
    Rational s(z);  // z in Rational umwandeln
    return s - r;   // Rational - Rational
}

// long * Rational
const Rational operator*(const long z, const Rational& r) {
    Rational s(z);  // z in Rational umwandeln
    return s * r;   // Rational * Rational
}
// long / Rational
const Rational operator/(const long z, const Rational& r) {
    Rational s(z);  // z in Rational umwandeln
    return s / r;   // Rational / Rational
}

// Vergleichsoperatoren
// long == Rational
bool operator==(long z, const Rational& r) {
    Rational s(z);
    return s == r;
}

// long != Rational
bool operator!=(long z, const Rational& r) {
    Rational s(z);
    return s != r;
}

// long < Rational
bool operator<(long z, const Rational& r) {
    Rational s(z);
    return s < r;
}

 // long > Rational
bool operator>(long z, const Rational& r) {
    Rational s(z);
    return s > r;
}

// long <= Rational
bool operator<=(long z, const Rational& r) {
    Rational s(z);
    return s <= r;
}

// long >= Rational
bool operator>=(long z, const Rational& r) {
    Rational s(z);
    return s >= r;
}

// Globale friend-Funktionen
// Ueberladen von Aus- und Eingabe-Operatoren <<, >>
ostream& operator<<(ostream& ausgabe, const Rational& r) {
    if ( r.nenner != 1 ) {
        ausgabe << r.zaehler << "/" << r.nenner;
    }
    else {
        ausgabe << r.zaehler;
    }
    return ausgabe;
}

istream& operator>>(istream& eingabe, Rational& r) {
    long z, n;
    cout << "Zaehler: ";
    eingabe >> z;
    r.zaehler = z;
    if( z != 0) {
        do {
            cout << "Nenner: ";
            eingabe >> n;
        } while( n == 0);
        r.nenner = n;
    }
    r.kuerzen();
    return eingabe;
}

