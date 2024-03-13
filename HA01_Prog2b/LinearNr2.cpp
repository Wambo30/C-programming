/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
// LinearNr2.cpp 

#include "LinearNr2.h"
#include <iostream>
#include <cfloat>   // wegen DBL_EPSILON
#include <cmath>    // wegen sqrt
using namespace std;

LinearNr2::LinearNr2() : Funktion(1) {}

LinearNr2::LinearNr2(const LinearNr2& l) : Funktion(1), grad(1) {

	koeffizienten = new double[2];

	for (int i = 0; i <= grad; i++) {
		koeffizienten[i] = l.koeffizienten[i];
	}
}

void LinearNr2::nullstellenFinden(double* &x) const { //ax + b
	double a = koeffizienten[1];
	double b = koeffizienten[0];
	if (a != 0) {
		*x = -b / a;
	}
	else
	{
		x = nullptr;
	}

}