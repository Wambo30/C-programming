/**
 * Prog1b WS2017/18
 * 6. Projekt: natürliche Zahlen beliebiger Länge
 */

#include <iostream>
#include "natuerlich.h"
using namespace std;

// Ende-Zeichen für Ziffernfolge im natuerlich-Format
int const ENDE= -1 ;

// max. Anzahl Ziffern in der Textausgabe (Annahme!)
int const MAX_TEXT= 10000 ;

// Datenformat: natürliche Zahl als Array ihrer Dezimalziffern,
// abgeschlossen mit ENDE.


/***  Level 1  ***/


// gib die Anzahl signifikanter Ziffern von zahl zurück
static int laenge ( int const zahl[] )
{
	int laengeZahl = 0 ;
	while ( zahl[laengeZahl] != ENDE )
		++laengeZahl;

	return laengeZahl;  // gib Anzahl zurück
}

// umwandlung von Text in neue dynamische natuerliche Zahl 
int* zuZahl ( char const text[] )
{

	// bestimme Länge der Zeichenkette
	int laengeText = 0;
	while ( text[ laengeText ] != '\0' )
	{
		
		if ( text[ laengeText ] < '0' || '9' < text[ laengeText ] ) //  enthält die Zeichenkette einen Buchstaben?
			break;					//wenn ja, break
		++laengeText;			
	}

	// text in zahl umwandeln
	int* zahl = new int[ laengeText + 1 ];	// Umwandlung von char-Array zu int-Array
	for ( int i = 0 ; i < laengeText ; ++i )
		zahl[ laengeText - i - 1 ] = text[ i ] - '0';	// Umwandlung von char zu int mithilfe von ASCII Code
	zahl[ laengeText ] = ENDE ;

	return zahl ;  // gib zahl zurück
}  //ENDE zuZahl()


// Umwandlung von Zahl in Text
char const* zuText ( int const zahl[] )
{
	static char text[MAX_TEXT] ;	
	for (int i = 0; i < MAX_TEXT; i++)
		text[i] = '\0';  // mit '\0' initialisieren
	
	int zahlLaenge = laenge( zahl ) ; // Aufruf Laenge-Funktion 
	for (int i = 0; i < zahlLaenge; ++i) 
		text[i] = zahl[ zahlLaenge - i - 1 ] + '0';	//Umwandlung von int zu char mithilfe von ASCII Code

	return text ; // Rückgabe Text
}  //ENDE zuText()


/***  Level 2  ***/

//Fkt addiere()
// addiere zahl1 + zahl2 zu einer dynamischen neuen natuerlich-Zahl
int* addiere ( int const zahl1[], int const zahl2[] )
{
	int laengeZahl1 = laenge( zahl1 ) ;
	int laengeZahl2 = laenge( zahl2 ) ;
	int ergebnisLaenge = 0;

	if( laengeZahl1 >= laengeZahl2 ) //  Zahlenlänge von Zahl1 und Zahl2 vergleichen
		ergebnisLaenge = laengeZahl1 + 1 ;  // Ergebnislänge + 1 wegen Übertrag
	else 
		ergebnisLaenge = laengeZahl2 + 1 ;  // Ergebnislänge + 1 wegen Übertrag 

	// alloziierung von neuen Speicher für Ergebnis
	int* endErgebnis = new int[ ergebnisLaenge + 1]; // +1 wegen ENDE-Symbol
	int i = 0;
	int index = 0;
	int uebertrag = 0;

	while (( zahl1[ i ] != ENDE ) && ( zahl2[ i ] != ENDE )) 
	{
		index = zahl1[ i ] + zahl2[ i ] + uebertrag;
		endErgebnis[i] = index % 10;

		if (index > 9)
			uebertrag = 1;
		else
			uebertrag = 0;
		i++;
	}

	// falls Ende von zahl1 erreicht wurde
	if (zahl1[ i ] == ENDE)
	{
		while (zahl2[i] != ENDE)
		{
			index = zahl2[ i ] + uebertrag;
			endErgebnis[i] = index % 10;

			if (index > 9)
				uebertrag = 1;
			else
				uebertrag = 0;

			i++;
		}
		if (uebertrag == 1)
		{
			endErgebnis[ i ] = uebertrag;
			i++;
		}
		
		endErgebnis[i] = ENDE;	// Endstelle von Ergebnis 
	}

	// falls Ende von Zahl2 erreicht wurde
	else
	{
		while (zahl1[ i ] != ENDE)
		{
			index = zahl1[ i ] + uebertrag;
			endErgebnis[i] = index % 10;

			if (index > 9)
				uebertrag = 1;
			else
				uebertrag = 0;

			i++;
		}
		if (uebertrag == 1)
		{
			endErgebnis[i] = uebertrag;
			i++;
		}
		endErgebnis[i] = ENDE; // Ende-Zeichen setzen
	}

	return endErgebnis;
}  //ENDE addiere()


/***  Level 3  ***/

	// berechne die n. Fibonacci-Zahl als dynamische neue natuerlich-Zahl
int* fibonacci(int n)
{
	int k;
	int* fibo = nullptr;
	int* fibo1 = new int[2];
	int* fibo2 = new int[2];

	// "null-te" Fibonacci-Zahl = 0
	fibo1[0] = 0;
	fibo1[1] = -1;

	// erste Fibonacci-Zahl = 1
	fibo2[0] = 1;
	fibo2[1] = -1;

	if (n == 0)
	{
		return fibo1;
	}
	if (n == 1)
	{
		return fibo2;
	}

	for (k = 2; k <= n; k++)
	{
		// addition der letzten beiden Fibonacci-Zahlen 
		// setzung von fibo1 und fibo2 auf die jeweils nächste Fibonacci-Zahl 
		fibo = addiere(fibo1, fibo2);
		delete[] fibo1;
		fibo1 = fibo2;
		fibo2 = fibo;
	}

	// Speicher frei machen
	delete[] fibo1;

	return fibo;
}  // ENDE fibonacci()








