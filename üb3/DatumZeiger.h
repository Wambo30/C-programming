/* Datum.h */
#ifndef DATUMZEIGER_H
#define DATUMZEIGER_H

class Datumzeiger {
public:
	const int STARTJAHR = 1990;
	Datumzeiger();                       // Standardkonstruktor
	Datumzeiger(int, int, int);          // Das Datum auf t.m.j setzen
	Datumzeiger(int);                    // Das Datum auf Neujahr j setzten
	Datumzeiger(bool);                   // bei true Zufallsdatum erstellen
	~Datumzeiger();                      // Destruktor

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
private:
	int tag;
	int monat;
	int jahr;

	// Eine Funktion, die ueberprueft, ob die Parameter einem gueltigen Datum entsprechen
	bool istGueltig() const;
};




#endif // DATUM_H
