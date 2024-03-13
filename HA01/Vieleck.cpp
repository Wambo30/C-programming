#include "Vieleck.h"
#include <iostream>
#include <cmath>
using namespace std;
#define _USE_MATH_DEFINES

double const PI = 4 * atan(1);

//konstruktoren

// --> kantenlänge muss raus da in aufgabenstellung nur
// ecken und radius gegeben sind!
Vieleck::Vieleck():radius(1),ecken(3){}

Vieleck::Vieleck(double r, int e) {
	ecken = e; 
	radius = r; 
}
	
/*
//3. konstruktor aber vlcht unnötig
Vieleck::Vieleck(double r, int e, double kantenLaenge, double umfang, double flaeche, double diagLaenge)
{

}
*/

Vieleck::~Vieleck(){}

// get und set methoden 

void Vieleck::setRadius(double r) { 
	if (r > 0)
		radius = r;
	else
		cout << "Fehler!Radius muss größer 0 sein!" << endl;

 }
void Vieleck::setEcken(int e) {
	if (e >= 3)
		ecken = e;
	else
		cout << "Fehler!Eckenanzahl muss >= 3 sein!" << endl;
 }


double Vieleck::getRadius() const {
	return radius;
}

int Vieleck::getEcken() const {
	return ecken;
}

double Vieleck::BerKantenLaenge() const { 
	return  2*radius*sin( PI / ecken) ;
}


// bestimmung innenwinkel, private
double Vieleck::Innnenwinkel() const {
	return (ecken - 2)*180 / (ecken);
}

// anzahl der ecken== anzahl der kanten
double Vieleck::Umfang() const {

	return 2 * ecken*radius*sin( PI / ecken);
}

double Vieleck::Flaeche() const {
	return (( ecken* pow(radius,2)) / 2 )* (sin(2*PI) / ecken) ;
}

//5 a)
int Vieleck::maxAnzahlDiags() {

	if (ecken % 2 == 0) {	// wenn eckenanzahl gerade
		int maxDiag = (ecken - 2) / 2;
		return	maxDiag;
	}
	else {
		int maxDiag = (ecken - 3) / 2;
		return maxDiag;
	}
}


double Vieleck::BerechDiags(int diagonalnr) {
	return 2 * radius*sin(((diagonalnr + 1)*(PI)) / ecken);
	}

// davor: void Vieleck::AusgabeDiags(Vieleck& v)
void Vieleck::AusgabeDiags(Vieleck& v) {
	for (int i = 1; i <= v.maxAnzahlDiags(); i++) 
	{
		double Diag = 2 * radius*sin(((i + 1)*(PI)) / ecken);
		cout << "ausgabe diag nr: " << i << "-->" << Diag << endl;
	}
}
// test fkt

void Vieleck::AusgabeDiags2() const  {
	for (int i = 1; i <= 5; i++)
	{
		double Diag = 2 * radius*sin(((i + 1)*(PI)) / ecken);
		cout << "ausgabe diag nr: " << i << "-->" << Diag << endl;
	}
}






//Vieleck einlesen
void vieleckEinlesen(Vieleck& v) {

	double r;
	cout << "Radius: ";
	cin >> r;
	v.setRadius(r);

	int e;
	cout << endl << "Anzahl Ecken: ";
	cin >> e;
	v.setEcken(e);
}
/*
// nicht klassen methoden
//option Wählen
void optionWaehlen(const Vieleck& v) {
	char eingabe;

	Vieleck v(v.getRadius(),v.getEcken());
	//v.setEcken(vieleck.getEcken());
	//v.setRadius(vieleck.getRadius());

	cout << "Radius: " << v.getRadius() << endl << "Anzahl Ecken: "
		<< v.getEcken() << endl;

	cout << "Folgendes steht zur Auswahl:" << endl
		<< "a - innerer Winkel\n"
		<< "b - Laenge der Kante\n"
		<< "c - Umfang\n"
		<< "d - Flaeche\n"
		<< "e - Laenge der Diagonale\n"
		<< "f - alles\n";

	cin >> eingabe;

	cout << "Gewünschte Eingabe: " << eingabe << endl;

	switch (eingabe) {
	case 'a':	//innerer Winkel
		cout << "Innerer Winkel= " << v.InnenWinkel() << endl;
		break;
	case 'b':	//Laenge der Kante
		//cout << "Kantenlaenge= " << v.BerKantenLaenge(v.getRadius(), v.getEcken()) << endl;
		cout << "Kantenlaenge= " << v.BerKantenLaenge() << endl;
		break;
	case 'c':	//Umfang
		cout << "Umfang= " << v.Umfang() << endl;
		break;
	case 'd':	//Fläche
		cout << "Flaeche= " << v.Flaeche() << endl;
		break;
	case 'e':	//Länge der Diagonalen
		cout << "Laenge der Diagonalen= " << v.BerechDiags();
		break;
	case 'f':	//alles
		cout << "Innerer Winkel= " << v.InnenWinkel() << endl;
		cout << "Kantenlaenge= " << v.BerKantenLaenge() << endl;
		cout << "Umfang= " << v.Umfang() << endl;
		cout << "Flaeche= " << v.Flaeche() << endl;
		cout << "Laenge der Diagonalen= " << v.BerechDiags();
		break;
	default:
		cout << "Fehelerhafte Eingabe!\n";
	} // switch
	
}

*/
//Ausgabe
void Vieleck::ausgeben() const {
	cout << "Radius=" << radius << " Ecken=" << ecken << endl;
}