/*
 *  Polynom.h
 *  Programmieren IIb - Uebung 3, Aufgabe 4
 *
 */

#ifndef POLYNOM_H
#define POLYNOM_H

#include "RangeError.h"
#include <cstdlib>  // wegen size_t
#include <iostream> // wegen Überladen von << und >>
using namespace std; 

class Polynom {
public:	
	Polynom();
	Polynom(int g, const double& a);
    Polynom(const double& z);   // Typumwandlungskonstruktor
    Polynom(const Polynom& p);  // Kopierkonstruktor
   
	~Polynom();
    
    Polynom& operator=(const Polynom& p);
    size_t getGrad() const;
    double& operator[](size_t i) throw(RangeError);               // erlaubt Zugriff auf koeffizienten[i]
    const double& operator[](size_t i) const;         // Überladen mit const für die Ausgabe
    double operator()(const double& x) const;   // statt wertBerechnen(double x)
    
    const Polynom operator-() const;
    Polynom& operator+=(const Polynom& p);
    Polynom& operator-=(const Polynom& p);
    Polynom& operator*=(const Polynom& p);
    
    Polynom& operator+=(const double& x);
    Polynom& operator-=(const double& x);
    Polynom& operator*=(const double& x);
    
    const Polynom operator+(const Polynom& p);
    const Polynom operator-(const Polynom& p);
    const Polynom operator*(const Polynom& p);
    
private:
	size_t grad;
	double* koeffizienten;
};

// reelle Zahl als der linke Operand
const Polynom operator+(const double& d, const Polynom& p);
const Polynom operator-(const double& d, const Polynom& p);
const Polynom operator*(const double& d, const Polynom& p);

ostream& operator<<(ostream& ausgabe, const Polynom& p);

#endif //POLYNOM_H
