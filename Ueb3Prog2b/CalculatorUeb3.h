/*
*  Calculator.h
*  Programmieren IIb - Uebung 4, Aufgabe 1
*
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "ErrorUeb3.h"

class CalculatorUeb3 {
public:
	double wurzel(double d) throw(NegativeNumberError);
	double kehrwert(double d) throw(NullDivisionError);
	double logarithmus(double d) throw(NonpositiveNumberError);
};
#endif // CALCULATOR_H



