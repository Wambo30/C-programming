/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
#ifndef POTENZ_H
#define POTENZ_H
#include "Funktion.h"
#include <iostream>
using namespace std;

class Potenz : public Funktion {
public:

	Potenz(size_t); //konstruktor mit zufallskoeffizienten
	~Potenz();

	const double operator()(double) const;	// p(x)

private:
	size_t grad;
};
#endif