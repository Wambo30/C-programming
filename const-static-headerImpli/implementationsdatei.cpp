#include "header_implem.h"

// globale Konstanten
double const FAKTOR = 2.5;  // statisch, da Wert für FAKTOR schon vor Programmstart feststeht
double const FAKTOR2 = FAKTOR * 5; // immer noch statisch, da vom Compiler vor Programmstart ausrechenbar
int variable = 5;

/*
sinn header datei: schnittstelle zwischen funktionen definitionen und main datei
wenn person a fkten schreibt mit eigener main --> will aber fkten von person b benutzen 
==> so wird die headerdatei von person b in main und in seine fkts datei von person a included
==> somit kann man auch fkten von anderen personen im projekt nutzen!
==> includen = #include "header_implem.h" --> das steht in der main und in fkten datei WOBEI der 
	name FKtendatei == name Header datei --> muss gelten.Unterschied nur in endung 
header datei == alle deklarationen von fkts definitionen --> somit sind fkten für compiler bekannt

*/


bool funktion1(double const KONSTANTE1)
{
	double const KONSTANTE2 = FAKTOR * KONSTANTE1;

	return KONSTANTE2;
}

  void staticFktTest()
{
	static int i = 0;
	++i;
	cout << i << endl;

}