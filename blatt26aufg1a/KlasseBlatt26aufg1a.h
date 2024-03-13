#include <iostream>
#include <cmath>		// für sqrt()

using namespace std;

/**
* Klasse zur Darstellung zweidimensionaler Vektoren
*/

class Vektor2d		// Name des Datentyps
{
	/***  private Attribute  ***/

	// Komponenten des Objekts
	// Konvention: private Variablen beginnen mit '_'
	double _x, _y;

public:		// ab hier ist alles außen sichtbar
			/***  Konstruktoren  ***/

			// Standardkonstruktor, alloziert neues Objekt
	Vektor2d()
	{
		// gute Idee! Vermeidet uninitialisierte Attribute.
		setze(0, 0);
	}

	// Initialisierungskonstruktor mit Attributwerten
	Vektor2d(double x, double y)
	{
		// kopiere Argumente ins Objekt
		setze(x, y);
	}

	/***  get-Methoden  ***/

	// gib x-Komponente aus
	// Das "const" macht das eigene Objekt konstant.
	// Bitte immer sofort darn denken, wenn die
	// Methode das eigene Objekt nicht verändert!
	double x() const
	{
		return _x;
	}

	// gib y-Komponente aus
	double y() const
	{
		return _y;
	}

	// berechne euklidische Norm des Objekts
	double norm() const
	{
		return sqrt(_x * _x + _y * _y);
	}

	/***  set-Methoden  ***/

	// weise Objekt von Koordinaten zu
	void setze(double x, double y)
	{
		_x = x;
		_y = y;
	}

	/***  Ausgabemethoden  ***/
/*
	// gib Objekt formatiert auf Datenstrom aus
	void gibAus(ostream& ostr) const
	{
		ostr << "( " << _x << ", " << _y << " )";	//bei klassenmethoden IMMER _x, _y benutzen!!
	}
*/
	/******************************************************************************************/
	/*
	REGEL: nutzung von ostream in ausgabemethode
	
	ostream == datentyp aller datenströme wie cout,cerr
	
	warum ostream& ostr? da mit referenz die werte/inhalt direkt von ostr ausgegeben wird OHNE
	das inhalt in eine variable kopiert/gespeichert wird DH 
	ostream& ==> direkte ausgabe ohne zwischenschritt! ABER ohne & zeigt compiler fehler an

	*/
	/******************************************************************************************/

	/***  Interaktionsmethoden  ***/

	// vergleiche Objekt mit Argument lexikografisch
	// Ergebnis:  -1 wenn Objekt < vek
	//             0 wenn Objekt = vek
	//             1 wenn Objekt > vek ist.
	// Hier nur eine Deklaration, weil die Definition
	// rtelativ lang ist und die Klasse an dieser Stelle
	// unübersichtlich machen würde. Die Definition wird
	// ausgelagert nach Vektor2d.cpp.
	int vergleiche (Vektor2d const& vek) const;

	// vertausche Inhalte von Objekt und vek
	void vertausche(Vektor2d& vek) const;

	int operator > (Vektor2d& vek) const;
	/***  Rechenmethoden  ***/

	// unäres Minus
	Vektor2d operator - () const	// gibt negatives zeichen an wert dran
	{
		return Vektor2d(-_x, -_y);
	}

	// addiere Objekt und vek zu neuem Objekt
	//Vektor2d addiere (Vektor2d const& vek) const
	 Vektor2d operator + (Vektor2d const& vek) const
	{
		/* alte Version mit Standardkonstruktor:
		Vektor2d summe ;
		summe.setze( _x + vek._x, _y + vek._y ) ;
		return summe ;
		*/
		// neue Version mit Init.-Konstruktor
		return Vektor2d(_x + vek._x, _y + vek._y);
	}

	// multipliziere Objekt und faktor zu neuem Objekt
	//Vektor2d multipliziere (double faktor) const	
	 Vektor2d operator * (double faktor) const
	{
		/* alte Version mit Standardkonstruktor:
		Vektor2d produkt ;
		produkt.setze( _x * faktor, _y * faktor ) ;
		return produkt ;
		*/
		// neue Version mit Init.-Konstruktor
		return Vektor2d(_x * faktor, _y * faktor);
	}
};  // class Vektor2d


	/***  globale Funktionen  ***/

	// Multiplikation mit vertauschten Parametern
	// Diese Funktion kann keine Methode der
	// Klasse Vektor2d sein, weil ihr erster
	// Parameter kein Vektor2d-Objekt ist!
	// Ihre Definition muss - wie immer - in
	// der Datei Vektor2d.cpp stehen.

Vektor2d operator * (double faktor,
	Vektor2d const& vek);

// gib vek formatiert auf ostr aus
ostream& operator << (ostream& ostr,
	Vektor2d const& vek);

//eingabe operator
istream& operator >> (istream& istr, Vektor2d& vek);