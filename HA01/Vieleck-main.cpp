#include "Vieleck.h"
#include <iostream>
#include <cmath>
using namespace std;

void vieleckEinlesen(Vieleck& v);
void optionWaehlen(const Vieleck& v);





int main() {

	/*
	// test max anzahl diag
	Vieleck sechseck (2,6);
	cout << sechseck.maxAnzahlDiag(6) << endl;
	//cout << sechseck << endl;
	*/


	// test ausgabe diagonalen

	// alle diagonalen sollen im dynamischen array gespeichert werden

	/*
	//test bestimmen kantenlänge
	//Vieleck const maxDiag = 1;
	int diag[1];
	Vieleck viereck;
	viereck.setEcken(4);
	viereck.setRadius(1);
	int erg =viereck.BerKantenLaenge();
	cout <<"kantenlaenge von viereck:" <<erg << endl;
	
	*/
	
	/*
	// test bestimmen diag 

	Vieleck viereck;
	viereck.setEcken(4);
	viereck.setRadius(1);
	int kantenlaenge = viereck.BerKantenLaenge();
	double LaengeDiag = 2 * viereck.getRadius()*sin(((1 + 1)*(4 * atan(1))) / viereck.getEcken());

	cout << "laenge diag von viereck muss kantenlaenge* wurzel(2) sein: " << LaengeDiag << endl;

	/*
	for (int i = 0; i < 4; i++) {
		diag[i] = 2 *viereck.getRadius()*sin(((4 * atan(1))) / viereck.getEcken());
		cout << "diagonale nr: " << i << "-->"<<diag[i] << endl;
	}
	*/


	// test 2 ausgeben von eckenanzahl und radius ==> stimmt alles!

	/* 
	int const maxDiag = 2;
	int  DiagArray[] = { maxDiag };
	Vieleck sechseck(1, 6);
	cout << "anzahl von ecken: " << sechseck.getEcken() << " radius: " << sechseck.getRadius() << endl;
	*/


	// test bestimmen max anzahl von diags zu einem vieleck ==> stimmt alles!
	/*
	Vieleck sechseck(1, 6);
	cout<<" max diag anzahl von 6 eck:"  <<sechseck.maxAnzahlDiag() << endl;
	//cout <<"max anzahl von diags bei sechseck: " << maxDiag << endl;

	cout << "ausgabe ecken: " << sechseck.getEcken() << endl;
	*/

	//test ausgabe der verschiedenen diags bzgl dessen längen
	/*
	Vieleck sechseck(1, 6); // radius=1, ecken=6
	//cout << " max diag anzahl von 6 eck:" << sechseck.maxAnzahlDiags() << endl;
	int  maxDiag = sechseck.maxAnzahlDiags();
	//int const DIM = maxDiag;
	cout << "ausgabe maxDiag:" << maxDiag << endl;
	*/
	/*
	brauchen leider ein dyn array da man bei statischen array die größe des arrays tatsächlich
	durch eine zahl angeben MUSS! es reiht da nicht aus mit einer variablen wo wert drin ist
	zuzuweisen!
	*/

	/*
	double* DiagArray = new double[maxDiag]; // maxDiag= größe von dyn array

	for (int i = 0; i < maxDiag; i++) {
		DiagArray[i] = 2 *sechseck.getRadius()*sin(( (i + 1)*(4 * atan(1))) / sechseck.getEcken() );
		cout << "ausgabe diag nr: "<< i << "-->" << DiagArray[i] <<endl;
	}

	*/
	//return DiagArray[maxDiag];

	//v.LaengeDiag(sechseck);

	// test ausgabe diags allgemein
	/*
	Vieleck sechseck (1,6);
	//sechseck.setRadius(1);
	//sechseck.setEcken(6);
	//sechseck.maxAnzahlDiags();
	sechseck.BerechDiags();
	//out << AusgabeDiags(sechseck) << endl;
	AusgabeDiags(sechseck);
	//cout << sechseck.AusgabeDiags() << endl;
	*/
	
	// test ausgabe diags

Vieleck sechseck(3, 7);
sechseck.AusgabeDiags2();// geht nicht da ausgabeDiags2() void hat 

// test ausgbae von fkt mit rückgabewert
/*
 double erg =sechseck.BerKantenLaenge();
 cout <<"ausgabe NUR ueber cout befehl: "  <<erg << endl;

 sechseck.ausgeben();
 cout << "ausgabe mit methode ausgeben() " << endl;
*/

cout <<"ausgabe kantenlaenge: " <<sechseck.BerKantenLaenge() << endl;
double c=sechseck.BerKantenLaenge();

cout << "ausgabe von b durch vorherige zuweisung auf c: " << c << endl;



	system("pause");
	return 0;

}