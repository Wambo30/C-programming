/* DatumUeb3.cpp */

#include "DatumUeb3.h"
#include "DatumFehler.h"
#include <iostream>
using namespace std;

// Konstruktoren
DatumUeb3::DatumUeb3() : tag(1), monat(1), jahr(STARTJAHR) {} //Standardkonstruktor

DatumUeb3::DatumUeb3(int t, int m, int j) : tag(t), monat(m), jahr(j) {
	if (!istGueltig()) {
		tag = monat = 1;
		jahr = STARTJAHR;
		cout << "WARNUNG: Ungueltiges DatumUeb3, wird auf 1.1.1990 gesetzt" << endl;
	}
}

DatumUeb3::DatumUeb3(bool zufall) {  // Wenn TRUE Zufallsdatum, sonst Standarddatum
	if (zufall) {
		tag = rand() % 31 + 1;
		monat = rand() % 12 + 1;
		jahr = rand() % 100 + 1990;
		if (!istGueltig()) {
			tag = rand() % 28 + 1;
		}
	}
	else {
		tag = monat = 1;
		jahr = STARTJAHR;
	}
}

// Destruktor
DatumUeb3::~DatumUeb3() {}

// Setter Methoden
void DatumUeb3::setTag(int t) {
	int temp = tag;         // den aktuellen Tag merken, falls die Aenderung nicht klappt
	if (istGueltig()) {
		tag = t;
	}
	else {
		/*
		cout << "WARNUNG: Tag " << t << " nicht gueltig!" << endl;
		tag = temp;       // Der alte Tag wird nicht veraendert
		*/
		throw InvalidDayError(t, monat, jahr);
	}
}

void DatumUeb3::setMonat(int m) {
	int temp = monat;
	if (istGueltig()) {
		monat = m;
	}
	else {
		//cout << "WARNUNG: Monat " << m << " nicht gueltig!" << endl;
		//monat = temp;
		throw InvalidMonthError(tag, m, jahr);
	}
}

void DatumUeb3::setJahr(int j) {
	int temp = jahr;
	if (istGueltig()) {
		jahr = j;
	}
	else {
		//cout << "WARNUNG: Jahr " << j << " nicht gueltig!" << endl;
		//jahr = temp;
		throw InvalidYearError(tag, monat, j);
	}
}

// Getter Methoden
int DatumUeb3::getTag() const { return tag; }
int DatumUeb3::getMonat() const { return monat; }
int DatumUeb3::getJahr() const { return jahr; }

// Wietere Methoden

// das DatumUeb3 auf ein Neujahr setzen
void DatumUeb3::setNeuJahr(int j) {
	tag = monat = 1;
	if (istGueltig()) {
		cout << "WARNUNG: Jahr " << j << " nicht gueltig wird auf " << STARTJAHR << " gesetzt." << endl;
		jahr = STARTJAHR;
	}
	throw InvalidYearError(tag, monat, j);
}

// Das DatumUeb3 um einen Tag verschieben
void DatumUeb3::setMorgen() {
	tag++;
	if (!istGueltig()) {
		tag = 1;
		monat++;
		if (!istGueltig()) {
			monat = 1;
			jahr++;
		}
	}
}

// ueberpruefen, ob das DatumUeb3 im Schaltjahr liegt
bool DatumUeb3::istSchaltjahr() const {
	return (jahr % 400 == 0) || (jahr % 4 == 0 && jahr % 100 != 0);
}

// DatumUeb3 im Format tag-monat-jahr ausgeben
void DatumUeb3::ausgeben() const {
	cout << tag << "-" << monat << "-" << jahr << endl;
}

// ueberpruefen, ob das DatumUeb3 gueltig ist
bool DatumUeb3::istGueltig() const {
	int maxTage[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	maxTage[1] = istSchaltjahr() ? 29 : 28;
	return (jahr >= STARTJAHR && monat >= 1 && monat <= 12 && tag >= 1 && tag <= maxTage[monat - 1]);
}

/*
ostream& operator<<(ostream& aus, const DatumUeb3& d) {
	aus << d.tag << "." << d.monat << "." << d.jahr;
	return aus;
}
*/