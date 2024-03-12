/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666

*  Datum2-Main.cpp
*  Programmieren IIb - Uebung 4, Aufgabe 2
*
*/

#include "DateError.h"
#include "Datum2.h"
#include <vector>

#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
	///*zum testen
	try {
		int t, m, j;
		cout << "Tag Monat Jahr: ";
		cin >> t >> m >> j;  // Werte fuer t, m und j nacheinader mit 
							 // Leerzeichen getrennt eingeben

		Datum2 d(t, m, j);

		d.setTag(t + 20);
		cout << d << endl;

		d.setMonat(m + 9);
		cout << d << endl;

		d.setJahr(j - 30);
		cout << d << endl;

		d.setMorgen();
		cout << d << endl;
	}
	catch (DateError& er) {
		er.meldung();
	}

	//*/

	cout << endl;
	//initialisierung der pruefungstermine bzw daten
	Datum2 zwtest1(29, 04, 2019);
	Datum2 zwtest2(13, 05, 2019);
	Datum2 zwtest3(27, 05, 2019);
	Datum2 zwtest4(03, 06, 2019);
	Datum2 zwtest5(17, 06, 2019);
	Datum2 zwtest6(01, 07, 2019);
	Datum2 projekt1(06, 05, 2019);
	Datum2 projekt2(27, 05, 2019);
	Datum2 klausur1(06, 06, 2019);
	Datum2 klausur2(8, 06, 2019);

	//allozierung von vector container
	vector <Datum2> termine(10);
	termine = { zwtest1, zwtest2, zwtest3, zwtest4, zwtest5, zwtest6, projekt1, projekt2, klausur1, klausur2 };
	
	//test der allozierung des vector containera
	for(int i = 0; i < 10; i++) {
		cout << termine[i] << endl;
	}

	//iterator festlegen
	vector <Datum2>:: iterator it;

	//anfang von daten initialisieren
	it = termine.begin();
	/*
	for (int i = 0; it != termine.end(); i++, it++) {
		*it = termine[i];	
	}
	*/
	cout << endl;

	//test ausgabe heutiges datum
	cout << "Ausgabe heutiges datum" << endl;
	Datum2 heute;
	heute.setHeute();
	for (int i = 0; i < 2; i++) {
		cout << heute << endl;
	}
	cout << endl;

	//einfuegen von 3. und 7. stelle mit heutigem datum
	termine[2].setHeute();
	termine[6].setHeute();
	cout << "Ausgabe nach 3. und 7. stelle neuzubesetzen" << endl;
	for(it = termine.begin(); it != termine.end(); ++it) {
		cout << *it <<" " << endl;
	}
	cout << endl;

	// letzten 3 elemente im container loeschen
	termine.erase(termine.begin() + 6, termine.end());
	

		cout << "letzten 3 elemente im container geloescht" << endl;
		for (it = termine.begin(); it != termine.end(); ++it) {
			cout << *it << " " << endl;
		}
		cout << endl;

//testen operatoren
		Datum2 testd(29, 04, 2019);
		if (zwtest1 == testd) {
			cout << "daten sind gleich" << endl;
		}
		else {
			cout << "daten sind nicht gleich" << endl;
		}

		cout << endl;
		if (zwtest1 > zwtest2){
			cout << "zwtest1 ist spaeter" << endl;
		}
		else {
			cout << "zwtest1 ist frueher" << endl;

		}

		cout << endl;
		if (zwtest1 < zwtest2) {
			cout << "zwtest1 ist spaeter" << endl;
		}
		else {
			cout << "zwtest1 ist frueher" << endl;

		}

		cout << endl;
		//nutzung der bibliothek algorythm
		//Aufgabe 4(a)
		sort(termine.begin(), termine.end());

		for (it = termine.begin(); it != termine.end(); it++)
			cout << *it << endl;

		cout << endl;

		//Aufgabe 4(b)
		it = find(termine.begin(), termine.end(), heute);
		termine.erase(it);

		for (it = termine.begin(); it != termine.end(); it++)
			cout << *it << endl;

		cout << endl;

		//Aufgabe 4(c)

		for (it = termine.begin(); it != termine.end(); it++) {
			cout << *it << endl;
		}

		cout << endl;
		/*
		//Aufgabe 4(d)
		for_each(termine.begin(), termine.end(), plusEinTag);

		for (it = termine.begin(); it != termine.end(); it++)
		cout << *it << endl;

		*/

	system("pause");
	return 0;
}















