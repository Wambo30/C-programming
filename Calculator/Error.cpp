/*
 *  Error.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 1
 *
 */

#include "Error.h"
#include <iostream>
using namespace std;

// Klasse Error
Error::Error(string op) : ursache(op) {}

void Error::meldeFehler() const {
    cout << "FEHLER! " << ursache;
}

// Klasse NegativeNumberError
NegativeNumberError::NegativeNumberError(double d)
    : zahl(d), Error("Negative Zahl") {}

void NegativeNumberError::meldeFehler() const {
    Error::meldeFehler();
    cout << " : " << zahl << endl;
}

// Klasse NullDivisionError
NullDivisionError::NullDivisionError() : Error("Nulldivision!\n") { }


//NullOrNegativeNumberError
NonpositiveNumberError::NonpositiveNumberError(double d) 
    : zahl(d), Error("Nicht-positive Zahl") {}; 

void NonpositiveNumberError::meldeFehler() const {
    Error::meldeFehler();
    cout << " : " << zahl << endl;
}
