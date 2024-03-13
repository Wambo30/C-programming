
#ifndef TestCalculator_h
#define TestCalculator_h

#include "Error.h"

class TestCalculator  {
public:
	//TestCalculator();
	double wurzel(double d) throw (NegativeZahlFehler);
	double kehrwert(double d) throw (NullDivisionFehler);

}; 
#endif
