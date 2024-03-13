// Ausgabe:
//	Programm 1 2 3
//	x^3 - 6x^2 + 11x - 6

#include <iostream>
#include <cstdio>
using namespace std;

int const ENDE = -1 ;

int laenge( double const p[] )
{
	int pLaenge = 0;
	while ( p[ pLaenge ] != ENDE )
		pLaenge++ ;

	return pLaenge;
}


double* multipliziere( double x0, double const p[] )
{
 	int pLaenge = laenge( p ) + 1 ;
	double* poly = new double[ pLaenge + 1 ];

	for ( int i = 0; i < pLaenge - 1 ; i++ )
	{
		poly[ i ] = p[ i ] * ( -x0 ) ;
		poly[ i + 1 ] = p[ i ] ;
	}


}


double* zuPolynom ( double const nullstellen[] , int n )
{
	double* p = nullptr;
	double* p0 = new double[ 1 ];
	p0[0] = ENDE;

	for ( int i = 0 ; i < n ; i++ ) 
	{
		p = multipliziere( nullstellen[ i ] ,  p0 );
		delete
	}
}


int main ( int narg , char* argv[] )
{
	int nNullstellen = narg - 1 ;
	double* nullstellen = new double[ nNullstellen ] ;

	for ( int i = 0 ; i < nNullstellen ; i++)
		nullstellen[ i ] = atof( argv[ i + 1 ] ) ;

	double* polynom = zuPolynom( nullstellen , nNullstellen ) ;
}
