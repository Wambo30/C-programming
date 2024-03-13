/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
/* Datum2.h */
#ifndef DATUM2_H
#define DATUM2_h


#include <iostream>

using namespace std;

class Datum2 {
	friend ostream& operator<<(ostream&, const Datum2&);
public:
	const int STARTJAHR = 1990;
	Datum2();                       // Standardkonstruktor
	Datum2(int, int, int);          // Das Datum auf t.m.j setzen
	//Datum2(int);                    // Das Datum auf Neujahr j setzten
	Datum2(bool);                   // bei true Zufallsdatum erstellen
	~Datum2();                      // Destruktor

	Datum2(const Datum2&);	//kopierkonstruktor
	const Datum2 operator=(const Datum2&);	//zuweisungsoperator
	
									
// Setter- und Getter-Methoden
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	int getTag() const;
	int getMonat() const;
	int getJahr() const;

	// andere Methoden
	void setNeuJahr(int);          // Das Datum auf Neujahr setzen
	void setMorgen();              // Das Datum um einen Tag verschieben
	void ausgeben() const;         // Das Datum auf der Konsole ausgeben
	bool istSchaltjahr() const;    // Ueberprueft, ob das Datum in
								   // einem Schaltjahr liegt
	void setHeute();

	//ueberladen von operatoren
	bool operator==(const Datum2&) const; //vergleichsoperator
	bool operator<(const Datum2& d) const;
	bool operator>(const Datum2& d) const;


private:
	int tag;
	int monat;
	int jahr;

	// ueberprueften, ob die Parameter einem gueltigen Datum entsprechen
	bool istGueltig() const;
	void ueberpruefen() const;
};




#endif // DATUM_H
