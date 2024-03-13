#include "TierAbrstrakt.h"
#include <iostream>
using namespace std;


int main() {
	//TierAbstrakt tier;
	Hund3 hund;
	Katze3 katze;
	Tiger3 tiger;

	hund.essen();
	katze.essen();
	tiger.essen();

	//test ausgeben wo eine fkt aus abgeleiteten klassen OHNE scope operator
	//benutzt wird , die in basisklasse aber REIN VIRTUELL ist!!  UND in einer
	// nicht reinvirtuellen methode aufgerufen wird!! es geht aber warum??
	cout << endl;
	hund.ausgeben2();

	/*
	ausgabe: Hund ausgabe
	==>warum? da hund in abgeleoteter klasse Hund erzeugt wurde obwohl man eine fkt
	nutzt die aus basisklasse ist!aber diese wird sowieso immer vererbt--> hier ist
	die ausgeben() fkt bloﬂ rein virtuell in der basisklasse und man NUTZT eine fkt
	die zwar in der basisklasse rein virtuell ist aber in der abgeleiteten klasse
	implementiert wurde----> es ist eigentlich keine groﬂe sache!!


	*/

	system("pause");
	return 0;
}