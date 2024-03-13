/*
*  PolynomUeb3.h
*  Programmieren IIb - Projekt 1
*
*/

#ifndef PolynomUeb3_H
#define PolynomUeb3_H

#include <cstdlib>  // wegen size_t
#include <iostream> // wegen Überladen von << und >>
using namespace std;

class PolynomUeb3 {
public:
	PolynomUeb3();                          // Nullpolynom
	PolynomUeb3(int g, const double& a);    // Alle Koeffizienten gleich a
										//PolynomUeb3(int g);                     // Zufallskonstruktor weglassen,
										// weil als Typumwandlungskonstruktor genommen wird
	PolynomUeb3(const double& z);           // Typumwandlungskonstruktor: reelle Zahl -> PolynomUeb3
	PolynomUeb3(const PolynomUeb3& p);          // Kopierkonstruktor
	~PolynomUeb3();

	PolynomUeb3& operator=(const PolynomUeb3& p);
	size_t getGrad() const;

	double& operator[](size_t i);               // erlaubt Zugriff auf koeffizienten[i]
												// statt Setter und Getter für koeffizienten[i]
	double& operator[](size_t i) const;         // Überladen mit const für die Ausgabe
	double operator()(const double& x) const;   // statt wertBerechnen(double x)

	const PolynomUeb3 operator-() const;
	PolynomUeb3& operator+=(const PolynomUeb3& p);
	PolynomUeb3& operator-=(const PolynomUeb3& p);
	PolynomUeb3& operator*=(const PolynomUeb3& p);

	PolynomUeb3& operator+=(const double& x);
	PolynomUeb3& operator-=(const double& x);
	PolynomUeb3& operator*=(const double& x);

	const PolynomUeb3 operator+(const PolynomUeb3& p);
	const PolynomUeb3 operator-(const PolynomUeb3& p);
	const PolynomUeb3 operator*(const PolynomUeb3& p);

	bool operator==(const PolynomUeb3& p) const;
	bool operator!=(const PolynomUeb3& p) const;

private:
	size_t grad;
	double* koeffizienten;
};

// reelle Zahl als der linke Operand
const PolynomUeb3 operator+(const double& d, const PolynomUeb3& p);
const PolynomUeb3 operator-(const double& d, const PolynomUeb3& p);
const PolynomUeb3 operator*(const double& d, const PolynomUeb3& p);

bool operator==(const double& d, const PolynomUeb3& p);
bool operator!=(const double& d, const PolynomUeb3& p);

ostream& operator<<(ostream& ausgabe, const PolynomUeb3& p);
istream& operator >> (istream& eingabe, PolynomUeb3& p);

#endif //POLYNOM_H