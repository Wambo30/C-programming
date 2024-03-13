#include <iostream>

class schatzFinden
{
	double _e1, _e2, _b, _faktor,_x,_y;

public:
	
	//konstruktoren


	// standardkonstruktor == setzt wert fest wenn man für objekt keine werte festlegt!
	schatzFinden()
	{

		setze(0, 0, 0);
	}

	//initialisierungskonstruktor == initialisiert und deklariert automatisch

	schatzFinden(double e1, double e2, double b)
	{
		setze(e1, e2, b);

	}

/********************************************************************************************************
REGEL: konstruktoren

- dienen allgemein zum erstellen eines objekts

1) standardkonstruktor, legt standardwerte fest falls ein objekt mit KEINEM wert initialisiert wurde
- enthält als datentyp die bearbeitende klasse
- runde klammern sind leer

bsp obda: 
schatzFinden()
{
	setze(0, 0, 0);	// setze methode
}

2)initialisierungskonstruktor , dient zum direkten initialisieren + deklarieren eines objekts
-enthält als datentyp die zu bearbeitende klasse
- in dunden klammern stehen primitive datentypen

bsp obda:

schatzFinden(double e1, double e2, double b)
{
	setze(e1, e2, b);
}
*********************************************************************************************************/



/*********************************************************************************************************
	REGEL: get methoden 
	
	1) lesen der werte aus variablen
	2) get methoden mit primitiven datentyp schreiben
	3) get methoden sind const immer da deren gelesenen werte nicht mehr verändert werden sollen
		--> bei get methoden ist das standard!!
	4)runden klammern bei get methoden sind immer LEER!
	5) ausgabe von _e1 variable also privater variable
	bsp obda:
	double e1() const
	{
		return _e1;
	}

*********************************************************************************************************/
//get methoden

	double e1() const
	{

		return _e1;
	}

	double e2() const
	{

		return _e2;
	}

	double b() const
	{

		return _b;
	}

	
    double rotLinks()const
	{

		return (-_y, -_x);
	}

/*********************************************************************************************************
	REGEL: set methoden

	1)zum initialisieren gedacht
	2) set methoden sind NIE const!
	3) in runden klammern stehen jene parameter die vom user eingegeben werden--> diese sind double
	syntax : void setze (double e1, double e2, double b) ..
	4) in methode selber beginnt zuweisung immer mit _e1 = e1 usw ....
	5) warum void? da man ja nix zurückgeben will als wert oder so. es soll nur was an die öffentliche 
	variable zugewiesen werden--> mehr nicht

	bsp obda:
	void setze (double e1, double e2, double b)
	{
		_e1 = e1;
		_e2 = e2;
		_b = b;
	}

*********************************************************************************************************/
//set methoden

	void setze (double e1, double e2, double b)
	{
		_e1 = e1;
		_e2 = e2;
		_b = b;

	}

// rechenmethoden
	schatzFinden operator - () const
	{
		return schatzFinden(-_y, -_x);

	}


/*
	schatzFinden operator -(schatzFinden const& Obj) const
	{

		return schatzFinden(_e1 - Obj._e1, _e2 - Obj._e2, _b - Obj._b); //initialisierungskonstruktor
	}
*/
	schatzFinden operator +(schatzFinden const& Obj) const
	{

		return schatzFinden(_e1 + Obj._e1, _e2 + Obj._e2, _b + Obj._b);//initialisierungskonstruktor
	}

	schatzFinden operator *(double faktor) const
	{

		return schatzFinden(_faktor * _e1, _faktor * _e2, _faktor * _b);//initialisierungskonstruktor
	}

	/*****************************************************************************************************
	REGEL: rechenmethoden add, subtr, multiplik schreiben 

	- rechenmethode hat folgende eigenschaften
	1) in der paramterliste gilt ( <KlassenName> const& <ObjektName> )
	2)man nutzt bei ausgabe des ergebnisses den initialisierungskonstruktor
	 bsp obda : return schatzFinden(_e1 + Obj._e1, _e2 + Obj._e2, _b + Obj._b);

	 --> man könnte natürlcih auch seperat mit der setze methode usw das machen
	 3) ALLE rechenmethoden haben const  am ende von parameterliste dh die ausgabewerte sind nicht 
	 mehr veränderbar!

	 -----------------------------------------------------------------------------------------------------
	 REGEL : rechenmethode faktor schreiben

	 1)parameterliste enthält folgendes (<PrimDatentyp> <NameVariable>) const
	 2) in methode selber nutzt man wieder den initialiserungskonstruktor ABER man nutzt kein objekt
	 da ja kein objekt vom user eingegeben wird dh man arbeitet direkt mit den variablen
	 return schatzFinden(_faktor * _e1, _faktor * _e2, _faktor * _b);

	****************************************************************************************************/

	//interaktionsmethode

	


	//ausgabemethoden
};
