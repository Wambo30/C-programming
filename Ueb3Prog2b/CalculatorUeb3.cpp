/*
*  Calculator.cpp
*  Programmieren IIb - Uebung 3, Aufgabe 1
*
*/

#include "CalculatorUeb3.h"
#include <cmath>
#include <cfloat> // wegen DBL_EPSILON

double CalculatorUeb3::wurzel(double d) throw(NegativeNumberError) {
	if (!d || d > DBL_EPSILON) { // d >= 0
		return sqrt(d);
	}
	throw NegativeNumberError(d);
}

double CalculatorUeb3::kehrwert(double d) throw(NullDivisionError) {
	if (d) {
		return 1. / d;
	}
	throw NullDivisionError();
}

double CalculatorUeb3::logarithmus(double d) throw(NonpositiveNumberError) {
	if (d > DBL_EPSILON) { // d > 0
		return log(d);
	}
	throw NonpositiveNumberError(d);
}

