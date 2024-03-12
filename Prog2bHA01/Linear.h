/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

// Linear.h 
#ifndef LINEAR_H
#define LINEAR_H

#include "PolynomHA01.h"
#include <string>
using namespace std;

class Linear : public PolynomHA01{

public:
	Linear(); // lineares Polynom mit Zufallskoeffizienten
	Linear(const Linear&);

	//Methoden	
	void nullstellenFinden(double*&) const;	//Nullstellen linearer Funktionen

private:
	size_t grad;

};

#endif // LINEAR_H
