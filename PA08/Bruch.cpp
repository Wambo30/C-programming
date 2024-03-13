#include "Bruch.h"
// Definitionen von Bruch.h


//static fkt
long long Bruch::ggt(long long m, long long n)
{
	while (n != 0)
	{
		long long h = m % n;
		m = n;
		n = h;
	}
	return m;//ausgabe ggt
}

long long Bruch::betrag(long long zahl)
{
	if (zahl < 0)
		return -zahl;
	return zahl;
}


//methode _formatiere()  mit folgenden eigenschaften
//1)nenner von bruch ist positiv also >0
//2)wenn bruch negativ --> zähler hat vorzeichen
//3)ist zähler == 0 dann nenner == 1
//4)zähler und nenner sind immer ausgekürzt

void Bruch::_formatiere()
{
	// Nenner ist null
	if ( _nenner == 0)
	{
		cerr << "Nenner ungleich 0 gefordert!" << endl;
		return;
	}

	//zu 1) und 2)
	if (_nenner < 0)
	{
		_nenner  = -_nenner;	// -1 * _nenner
		_zaehler = -_zaehler; // -1 *_zaehler
	}

	//zu 3)
	if (_zaehler == 0)
	{
		_nenner = 1;
		return;
	}

	//zu 4)
	long long teiler = ggt(betrag(_zaehler), _nenner);
	_zaehler = _zaehler / teiler; // abs() = Betragsfkt
	_nenner  = _nenner  / teiler;
}

/**** Rechenmethoden  ******/

//unäres minus
Bruch Bruch::operator - () const
{
	return Bruch( -_zaehler, _nenner);

}

//addiere bruch mit bruch
Bruch Bruch::operator + (Bruch const& ObjBr2) const
{
	Bruch ergebnis( _zaehler * ObjBr2._nenner + _nenner* ObjBr2._zaehler,
					_nenner * ObjBr2._nenner);	//bilden von gemeinsamen nenner
	
	ergebnis._formatiere(); // bruch wird gekürzt

	return ergebnis;
}

//subtrahiere bruch mit bruch
Bruch Bruch::operator -(Bruch const& ObjBr2) const
{
	Bruch ergebnis(_zaehler * ObjBr2._nenner - _nenner* ObjBr2._zaehler,
				   _nenner * ObjBr2._nenner);

	ergebnis._formatiere();// bruch wird gekürzt

	return ergebnis;
}

//multiplizieren bruch mit bruch
Bruch Bruch::operator *(Bruch const& ObjBr2) const 
{
	Bruch ergebnis(_zaehler * ObjBr2._zaehler,
					_nenner * ObjBr2._nenner);

	ergebnis._formatiere();// bruch wird gekürzt

	return ergebnis;
}

//dividiere bruch mit bruch
Bruch Bruch::operator /(Bruch const& ObjBr2) const
{
	Bruch kehrwert (ObjBr2._nenner, ObjBr2._zaehler);	// kehrwert gebildet


	return *this * kehrwert;
}