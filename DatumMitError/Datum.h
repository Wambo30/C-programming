/* Datum.h */
#ifndef DATUM_H
#define DATUM_H

#include <iostream>
using namespace std;

class Datum {
    friend ostream& operator<<(ostream&, const Datum&);
public:
    const int STARTJAHR = 1990;
    Datum();                       // Standardkonstruktor
    Datum(int, int, int);          // Das Datum auf t.m.j setzen
    Datum(int);                    // Das Datum auf Neujahr j setzten
    Datum(bool);                   // bei true Zufallsdatum erstellen
    ~Datum();                      // Destruktor
    
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
    
    // ueberprueften, ob die Parameter einem gueltigen Datum entsprechen
    bool istGueltig() const;
    void ueberpruefen() const;
};




#endif // DATUM_H
