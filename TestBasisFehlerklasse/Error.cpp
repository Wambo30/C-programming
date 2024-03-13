#include "Error.h"
#include <iostream>
using namespace std;
#include <string>

Error::Error(string op) { ursache = op; }

Error::~Error(){}

void Error::meldeFehler() const {
	cout << "FEHLER: " << ursache <<endl;
}


NegativeZahlFehler::NegativeZahlFehler(double w) : Error("Negative Zahl: ") {
	ursache.append(to_string(w));
}

NegativeZahlFehler::~NegativeZahlFehler() {}


NullDivisionFehler::NullDivisionFehler(double w):Error("Division durch Null") {
	ursache.append(to_string(w));
}

NullDivisionFehler::~NullDivisionFehler(){}

