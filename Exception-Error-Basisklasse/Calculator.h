/* Calculator.h */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Error.h"

class Calculator
{
public:
	Calculator();
	~Calculator();

	double wurzelVon(double x) throw(NegativeNumberError);
	double kehrwertVon(double x) throw(NullDivisionError);
};

#endif //CALCULATOR_H
