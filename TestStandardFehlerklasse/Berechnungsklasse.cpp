
#include "TestStandardFehlerklasse.h"
#include <exception>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;


double Berechnungsklasse::wurzel(double d) throw (FehlerNegativeZahl) {
	if (d >= 0.0)
		return sqrt(d);
	else
		throw FehlerNegativeZahl(d);
}

double Berechnungsklasse::kehrwert(double n) throw (FehlerNullDivision) {
	if (n) {
		return 1. / n;
	}
	else {
		throw FehlerNullDivision();
	}
}