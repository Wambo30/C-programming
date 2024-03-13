/* Datumzeioger.cpp */

#include "Datumzeiger.h"
#include <iostream>
using namespace std;

// Konstruktoren
Datumzeiger::Datumzeiger() : tag(1), monat(1), jahr(STARTJAHR) {} //Standardkonstruktor

Datumzeiger::Datumzeiger(int j) : tag(1), monat(1), jahr(j) {
	if (!istGueltig()) {
		jahr = STARTJAHR;
		cout << "WARNUNG: Ungueltiges Datum, wird auf 1.1.1990 gesetzt" << endl;
	}
}

Datumzeiger::Datumzeiger(int t, int m, int j) : tag(t), monat(m), jahr(j) {
	if (!istGueltig()) {
		tag = monat = 1;
		jahr = STARTJAHR;
		cout << "WARNUNG: Ungueltiges Datum, wird auf 1.1.1990 gesetzt" << endl;
	}
}

Datumzeiger::Datumzeiger(bool zufall) {  // Wenn TRUE Zufallsdatum, sonst Standarddatum
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
Datumzeiger::~Datumzeiger() {}

// Setter Methoden
void Datumzeiger::setTag(int t) {
	int temp = tag;         // den aktuellen Tag merken, falls die Aenderung nicht klappt
	if (istGueltig()) {
		tag = t;
	}
	else {
		cout << "WARNUNG: Tag " << t << " nicht gueltig!" << endl;
		tag = temp;       // Der alte Tag wird nicht veraendert
	}
}

void Datumzeiger::setMonat(int m) {
	int temp = monat;
	if (istGueltig()) {
		monat = m;
	}
	else {
		cout << "WARNUNG: Monat " << m << " nicht gueltig!" << endl;
		monat = temp;
	}
}

void Datumzeiger::setJahr(int j) {
	int temp = jahr;
	if (istGueltig()) {
		jahr = j;
	}
	else {
		cout << "WARNUNG: Jahr " << j << " nicht gueltig!" << endl;
		jahr = temp;
	}
}

// Getter Methoden
int Datumzeiger::getTag() const { return tag; }
int Datumzeiger::getMonat() const { return monat; }
int Datumzeiger::getJahr() const { return jahr; }

// Wietere Methoden

// das Datum auf ein Neujahr setzen
void Datumzeiger::setNeuJahr(int j) {
	tag = monat = 1;
	if (istGueltig()) {
		cout << "WARNUNG: Jahr " << j << " nicht gueltig wird auf " << STARTJAHR << " gesetzt." << endl;
		jahr = STARTJAHR;
	}
}

// Das Datum um einen Tag verschieben
void Datumzeiger::setMorgen() {
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

// ueberpruefen, ob das Datum im Schaltjahr liegt
bool Datumzeiger::istSchaltjahr() const {
	return (jahr % 400 == 0) || (jahr % 4 == 0 && jahr % 100 != 0);
}

// Datum im Format tag-monat-jahr ausgeben
void Datumzeiger::ausgeben() const {
	cout << tag << "-" << monat << "-" << jahr << endl;
}

// ueberpruefen, ob das Datum gueltig ist
bool Datumzeiger::istGueltig() const {
	int maxTage[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	maxTage[1] = istSchaltjahr() ? 29 : 28;
	return (jahr >= STARTJAHR && monat >= 1 && monat <= 12 && tag >= 1 && tag <= maxTage[monat - 1]);
}
