//  main.cpp
//  prog2A-uebung-2-Rational

#include "Rational.h"
#include <iostream>
using namespace std;

int main() {
    Rational b1(1,2), b2(1,4), b3;
    long z = 7;
    
    b3 += z;
    
    cout << b3 << endl;
    
    /*
    cout << "Ein neuer Bruch: " << endl;
    cin >> b2;
    cout << "Die rationale Zahl: " << b2 << endl;
    */
    
    //b3 /= 0;
    
    cout << b3 << "  " << b2 << endl;
    b3 = b2++;
    cout << b3 << "  " << b2 << endl;
    b3 = ++b2;
    cout << b3 << "  " << b2 << endl;
    
    b1+= z;
    if( b1 < z) {
        cout << b1 << " < " << z << endl;
    }
    else {
        cout << b1 << " >= " << z << endl;
    }
    
    b1 = 7;
    
    cout << -b3 << endl;
    
    

    return 0;
}
