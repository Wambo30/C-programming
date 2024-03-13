#include <iostream>
using namespace std;
#include "Datum.h"

// üb2 aufg1.1 : ausgeben -- wollen damit nur LESEN!
void ausgeben(const Datum& d) {	// eigentlich steht hier const Datum& d
	cout << d.getTag() << "-" << d.getMonat() << "-" << d.getJahr() << endl;

}

//warum meckern wenn const da steht? bei get ist nicht sicher gestellt das 
//referenz: geh auf speicherplatz und mach änderungen
//dh ohne referenz & oben würde das objekt kopiert werden!
	
// übung 2 aufgabe 1 eigentlich
int main() {

	/*
	Datum heute; // heute= objekt
	heute.tag = 15;
	heute.monat = 4;
	heute.jahr = 2019;
	cout << heute.tag << " " << heute.monat <<" " <<heute.jahr << endl;
	

	Datum morgen;	// morgen = objekt
	morgen = heute;
	morgen.tag++;
	cout << morgen.tag << endl;

	Datum neujahr2;	
	neujahr2.neuJahr(2050);

	Datum termine[3];
	termine[2].neuJahr(2016);
	

	//set und get
	Datum heute;
	heute.setTag(15);
	
	cout << heute.getTag() <<" "<<heute.getMonat()	<<" "<<	heute.getJahr()<<" "<< endl;

	Datum termine[5];
	Datum ostersonntag(21, 4, 2019);	// mit anderen konstruktor wurden daten gesetzt

	cout << ostersonntag.getTag() << " "<< ostersonntag.getMonat() <<" " << ostersonntag.getJahr() << endl;

	Datum neu(1976);
	*/

	//üb2aufg1.1
	/*
	Datum heute;
	heute.setTag = 16;
	heute.setMonat = 4;
	heute.setJahr = 2019;
	ausgeben(heute);
	*/

	/*
	//ub2aufg1.2
	Datum heute;
	heute.setJahr(2016);
	if (heute.istSchaltjahr())
		cout << true << endl;
	else
		cout << false << endl;
	*/

	/*
	//ub2aufg1.3
	Datum heute;
	//heute.setJahr(2016);
	heute.setTag = 16;
	heute.setMonat = 4;
	heute.setJahr = 2019;
	
	if (heute.istGueltig() )
		cout << "Jahr wurde korrekt gewählt" + true << endl;
	else
		cout << "Jahr muss größer 1990 sein" + false<< endl;
	*/

	// blatt 2 aufg1.4
	/*
	Datum heute;
	heute.setTag(1);
	heute.setMonat(4);
	heute.setJahr(2019);

	heute.setMorgen();
	/*
	if (heute.istGueltig())
		cout << "format korrekt"<< endl;
	else
		cout << "format nicht korrekt"<< endl;
	
	ausgeben(heute);
	*/

	// test bzgl destruktor

	Datum heute[1];
	//heute[2].ausgeben();
	cout << heute << endl;

	system("pause"); // HINREICHEND damit konsole stehen bleibt und ausgabe sehen kann
	return 0;
}