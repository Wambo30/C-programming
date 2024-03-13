
#include "TestCalculator.h"
#include "Error.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;


//TestCalculator::TestCalculator (){}
double TestCalculator::wurzel(double d) throw (NegativeZahlFehler) {
	if (d >= 0.0)
		return sqrt(d);
	else
		throw NegativeZahlFehler(d);
}

double TestCalculator::kehrwert(double d) throw(NullDivisionFehler) {
	if (d)
		return 1. / d;
	else
		throw NullDivisionFehler(d);

}