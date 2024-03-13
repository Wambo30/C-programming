//  RationalUeb3.h

#ifndef RationalUeb3_H
#define RationalUeb3_H

#include "NullDenominator.h"
#include <iostream>
using namespace std;

class RationalUeb3{
	// Globale friend-Funktionen, Ueberladen von Aus- und Eingabe-Operatoren <<, >>
	friend ostream& operator<<(ostream&, const RationalUeb3& b);
	friend istream& operator >> (istream& eingabe, RationalUeb3& b);

public:
	RationalUeb3();
	RationalUeb3(long z, long n);
	RationalUeb3(long z);   // Typumwandlungskonstruktor

	void setZaehler(long);
	void setNenner(long);
	long getZaehler() const;
	long getNenner() const;

	// Operatoren
	RationalUeb3& operator+=(const RationalUeb3& r); // += RationalUeb3/long
	RationalUeb3& operator-=(const RationalUeb3& r); // -= RationalUeb3/long
	RationalUeb3& operator*=(const RationalUeb3& r); // *= RationalUeb3/long
	RationalUeb3& operator/=(const RationalUeb3& r); // /= RationalUeb3/long

	const RationalUeb3 operator+(const RationalUeb3& r) const; // RationalUeb3 + RationalUeb3/long
	const RationalUeb3 operator-(const RationalUeb3& r) const; // RationalUeb3 - RationalUeb3/long
	const RationalUeb3 operator*(const RationalUeb3& r) const; // RationalUeb3 * RationalUeb3/long
	const RationalUeb3 operator/(const RationalUeb3& r) const; // RationalUeb3 / RationalUeb3/long

	RationalUeb3& operator++();    // ++r
	const RationalUeb3 operator++(int); // r++
	RationalUeb3& operator--();    // --r
	const RationalUeb3 operator--(int); // r--
	const RationalUeb3 operator-();   // unaerer Minus

								  // Vergleichsoperatoren
	bool operator==(const RationalUeb3&);       // RationalUeb3 == RationalUeb3/long
	bool operator!=(const RationalUeb3&);       // RationalUeb3 != RationalUeb3/long
	bool operator<(const RationalUeb3&);        // RationalUeb3 < RationalUeb3/long
	bool operator>(const RationalUeb3&);        // RationalUeb3 > RationalUeb3/long
	bool operator<=(const RationalUeb3&);       // RationalUeb3 <= RationalUeb3/long
	bool operator>=(const RationalUeb3&);       // RationalUeb3 >= RationalUeb3/long

	void umkehren();

private:
	long zaehler;
	long nenner;

	void kuerzen();
};

/* Globale Funktionen */
// long +/-/*/ RationalUeb3
const RationalUeb3 operator+(long z, const RationalUeb3& b);
const RationalUeb3 operator-(long z, const RationalUeb3& b);
const RationalUeb3 operator*(long z, const RationalUeb3& b);
const RationalUeb3 operator/(long z, const RationalUeb3& b);

// Vergleichsoperatoren
bool operator==(long, const RationalUeb3&);       // long == RationalUeb3
bool operator!=(long, const RationalUeb3&);       // long != RationalUeb3
bool operator<(long, const RationalUeb3&);        // long < RationalUeb3
bool operator>(long, const RationalUeb3&);        // long > RationalUeb3
bool operator<=(long, const RationalUeb3&);       // long <= RationalUeb3
bool operator>=(long, const RationalUeb3&);       // long >= RationalUeb3

#endif /* RATIONAL_H */
