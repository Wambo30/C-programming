/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/


/* Quadratisch.h */
#ifndef QUADRATISCHNR2_H
#define QUADRATISCHNR2_H
#include "Funktion.h"
#include <string>
using namespace std;

class QuadratischNr2 : public Funktion {

public:
	QuadratischNr2(); // quadratisches Polynom mit Zufallskoeffizienten
	QuadratischNr2(const QuadratischNr2&);

	//Methoden	
	void nullstellenFinden(double*&) const;	//// Mitternachtsformel da quadratische Funktion

private:
	size_t grad;

};

#endif // QUADRATISCHNR2_H
