/* DatumUeb3.h */
#ifndef DatumUeb3_H
#define DatumUeb3_H
#include "DatumFehler.h"

class DatumUeb3 {

	//friend ostream& operator<<(ostream& aus, const DatumUeb3&);
public:
	//friend ostream& operator << (ostream& aus, const DatumUeb3&);
	const int STARTJAHR = 1990;
	DatumUeb3();                       // Standardkonstruktor
	DatumUeb3(int, int, int);          // Das Datum auf t.m.j setzen
	//DatumUeb3(int);                    // Das Datum auf Neujahr j setzten
	DatumUeb3(bool);                   // bei true Zufallsdatum erstellen
	~DatumUeb3();                      // Destruktor

								   // Setter- und Getter-Methoden
	void setTag(int) throw (InvalidDayError) ;
	void setMonat(int) throw (InvalidMonthError);
	void setJahr(int) throw (InvalidYearError);
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
