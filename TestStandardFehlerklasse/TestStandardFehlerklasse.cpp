#include "TestStandardFehlerklasse.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;


FehlerNegativeZahl::FehlerNegativeZahl(double d) {
	//double zahl;
	sprintf (meldung , " Fehler: Die Zahl %.4lf ist negativ! ",  d );

}

const char* FehlerNegativeZahl::what() const throw() {
	return meldung;
}

const char* FehlerNullDivision::what() const throw() {
	return "Fehler: Nulldivision";
}
