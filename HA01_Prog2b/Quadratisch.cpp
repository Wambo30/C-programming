/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
//Quadratisch.cpp 

#include "Quadratisch.h"
#include <iostream>
#include <cfloat>   // wegen DBL_EPSILON
#include <cmath>    // wegen sqrt
using namespace std;

Quadratisch::Quadratisch() : PolynomHA01(2) {}

Quadratisch::Quadratisch(const Quadratisch& q) : PolynomHA01(2), grad(2) {

	koeffizienten = new double[3];

	for (int i = 0; i <= grad; i++) {
		koeffizienten[i] = q.koeffizienten[i];
	}
}

void Quadratisch::nullstellenFinden(double* &x) const { // Mitternachtsformel
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