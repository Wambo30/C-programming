/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/


/* Linear.h */
#ifndef LINEARNR2_H
#define LINEARNR2_H
#include "Funktion.h"
#include <string>
using namespace std;

class LinearNr2 : public Funktion {

public:
	LinearNr2(); // lineares Polynom mit Zufallskoeffizienten
	LinearNr2(const LinearNr2&);

	//Methoden	
	void nullstellenFinden(double*&) const;	//Nullstellen linearer Funktionen

private:
	size_t grad;

};

#endif // LINEARNR2_H
