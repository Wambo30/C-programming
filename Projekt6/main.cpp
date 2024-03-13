/**
* Prog1b WS2017/18
* 6. Projekt: kleiner Kommandozeilenrechner
*
* Autoren:	Ekrem Tokgöz 841530
*			Okhtay Wahid Far 870485
*/
#include <iostream>
#include <cstdlib>
#include "natuerlich.h"
using namespace std;



   /***  Hauptprogramm  *************************************************/

   // symbolische Konstanten für erlaubte Operationen
char const ADDITION = '+';
char const FIBONACCI = 'f';
char const FIBONACCI1 = 'F';


int main(int narg, char* argv[])
{
	if (narg < 4)
	{
		// usage
		cout << "usage : " << argv[0] << " m op n" << endl;
		cout << "m, n : natuerliche Zahlen >= 0" << endl;
		cout << "op : Operator '+' 'f' 'F'" << endl;
		cout << "Berechnet Ergebnis des Ausdrucks \"m op \"n." << endl;
		cout << "op = 'f' 'F' : fibonacci(m)[n wird ggf. ignoriert]" << endl;
		cout << endl;

		return 0;
	}


	// hole Eingaben aus Kommandozeile
	int* m = zuZahl(argv[1]);
	char op = argv[2][0];
	int* n = zuZahl(argv[3]);
	int* zahl1 = new int[MAX_TEXT];			// Variablen für Zahlen
	int* zahl2 = new int[MAX_TEXT];
	char rechenzeichen;						// Variable für den Operator

	int* erg = nullptr;
	
	// berechne den Ausdruck, gebe Ergebnis aus
	switch (op)
	{

	case ADDITION:
	{
		cout << zuText(m) << endl;
		cout << zuText(n) << endl;
		erg = addiere(m, n);
		cout << zuText(erg);  // Ausgabe Addition
		break;
	}

	case FIBONACCI:
	case FIBONACCI1:
	{
		erg = fibonacci(atoi(argv[1]));
		cout << zuText(erg);
		break;
	}

	default:
		// kein gültigen Operator eingeben
		cerr << "unbekanntes Rechenzeichen...";
	}

	// Leerzeichen zwischen Ausgaben
	cout << endl << endl;

	// Freigabe von Speicher
	delete[] m;
	delete[] n;
	delete[] erg;

	return 0;     // alles Ok
}  // ENDE main()