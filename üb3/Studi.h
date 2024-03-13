#pragma once
#include "DatumZeiger.h"
#include <string>


class Studi {

public:
	// konstruktoren
	Studi();
	~Studi();

	// setter und getter
	void setName(const string& n);
	void setGeburtstag(const Datumzeiger& g);
	void setFachsemester(const int f);
	string getName() const;
	Datumzeiger getGeburtstag(const Datumzeiger& g);
	int getFachsemester() const;

	// andere methoden
	// ausgabe von 10 objekten wo studis mit 
	string TestProgramm(  ) const;

private:
	string name;
	Datumzeiger geburtstag ;
	int fachsemester;

};