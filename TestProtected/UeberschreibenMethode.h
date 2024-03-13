#include <iostream>
#include <string>
using namespace std;

#ifndef DATUM_H
#define DATUM_H

class Datum
{
public:
	Datum();
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	int getTag() const;
	int getMonat() const;
	int getJahr() const;
	void ausgeben() const;
	void ausgeben();
	int fkt1(int);
	
	void ausgeben2Ueber(int i);
	void ausgeben2Ueber(double i);

	void ausgeben3Spezial(int i)const;
	void ausgeben3Spezial(double i)const;
private:
	int tag, monat, jahr;

};
#endif

class Feiertag : public Datum {
public:
	Feiertag();
	void setName(string);
	string getName() const;
	void ausgeben() const;
	void setAnlass(string a);
	double fkt1(int);

	void Feiertag::ausgeben3Spezial(int i)const;
private:
	string name;
	string anlass;
	int monatfeiertag;
};