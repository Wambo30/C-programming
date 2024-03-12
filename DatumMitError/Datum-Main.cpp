/*
 *  Datum-Main.cpp
 *  Programmieren IIb - Uebung 4, Aufgabe 2
 *
 */

#include "DateError.h"
#include "Datum.h"

#include <iostream>
using namespace std;

int main(void) {
    try{
        int t, m, j;
        cout << "Tag Monat Jahr: ";
        cin >> t >> m >> j;  // Werte fuer t, m und j nacheinader mit 
                            // Leerzeichen getrennt eingeben
        
        Datum d(t,m,j);
        
        d.setTag(t + 20);
        cout << d << endl;
        
        d.setMonat(m + 9);
        cout << d << endl;
        
        d.setJahr(j - 30);
        cout << d << endl;
        
        d.setMorgen();
        cout << d << endl;
     }
     catch(DateError& er) {
        er.meldung();
    }
    
    return 0;
}















