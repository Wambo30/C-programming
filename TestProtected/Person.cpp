#include <iostream>
#include <string>
#include "Person.h"
using namespace std;


// Klasse Person





void Person::setName(string n) {
	name = n;

}
void Person::setAdresse(string a) {

	adresse = a;
}
string Person::getName() const {

	return name;
}
string Person::getAdresse() const {

	return adresse;
}


// klasse Angestellte

void Angestellte::setPersonalnr(string p) {
	personalnr = p;

}
void Angestellte::ausgeben() const {
	cout <<"name: " << getName() << endl;
	cout << "adresse: " << adresse << endl;
	cout << "email: " << email << endl;
	cout << "personalnr: " << personalnr << endl;

}

void Angestellte::ausgeben2() const {
	cout << email << endl;
}
