/*
 *  FractionError.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 3
 */

#include "FractionError.h"


// NullDivisionError
const char* NullDivisionError::what() const throw() {
    return "Fehler: Nulldivision!";
}

// NullDenominatorError
const char* NullDenominatorError::what() const throw() {
   return "Fehler: Null im Nenner!";
}
