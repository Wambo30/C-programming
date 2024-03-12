/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
/* Datum.cpp */

#define _CRT_SECURE_NO_WARNINGS

#include "Datum2.h"
#include "DateError.h"
#include <iostream>
#include <ctime>

	using namespace std;

// Konstruktoren
Datum2::Datum2() : tag(1), monat(1), jahr(STARTJAHR) {} //Standardkonstruktor

Datum2::Datum2(int t, int m, int j) : tag(1), monat(1), jahr(STARTJAHR) {
	setJahr(j);
	setMonat(m);
	setTag(t);
}

Datum2::Datum2(bool zufall) {  // Wenn TRUE Zufallsdatum, sonst Standarddatum
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

bool Datum2::operator<(const Datum2& d) const {
	if (jahr < d.jahr)
	{
		return true;
	}
	else if (jahr == d.jahr)
	{
		if (monat < d.monat)
		{
			return true;
		}
		else if (monat == d.monat)
		{
			if (tag < d.tag)
				return true;
		}
	}
	return false;
}

bool Datum2::operator>(const Datum2& d) const {
	cout << jahr << " " << d.jahr << endl;
	if (jahr > d.jahr)
	{
		return true;
	}
	else if (jahr == d.jahr)
	{
		cout << monat << " " << d.monat << endl;
		if (monat > d.monat)
		{
			cout << "test1" << endl;
			return true;
		}
		else if (monat == d.monat)
		{
			if (tag > d.tag) {
				cout << "test2" << endl;
				return true;
			}
		}
	}
	return false;
}


//kopierkonstruktor
Datum2::Datum2(const Datum2& d) {
	tag = d.tag;
	monat = d.monat;
	jahr = d.jahr;
}


//zuweisungsoperator
const Datum2 Datum2::operator=(const Datum2& d) {
	tag = d.tag;
	monat = d.monat;
	jahr = d.jahr;
	return *this;
}

//vergleichsoperator
bool Datum2::operator==(const Datum2& d) const {
	return (tag == d.tag && monat == d.monat && jahr == d.jahr);
}


// Destruktor
Datum2::~Datum2() {}

// Setter Methoden
void Datum2::setTag(int t) {
	tag = t;
	if (!istGueltig()) {
		throw InvalidDayError(t, monat, jahr);
	}
}

void Datum2::setMonat(int m) {
	monat = m;
	if (!istGueltig()) {
		throw InvalidMonthError(tag, monat, jahr);
	}
}

void Datum2::setJahr(int j) {
	jahr = j;
	if (!istGueltig()) {
		throw InvalidYearError(tag, monat, jahr);
	}
}

// Getter Methoden
int Datum2::getTag() const { return tag; }
int Datum2::getMonat() const { return monat; }
int Datum2::getJahr() const { return jahr; }

// Wietere Methoden

// das Datum auf ein Neujahr setzen
void Datum2::setNeuJahr(int j) {
	tag = monat = 1;
	jahr = j;
	if (!istGueltig()) {
		throw InvalidYearError(tag, monat, jahr);
	}
}

// Das Datum um einen Tag verschieben
void Datum2::setMorgen() {
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

void Datum2::setHeute() {
	time_t zeit = time(NULL);
	tm heute = *localtime(&zeit);
	tag = heute.tm_mday;
	monat = heute.tm_mon + 1; // Zaehlung beginnt bei 0
	jahr = heute.tm_year + 1900; // Zaehlung beginnt bei 1900
}




// ueberpruefen, ob das Datum im Schaltjahr liegt
bool Datum2::istSchaltjahr() const {
	return (jahr % 400 == 0) || (jahr % 4 == 0 && jahr % 100 != 0);
}

// Datum im Format tag-monat-jahr ausgeben
void Datum2::ausgeben() const {
	cout << tag << "-" << monat << "-" << jahr << endl;
}

// ueberpruefen, ob das Datum gueltig ist
bool Datum2::istGueltig() const {
	int maxTage[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	maxTage[1] = istSchaltjahr() ? 29 : 28;
	return (jahr >= STARTJAHR && monat >= 1 && monat <= 12 && tag >= 1 && tag <= maxTage[monat - 1]);
}

ostream& operator<<(ostream& aus, const Datum2& d) {
	aus << d.tag << "." << d.monat << "." << d.jahr;
	return aus;
}

