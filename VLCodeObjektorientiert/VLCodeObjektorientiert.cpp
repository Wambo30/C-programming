#include <iostream>
#include <string>
using namespace std;


int main()
{
	/*********skript objektorientiert *************/

	/*unterschied zwischen char und string*/

	//----------------------------------------------------

/* BEGINN komplett kommentiert
	//lesen und schreiben bei char bzw string

	string var2 = "Hallo";

	char var1 =var2[0];    // lesen	dh erster eintrag von var2 wird var1 zugewiesen
	//str[0] = 'H';         // schreiben

	cout << "ausgabe von var1 : "<< var1 << endl;
	cout << "ausgabe von var2 : " << var2 << endl;

	//-----------------------------------------------------------------------------

	//skript objektorientiert seite 187
	char text[] = "hallo!";
	text[3] = '\0';
	cout << "ausgabe von char array namens text: "  << text << endl;  // endet bei ’\0’
	//ausgabe: hal dh char ist so definiert das eine char zeichenkette bei '\0' endet

	//-----------------------------------------------------------------------------

	//ausgabe bei string
	string var3 = "hallo!";
	var3[3] = '\0';
	cout << "ausgabe von var3 : " << var3 << endl;   // ’\0’ wird leeres Zeichen
	// ausgabe: hal o! 
	//warum? da '\0' == leerzeichen gesehen bzw wird nicht als spezielles zeichen erkannt
	// UND der compiler gibt die zeichen hinter '\0' trotzdem aus!dh strings haben keine begrenzung
	//auch nicht durch bestimmte zeichen --> string == dynamisch== ohne grenzen

	//-----------------------------------------------------------------------------

	//einlesen char
	char einlesenText[10];	// char einlesenText[10] == char darf höchstens länge 10 haben
	cin >> einlesenText;   // darf max. 9 Zeichen lang sein
	cout << "ausgabe von einlesenText: "<< einlesenText << endl;

	//ausgabe: text der eingegeben wurde --> sogar welche die länger als 10 zeichen sind?! weiss
	//nicht warum so ist

//-----------------------------------------------------------------------------

	//einlesen string
	string einlesenString;
	cin >> einlesenString;    // keine Langenbeschrankung!
	cout << "ausgabe einlesenString: " << einlesenString << endl;
	
	//ausgabe:alles was man reinschreibt ABER wenn ich string und char in einer datei ausgeben lasse
	//so entsteht komischerweise bei ausgabe von string ein fehler ab gewisse anzahl von zeichen

//-----------------------------------------------------------------------------

	string wort = "hallo";
	
	cout << size_t wort.size() << endl;

//-----------------------------------------------------------------------------

//was ist ifstream? istream?


//-----------------------------------------------------------------------------



	//einlesen von string eingabe vom user

	cout << "gib ein paar Woerter ein: ";
	string input;	//
	getline(cin, input);     // liest gesamte eingabe egal was da steht und wie lang
	//getline == methode zum einlesen von string, getline (<datenstrom cin>, <string variable>)
	cout << input << endl;	// ausgabe von string variable

	//ausgabe: alles wird ausgegeben, egal was man in input reingeschrieben wurde
____________________________________________________________________________________________
	REGEL: nutzung von getline methode bzgl eingabe während laufzeit

	syntax OBDA: 

	getline(cin, input);     // liest gesamte eingabe egal was da steht und wie lang
	//getline == methode zum einlesen von string, getline (<datenstrom cin>, <string variable>)
	cout << input << endl;	// ausgabe von string variable

	dh eingabe hier von user während laufzeit gegeben
________________________________________________________________________________________________

//-----------------------------------------------------------------------------
ENDE komplett kommentiert */

	//einlesen aus dateien 

	ifstream datei(dateiName);
	string   input;
	
			while (getline(datei, input))     // solange eine Zeile gelesen wird
			{
			
			}




	return 0;
}
