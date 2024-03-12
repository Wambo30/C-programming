/* Error.cpp */
#include "Error.h"

Error::Error(string op) : ursache(op) {}

Error::~Error() {}

void Error::meldeFehler() const {
    cout << "FEHLER: " << ursache << endl;
}

/* NEGATIVE NUMBER ERROR */

NegativeNumberError::NegativeNumberError(double w) : Error("Negative Zahl : ")
{
    ursache.append(to_string(w));
}

NegativeNumberError::~NegativeNumberError() {}

/* NULL DIVISION ERROR */

NullDivisionError::NullDivisionError() : Error("Nulldivision!")
{}

NullDivisionError::~NullDivisionError(){}
