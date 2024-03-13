/*
PA08 Prof Oellrich

Name: Wahid Far, Okhtay 
Mtklnr.: 870 485

Name: Tokg�z, Ekrem
Mtklnr.: 841 530

*/


#include <iostream>       // f�r ostream

using namespace std;



/**
* Klasse f�r Br�che als Quotienten ganzer Zahlen
*
* Datenformat:
*		- der Nenner ist immer positiv
*		- bei Z�hler == 0 ist Nenner == 1
*		- Z�hler und Nenner sind immer ausgek�rzt
*/

class Bruch
{
	/***  private Elemente ***/

	// Z�hler und Nenner des Objekts
	long long _zaehler, _nenner;

	// stelle Datenformat des Objekts her
	void _formatiere();

public:
	//static Funktionen

	static long long ggt(long long m, long long n);
	static long long betrag(long long zahl);


	/***  Konstruktoren  ***/

	//initialisserungskonstruktur damit z�hler und nenner gesetzt werden
	Bruch(long long zaehler, long long nenner)
	{
		setze(zaehler, nenner);
		_formatiere();
	}

	//Standardkonstruktor, vermeidet uninitialiserte br�che
	Bruch()
	{
		setze(0, 1);	// wenn zaehler ==0 dann nenner == 1
		
	}
	
	//Umwandlungskonstruktor, festlegen das eine zahl alleine den nenner 1 hat
	Bruch (long long m)
	{
		setze(m, 1);
	}

	/**** Get Methoden  ******/
	
	long long zaehler() const
	{
		return _zaehler;
	}

	long long nenner() const
	{
		return _nenner;
	}
	
	/**** Set Methoden  ******/

	void setze(long long zaehler, long long nenner)
	{
		_zaehler = zaehler;
		_nenner = nenner;
	}


	
	/***  Interaktionsmethoden  ***/

	//vergleich ob objekt kleiner ist
	bool operator < (Bruch const& ObjBr2) const
	{
		if (_zaehler*ObjBr2._nenner < ObjBr2._zaehler *_nenner)
			return true;
		return false;
	}

	//vergleich ob objekt kleiner oder gleich ist
	bool operator <= (Bruch const& ObjBr2) const
	{
		if ( ( _zaehler*ObjBr2._nenner < ObjBr2._zaehler *_nenner )  ||
			 ( _zaehler == ObjBr2._zaehler && _nenner == ObjBr2._nenner ) )
			return true;
		return false;
	}

	//vergleich ob objekt gr��er oder gleich ist
	bool operator >= (Bruch const& ObjBr2) const
	{
		if ( ( _zaehler*ObjBr2._nenner > ObjBr2._zaehler *_nenner ) ||
			 ( _zaehler == ObjBr2._zaehler && _nenner == ObjBr2._nenner ) )
			return true;
		return false;
	}
	
	//vergleich ob objekt gleich ist
	bool operator == (Bruch const& ObjBr2) const
	{
		if (_zaehler == ObjBr2._zaehler && _nenner == ObjBr2._nenner)
			return true;
		return false;
	}

	//vergleich ob objekt ungleich ist
	bool operator != (Bruch const& ObjBr2) const
	{
		if (_zaehler != ObjBr2._zaehler || _nenner != ObjBr2._nenner)
			return true;
		return false;
	}

	/***  Rechenmethoden  ***/

	//un�res minus
	Bruch operator - () const;

	//addiere bruch mit bruch
	Bruch operator + (Bruch const& ObjBr2) const;

	//subtrahiere bruch mit bruch
	Bruch operator - (Bruch const& ObjBr2) const;

	//multiplizieren bruch mit bruch
	Bruch operator * (Bruch const& ObjBr2) const;
	
	//dividiere bruch mit bruch
	Bruch operator / (Bruch const& ObjBr2) const;
	

	/***  Ausgabe auf Datenstrom  ***/

	friend ostream& operator << (ostream& ostr, Bruch const& ObjBr)
	{
		if (ObjBr._nenner == 1)
			return ostr << ObjBr._zaehler;

		return ostr << ObjBr._zaehler << "/" << ObjBr._nenner;
	}

} ;  // class Bruch
