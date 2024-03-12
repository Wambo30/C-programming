/*
 *  Calculator.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 1
 *
 */
 
#include "Calculator.h"
#include <cmath>
#include <cfloat> // wegen DBL_EPSILON

double Calculator::wurzel(double d) throw(NegativeNumberError) {
	if ( !d || d > DBL_EPSILON) { // d >= 0
		return sqrt(d);
    }
	throw NegativeNumberError(d);
}

double Calculator::kehrwert(double d) throw(NullDivisionError) {
	if( d ) {
		return 1./d;
    }
	throw NullDivisionError(); 
}

double Calculator::logarithmus(double d) throw(NonpositiveNumberError) {
	if ( d > DBL_EPSILON ) { // d > 0
		return log(d);
    }
	throw NonpositiveNumberError(d);
}

