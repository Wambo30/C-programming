/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

// Quadratisch.h 
#ifndef QUADRATISCH_H
#define QUADRATISCH_H

#include "PolynomHA01.h"
#include <string>
using namespace std;

class Quadratisch : public PolynomHA01 {

public:
	Quadratisch(); // quadratisches Polynom mit Zufallskoeffizienten
	Quadratisch(const Quadratisch&);

	//Methoden	
	void nullstellenFinden(double*&) const;	//// Mitternachtsformel da quadratische Funktion

private:
	size_t grad;

};

#endif // QUADRATISCH_H
