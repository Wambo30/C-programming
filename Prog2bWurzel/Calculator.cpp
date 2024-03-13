/* Calculator.cpp */

#include "Calculator.h"

#include <iostream>
using namespace std;
#include <cmath>
#include <cfloat> // wegen DBL_EPSILON


Calculator::Calculator() {}

Calculator::~Calculator() {}


double Calculator::wurzelVon(double x) throw(NegativeNumberError) {
	if (x >= 0.) {
		return sqrt(x);
	}
	throw NegativeNumberError(x);
}

double Calculator::kehrwertVon(double x) throw(NullDivisionError) {
	if (abs(x) > DBL_EPSILON) {
		return 1. / x;
	}
	throw NullDivisionError();
}
