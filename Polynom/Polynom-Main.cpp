/*
 *  Polynom-Main.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 4
 */

#include "Polynom.h"
#include "RangeError.h"
#include <iostream>
using namespace std;

int main(void) {
    try {
        Polynom p1;
        Polynom p2(3);  
        Polynom p3(3,1.);
    
        cout << "p1: " << p1 << endl;
        cout << "p2: " << p2 << endl;
        cout << "p3: " << p3 << endl;
    
        p3[4] = -7;     // Den Koeffizienten a_4 auf -7 setzen
    }
    catch(out_of_range& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
