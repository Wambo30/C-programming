#include <iostream>
using namespace std;
#include "Datumzeiger.h"

// üb2 aufg1.1 : ausgeben -- wollen damit nur LESEN!
/*
void Datum::ausgeben(const Datum& d) {	// eigentlich steht hier const Datum& d
	cout << d.getTag() << "-" << d.getMonat() << "-" << d.getJahr() << endl;

}
*/
//warum meckern wenn const da steht? bei get ist nicht sicher gestellt das 
//referenz: geh auf speicherplatz und mach änderungen
//dh ohne referenz & oben würde das objekt kopiert werden!

// übung 2 aufgabe 1 eigentlich
int main() {

	const string name = "hallo";

	cout << name << endl;
	/*
	DatumZeiger dat(1, 5, 2019);
	dat.setMorgen();
	dat.ausgeben();


	DatumZeiger* zdat = new DatumZeiger(23, 4, 2019);
	zdat = &dat;
	zdat->setMorgen();
	zdat->ausgeben();

	delete zdat;

	zdat = &dat;
	zdat->setMorgen();
	*/
	//d1.setTag(3);
	Datumzeiger d1;
	d1.setTag(3);
	int z;
	int jahr;
	z = rand() % 31; //+ 1;
	jahr = rand() % 10;
	cout << z << endl;
	cout << jahr << endl;

	system("pause"); // HINREICHEND damit konsole stehen bleibt und ausgabe sehen kann
	return 0;
}