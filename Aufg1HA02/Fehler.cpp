/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
#include "Fehler.h"
#include <iostream>
#include "Winzig.h"
#include <string>
using namespace std;

const int OBERGRENZE = 100;
const int UNTERGRENZE = -100;

/**** basisklasse fehler ************************/
Fehler::Fehler(char c):operation(c){}

Fehler::~Fehler(){}

void Fehler::melden() const {
	cout << "FEHLER " << operation << ": ";
}


/****klasse NulldivisionFehler ************************/

NulldivisionFehler::NulldivisionFehler(): Fehler('/'){
	//operation.NulldivisionFehler::melden();
}

NulldivisionFehler::~NulldivisionFehler(){}

void NulldivisionFehler::melden() const {
	Fehler::melden();
	cout << "Division durch 0." << endl;
}


/****klasse bereichsfehler ************************/

BereichsFehler::BereichsFehler(int a, int b, char c): wert(a) ,limit(b),Fehler(c){}

BereichsFehler::~BereichsFehler(){}

void BereichsFehler::melden() const {
	Fehler::melden();
}

/****klasse Unterlauffehler ************************/


UnterlaufFehler::UnterlaufFehler(int a, int b, char c):BereichsFehler(a, b, c) {

}
UnterlaufFehler::~UnterlaufFehler() {

}

void UnterlaufFehler::melden() const {
	Fehler::melden();
	cout << " Wert " << wert << " < " << limit;
}


/****klasse Ueberlauffehler ************************/

UeberlaufFehler::UeberlaufFehler(int a, int b, char c) :BereichsFehler(a, b, c) {}

UeberlaufFehler::~UeberlaufFehler() {}

void UeberlaufFehler::melden() const {
	Fehler::melden();
	cout << "Wert " << wert << " > " << limit;
}
