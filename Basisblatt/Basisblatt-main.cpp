#include "DatumStaticConst.h"
#include "ZaehlerStatisch.h"
#include "Aufg2.5_Struct.h"
#include <chrono> // für zeitmessung
#include "aufg3.3_RuleOfThree.h" // aufg3.3

//aufg1.3)
//initiliaisierung von rein stat. attribut
int ZaehlerStatisch::Anzahl = 10;

//aufg 4.2)
#include <stdbool.h>
#include <stdio.h>
#define B2S(x)  (x==true) 
#define b2s(x)( (x==true) ? "true": "false")

//aufg 4.3
//#define int* zeigerVar == nullptr
#define zeigerPruefung(nullptr) printf("\n Achtung, der Zeiger ist NULL!\n")
#define NULL printf("\n Achtung, der Zeiger ist NULL!\n")

//aufg 4.4)
//#define var2 == nullptr
#define MAKE_STRING(...) #__VA_ARGS__
#define zeigerPruefung2(zeiger2) printf("\n Der Zeiger %s ", MAKE_STRING(zeiger2) )

//aufg 5)
#include "aufg5_Stack-Heap.h"

//aufg6)
#include "Aufg6_Vererbung.h"

//aufg8.1)
#include "Aufg8.1.h"

//aufg8.2)
#include "Aufg8_vektor.h"
#include <cassert>


#include <iostream>
using namespace std;

int main() {

	//test const+stat attribut
	DatumStaticConst d1;
	cout << d1.getTag() << "." << d1.getMonat() << "." << d1.getJahr() << endl;
	//ausgabe: 1.1.1990
	cout << endl;

	// test nutzung von rein statischen attribut
	ZaehlerStatisch ob1, ob2, ob3;
	cout << ZaehlerStatisch::getAnzahl() << endl;
	//Ausgabe: 13 da 3 mal das attribut Anzahl um ++ addiert wurde
	cout << endl;


	// test2 nutzung von rein statischen attribut
	if (ZaehlerStatisch::getAnzahl() > 12) {
		ZaehlerStatisch feld[5];
		//array angelegt wo zusätzlich 5 dazu angelegt werden
		cout << ZaehlerStatisch::getAnzahl() << endl;
	}//ausgabe: 18

	cout << ZaehlerStatisch::getAnzahl() << endl;
	//ausgabe:13

/*******************************ENDE aufg1**************************************************/

/*********aufg2****************************************************************************/

// test aufg2.5
	cout << endl;
	cout << endl;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
	// zeit messen
	Test1 obj1, obj2;
	obj1.zahl1 = 10; // attribut
	obj2.zahl1 = 10;

	//mit konstanter referenz
	for (int i = 1; i < 10000000; i++) {
		obj1.Fkt1(obj2);
	}

	cout << obj1.zahl1 << endl;
	chrono::high_resolution_clock::time_point ende = chrono::high_resolution_clock::now();
	chrono::high_resolution_clock::duration diff = ende - start;
	int ms = chrono::duration_cast<chrono::milliseconds>(diff).count();
	cout << "Zeitdauer in Millisekunden mit konst. referenz: " << ms << endl;

	// ohne konstanter referenz
	cout << endl;
	chrono::high_resolution_clock::time_point start2 = chrono::high_resolution_clock::now();
	Test2 obj3, obj4;
	obj3.zahl4 = 10;
	obj4.zahl4 = 10;
	//chrono::high_resolution_clock::time_point start2 = chrono::high_resolution_clock::now();
	for (int i = 1; i < 10000000; i++) {
		obj3.Fkt2(obj4);
	}

	cout << obj3.zahl4 << endl;
	chrono::high_resolution_clock::time_point ende2 = chrono::high_resolution_clock::now();
	chrono::high_resolution_clock::duration diff2 = ende2 - start2;
	int ms2 = chrono::duration_cast<chrono::milliseconds>(diff2).count();
	cout << "Zeitdauer in Millisekunden ohne konst. referenz: " << ms2 << endl;


	/*******************************ENDE aufg2**************************************************/

	/*********aufg3****************************************************************************/
	cout << endl;
	cout << endl;
	Point2d test1;
	test1.uebung3_3();


	/*******************************ENDE aufg3**************************************************/

	/*********aufg4****************************************************************************/
	cout << endl;
	cout << endl;
	// aufg 4.2)makro fkt b2s aufrufen
	int zahl = 20;
	cout << "This is: " << B2S(true) << endl;
	cout << "This is: " << b2s(true) << endl;

	//aufg 4.3) makro schreiben was zeiger darauf prüft obs nullzeiger ist
		//int var = 10;
	cout << endl;
	int* zeiger = nullptr;
	if (zeigerPruefung(zeiger) || zeiger) { //wegen #define NULL printf("...")

	}
	else {
		cout << "zeiger ist kein nullptr!";
	}


	//aufg4.4
	cout << endl;
	int* zeiger1 = nullptr;
	int* zeiger3 = nullptr;

	if ((zeigerPruefung2(zeiger3))) {
		printf(" ist NULL\n");
	}


	/*******************************ENDE aufg4**************************************************/

	/*********aufg5****************************************************************************/
	cout << endl;
	cout << endl;
	meeting();

	int* p2 = new int[10];

	/*******************************ENDE aufg5**************************************************/

	/*********aufg6****************************************************************************/
	cout << endl;
	cout << endl;
	//aufg6b)
	Animal* tux = new Penguin;
	tux->move();
	Fish* nemo = new Fish;
	nemo->move();
	delete tux;
	delete nemo;

	//aufg 6c)
	cout << endl;

	//Penguin* v1 = dynamic_cast<Bird*> (tux);
	//Fish* v2 = dynamic_cast<Fish*> (tux);
	//tux[10];
	//Bird* t1 =
	//Fish test	= dynamic_cast<Bird*> (tux);
	//Fish* t2 = 
		//dynamic_cast<Fish*> (tux);


/*******************************ENDE aufg6**************************************************/


/*********aufg8****************************************************************************/
	cout << endl;
	cout << endl;
// aufg 8.2)
	vector v1(6), v2(v1), v3(10);
	v1 = v2;
	v3 = v2;

	//v1(2) = 1.0; ==> kann nicht klappen da man ja eine stelle in dem data array ändert
	//v1[2] = 1.0; // das klappt
	//const vector v4(v1);
	//v4[2] = 1.0; //==> kann nicht klappen da v4 const ist
	
	cout << endl;
//aufg 8.1)
	using math::foo; using math1::ns::foo2;

	std::cout << foo(6.0) << "\n";
	std::cout << foo2(6.0) << "\n";
	//std::cout << math1::foo(6.0) << "\n";

	math1::dd x; x.d = 6.0;
	std::cout << foo(x) << "\n";
	{
		using namespace math;
		std::cout << foo(6.0) << "\n";
		std::cout << foo2(6.0) << "\n";
	}

	{
		using  math1::foo; using math::foo2;
		std::cout << foo(6.0) << "\n";
		std::cout << foo2(6.0) << "\n";
	}

	std::cout << foo(6.0) << "\n";
	std::cout << foo2(6.0) << "\n";
	std::cout << math1::ns2::foo2(6.0) << "\n";


/*******************************ENDE aufg8**************************************************/

	system("pause");
	return 0;
}