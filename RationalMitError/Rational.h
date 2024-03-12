//  Rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
    // Globale friend-Funktionen, Ueberladen von Aus- und Eingabe-Operatoren <<, >>
    friend ostream& operator<<(ostream&, const Rational& b);
    friend istream& operator>>(istream& eingabe, Rational& b);
    
public:
    Rational();
    Rational(long z, long n);
    Rational(long z);   // Typumwandlungskonstruktor
    
    void setZaehler(long);
    void setNenner(long);
    long getZaehler() const;
    long getNenner() const;
    
    // Operatoren
    Rational& operator+=(const Rational& r); // += Rational/long
    Rational& operator-=(const Rational& r); // -= Rational/long
    Rational& operator*=(const Rational& r); // *= Rational/long
    Rational& operator/=(const Rational& r); // /= Rational/long
    
    const Rational operator+(const Rational& r) const; // Rational + Rational/long
    const Rational operator-(const Rational& r) const; // Rational - Rational/long
    const Rational operator*(const Rational& r) const; // Rational * Rational/long
    const Rational operator/(const Rational& r) const; // Rational / Rational/long
    
    Rational& operator++();    // ++r
    const Rational operator++(int); // r++
    Rational& operator--();    // --r
    const Rational operator--(int); // r--
    const Rational operator-();   // unaerer Minus
    
    // Vergleichsoperatoren
    bool operator==(const Rational&);       // Rational == Rational/long
    bool operator!=(const Rational&);       // Rational != Rational/long
    bool operator<(const Rational&);        // Rational < Rational/long
    bool operator>(const Rational&);        // Rational > Rational/long
    bool operator<=(const Rational&);       // Rational <= Rational/long
    bool operator>=(const Rational&);       // Rational >= Rational/long
    
    void umkehren();
    
private:
    long zaehler;
    long nenner;
    
    void kuerzen();
};

/* Globale Funktionen */
// long +/-/*/ Rational
const Rational operator+(long z, const Rational& b);
const Rational operator-(long z, const Rational& b);
const Rational operator*(long z, const Rational& b);
const Rational operator/(long z, const Rational& b);

// Vergleichsoperatoren
bool operator==(long, const Rational&);       // long == Rational
bool operator!=(long, const Rational&);       // long != Rational
bool operator<(long, const Rational&);        // long < Rational
bool operator>(long, const Rational&);        // long > Rational
bool operator<=(long, const Rational&);       // long <= Rational
bool operator>=(long, const Rational&);       // long >= Rational

#endif /* RATIONAL_H */
