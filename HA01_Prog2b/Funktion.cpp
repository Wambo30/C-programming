/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

#include "Funktion.h"

#include <iostream>
#include <cmath>
using namespace std;

// Konstruktor fuer ein Funktion mit Zufallskoeffizienten in [-1.,1.]
Funktion::Funktion(size_t g) : grad(g) {
	koeffizienten = new double[grad + 1];
	for (size_t i = 0; i < grad + 1; i++) {
		// Eine Zahl zwischen -10000 und 10000 (zum Beispiel)
		// die Zahl auf den Intervall [-1,1] skalieren
		koeffizienten[i] = (rand() % 20001 - 10000) / 10000.;
	}
	// solange der führende Koeffizient auf Null gesetzt wird
	// Rundungsfehler bei double Datentyp beachten
	while (abs(koeffizienten[grad]) < DBL_EPSILON) { // == 0
		koeffizienten[grad] = (rand() % 20001 - 10000) / 10000.;
	}
}


// Kopierkonstruktor
Funktion::Funktion(const Funktion& p) : grad(p.grad) {
	// Speicherplatz fuer die Kopie des Feldes reservieren
	koeffizienten = new double[p.grad + 1];

	// Die Elemente des Feldes Kopieren
	for (int i = 0; i <= p.grad; i++) {
		koeffizienten[i] = p.koeffizienten[i];
	}
}

// Zuweisungsoperator
// Rueckgabewert: eine Referenz auf ein Objekt der eigenen Klasse
// Parameter: konstante Refrenz auf ein Objekt der Klasse
Funktion& Funktion::operator=(const Funktion& p) {

	// Speicherplatz des Zielobjektes freigeben
	if (koeffizienten) delete[] koeffizienten;

	// Neuen Speicherplatz anfordern
	koeffizienten = new double[p.grad + 1];

	// Dynamische Daten des Quellobjekts in das Zielobjekt speichern
	for (int i = 0; i <= p.grad; i++)
		koeffizienten[i] = p.koeffizienten[i];

	// Alle Elementvariablen, die keine Zeiger sind, kopieren
	grad = p.grad;

	// das Zielobjekt zurueckgeben
	return *this;
}

// Destruktor
Funktion::~Funktion() {
	if (koeffizienten) {
		delete[] koeffizienten;
		koeffizienten = 0;
	}
}

//p(x)
//berechne p(x) für einen bestimmten Wert x
const double Funktion::operator()(double x) const {
	double x_temp = x;
	double ergebnis = 0;
	//size_t hoch = 0;
	size_t hoch = grad;
	for (int i = 0; i <= grad; i++) {
		ergebnis += koeffizienten[i] * pow(x_temp, hoch);
		hoch++;
	}
	return ergebnis;
}

// Wert Ableitung der Funktion p(x)
double Funktion::ableitung(double x) const {
	double x_temp = x;
	double ergebnis = 0;
	size_t hoch = 1;
	for (int i = 1; i <= grad; i++) {
		ergebnis += koeffizienten[i] * pow(x_temp, hoch - 1) * hoch;
		hoch++;
	}
	return ergebnis;
}

bool Funktion::istGerade() {
	return grad % 2 == 0;
}

bool Funktion::istUngerade() {
	return grad % 2 != 0;
}


//Betragsfunktion
double Funktion::betrag(double x) const {
	return (x >= 0) ? (x) : -(x);
}

//Nullstellenberechnung mit Newton
void Funktion::nullstellenFinden(double*& x) const {
	double delta_x = 10;
	size_t iterAnz = 100;
	int i = 0;
	for (; i <= iterAnz; i++) {
		if (betrag(delta_x) > EPS) {
			delta_x = -(*this)(*x) / ableitung(*x);
			*x = *x + delta_x;
		}
		else
		{
			break;
		}
	}
	if (i == iterAnz + 1) {
		x = nullptr;
	}
}

// Ausgabe als String
string Funktion::toString() const {
	string pol = " = ";
	for (size_t i = grad; i > 0; i--) {
		if (abs(koeffizienten[i]) > DBL_EPSILON) { //koeffizienten[i] != 0
			pol.append(to_string(koeffizienten[i]));
			pol.append(" * x^");
			pol.append(to_string(i));
			pol.append(" + ");
		}
	}
	if (abs(koeffizienten[0]) > DBL_EPSILON) {
		pol.append(to_string(koeffizienten[0]));
	}
	else if (grad == 0) { // Bei Null macht to_string gar nichts
		pol.append("0");
	}
	return pol;
}
