#include <iostream>
#include <string>
#include <fstream>
#include "artikel.h"
using namespace std;

char const LEERZEICHEN = ' ';
char const ZEILENUMBRUCH = '\n';
string const ABSATZ = "\n\n";

/*
Algorythmische Strategie:
Es wird eine Textdatei als in ein string eingelesen und dessen Zeilenumbrüche gelöscht. 
Die Absätze bleiben aber bestehen.
Dieser String wird in einen lesbaren artikel umgewandelt, welcher für den leser leichter zu lesen ist.
Der User kann während der Laufzeit die Spaltenbreite, die Spaltenanzahl und den Spaltenzwischenraum
bestimmen und kriegt das in der Kommandozeile ausgegeben.


*/
string leseArtikel(char const dateiName[])
{
	string rohartikel = "";	// speicher für string ohne zeilenumbruch
	string zeile = "";	//zwischenvariable
	
	ifstream inputDatei(dateiName);		


	if (!inputDatei)	// wenn man inputDatei nicht öffnen kann
		return rohartikel;

	while (getline(inputDatei, zeile))  // liest zeilenweise ein
	{
		if (!zeile.empty())	// wenn zeile nicht leer ist
		{
		
			if (zeile.back() == '-')//zeilenende bindestrich hat
			{
				zeile.pop_back();	//löschen des letzten zeichens in zeile
				rohartikel += zeile;
			}
			else
			{
				zeile += LEERZEICHEN;		//ersetze zeilenende mit leerzeichen
				rohartikel += zeile;
			}
		
		}
		else
		{
			if (rohartikel.back() == LEERZEICHEN)	//wenn letztes zeichen in rohartikel Leerzeichen
				rohartikel.pop_back();	//löschen des letzten zeichens in rohartikel
			rohartikel += ABSATZ;	//hinzufügen von absatz
		}

	}
	inputDatei.close();	//schließen der geöffneten datei
	return rohartikel;
}//ENDE leseArtikel()


// Fkt Hinzufügen von Leerzeichen
string getLeerZeichenKette(size_t len)
{
	string leerZeichenKette = "";	// leerzeichen
	for (size_t i = 0; i < len; i++)
		leerZeichenKette += LEERZEICHEN;
	return leerZeichenKette;
}// Ende getLeerZeichenKette

// Funktion ausgabeSpaltensatz 
void ausgabeSpaltensatz(string spaltenSatz, size_t spaltenBreite, size_t nSpalten, size_t zwRaum)
{
	size_t gesamtZeilenAnzahl = spaltenSatz.size() / spaltenBreite; //Berechnung gesamtZeilenAnzahl
		if (spaltenSatz.size() % spaltenBreite)
			gesamtZeilenAnzahl++;
	size_t zeilenAnzahl = gesamtZeilenAnzahl / nSpalten;	// Berechnung Zeilenanzahl
		if (gesamtZeilenAnzahl % nSpalten)
			zeilenAnzahl++;
	size_t zeilenBreite = nSpalten * spaltenBreite;		//Berechnung Zeilenbreite
	size_t pos = 0;
	for (size_t i = 0; i < zeilenAnzahl; i++)
	{
		for (size_t j = 0; j < nSpalten; j++)
		{
			pos = j*spaltenBreite*zeilenAnzahl + i*spaltenBreite;
			cout << spaltenSatz.substr(pos, spaltenBreite); 
			if (j < zeilenAnzahl - 1)
				cout << getLeerZeichenKette(zwRaum);
		}
		cout << endl;
	}
}// ENDE ausgabeSpaltensatz

void schreibeArtikel(string artikel, size_t breite, size_t nSpalten, size_t zwRaum)
{
	
	size_t spaltenBreite = (breite - (nSpalten - 1)*zwRaum) / nSpalten;// berechnung der Spaltenbreite
	
	// cerr wenn zeilenbreite (== spaltenbreite) kleiner 3 
	if (spaltenBreite < 3)
	{
		cerr << "Spaltenbreite >= 3 wird gefordert" << endl;
		return;	// reicht das aus?
	}
	// zwischenvariable zum speichern des gesamten textes in einer zeile
	size_t len = artikel.size();


	for (size_t posA = 0; posA < len; posA += spaltenBreite) //posA == erste stelle im rohartikel , len == länge von artikel
	{
		size_t posE = posA + spaltenBreite;
		size_t zeilenumbruchPos = artikel.find(ZEILENUMBRUCH, posA);
		size_t leerzeichenPos = artikel.rfind(LEERZEICHEN, posE);

		//erster fall
		if (zeilenumbruchPos == posE)	//gilt wenn zeilenumbruch letzte stelle in der zeile ist
		{
			artikel.erase(posE,1);	
			len--;
		}
		// zweiter fall
		else if ( posA <= zeilenumbruchPos && zeilenumbruchPos < posE )	//gilt wenn zeilenumbruch mitten in zeile ist
		{
			artikel.replace( zeilenumbruchPos, 1, getLeerZeichenKette(posE- zeilenumbruchPos) );
			len += posE - zeilenumbruchPos - 1;
		}

		// dritter fall
		else if (leerzeichenPos == posE)	//gilt wenn leerzeichen am ende der zeile ist
		{
			artikel.erase(posE,1);
			len--;
		}

		// vierter fall
		else if (posA <= leerzeichenPos && leerzeichenPos < posE)	//gilt wenn leerzeichen mitten in zeile ist
		{
			artikel.replace(leerzeichenPos, 1, getLeerZeichenKette(posE - leerzeichenPos));
			len += posE - leerzeichenPos - 1;
		}
		else
		{ 
			artikel.insert(posE - 1, 1, '-');	//an vorletzter position in zeile
			len++;

		}
	}

	ausgabeSpaltensatz(artikel, spaltenBreite, nSpalten, zwRaum);

}