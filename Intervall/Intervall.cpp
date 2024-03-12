/*
 *  Intervall.cpp
 *  ProgIIb-Projekt3
 *
 */

#include "Intervall.h"
#include <float.h> // wegen DBL_EPSILON
#include <cmath>

using namespace std;

inline Grenze max(Grenze a, Grenze b) { return ( a < b ) ? b : a; }
inline Grenze min(Grenze a, Grenze b) { return ( a < b ) ? a : b; }

Intervall::~Intervall() {}

Grenze Intervall::getLinks() const { 
        return links; 
}

Grenze Intervall::getRechts() const { 
    return rechts; 
}

bool Intervall::istLeer() const { return leer; }

void Intervall::setLinks(const Grenze& l) {
    links = l;
}

void Intervall::setRechts(const Grenze& r) {
	rechts = r;
}

void Intervall::setLeer(bool l) {
    leer = l;
}

bool Intervall::istGleich(const Intervall& a) const {
    return (links == a.links && rechts == a.rechts);
}

bool Intervall::istTeilmengeVon(const Intervall& a) const {
    return istGleich(a) || istEchteTeilmengeVon(a);
}

ostream& operator<<(ostream& aus, const Intervall& a) {
    if( !a.istLeer() ) {
        Grenze l = a.getLinks();
        Grenze r = a.getRechts();
        aus << " " << l.getKlammer() << l.getWert();
        if( l.getWert() != r.getWert() ) {
            aus << ", " << r.getWert();
        }
        aus << r.getKlammer() << " ";
    }
    else {
        //char l = 157;
        aus << "leer";
    }
    return aus;
}

/* OIntervall */
OIntervall::~OIntervall() {}

OIntervall::OIntervall(const double& l, const double& r) {
    if( l < r ) {
        Grenze lg(l, '(', false), rg(r, ')', false);
        links.set( lg);
        rechts.set( rg );
        leer = false;
    }
    else {
        leer = true;
    }
}

bool OIntervall::enthaelt(const double& x) const {
    return ( !leer && x > links.getWert()  && x < rechts.getWert() );
}

bool OIntervall::istEchteTeilmengeVon(const Intervall& a) const {
    if ( a.istLeer() || (*this).istGleich(a)  ) {
        return false;
    }
    if (leer) {
        return true;
    }
    Grenze alinks = a.getLinks();
    Grenze arechts = a.getRechts();
    if ( abs(alinks.getWert() - arechts.getWert() ) < DBL_EPSILON ) {
        return false;
    }
	return (alinks.getWert() <= links.getWert() && rechts.getWert() <= arechts.getWert()  );
}

/* AIntervall */
AIntervall::AIntervall(const double& l, const double& r) {
    if( l < r ) {
        links.set( Grenze(l, '[', true) );
        rechts.set( Grenze(r, ']', true) );
        leer = false; 
    }
    else if ( abs(l-r) <= DBL_EPSILON) {
        links.set( Grenze(l, '{', true) );
        rechts.set( Grenze(l, '}', true) );
        leer = false;
    }
    else {
        leer = true;
    }
}

AIntervall::AIntervall(const double& l) {
    links.set( Grenze(l, '{', true) );
    rechts.set( Grenze(l, '}', true) );
    leer = false;
}

AIntervall::~AIntervall() {}

bool AIntervall::enthaelt(const double& x) const {
    return (!leer && x >= links.getWert()  && x <= rechts.getWert() );
}

bool AIntervall::istEchteTeilmengeVon(const Intervall& a) const {
    if ( a.istLeer() || (*this).istGleich(a)  ) {
        return false;
    }
    if (leer) {
        return true;
    }
    return ( a.enthaelt(links.getWert()) && a.enthaelt(rechts.getWert()) );
}

/* LOIntervall */
LOIntervall::LOIntervall(const double& l, const double& r) {
    if( l < r ) {
        links.set( Grenze(l, '(', false) );
        rechts.set( Grenze(r, ']', true) );
        leer = false;
    }
    else {
        leer = true;
    }
}
LOIntervall::~LOIntervall() {}

bool LOIntervall::enthaelt(const double& x) const {
    return ( (!leer) && (x > links.getWert())  && (x <= rechts.getWert()) );
}

bool LOIntervall::istEchteTeilmengeVon(const Intervall& a) const {
    if ( a.istLeer() || (*this).istGleich(a)  ) {
        return false;
    }
    if (leer) {
        return true;
    }
    Grenze al = a.getLinks();
    return ( al.getWert() <= links.getWert() && a.enthaelt(rechts.getWert()) );
}

/* ROIntervall */
ROIntervall::ROIntervall(const double& l, const double& r) {
    if( l < r ) {
        links.set( Grenze(l, '[', false) );
        rechts.set( Grenze(r, ')', true) );
        leer = false;
    }
    else {
        leer = true;
    }
}
ROIntervall::~ROIntervall() {}

bool ROIntervall::enthaelt(const double& x) const {
    return (!leer && x >= links.getWert()  && x < rechts.getWert() );
}

bool ROIntervall::istEchteTeilmengeVon(const Intervall& a) const {
    if ( a.istLeer() || (*this).istGleich(a)  ) {
        return false;
    }
    if (leer) {
        return true;
    }
    Grenze ar = a.getRechts();
    return ( a.enthaelt(links.getWert())
             && rechts.getWert() <= ar.getWert()  );
}




