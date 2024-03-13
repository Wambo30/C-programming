//  Rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational2 {
	// Globale friend-Funktionen, Ueberladen von Aus- und Eingabe-Operatoren <<, >>
	friend ostream& operator<<(ostream&, const Rational2& b);
	friend istream& operator >> (istream& eingabe, Rational2& b);

public:
	Rational2();
	Rational2(long z, long n);
	Rational2(long z);   // Typumwandlungskonstruktor

	void setZaehler(long);
	void setNenner(long);
	long getZaehler() const;
	long getNenner() const;

	// Operatoren
	Rational2& operator+=(const Rational2& r); // += Rational/long
	Rational2& operator-=(const Rational2& r); // -= Rational/long
	Rational2& operator*=(const Rational2& r); // *= Rational/long
	Rational2& operator/=(const Rational2& r); // /= Rational/long

	const Rational2 operator+(const Rational2& r) const; // Rational + Rational/long
	const Rational2 operator-(const Rational2& r) const; // Rational - Rational/long
	const Rational2 operator*(const Rational2& r) const; // Rational * Rational/long
	const Rational2 operator/(const Rational2& r) const; // Rational / Rational/long

	Rational2& operator++();    // ++r
	const Rational2 operator++(int); // r++
	Rational2& operator--();    // --r
	const Rational2 operator--(int); // r--
	const Rational2 operator-();   // unaerer Minus

								  // Vergleichsoperatoren
	bool operator==(const Rational2&);       // Rational == Rational/long
	bool operator!=(const Rational2&);       // Rational != Rational/long
	bool operator<(const Rational2&);        // Rational < Rational/long
	bool operator>(const Rational2&);        // Rational > Rational/long
	bool operator<=(const Rational2&);       // Rational <= Rational/long
	bool operator>=(const Rational2&);       // Rational >= Rational/long

	void umkehren();

private:
	long zaehler;
	long nenner;

	void kuerzen();
};

/* Globale Funktionen */
// long +/-/*/ Rational
const Rational2 operator+(long z, const Rational2& b);
const Rational2 operator-(long z, const Rational2& b);
const Rational2 operator*(long z, const Rational2& b);
const Rational2 operator/(long z, const Rational2& b);

// Vergleichsoperatoren
bool operator==(long, const Rational2&);       // long == Rational
bool operator!=(long, const Rational2&);       // long != Rational
bool operator<(long, const Rational2&);        // long < Rational
bool operator>(long, const Rational2&);        // long > Rational
bool operator<=(long, const Rational2&);       // long <= Rational
bool operator>=(long, const Rational2&);       // long >= Rational

#endif /* RATIONAL_H */
