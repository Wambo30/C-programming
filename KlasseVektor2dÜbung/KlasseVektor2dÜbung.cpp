
#include "Vektor2d.h"


/* interaktionsmethoden*/

//vergleiche objekt mit argument lexikografisch
//ergebnis: -1 wenn objekt < vek
//			0 wenn ibjekt = vek
//			1 wenn objekt > vek ist

//schreibweise : Vektor2d::vergleiche == bedeutet die fkt vergleiche ist element
//der klasse vektor2d ==> das macht man mit dem doppelpunkt

int Vektor2d::vergleiche( Vektor2d const& vek)	// immer const& wenn es nur gelesen wird!!!
{
	if (_x < vek._x)
		return -1;
	if (_x > vek._x)
		return 1;
	if (_y < vek._y)
		return -1;
	if (_y < vek._y)
		return 1;
	return 0;


}

void Vektor2d::vertausche(Vektor2d& vek)
{
	double temp = _x;
	_x = vek.x;
	vek._x = temp;

	temp = y;
	_y = vek._y;
	vek._y = temp;

}

//addiere objekt

Vektor2d addiere(Vektor2d const& vek)
{
	Vektor2d summe;
	summe.setze(_x + vek._x, _y + vek._y);
	return summe;
}



Vektor2d multipliziere(double faktor)
{
	Vektor2d produkt;
	produkt.setze(_x + vek._x, _y + vek._y);
	return produkt;
}