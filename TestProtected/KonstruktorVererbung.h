#ifndef KonstruktorVererbung_H
#define KonstruktorVererbung_H
#include <string>
#include <iostream>
using namespace std;

class Basis {
public:
	Basis(char i);
	//Basis::Basis(double , int );
	Basis::Basis();
};
#endif // ENDE KonstruktorVererbung_H

class Spezialfall : public Basis {
public:
	Spezialfall();
	Spezialfall(double i, double z);
	Spezialfall(char i);
};
