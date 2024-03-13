#ifndef STAPEL_H
#define STAPEL_H

#include "StapelIstLeerFehler.h"
#include <iostream>
using namespace std;

template<typename T> class Stapel{
public :
	// Einen leeren Stapelanlegen
	Stapel();

	// Der Kopierkonstruktor
	Stapel(const Stapel<T>&);

	// Der Destruktor
	~Stapel();

	// Der Zuweisungsoperator
	Stapel<T>& operator=(const Stapel<T>&);

	// Ueberpruefen , ob der Stapel Elemente enthaelt
	bool istLeer() const;

	// Anzahl der gespeicherten Elemente zurueckgeben
	size_t getAnzahl() const;

	// Das oberste Element vom Stapel zurueckgeben
	T getVonOben() const throw (StapelIstLeerFehler);

	// Neues Element auf den Stapellegen
	void fuegeHinzu(const T&);

	// Ein Element vom Stapelentfernen
	void entferne() throw (StapelIstLeerFehler);

private :
	T *elemente;	// das Array mit den Elementen des Stapels
	size_t anzahl; // die aktuelle Anzahl der Elemente im Stapel
};

// Ausgabe eines Stapels
template <typename T>
ostream& operator<<(ostream& out, const Stapel<T>& s) {
	Stapel<T> kopie = s;
	int i = kopie.getAnzahl();
	while (!kopie.istLeer()) {
		out << i << ". Element im Stapel: " << kopie.getVonOben() << endl;
		kopie.entferne();
		i--;
	}
	return out;
}

//Implementierung aller template fkten usw da wir template klasse haben!
//dh stapel.cpp existiiert nicht!

template <typename T>
Stapel<T>::Stapel() : anzahl(0), elemente(nullptr) {}

template <typename T>
Stapel<T>::~Stapel() {
	if (elemente) {
		delete[] elemente;
	}
}

//kopierkonstr
template <typename T>
Stapel<T>::Stapel(const Stapel<T>& s): anzahl(s.anzahl) {
	elemente = new T[anzahl];     //[s.getAnzahl()+1];
	for (size_t i = 0; i < anzahl; i++) {
		elemente[i] = s.elemente[i];
	}
}

//Zuweisungsoperator
template <typename T>
Stapel<T>& Stapel<T>::operator=(const Stapel<T>& s) {
	if (elemente) {
		delete[] elemente;
	}
	elemente = new T[s.anzahl];
	for (int i = 0; i < s.anzahl; i++) {
		elemente[i] = s.elemente[i];
	}
	anzahl = s.anzahL;
	return *this;
}

template <typename T>
bool Stapel<T>::istLeer() const {
	return getAnzahl() == 0;
}

template <typename T>
size_t Stapel<T>::getAnzahl() const {
	return anzahl;
}

template <typename T>
T Stapel<T>::getVonOben() const throw (StapelIstLeerFehler) {
	if (anzahl == 0) {
		throw StapelIstLeerFehler();
	}
	return elemente[anzahl - 1];
}

template <typename T>
void Stapel<T>::fuegeHinzu(const T& s) {
	// Kopie vom aktuellem Stapel machen
	Stapel<T> kopie = *this;

	// Stapel löschen
	if( elemente) delete[] elemente;

	// Stapel neu mit 1 element mehr anlegen
	anzahl++;
	elemente = new T[anzahl];

	// alte Elemente kopieren
	for (int i = 0; i < kopie.anzahl; i++) {
		elemente[i] = kopie.elemente[i];
	}
	// Das neue Element (Parameter) nach oben legen
	elemente[anzahl - 1] = s;
}

template <typename T>
void Stapel<T>::entferne() throw (StapelIstLeerFehler) {
	if (anzahl == 0) {
		throw StapelIstLeerFehler();
	}

	// Kopie vom aktuellem Stapel machen
	Stapel<T> kopie = *this;

	// Stapel löschen also speicherplatz freigeben
	if (elemente) delete[] elemente;

	anzahl--;
	elemente = new T[anzahl];

	// kopie zum array mit anzahl -1  
	for (int i = 0; i < anzahl; i++) {
		elemente[i] = kopie.elemente[i];
	}

}


#endif //STAPEL_H
