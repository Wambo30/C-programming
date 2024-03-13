#pragma once
#include <cmath>

class Vieleck {

public:

	//konstruktoren
	Vieleck();
	Vieleck(double r, int ecken);
	//Vieleck::Vieleck(double r, int e, double kantenLaenge, double umfang, double flaeche, double diagLaenge);
	~Vieleck();

	// get und set methoden
	void setRadius(double r);
	void setEcken(int e);

	double getRadius()const;
	int getEcken() const;


	// andere methoden
	double Innnenwinkel()const;
	double Umfang() const;
	double Flaeche() const;
	double BerKantenLaenge() const;

	//double maxAnzahlDiag() const;
	double BerechDiags(int diagonalnr) ;
	int maxAnzahlDiags();
	void AusgabeDiags(Vieleck& v) ;
	void AusgabeDiags2() const;
	void ausgeben() const;
	//void optionWaehlen(const Vieleck& v);
	void vieleckEinlesen(Vieleck& v);



private:
	double radius;
	int ecken;
	//double kantenLaenge;
	//int maxDiag;
	//double* DiagArray = new double[maxDiag];

	//double innenWinkel;
	//double umfang;
	//double flaeche;
	//double diagLaenge;

};