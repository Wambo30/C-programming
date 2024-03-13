//  Rational.h
//  prog2A-uebung-2

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational();
	Rational(long z, long n);
	Rational(long z);
	~Rational();

	// setter und getter
	void setZaehler(long z);
	void setNenner(long n);
	long getZaehler() const;
	long getNenner() const;

	// andere methoden
	void multiplizieren(long z);
	void umkehren();
	void ausgeben() const;

	// rechenmethoden
	void addieren(const Rational& b); // warum &? da objekte groß werden können
	void subtrahieren(const Rational& b);
	void multiplizieren(const Rational& b);
	void dividieren(const Rational& b);

private:
	long zaehler;
	long nenner;
	// private methode
	void kuerzen();
};

#endif /* RATIONAL_H */
