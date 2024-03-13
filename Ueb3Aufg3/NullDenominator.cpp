#include "NullDenominator.h"
#include <iostream>
using namespace std;


NullDenominator::NullDenominator(int n) : nenner(n){}

NullDenominator::~NullDenominator(){}

void NullDenominator::meldeFehler() const {
	cout << "Fehler: Teilen durch 0 ist nicht erlaubt!"<< endl;
}

/*
TeilerNullFehler::TeilerNullFehler(int n): NullDenominator(z,n) {}

TeilerNullFehler::~TeilerNullFehler() {}

void TeilerNullFehler::meldeFehler() const {
	NullDenominator::meldeFehler();
	cout << " Divison durch 0 ist nicht erlaubt!" << endl;
}
*/