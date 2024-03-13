/*
*  Intervall.h
*  eine Klassenhierarchie fuer Intervalle
*
*  Programieren 2B - Uebungsblatt 2, 2. Uebung
*/

#ifndef INTERVALL_H
#define INTERVALL_H

#include "Grenze.h"
#include <iostream>
using namespace std;

class Intervall {
public:
	virtual ~Intervall();

	Grenze getLinks() const;
	Grenze getRechts() const;
	void setLinks(const Grenze&);
	void setRechts(const Grenze&);
	bool istLeer() const;
	void setLeer(bool);

	virtual bool istGleich(const Intervall&) const;
	virtual bool istTeilmengeVon(const Intervall&) const;

	virtual bool enthaelt(const double&) const = 0;
	virtual bool istEchteTeilmengeVon(const Intervall&) const = 0;

protected:
	Grenze links, rechts;
	bool leer;
};

ostream& operator<<(ostream& aus, const Intervall& in);
istream& operator >> (istream& ein, Intervall& in);

// beidseitig offenes Intervall
class OIntervall : public Intervall {
public:
	OIntervall(const double&, const double&);
	virtual ~OIntervall();

	virtual bool enthaelt(const double&) const;
	virtual bool istEchteTeilmengeVon(const Intervall&) const;
};

// beidseitig abgeschlossenes Intervall
class AIntervall : public Intervall {
public:
	AIntervall(const double&, const double&);
	AIntervall(const double&); // {wert}
	virtual ~AIntervall();

	virtual bool enthaelt(const double&) const;
	virtual bool istEchteTeilmengeVon(const Intervall&) const;
};

// links offenes Intervall
class LOIntervall : public Intervall {
public:
	LOIntervall(const double&, const double&);
	virtual ~LOIntervall();

	virtual bool enthaelt(const double&) const;
	virtual bool istEchteTeilmengeVon(const Intervall&) const;
};

// rechts offenes Intervall
class ROIntervall : public Intervall {
public:
	ROIntervall(const double&, const double&);
	virtual ~ROIntervall();

	virtual bool enthaelt(const double& x) const;
	virtual bool istEchteTeilmengeVon(const Intervall&) const;
};

#endif //INTERVALL_H
