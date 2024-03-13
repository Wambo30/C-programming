//  Rational.h
//  prog2A-uebung-2

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational();
	Rational(long z, long n);
	Rational(long z);

	void setZaehler(long z);
	void setNenner(long n);
	long getZaehler() const;
	long getNenner() const;

	void multiplizieren(long z);
	void umkehren();
	void ausgeben() const;

	void addieren(const Rational& b);
	void subtrahieren(const Rational& b);
	void multiplizieren(const Rational& b);
	void dividieren(const Rational& b);

private:
	long zaehler;
	long nenner;

	void kuerzen();
};

#endif /* RATIONAL_H */
