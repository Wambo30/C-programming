//Autoren: 

#include <cstdio>
#include <string>

using namespace std;

//Klasse für Natuerliche Zahlen
class Natuerlich 
{

private:
 /*** private Attribute***/

	//Ziffern des Objekts
    int *_ziffer;

	//Gesamtlänge des Objekts
    size_t _laenge;

 /*** privater Konstruktor***/

	//Ersttele ein Array mit lenght Nullen
    Natuerlich(size_t);

public:
	//Ersetze den strandard Konstruktor
    Natuerlich();

	//lese aus dem String eine Zahl heraus bis zur ersten nicht Zahl
    Natuerlich(string const &);

	//Kopierkonstruktor
    Natuerlich(Natuerlich const&);

	// initialisiere Objekt mit dem Betrag des Zahlenwerts seines Arguments
    Natuerlich(long long);

	// Zuweisungoperator
    void operator= (Natuerlich const&);

	
 /*** Rechenoperatoren ***/

	//Addition
    Natuerlich operator+ (Natuerlich const&)const;

	//Multiplikation
    Natuerlich operator* (Natuerlich const&)const;


	//gebe zurück, ob das Objekt einen geraden Zahlenwert hat
    bool istGerade();

 /*** globale Funktion ***/

	// gib String auf ostream aus
    friend ostream& operator << (ostream& ostr, Natuerlich const&);
	
 /*** Destruktor ***/

    ~Natuerlich();
};

// berechne n. Fibonacci-Zahl
Natuerlich fibonacci (size_t);

// berechne Potenz x hoch n
Natuerlich potenz (Natuerlich const&, size_t);

// berechne Fakultät n! 
Natuerlich fakultaet ( size_t);