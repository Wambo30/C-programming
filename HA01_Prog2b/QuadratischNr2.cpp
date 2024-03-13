/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
/* QuadratischNr2.cpp */

#include "QuadratischNr2.h"
#include "Funktion.h"
#include <iostream>
#include <cfloat>   // wegen DBL_EPSILON
#include <cmath>    // wegen sqrt
using namespace std;

QuadratischNr2::QuadratischNr2() : Funktion(2) {}

QuadratischNr2::QuadratischNr2(const QuadratischNr2& q) : Funktion(2), grad(2) {

	koeffizienten = new double[3];

	for (int i = 0; i <= grad; i++) {
		koeffizienten[i] = q.koeffizienten[i];
	}
}

void QuadratischNr2::nullstellenFinden(double* &x) const { // Mitternachtsformel
	double a = koeffizienten[2];
	double b = koeffizienten[1];
	double c = koeffizienten[0];
	if (b * b - 4 * a*c >= 0) {
		*x = (-b + sqrt(b * b - 4 * a*c)) / (2 * a);
	}
	else
	{
		x = nullptr;
	}
}