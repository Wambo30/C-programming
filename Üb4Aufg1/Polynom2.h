/* Polynom.h */

#ifndef POLYNOM2_H
#define POLYNOM2_H

#include <string>
// ifndef sagt das man nur EINMAL string includen muss
//--> daher nutzt man das immer im header!! regel aufschreiben!

using namespace std;

class Polynom2 {
public:
	Polynom2();
	Polynom2(size_t, double);
	Polynom2(size_t);// für zufällige parameter
	Polynom2(const Polynom2&); // kopierkonstruktor
	Polynom2& operator=(const Polynom2&); // zuweisungsoperator
	~Polynom2();

//set und get methoden


	double getKoeffizienten(size_t i) const;
void setKoeffizienten(size_t i, double a);
// andere methoden
	string toString() const;
	double wertBerechnen(double) const;
	bool istNullstelle(double x) const;

//rechnen mit polynomen
	void multipliziere(double w);
	void multipliziere(const Polynom2&);
	void addiere(const Polynom2&);

private:
	size_t grad;
	double* koeffizienten;
	void gradRunterSetzen(const Polynom2& p);
};

#endif //POLYNOM_H
