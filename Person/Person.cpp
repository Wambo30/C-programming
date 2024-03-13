/* Person.cpp */

#include "Person.h"
#include <iostream>
using namespace std;

/* class Person */

Person::Person(){
	cout << "Konstruktor von Person" << endl;

}

void Person::setName(string s) { name = s; }
void Person::setAdresse(string s) { adresse = s; }
void Person::setEmail(string s) { email = s; }

string Person::getName() const { return name; }
string Person::getAdresse() const { return adresse; }
string Person::getEmail() const { return email; }


/* class Student */
Student::Student() {

	cout << "Konstruktor von Student" << endl;
}

void Student::setMatrikelnummer(int i) { matrikelnummer = i; }
int Student::getMatrikelnummer() const { return matrikelnummer; }


/* class OnlineStudent */

void OnlineStudent::setOnlineZugang(string s) { onlineZugang = s; }
string OnlineStudent::getOnlineZugang() const { return onlineZugang; }


/* class Angestellte */

void Angestellte::setPersonalnummer(string s) { personalnummer = s; }
string Angestellte::getPersonalnummer() const { return personalnummer; }

void Angestellte::ausgeben() const {
	cout << getName() << endl; // private in Person
	cout << getAdresse() << endl;	// protected
	cout << getEmail() << endl;
	cout << personalnummer<< endl;
}

/* class Dozent */

void Dozent::setFachbereich(int i) { fachbereich = i; }
int Dozent::getFachbereich() const { return fachbereich; }
void Dozent::ausgeben() const {
	Angestellte::ausgeben();
	cout << fachbereich << endl;
}

/* class Verwaltung */

void Verwaltung::setAbteilung(string s) { abteilung = s; }
string Verwaltung::getAbteilung() const { return abteilung; }