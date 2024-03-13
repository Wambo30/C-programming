#include "UeberschreibenMethode.h"
#include <iostream>
using namespace std;

void Datum::setTag(int t) {
	tag = t;
}
void Datum::setMonat(int m) {
	monat = m;
}
void Datum::setJahr(int j) {
	jahr = j;
}
int Datum::getTag() const {
	return tag;
}
int Datum::getMonat() const {
	return monat;
}
int Datum::getJahr() const {
	return jahr;
}

Datum::Datum(): tag(1),monat(1),jahr(1987){}

void Datum::ausgeben() const {
	cout << "tag: " << getTag() << endl;
	cout << "monat: " << getMonat() << endl;
	cout << "jahr: " << getJahr() << endl;
}

void Datum::ausgeben()  {
	cout << "ausgeben2 tag: " << getTag() << endl;
	cout << "ausgeben2 monat: " << getMonat() << endl;
	cout << "ausgeben2 jahr: " << getJahr() << endl;
}

void Datum::ausgeben2Ueber(int i) {
	cout << "ausgeben2Ueber int tag: " << getTag() << endl;
	cout << "ausgeben2Ueber int monat: " << getMonat() << endl;
	cout << "ausgeben2Ueber int jahr: " << getJahr() << endl;
}

void Datum::ausgeben2Ueber(double i) {
	cout << "ausgeben2 ueberlaedt mit double tag: " << getTag() << endl;
	cout << "ausgeben2 ueberlaedt mit double monat: " << getMonat() << endl;
	cout << "ausgeben2 ueberlaedt mit double jahr: " << getJahr() << endl;
}


void Datum::ausgeben3Spezial(int i)const {
	cout << "spezial ausgeben3 mit int tag: " << getTag() << endl;
	cout << "spezial ausgeben3 mit int monat: " << getMonat() << endl;
	cout << "spezial ausgeben3 mit int jahr: " << getJahr() << endl;
}

void Datum::ausgeben3Spezial(double i)const {
	cout << "spezial ausgeben3 mit double tag: " << getTag() << endl;
	cout << "spezial ausgeben3 mit double monat: " << getMonat() << endl;
	cout << "spezial ausgeben3 mit double jahr: " << getJahr() << endl;
	

}



int Datum::fkt1(int i) {
	
	return getTag();

}

double Feiertag::fkt1(int i) {
	return getTag() + i;
}

// klasse feiertag
Feiertag::Feiertag(){
	name = "bayram";
	anlass = "ramadan";
	monatfeiertag = 6;
}

void Feiertag::setName(string n) {
	name = n;
}

string Feiertag::getName() const {
	return name;
}

void Feiertag::setAnlass(string a) {
	anlass = a;
}
void Feiertag::ausgeben()const {
	cout << "monat feiertag: " << monatfeiertag << endl; // OHNE getter möglich!
	cout << "anlass feiertag: " << anlass << endl; // OHNE getter möglich!
	cout << "name feiertag: " << name << endl; // OHNE getter möglich!
// warum? bei abgeleiteten klassen kann man die eigenen private attribute auch OHNE
// getter LESEN!ist ausnahme
	cout << "tag: " << getTag() << endl;
	cout << "monat: " << getMonat() << endl;
	cout << "jahr: " << getJahr() << endl;
	Datum::ausgeben();
}

void Feiertag::ausgeben3Spezial(int i)const {
	cout << "spezial mit int monat feiertag: " << monatfeiertag << endl; // OHNE getter möglich!
	cout << "spezial mit int anlass feiertag: " << anlass << endl; // OHNE getter möglich!
	cout << "spezial mit int name feiertag: " << name << endl; // OHNE getter möglich!
											   // warum? bei abgeleiteten klassen kann man die eigenen private attribute auch OHNE
											   // getter LESEN!ist ausnahme
	cout << "spezial mit int tag: " << getTag() << endl;
	cout << "spezial mit int monat: " << getMonat() << endl;
	cout << "spezial mit int jahr: " << getJahr() << endl;
	
}