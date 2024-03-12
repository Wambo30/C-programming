/* Datum.cpp */

#include "Datum.h"
#include "DateError.h"
#include <iostream>
using namespace std;

// Konstruktoren
Datum::Datum() : tag(1), monat(1), jahr(STARTJAHR) {} //Standardkonstruktor

Datum::Datum(int t, int m, int j) : tag(1), monat(1), jahr(STARTJAHR) {
    setJahr(j);
    setMonat(m);
    setTag(t);
}

Datum::Datum(bool zufall) {  // Wenn TRUE Zufallsdatum, sonst Standarddatum
    if( zufall ) {
        tag = rand() % 31 + 1;
        monat = rand() % 12 + 1;
        jahr = rand() % 100 + 1990;
        if ( !istGueltig()) {
            tag = rand() % 28 + 1;
        }
    }
    else {
        tag = monat = 1;
        jahr = STARTJAHR;
    }
}

// Destruktor
Datum::~Datum() {}

// Setter Methoden
void Datum::setTag(int t) {
    tag = t;
    if( !istGueltig() ) {
        throw InvalidDayError(t, monat, jahr);
    }
}

void Datum::setMonat(int m) {
    monat = m;
    if( !istGueltig() ) {
        throw InvalidMonthError(tag, monat, jahr);
    }
}

void Datum::setJahr(int j) {
    jahr = j;
    if( !istGueltig() ) {
        throw InvalidYearError(tag, monat, jahr);
    }
}

// Getter Methoden
int Datum::getTag() const { return tag; }
int Datum::getMonat() const { return monat; }
int Datum::getJahr() const { return jahr; }

// Wietere Methoden

// das Datum auf ein Neujahr setzen
void Datum::setNeuJahr(int j) {
    tag = monat = 1;
    jahr = j;
    if( !istGueltig() ) {
        throw InvalidYearError(tag, monat, jahr);
    }
}

// Das Datum um einen Tag verschieben
void Datum::setMorgen() {
    tag++;
    if( !istGueltig() ) {
        tag = 1;
        monat++;
        if( !istGueltig() ) {
            monat = 1;
            jahr++;
        }
    }
}

// ueberpruefen, ob das Datum im Schaltjahr liegt
bool Datum::istSchaltjahr() const {
    return (jahr % 400 == 0) || (jahr % 4 == 0 && jahr % 100 != 0);
}

// Datum im Format tag-monat-jahr ausgeben
void Datum::ausgeben() const {
    cout << tag << "-" << monat << "-" << jahr << endl;
}

// ueberpruefen, ob das Datum gueltig ist
bool Datum::istGueltig() const {
    int maxTage[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    maxTage[1] = istSchaltjahr() ? 29 : 28;
    return (jahr >= STARTJAHR && monat >= 1 && monat <= 12 && tag >= 1 && tag <= maxTage[monat-1]);
}

ostream& operator<<(ostream& aus, const Datum& d){
    aus << d.tag << "." << d.monat << "." << d.jahr;
    return aus;
}
