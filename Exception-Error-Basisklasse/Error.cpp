/* Error.cpp */
#include "Error.h"
#include "Calculator.h"
/*
Error::Error(string op) : ursache(op) {}

Error::~Error() {}

void Error::meldeFehler() const {
	cout << "FEHLER: " << ursache << endl;
}
*/

/* NEGATIVE NUMBER ERROR */

NegativeNumberError::~NegativeNumberError() {}

const char* NegativeNumberError::what() const throw() {

	return meldung;
}


NegativeNumberError::NegativeNumberError(double w) {

	sprintf(meldung, "Fehler: Die Zahl %.4lf  ist negativ!", w);
}


/* NULL DIVISION ERROR */

NullDivisionError::NullDivisionError(){}

NullDivisionError::~NullDivisionError() {}

const char* NullDivisionError::what() const throw() {

	return "Fehler: Nulldivision!";
}