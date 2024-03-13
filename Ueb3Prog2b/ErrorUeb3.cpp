/*
*  Error.cpp
*  Programmieren IIb - Uebung 3, Aufgabe 1
*
*/

#include "ErrorUeb3.h"
#include <iostream>
using namespace std;

// Klasse Error
ErrorUeb3::ErrorUeb3(string op) : ursache(op) {}

void ErrorUeb3::meldeFehler() const {
	cout << "FEHLER! " << ursache;
}

// Klasse NegativeNumberError
NegativeNumberError::NegativeNumberError(double d)
	: zahl(d), ErrorUeb3("Negative Zahl") {}

void NegativeNumberError::meldeFehler() const {
	ErrorUeb3::meldeFehler();
	cout << " : " << zahl << endl;
}

// Klasse NullDivisionError
NullDivisionError::NullDivisionError() : ErrorUeb3("Nulldivision!\n") { }


//NullOrNegativeNumberError
NonpositiveNumberError::NonpositiveNumberError(double d)
	: zahl(d), ErrorUeb3("Nicht-positive Zahl") {};

void NonpositiveNumberError::meldeFehler() const {
	ErrorUeb3::meldeFehler();
	cout << " : " << zahl << endl;
}
