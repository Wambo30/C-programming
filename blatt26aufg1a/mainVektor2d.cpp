#include <iostream>
#include "KlasseBlatt26aufg1a.h"	// hier steht die Klasse
using namespace std;


/**
* 16. + 23.04.18
* Ihr erstes objektorientiertes Programm.
*
* Hier in main() schreibt der Anwender und es soll höchste
* Übersicht über das Geschehen herrschen. Eine Linearkombination
* zweier Vektoren soll z.B. so aussehen:
*
*     Vektor2d u( 1,  1 ) ;			// u = ( 1,  1 )
*     Vektor2d v( 2, -1 ) ;			// v = ( 2, -1 )
*     Vektor2d w = 3 * u + 2 * v ;		// w = 3u + 2v
*     cout << "w = " << w << endl ;	// "w = ( 7, 1 )"
*
* Die technischen Details des Datentyps Vektor2d gehören in
* seinen Header, den der Klassendesigner schreibt.
*
* Wir müssen lernen, beim Programmieren zwischen beiden
* Rollen zu wechseln, ohne sie zu vermischen.
*/

int main()
{
	

	/***  das kann jede Klasse sofort  ***/
	/*
	// Deklaration und Definition
	Vektor2d vek1 ;

	// Dekl. und Def. mit Init. von gleicher Klasse
	Vektor2d vek2 = vek1 ;

	// Zuweisung von gleicher Klasse
	vek1 = vek2 ;

	/*********************************************************************************************************
	REGEL: zuweisung von variablen mit setze methode

	JEDE klasse kann sofot jenen code von oben:ABER nachteil hier: man kann weder werte lesen noch zugreifen 
	da PER definition jeder variable in einer klasse private ist
	==> kann man variable public machen? NEIN man muss dazu eine setze methode dafür schreiben, wo zuweisung
	von variable das erst ermöglicht

	SETZE METHODE:

	//set - Methode == dient zum Zuweisen von Werten an das Objekt
	// weise Objekt von Koordinaten zu
	void setze(double x, double y)
	{
	_x = x;
	_y = y;
	}
	/*
	sinn setze methode: wir brauchen UNBEDINGT die setze methode da wir sonst keine daten/werte einlesen
	bzw zuweisen können
	setze methode ==> zuweisen von werten zu einem objekt

	
	******************************************************************************************************/

	/***  Lesezugriff auf Attribute  ***/
	
	/*
	Vektor2d vek ;
	cout << "ausgabe vek.x : " <<vek.x() << " " << "ausgabe vek.y : " <<vek.y() << endl ;
	// AUSGABE: vek.x = 0 und vek.y= 0  warum? da man werte nur mit setze methode zuweist!
	
	cout << "|vek| = " << vek.norm() << endl ;
	//AUSGABE: |vek| = 0 warum? da den variablen des objektes vek noch keine werte zugewiesen
	//wurde !!
	*/
	
	/***  Schreibzugriff auf Attribute  ***/
	
	// Zuweisung
	/*
	Vektor2d vek1 ;
	vek1.setze( 4, -3 ) ;	// wegen setze(double x, double y) dadurch, vek1 == objekt mit 2 variablen x und y
	cout <<"ausgabe vek1.x : " <<vek1.x() << " " <<"ausgabe vek1.y : " <<vek1.y() << endl ;
	cout << "|vek1| = " << vek1.norm() << endl ;
	//DH methode setze weist nur wert zu und mehr nicht!

	/*
	// Initialisierung
	Vektor2d vek2 = vek1 ;	// initialisierung == zuweisung von einem objekt zum anderen
	cout << vek2.x() << " " << vek2.y() << endl ;
	//*/
	/***************************************************************************************************/
	/*	
	REGEL: zuweisung und initialisierung in klasse

	zuweisung == erfolgt durch setze methode also
	//set - Methode == dient zum Zuweisen von Werten an das Objekt
	// weise Objekt von Koordinaten zu
	void setze(double x, double y)
	{
		_x = x;
		_y = y;
	}

	Im main:

	Vektor2d vek1 ;	//variablen x und y gehören zum objekt
	vek1.setze( 4, -3 ) ;	// zuweisung von x und y variable zu einem wert jeweils was NUR über 
	//setze methode erfolgen kann
	cout <<"ausgabe vek1.x : " <<vek1.x() << " " <<"ausgabe vek1.y : " <<vek1.y() << endl ;


	INITIALISIERUNG:
	- erfolgt nur über zuweisung von zwei objekten wo die variablen eines objekts bereits werten zugewiesen
	  wurde

	  bsp: In main
	  // Initialisierung
	  Vektor2d vek2 = vek1 ;	// initialisierung == zuweisung von einem objekt zum anderen
	  //variablen von objekt vek1 wurden zuvor schon werten zugewiesen

	  cout << vek2.x() << " " << vek2.y() << endl ;

	*/
	/***************************************************************************************************/


	/***  formatierte Ausgabe auf Datenstrom  ***/
	

	/*
	Vektor2d vek ;
	vek.setze( 4, -3 ) ;
	
	double summe = vek.x() + vek.y();
	cout << "ausgabe summe: " << summe << endl;
	
	// Ausgabe auf cout
	vek.gibAus( cout ) ;
	cout <<"ausgabe vek : " << vek << endl ;
	*/
	//ausgabe: gibt (4,-3) aus da gibAus() methode für objekt so definiert

/*********************************************************************************************************/
/*
REGEL: ausgabemethode bzgl objekt

- ausgabemethode übernimmt das format bzw signatur von der setze methode 
dh da setze (double x, double y) so definiert ist wird in ausgabe durch ausgabemethode zb (4, -3) bei x=4 , y=-3
ausgegeben

// gib Objekt formatiert auf Datenstrom aus
void gibAus(ostream& ostr) const
{
ostr << "( " << _x << ", " << _y << " )";
}

==> warum? da ostream& der allgemeine datentyp von den datenströmen cerr und cout ist!

*/
/*********************************************************************************************************/
	/***  Interaktion zwischen Objekten: sortieren  ***/
/*
	//STARK KOMMENTIERT!!
	// deklariere und definiere Vektoren
	int const NVEK = 4 ;
	Vektor2d vek[ NVEK ] ;	//NVEK == länge von einträge ; vek == objekt dessen einträge vektoren sind wobei jeder 
	//eintrag eine x und y variale hat UND AUCH vek == array !!

	// weise Vektoren zu
	vek[ 0 ].setze( -1, 5 ) ;	// 0 ter eintrag mit vektor x= -1 und y=5
	vek[ 1 ].setze(  2, 0 ) ;	// 1. eintrag mit vektor x=2 und y=0
	vek[ 2 ].setze( -1, 2 ) ;
	vek[ 3 ].setze( -3, 4 ) ;

	cout << "ausgabe vek[0] :" << vek[0] << endl;
	cout << "ausgabe vek[1] :" << vek[1] << endl;
	cout << "ausgabe vek[2] :" << vek[2] << endl;
	cout << "ausgabe vek[3] :" << vek[3] << endl;
	cout << "ausgabe vek[0].x() :" << vek[0].x() <<"ausgabe vek[0].y() :" << vek[0].y() << endl;
	cout << "ausgabe vek[1].x() :" << vek[1].x() << "ausgabe vek[1].y() :" << vek[1].y() << endl;
	//ausgabe: erwartet wies oben steht

	cout << "ausgabe vergleich vek[0] und vek[1] : " << vek[0].vergleiche(vek[1]) << endl;
	//ausgabe: -1 da vek[1] == objekt und vek[0] == argument an stelle 0 von objekt;
	//DH vek[<ArgumentAnEinerStelle>].vergleiche(vek[<ObjektAnStelle>) OBWOHL beides argumente sind
	//aber beim einsetzen in vergleichsmethode wird jener eintrag insgesamt NUR als "objekt" bezeichnet
	//was SEHR verwirrend ist!!!
	
	cout << "ausgabe vergleich vek[2] und vek[3] : " << vek[2].vergleiche(vek[3]) << endl;
	//ausgabe: 1 da vek[2] == objekt und vek[3] == argument an stelle 3 obwohl BEIDES argumente darstellen!
	//warum ist vek[2]>vek[3]?? da |vek[2]| > |vek[3]| gilt!!


	// sortiere Vektoren lexikografisch
	for ( int i = 0 ;  i < NVEK ;  ++i )	// durchgehen von einträge der "argumenten"
		for ( int j = i + 1 ;  j < NVEK ;  ++j )	//durchgehen von einträge von "Objekte" (=auch argumente)
			if ( 1 == vek[ i ].vergleiche( vek[ j ] ) )
				vek[ i ].vertausche( vek[ j ] ) ;
	// wenn 1 bei einer komponente festgestellt wurde ==> dann komplettes paar wird an diese stelle kopiert
	cout <<"ausgabe vek[0]" << vek[0] << endl;
	cout << "ausgabe vek[1]" << vek[1] << endl;
	//cout << "ausgabe vek[2]" << vek[2] << endl;
	//cout << "ausgabe vek[3]" << vek[3] << endl;
	

	// gebe Vektoren sortiert aus
	for ( int i = 0 ;  i < NVEK ;  ++i )
	{
	vek[ i ].gibAus( cout ) ;		// vek ist array + objekt wo paare die einträge des arrays sind
	cout << "ausgabe sortierter vektoren: "<< endl ;
	}
	
*/


/***  mit Vektoren rechnen  ***/
/*
	// Zwischenziel: w = 3u + 2v
	Vektor2d u, v ;	// u und v == objekte jeweils
	u.setze( 1,  1 ) ;	//zuweisung über set methode SETZE ==> 'ist deklaration mit einem wert ' dh noch nicht initialisiert!
	v.setze( 2, -1 ) ;

	// berechne Linearkombination
	Vektor2d x = u.multipliziere( 3 ) ;	//objekt u also u(x,y) wird mit 3 komplett multipliziert--->skaklare multiplik
	Vektor2d y = v.multipliziere( 2 ) ;
	Vektor2d w = x.addiere( y ) ;

	// gib Ergebnis aus
	//cout <<"ausgabe objekt u mit (1,1) nach skl.multiplk mit 3 : " <<"3 * " << endl;
	x.gibAus( cout ) ;	//u.gibAus(cout)
	//cout << "ausgabe objekt v mit(2, -1) nach skl.multiplk mit 2 : "<< " + 2 * "<<endl ;
	y.gibAus( cout ) ;	//v.gibAus(cout) wenn man u alleine OHNE skal multiplik. sehen will	
	cout << " = " ;
	w.gibAus( cout ) ;
	cout << endl ;
*/

/*********************************************************************************************************************
REGEL: allgemeines arbeiten mit objekten

1) definieren eines objektes was durch deklaration mit klasssendatentyp erfolgt
bsp: Vektor2d u; oder Vektor2d u,v;

2)set methode SETZE nutzen, um wert dem objekt zuzuweisen.ist aber KEINE initialisierung sondern  NUR zuweisung!+
==> da durch setze methode IMMER ZWEI komponenten für ein Objekt festgelegt werden müssen, wird immer damit
gearbeitet

bsp: v.setze(1,3); //zuweisung von x=1 , y=3 zu objekt v

3)initialisierung erfolgt ERST durch zuweisung zweier objekte die bereits zuvor schon einem wert jeweils zugewiesen
wurden

bsp: Vektor2d u = v;

**********************************************************************************************************************/
	
/***  Initialisierungskonstruktor  ***/
/*
	// bisher muessen wir Dekl./Def. und Initialisierung trennen:
	Vektor2d vek1 ;
	cout << "vorher:  vek1 = " ;
	vek1.gibAus( cout ) ;         // Sicherheitslücke!
	cout << endl ;

	vek1.setze( 2, 5 ) ;
	cout << "nachher: vek1 = " ;
	vek1.gibAus( cout ) ;
	cout << endl ;
	//*
	// deklarieren und initialisieren in einem
	// macht ein Konstruktor zur Initialisierung:
	Vektor2d vek2( 2, 5 ) ;
	cout << "vek2 = " ;
	vek2.gibAus( cout ) ;
	cout << endl << endl ;
*/
/*********************************************************************************************************************
REGEL:initialisierungskonstruktur

// bisher muessen wir Dekl./Def. und Initialisierung trennen:
Vektor2d vek1 ;
cout << "vorher:  vek1 = " ;	//vorher text außerhalb von ausgabemethode schreiben, da ausgabemeth. das nicht macht!
vek1.gibAus( cout ) ;         // Sicherheitslücke!
cout << endl ;

warum sicherheitslücke?da man zwischen objektdeklaration und initialisierung IMMERNOCH auf das objekt zuweisen kann!
daher definiert man einen initialisierungskonstruktor!!

vek1.setze( 2, 5 ) ;
cout << "nachher: vek1 = " ;	//vorher text außerhalb von ausgabemethode schreiben, da ausgabemeth. das nicht macht!
vek1.gibAus( cout ) ;
cout << endl ;

// deklarieren und initialisieren in einem
// macht ein Konstruktor zur Initialisierung:
Vektor2d vek2( 2, 5 ) ;	//DIREKT bei objektdefinition wert x=2, y=5 dem objekt zuweisen!!!		
cout << "vek2 = " ;	
vek2.gibAus( cout ) ;
cout << endl << endl ;

ABER man hat im header zuvor den initialisierungskonstruktur definiert

// Initialisierungskonstruktor mit Attributwerten
Vektor2d(double x, double y)
{
// kopiere Argumente ins Objekt
setze(x, y);
}


**********************************************************************************************************************/
	/***  konstante Objekte  ***/
/*
	// jetzt möglich: konstantes Objekt
	Vektor2d const URSPRUNG( 0, 0 ) ;	// da wir initialisierungskonstruktur definiert haben

	// was ist das Problem?
	cout << "URSPRUNG = " ;
	URSPRUNG.gibAus( cout ) ;
	cout << endl ;
	//*
	// rechne mit konstantem Objekt
	Vektor2d vek1( 2, 5 ) ;	// mit initialisierungskonstruktor objekt direkt initialisiert
	Vektor2d vek2 = vek1.addiere( URSPRUNG ) ;
	cout << "vek1 + URSPRUNG = " ;
	vek2.gibAus( cout ) ;
	cout << endl << endl ;

	// was passiert hier?
	Vektor2d vek3 = URSPRUNG.addiere( vek1 ) ;	//URSPRUNG objekt = (0,0) ; 
	cout << "URSPRUNG + vek1 = " ;
	vek3.gibAus( cout ) ;
	cout << endl << endl ;
*/
	/***********************************************************************************************************
	REGEL: konstante objekte

	legt initialisiertes und konstantes objekt fest mit initialisierungskonstruktor

	bsp obda:
	Vektor2d const URSPRUNG( 0, 0 ) ;	// da wir initialisierungskonstruktur definiert haben
	
	- mit diesem kann man dann rechnen
	bsp obda:

	Vektor2d vek1( 2, 5 ) ;	// mit initialisierungskonstruktor objekt direkt initialisiert
	Vektor2d vek2 = vek1.addiere( URSPRUNG ) ;
	cout << "vek1 + URSPRUNG = " ;
	vek2.gibAus( cout ) ;

	ausgabe: (2,5)


	*************************************************************************************************************/

	/***  Standardkonstruktor  ***/
/*	
	// Was passiert hier plötzlich?
	Vektor2d vek ;

	cout << "vek = " ;
	vek.gibAus( cout ) ;
	cout << endl << endl ; // ausgabe : (0,0)
	//warum?da wir per standardkonstruktor einen standardwert festgelegt hatten
*/
/******************************************************************************************************
REGEL: standardkonstruktor

-ist immer von compiler gegeben auch wenn man ihn nicht selbst definiert
---> ansonsten selber setzen
syntax: klassenname

bsp obda:
class klassenname
{

	// Standardkonstruktor, alloziert neues Objekt
	Vektor2d()
	{
		// gute Idee! Vermeidet uninitialisierte Attribute.
		setze(0, 0);
	}

}

- zur initialisierung eines arrays also dessen länge --> nutzung standardkonstruktor

bsp obda:

Vektor2d basis[ 5 ] ;
cout << "ausgabe basis[5]: " << basis << endl;


*************************************************************************************************/

/*
	// Initialisierung eines Arrays braucht
	// den Standardkonstruktor
	Vektor2d basis[ 2 ] ;
	// dh 

	Vektor2d basis = { Vektor2d (3,4) , Vektor2d (2,1)  };
	cout << "ausgabe basis[5]: " << basis << endl;
	//ausgabe: gibt speicher adresse von array basis aus

*/
	/***  Rechenoperatoren  ***/
/*	
	// Addition mathematisch geschrieben
	Vektor2d vek1( 3, -4 ) ;	// initialisierung von objekt vek1 mit werten x=3,y=-4 --> nutzung initialisierungskonstr.
	Vektor2d vek2( 1,  2 ) ;

	// neue Schreibweise mit Operator '+'
	Vektor2d vek3 = vek1 + vek2 ;
	//Vektor2d vek3 = vek1.operator + ( vek2 ) ;

	cout << "vek3 = " ;
	vek3.gibAus( cout ) ;
	cout << endl ;
	//*
	// Multiplikation mit Skalar
	Vektor2d const& vek4 = vek1 * -1 ;

	cout << "vek4 = " ;
	vek4.gibAus( cout ) ;
	cout << endl ;
	//*
	// Multiplikation in normaler Schreibweise
	// hier wird ein globaler Operator '*' benötigt!
	Vektor2d const& vek5 = -1 * vek1 ;

	cout << "vek5 = " ;
	vek5.gibAus( cout ) ;
	cout << endl ;

*/
	/**********************************************************************************************************
	REGEL: sinn globale fkt und unterschied zur methode

	-methode == fkt bzgl eines objektes welches zuvor im main initialisiert wurde
	- (globale) fkt == fkt die man nutzt um objekt mit einer konkreten zahl zusammen zu rechnen
	
	bsp obda:
	main:
		// Multiplikation in normaler Schreibweise
		// hier wird ein globaler Operator '*' benötigt!
		Vektor2d const& vek5 = -1 * vek1 ;	//objekt vek1 mit zahl -1 mal genommen

	header:
	class Vektor2d
	{
		...
	};  // class Vektor2d


	//  globale Funktionen  

	// Multiplikation mit vertauschten Parametern Diese Funktion kann keine Methode der Klasse Vektor2d sein, 
	//weil ihr erster Parameter kein Vektor2d-Objekt ist! Ihre Definition muss - wie immer - in
	// der Implementationsdatei Vektor2d.cpp stehen.

	Vektor2d operator * (double faktor,Vektor2d const& vek);
	//hier sieht man das man eine double zahl mit einem objekt aus klasse vektor2d berechnen will!
	// UND man nutzt NICHT :: da globale fkten nicht zur klasse gehören

	==> dh globale fkt stehen im header aber außerhalb der klasse, da sie nicht für dessen objekte nicht
	direkt genutzt werden ABER man kann sie für objekte auch nutzen
	für normale variablen sowieso
	
	
	***********************************************************************************************************/


	/*
	// unäres Minus
	Vektor2d vek1(2,3);	// initialisierung durch initialisierungskonstruktor
	Vektor2d vek6 = -vek1 ;

	cout << "vek6 = " ;
	vek6.gibAus( cout ) ;
	cout << endl ;
	*/

/*****************************************************************************************************************
REGEL: unäres minus

- legt negatives vorzeichen an einem wert fest--> muss immer vorher in klasse definiert werden

bsp obda:
header:

class vektor2d
{
	public:
	// unäres Minus
	Vektor2d operator - () const	// gibt negatives zeichen an wert dran
	{
		return Vektor2d(-_x, -_y);
	}
	...
};
==> sehr wichtig für negative zeichen da sonst keine negative zahlen darstellbar

*****************************************************************************************************************/


	/***  Ein- und Ausgabeoperatoren  ***/
/*
	// Ausgabe in einer cout-Kette
	Vektor2d vek7( -5, 3 ) ;

	// hier wird ein globaler Operator '<<' benötigt!
	cout << vek7;
	cout <<"vek7 = "  << vek7 << endl ;
*/

/*********************************************************************************************************************
REGEL: unterschied zwischen ausgabemethode und globale ausgabefkt


bsp obda bzgl ausgabemethode:
main:

Vektor2d vek3 (2, 5);
cout << "vek3 = " ;
vek3.gibAus( cout ) ;
cout << endl ;

header:

// Ausgabemethoden  

// gib Objekt formatiert auf Datenstrom aus
	void gibAus(ostream& ostr) const
	{
		ostr << "( " << _x << ", " << _y << " )";	//bei klassenmethoden IMMER _x, _y benutzen!!
	}

==> dh hier haben wir eine methode für objekt wo man ausgibt

bsp obda bzgl globale ausgabefkt:
main:

// hier wird ein globaler Operator '<<' benötigt!
cout <<"vek7 = "  << vek7 << endl ;

header:
ostream& operator << (ostream& ostr, Vektor2d const& vek)
{
	return ostr << "( " << vek.x() << ", " << vek.y() << " )" ;
}

==> die globale fkt == gilt für objekte UND NICHT objekte gleichzeitig
KEINE def einer globalen ausgabe fkt --> keine ausgabe allgemein möglich!

Man MUSS also zumindest eine globale ausgabefkt schreiben!

*********************************************************************************************************************/


	/***  Ziel erreicht!  ***/
	//*
	Vektor2d u( 1,  1 ) ;			// u = ( 1,  1 ) da mit initialisierungskonstruktur initialisiert wurde
	Vektor2d v( 2, -1 ) ;			// v = ( 2, -1 )
	Vektor2d w = 3 * u + 2 * v ;	// w = 3u + 2v , addieren von zwei objekten

	cout << "w = " << w << endl ;	// "w = ( 7, 1 )"
	//*/

//Vektor2d _x;
//int _x = 10;
//cout << "ausgabe von _x :" << endl;

	/****************************************************************************************************************/
	
	//Testbereich für codes um regeln zu bestimmen
	
	
	Vektor2d z(3, 4);
	cout << "gib z aus: " << z << endl;
	//cin >> z;
	
	Vektor2d ui;
	cout << "gib ui aus: " << ui << endl;
	
	
	/****************************************************************************************************************/






	cout << endl;
	return 0;

}  // main()


