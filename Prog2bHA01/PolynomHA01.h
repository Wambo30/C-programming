/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

// PolynomHA01.h 
#ifndef POLYNOM_H
#define POLYNOM_H

#include <string>
using namespace std;

const float EPS = 0.0001;

class PolynomHA01 {

public:
	PolynomHA01(size_t); // PolynomHA01 gegebenen Grades mit Zufallskoeffizienten
	PolynomHA01(const PolynomHA01&);
	PolynomHA01& operator = (const PolynomHA01&);
	~PolynomHA01();

	//Methoden
	double& operator[](size_t);				// i-ter Koeffizient
	const double& operator[](size_t) const;	// i-ter Koeffizient
											//bei const Objekten
	const double operator()(double) const;	// p(x)
	double ableitung(double) const;
	double betrag(double x) const;
	void nullstellenFinden(double*&) const;	//Newton- Verfahren
	string toString() const;

protected:
	size_t grad;
	double* koeffizienten;


private:


};

#endif // POLYNOM_H
