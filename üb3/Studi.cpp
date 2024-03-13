#include <iostream>
using namespace std;
#include "Studi.h"
#include "DatumZeiger.h"

/*

// Konstruktoren
DatumZeiger::DatumZeiger() : tag(1), monat(1), jahr(STARTJAHR) {} //Standardkonstruktor

DatumZeiger::DatumZeiger(int j) : tag(1), monat(1), jahr(j) {
	if (!istGueltig()) {
		jahr = STARTJAHR;
		cout << "WARNUNG: Ungueltiges Datum, wird auf 1.1.1990 gesetzt" << endl;
	}
}

DatumZeiger::DatumZeiger(int t, int m, int j) : tag(t), monat(m), jahr(j) {
	if (!istGueltig()) {
		tag = monat = 1;
		jahr = STARTJAHR;
		cout << "WARNUNG: Ungueltiges Datum, wird auf 1.1.1990 gesetzt" << endl;
	}
}

Studi::~Studi(){}


//setter 
void Studi::setName(const string& n) {
	name = n;
}

void Studi::setGeburtstag(const DatumZeiger& g) {
	geburtstag = g;
}

void setFachsemester(const int f) {
	fachsemester = f;
}

//getter

string Studi::getName() const {
	return name;
}

DatumZeiger Studi::getGeburtstag(const DatumZeiger& g) {
	return geburtstag;
}

int Studi::getFachsemester() const {

}

*/