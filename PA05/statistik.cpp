/*
Datum:08.01.18
Autoren: Okhtay Wahid Far 870485
		 Ekrem Tokgöz 841530 

Beschreibung:
Level 1:Einlesen der ausgewählten Textdatei erfolgt hier.
Es wird eine Fehlermeldung ausgegeben, wenn die Datei nicht geöffnet 
werden kann. Man überpüft zeichenweise , ob das untersuchte Zeichen
ein ASCII Zeichen ist. Falls ja, dann wird der Gesamtzähler um eins
jeweils erhöht.

Level 2:Hier wird die Statistik berechnet und mathematisch verarbeitet.
Es werden die Anteile von verschiedenen ASCII Zeichen gezählt und dessen
prozentanteil berechnet. Im Array wird dann die Häufigkeit der Zeichen 
sortiert.

Level 3:Die berechneten Ergebnisse werden in Tabellenform ausgegeben. Es wird
die Anzahl aller Zeichen und die Anzahl der verschiedenen Zeichen ausgegeben.
Der prozenthaltige Anteil des Zeichens wird jeweils auch ausgegeben.

*/

#include "projekt5.h"

#include <fstream>	//ausgabe in tabelle
#include <iomanip>	//nutzen von manipulatoren
#include <cmath>	//für ceil 
int const NSPALTEN = 4;	

int statistik(char const dateiName[])
{
	ifstream datei(dateiName);

	if (!datei)					//falls kein Zugriff zur Datei existiert
	{
		return KEINE_DATEI;		//ausgabe KEINE_DATEI
	}
	
	int const NASCII = 127;	//Anzahl ASCII Zeichen
	int z[NASCII] = { 0 };	//Array namens z mit Länge 127 

	int anzahlGesamt = 0; //wieviele zeichen im text vorhanden sind
	char varEinlesen;	// Speicher für Zeicheneinlesung
	datei >> noskipws;	//beachte whitespaces

	// Anzahl aller Zeichen bestimmen
	while (datei >> varEinlesen)	//einlesen der textdatei in varEinlesen
	{
		++anzahlGesamt;		
		if (varEinlesen >= 0 && varEinlesen <= 127)		//falls ASCII zeichen in textdatei existieren
		{
			++z[varEinlesen];	//überprüfe nächstes Zeichen
		}
	}//ENDE Anzahl aller Zeichen bestimmen,
	datei.close();	//schließen der Datei
	
	if (anzahlGesamt == 0)	//wenn keine Zeichen in Datei existieren 
		return DATEI_LEER;
	
	cout << "Anzahl Zeichen = " << anzahlGesamt << endl;	//Ausgabe Anzahl aller Zeichen in Datei
	//ENDE Level 1

	//Ab hier Level 2
	int index[NASCII] = { 0 };			// Array für die ASCII- Zeichen zum tauschen später
	double prozent[NASCII] = { 0 };		// Array für Häufigkeit
	int verschieden = 0;		// Speicher für die Anzahl der verschiedenen ASCII- Zeichen
	
	// Anzahl der verschiedenen Zeichen
	for ( int i = 0; i < NASCII; ++i )		 
	{
		if ( z[i] > 0 )		//wenn in z die Stellen einen Wert größer 0 haben
		{
			++verschieden;	// dann wird der Wert in der Variablen verschieden um eins erhöht
			prozent[i] =  double(z[i]) / double(anzahlGesamt)*100. ;
			// Prozentanteil = Häufigkeit von Zeichen durch Gesamtanteil aller Zeichen mal 100
		}
		index[i] = i; // die zu den Zahlen dazugehörenden ASCII-Zeichen werden in index gespeichert
	}// ENDE Anzahl verschiedene Zahlen

	cout << "davon verschieden = " << verschieden << endl;	// Ausgabe der verschiedenen Zeichen

	//Sortierung der Werte absteigend durch Austausch der Werte
	for (int i = 0; i < NASCII ; ++i)	
	{
		for (int j = i + 1; j < NASCII ; ++j)
		{
			if ( prozent[i] < prozent[j] ) 
			{
				double ablage = prozent[i];	// Ablage, um die Werte zu tauschen
				prozent[i] = prozent[j];
				prozent[j] = ablage;

				int indizes = index[i];	//indizes ist vertauschungsvariable
				index[i] = index[j];
				index[j] = indizes;
			}
		}

	}// ENDE Sortierung
	//ENDE Level 2

	//Level 3
	// Ausgabe der Ergebnisse
	int nZeilen = ceil(verschieden *1.0/ NSPALTEN);	//globale Variable nZeilen und Aufrundung durch ceil
	for (int i = 0; i < nZeilen; ++i)	
	{
		for (int j = 0; j < NSPALTEN; ++j)
		{
			int k = j * nZeilen + i;	
			if (k < NASCII  && prozent[k] > 0)
			{
			//Formatierung der Tabelle
				if (index[k] > 32)
					cout << setw(3) << right << char(index[k]);	//Ausgabe feste Breite=3 und rechtsbündig
				else
					cout << '*' << setw(2) << right  << index[k];	//Ausgabe  feste Breite=2 und rechtsbündig
				cout << fixed << " : " << setprecision(2) << right << setw(5) << prozent[k] << " %  ";
				//Ausgabe der Prozentzahl rechtsbündig mit 2 festen Nachkommastellen,feste Breite = 5
			}
		} 
		cout << endl;
	}// Ende der Ergebnisse
		
	return 0;
}
