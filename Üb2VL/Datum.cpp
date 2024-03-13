// diese Datei wo alle methoden/fkten stehen MUSS genauso hei�en
// wie der header also Datum eben

#include "Datum.h"
#include <iostream>
using namespace std;

// standardkontruktor

Datum::Datum() {
	tag = monat = 1;	// standard werte werden hier gesetzt!!
	jahr = 1990;
	//cout<< "Ein Startdatum: "<< endl;
}

Datum::Datum(int t, int m, int j) {
	setTag(t);
	setMonat(m);
	setJahr(j);
	//�nderung wegen g�ltigkeit von datum

	int temp = tag;
	tag = t;
	if (!istGueltig()) {
		cout << "ung�ltiges Datum" << tag - monat - jahr << endl;
		tag = temp;
	}

}
/*
Datum::Datum(int j) { // konstruktor 3
	tag = monat = 1;
	jahr = j;
	//cout <<"Ein neujahr: " << endl;
}
*/
// anderes schreiben des kontruktors 3 also k�rzere form
Datum::Datum(int j) :tag(1), monat(1), jahr(j) {
}

//blatt 2 aufg1.5
//konstruktor der objekt auf ein zuf�lliges, g�ltiges datum setzt
// soll bool 


// Datum::Datum() {

//}


//destruktor--> wird bei arrays benutzt
Datum::~Datum() {
}

// konstruktoren k�nnen ERST benutzt werden wenn wir bereits die objekte tag,monat, jahr
//haben!



void Datum::setTag(int t) {
	tag = t;
}

void Datum::setMonat(int m) {
	monat = m;
}

void Datum::setJahr(int j) {
	jahr = j;
}


// durch const in signatur k�nnen objekte nicht ver�ndert werden!
int Datum::getTag() const {
	return tag;
}

int Datum::getMonat() const{
	return monat;
}

int Datum::getJahr()const {
	return jahr;
}

//andere funktionen

void Datum::neuJahr(int j) {
	tag = 1;
	monat = 1;
	jahr = j;
}


bool Datum::istSchaltjahr() const {

	//jahreszahl durch 4 teilbar aber nicht durch 100 und jahr durch 400 teilbar
	//modulo regel: n = m*a+b also 17%3 = 2 da 17= 5*3+2
	//((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0))
	return ((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0) );

}

// void == hei�t es wird kein return in fkt benutzt!
//g�ltigkeit des datums pr�fen dh soll gr��er gleich 1990 sein
bool Datum::istGueltig()const {
	
	int maxTage[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	maxTage[1] = (istSchaltjahr()) ? 29 : 28;
	return (jahr >= 1990 && monat >= 1 && monat <= 12 && tag >= 1 && tag <= maxTage[monat - 1]);
}

//aufg 1.4
// um ein tag datum verschieben und gucken ob das datum noch g�ltig ist
void Datum::setMorgen() {
	tag++;
	if (!istGueltig()) {
		tag = 1;
		monat++;
		if (!istGueltig()) {
			monat = 1;
			jahr++;
		}


		/*if (tag <= 31 && monat <= 12)
			tag++;

		if (tag > 31 && monat >= 12) {
			setTag(1);
			setMonat(1);
			jahr++;
			}*/
	}
}
