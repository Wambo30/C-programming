#ifndef DATUM_H  // das nachgucken!
#define DATUM_H

class Datum {
public: // durch public kann man IMMER neuJahr und andere fkten nutzen
	//klassenkonstante
	const int Startjahr = 1990;


	//konstruktoren

	Datum(); //standardkonstruktor 
	//hier gibts kein rückgabetyp also nicht void oder int
	//DH sie heißen IMMER wie die klasse selber und selber ein

	Datum(int, int, int);
	Datum(int);
	//bool zufKonstr();
	~Datum();//destruktor

	//set und get methoden
//warum? damit eigenschaften private bleiben also nicht veränderbar sind
// dh die eigenschaften einer klasse werden so geschützt und sind nicht manipulierbar!!
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	

	int getTag() const;	// durch const wird der gesetzte wert konstant und nicht veränderbar
	int getMonat() const;
	int getJahr() const;
	

	// andere methoden
	void neuJahr(int j);
	bool istSchaltjahr() const;
	void setMorgen();
private:
// private == man kann alles darunter im main nicht nutzen
// dh im main wird das als fehler angezeigt! 

	// hier stehen die eigenschaften=attribute der klasse
	int tag;
	int monat;
	int jahr;

	bool istGueltig() const;
};	// SEMIKOLON am ende sehr wichtig! häufigster fehler
#endif