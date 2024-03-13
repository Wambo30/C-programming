
#include "KlasseBlatt26aufg1a.h"

using namespace std;




	Vektor2d vek;	//deklaration und definition--> klassentyp = Vektor2d
	//--> dh bei klassentypen gilt : deklaration nur OHNE initialiserung möglich!
	
	
	/*
	vek.setze(1,1);	//initialisierung erst bei methoden aufruf warum? da per default alle variablen einer klasse
	//vom anwender nicht zugreifbar sind! dh man kann sie deswegen nicht initialisieren, daher muss man methode
	//wie setze() schreiben um initialisierung zu ermöglichen



	/***  Interaktionsmethoden  ***/

	// vergleiche Objekt mit Argument lexikografisch
	// Ergebnis:  -1 wenn Objekt < vek
	//             0 wenn Objekt = vek
	//             1 wenn Objekt > vek ist.
	int Vektor2d::vergleiche(Vektor2d const& vek) const
	{		// "Vektor2d::" zeigt Zugehörigkeit zur Klasse an
			// Algorithmus für lexikografischen Vergleich
		if (_x < vek._x)	//vek == objekt ; vek._x == variable x bzgl des objektes vek
			return -1;
		if (_x > vek._x)
			return  1;
		if (_y < vek._y)
			return -1;
		if (_y > vek._y)
			return  1;
		return 0;

	}  // Vektor2d::vergleiche()
/*******************************************************************************************************************
REGEL: verständnis vergleiche methode

-man geht hier alle komponenten durch wenn man dann ein 1 was wir in main geschrieben hatten finden--> dann wird
kompletter vektor an diese eintragstelle vertauscht

1 = vek[ 0 ].vergleiche( vek[ 1 ] )

vek[0] == (-1,5) == argument , vek[1] == (2,0) == objekt

-x < vek._x  <==> -1 < 2 also ausgabe ==> -1
_y > vek._y <==> 5 > 0 also ausgabe ==> 1

*********************************************************************************************************************/
	int Vektor2d::operator > (Vektor2d& vek) const
	{
		/* --> das ist meine lösung
		if (_x < vek._x && _y < vek._y)
			return false;
		if (_x > vek._x || _y > vek._y)
			return true;
		*/
		return _x > vek._x || (_x == vek._x  &&  _y > vek._y);
	}
/********************************************************************************************************************
REGEL: lexikografisches größenverhältnis




********************************************************************************************************************/



/********************************************************************************************************************
REGEL: nutzen von :: bei implementationsdatei

- man hat im header die deklaration der fkt und will nun in implemationsdatei die gesamte fkt schreiben
--> dazu :: notwendig

syntax: <primDatentypOderVoid> <KlassenName>::<NameFkt> (<KlassenName> <NameVariable>,...)

--> in paramterliste muss MINDESTENS ein paramter als Datentyp die bearbeitende KLASSE haben, der rest
kann primitiven datentyp haben

bsp obda:1)
int Vektor2d::operator > (Vektor2d& vek) const
{

}

2)
void Vektor2d::vertausche(Vektor2d& vek) const
{

}

==> es darf KEIN LEERZEICHEN zwischen <KlassenName>::<NameFkt> sein--> sonst fehlermeldung!!

*********************************************************************************************************************/

/*

	   // vertausche Inhalte von Objekt und vek
	void Vektor2d::vertausche(Vektor2d& vek) const
	{
		double temp = _x;	//bsp1 also _x=-1  zwischenvariable da sonst vertauschen nicht möglich ist bsp 
		_x = vek._x;
		vek._x = temp;

		temp = _y;
		_y = vek._y;
		vek._y = temp;

	}  // Vektor2d::vertausche()
*/
/****************************************************************************************************************

REGEL: verständnis der vertausche methode

- OHNE zwischenvariable ==> KEIN verstauschen möglich!!

betrachtung bsp1: vek[2] == (-1,2) == argument, vek[3] == (-3,4) == objekt
double temp = _x;	//bsp1 also _x=-1  zwischenvariable da sonst vertauschen nicht möglich ist bsp
_x = vek._x;		//vek._x = -3 wird _x zugewiesen also _x=-3
vek._x = temp;		//da temp=-1 gilt vek._x = -1

temp = _y;	//von argument also temp= 2
_y = vek._y;	//_y = 4
vek._y = temp;	//vek._y = 2

==> somit haben wir die einträge der vektoren komplett vertrauscht! es gilt somit: vek[2] (-3,4) und vek[3]=(-1,2)
 dh es wird einfach die eintragsstelle im array durch anderen vektoren vertauscht

****************************************************************************************************************/
	


	   /***  globale Funktionen  ***/

	   // Multiplikation mit vertauschten Parametern
	   // Diese Funktion kann keine Methode der
	   // Klasse Vektor2d sein, weil ihr erster
	   // Parameter kein Vektor2d-Objekt ist!

	Vektor2d operator * (double faktor,
		Vektor2d const& vek)
	{
		// führe zurück auf Methode in der Klasse
		return vek * faktor;
	}
//*/
	// gib vek formatiert auf ostr aus
	///*
	ostream& operator << (ostream& ostr, Vektor2d const& vek)
	{
		// 1. Möglichkeit: führe zurück auf Methode
		//vek.gibAus(ostr);
		//return ostr;

		// 2. Möglichkeit: spare Methode, schreibe
		// die Ausgabesemantik direkt hierhin
		return ostr << "( " << vek.x() << ", " << vek.y() << " )" ;
		
	}
	//*/
	istream& operator >> (istream& istr, Vektor2d& vek)
	{
		double x, y;
		istr >> x >> y;
		vek.setze(x, y);
		return istr;
		
	}
	
/*****************************************************************************************************
REGEL: ausgabemethode und eingabemethode allgemein

- man beide methoden jeweils global definieren oder eben in der klasse
-folgende syntax gilt hierbei:

-----------------------------------------------------------------------------------------------------
syntax: ausgabefkt bzw -methode

im header:
ostream& operator << (ostream& ostr, <KlassenName>& <ObjektName>);

in implementationsdatei:

ostream& operator << (ostream& ostr, <KlassenName>& <ObjektName>)
{
	return ostr << "( " << vek.x() << ", " << vek.y() << " )" ;
}

==> ostream == datentyp für ausgaben allgemein,  ostr== name der variable mit datentyp ostream
- zudem :: ist nicht nötig da es eine globale fkt in dem fall darstellt--> sonst wäre :: nötig
- haben operator mit << eingeführt für ausgabe

----------------------------------------------------------------------------------------------------
syntax: eingabefkt bzw. -methode

im header:
istream& operator >> (istream& istr, <KlassenName>& <ObjektName>);

in implementationsdatei:

istream& operator >> (istream& istr, <KlassenName>& <ObjektName>)
{
		double x, y;
		istr >> x >> y;
		vek.setze(x, y);
		return istr;
}

bsp obda:
in main:

Vektor2d z(2,5);	// mit initialisierungskonstruktor initialisiert
cout << "gib z aus : "<< z << endl;

==> dh man bruacht TROTZDEM cout als schlüsselwort um ausgabefkt nutzen zu können! man kommt nicht drum
herum ABER OHNE definition der ausgabefkt mit << würde es zwar kompilieren aber nix ausgeben können!!


**********************************************************************************************************/