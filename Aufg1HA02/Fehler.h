/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
#ifndef FEHLER_H
#define FEHLER_H
#include <iostream>
#include "Winzig.h"
#include <string>
using namespace std;

class Fehler {
public:
	Fehler(char);
	virtual ~Fehler(); 
	// muss virtual sein sonst wird destruktor von abgel. klassen nicht aufgerufen
	// wird auch gemacht da diese klasse abgeleitet wird
	
	virtual void melden() const ;
	//rein virtuelle methode durch const=0 die nur von den abgeleiteten klassen genutzt
	//wird ---> somit ist klasse fehler == abstrakte klasse

protected:
	char operation;
};


class NulldivisionFehler : public Fehler {
public:
	NulldivisionFehler();
	~NulldivisionFehler();
	virtual void melden() const;
};

class BereichsFehler : public Fehler {
public:
	virtual void melden() const;
	BereichsFehler(int,int,char );
	~BereichsFehler();
protected:
	int wert;
	int limit;
};


class UnterlaufFehler : public BereichsFehler {
public:
	UnterlaufFehler(int,int,char);
	~UnterlaufFehler();
	virtual void melden() const;
};

class UeberlaufFehler : public BereichsFehler {
public:
	UeberlaufFehler(int, int, char);
	~UeberlaufFehler();
	virtual void melden() const;
};




#endif