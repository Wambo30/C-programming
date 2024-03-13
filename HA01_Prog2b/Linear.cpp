/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
//Linear.cpp 

#include "Linear.h"
#include <iostream>
#include <cfloat>   // wegen DBL_EPSILON
#include <cmath>    // wegen sqrt
using namespace std;

Linear::Linear() : PolynomHA01(1) {}

Linear::Linear(const Linear& l) : PolynomHA01(1), grad(1) {

	koeffizienten = new double[2];

	for (int i = 0; i <= grad; i++) {
		koeffizienten[i] = l.koeffizienten[i];
	}
}

void Linear::nullstellenFinden(double* &x) const { //ax + b
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