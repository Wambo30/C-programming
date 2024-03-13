/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

/* Dual.cpp */

#define _USE_MATH_DEFINES
#define M_PI1 

#include "Dual.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Konstruktoren

//Standardkonstruktor
Dual::Dual() : anzahl(1) {
	ziffern = new bool[anzahl];
	ziffern[0] = false;
}	

Dual::Dual(size_t dezimal) {
	if (dezimal > 0) {
		double stellenanzahl = log2(dezimal);

		anzahl = (size_t)ceil(stellenanzahl);
		if (ceil(stellenanzahl) == floor(stellenanzahl))
		{
			anzahl = anzahl + 1;
		}

		ziffern = new bool[anzahl];
		umrechnenDezimalZuDual(dezimal);
	}
	else {
		cout << "WARNUNG: Dezimalzahl < 0 und wird auf 0 gesetzt" << endl;
		ziffern = new bool[1];
		ziffern[0] = 0;
	}
}

//Kopierkonstruktor
Dual::Dual(const Dual& d) : anzahl(d.anzahl) {
	// Speicherplatzreservierung fuer Kopie des arrays 
	ziffern = new bool[anzahl];

	// Kopie der Elemente aus Array
	for (int i = 0; i < anzahl; i++) {
		ziffern[i] = d.ziffern[i];
	}
}
// Zuweisungsoperator
Dual& Dual::operator=(const Dual& d) {

	// Speicherplatz des Zielobjektes freigeben
	if (ziffern) delete[] ziffern;

	// Neuen Speicherplatz anfordern
	ziffern = new bool[d.anzahl];

	// Dynamische Daten des Quellobjekts in das Zielobjekt speichern
	for (int i = 0; i < d.anzahl; i++)
		ziffern[i] = d.ziffern[i];

	// Alle Elementvariablen, die keine Zeiger sind, kopieren
	anzahl = d.anzahl;

	// das Zielobjekt zurueckgeben
	return *this;
}

// Destruktor
Dual::~Dual() {
	if (ziffern) {
		delete[] ziffern;
		ziffern = 0;
	}
}

// Setter Methoden

// Getter Methoden

// andere Methoden

//Augabe als String
void Dual::ausgeben() {

	cout << toString() << endl;
}

//Umwandlung von Dual zu Dezimal
double Dual::toDezimal() {
	double dezimal = 0;
	for (int i = anzahl - 1; i >= 0; i--) {
		if (ziffern[i]) {
			dezimal = (2 * dezimal + 1);
		}
		else {
			dezimal = (2 * dezimal + 0);
		}
	}
	return dezimal;
}

string Dual::toString() const {
	string dual;

	for (int i = anzahl - 1; i >= 0; i--) {
		if (ziffern[i]) {
			dual += "1";
		}
		else {
			dual += "0";
		}
	}
	return dual;
}

// Operatoren

//Dual + Dual
Dual& Dual::operator+=(const Dual& d) {
	size_t anzahlNeu = (size_t)fmax(d.anzahl, anzahl);
	bool uebertrag = false;

	bool *resultZiffern = new bool[anzahlNeu + 1];
	if (anzahl > d.anzahl) {
		for (int i = 0; i < anzahl; i++) {
			if (i < d.anzahl) {
				resultZiffern[i] = addieren(ziffern[i], d.ziffern[i], uebertrag);
			}
			else {
				resultZiffern[i] = addieren(ziffern[i], false, uebertrag);
			}
		}
	}
	else {
		for (int i = 0; i < d.anzahl; i++) {
			if (i < anzahl) {
				resultZiffern[i] = addieren(d.ziffern[i], ziffern[i], uebertrag);
			}
			else {
				resultZiffern[i] = addieren(d.ziffern[i], false, uebertrag);
			}
		}
	}
	if (uebertrag == true) {
		resultZiffern[anzahlNeu] = true;
		anzahl = anzahlNeu + 1;
	}
	else {
		anzahl = anzahlNeu;
	}

	delete[] ziffern;
	ziffern = resultZiffern;
	return *this;
}

Dual Dual::operator+(const Dual& d) {
	Dual result;
	result += d;
	result += *this;
	return result;
}


// Dual * Dual
Dual& Dual::operator*=(const Dual& d) {
	size_t anzahlNeu = d.anzahl + anzahl;
	bool *resultZiffern = new bool[anzahlNeu];
	for (size_t i = 0; i < anzahlNeu; i++) {
		resultZiffern[i] = false;
	}
	bool uebertrag = false;

	for (size_t i = 0; i < anzahl; i++) {
		if (ziffern[i]) {
			uebertrag = false;
			for (size_t j = 0; j < d.anzahl; j++) {
				size_t pos = i + j;
				bool ziffer = d.ziffern[j];
				bool resultZiffer = resultZiffern[pos];
				resultZiffern[pos] = addieren(ziffer, resultZiffer, uebertrag);
			}
			if (uebertrag) {
				resultZiffern[i + d.anzahl] = true;
			}
		}
	}
	delete[] ziffern;
	ziffern = resultZiffern;
	if (resultZiffern[anzahlNeu - 1]) {
		anzahl = anzahlNeu;
	}
	else {
		anzahl = anzahlNeu - 1;
	}
	return *this;
}

Dual Dual::operator*(const Dual& d) {
	Dual result(1);
	result *= d;
	result *= *this;
	return result;
}

// Berechnungen

//umrechnen von Dezimal in Dualzahl
void Dual::umrechnenDezimalZuDual(size_t dezimal) {
	size_t temp = dezimal;
	for (int i = 0; i < anzahl; i++) {
		if (temp % 2 == 0) {
			ziffern[i] = false;
		}
		else {
			ziffern[i] = true;
		}
		temp = temp / 2;
	}
}

// Funktion zum Addieren zweier Dualzahlen
bool Dual::addieren(bool b1, bool b2, bool& uebertrag) {
	bool result = false;
	if (b1 != b2 && uebertrag == false) {
		result = true;
	}
	else if (b1 != b2 && uebertrag == true) {
		result = false;
	}
	else if (b1 && b2 && uebertrag == false) {
		result = false;
		uebertrag = true;
	}
	else if (b1 && b2 && uebertrag == true) {
		result = true;
	}
	else if (!b1 && !b2 && uebertrag == false) {
		result = false;
	}
	else if (!b1 && !b2 && uebertrag == true) {
		result = true;
		uebertrag = false;
	}
	return result;
}


