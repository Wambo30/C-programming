//  main.cpp
//  prog2A-uebung-2-Rational
// hier gehts ums überladen

#include "Rational2.h"
#include <iostream>
using namespace std;

int main() {
	Rational2 b1(1,2), b2(3,4), b3(2,3);
	

	//test 3
	cout << "TEST bzgl 3 mal const" << endl;
	Rational2 t1(2, 3), t2(8, 3),u;
	u = t1 + t2;// b1=b2.operator+(b3)
				 //b1.ausgeben();
	cout << u << endl;
	cout << "will u aendern" << endl;
	// u ändern heißt ich werde es in einem term weiter verwenden
	Rational2 t3(4, 3), t4(8, 3), u2;
	Rational2 t5;
	u2 += t3 ;
	// wegen unären minus
	//u + t3 = u2;
	// das geht nicht
	//-u2 = t3 + t4;
	//-u2 = t3;
	//t3 + (-t4) = u2;
	
	//das geht
	//u2 = t3 + (-t4) * t2;
	//u2 = -t3;
	//t3 + t4 = -u2;
	//t3 + t4 = u2 + t2;

	cout <<"ausgabe von u2: " << u2 << endl;
	u2 = -u2;

	cout <<"ausgabe von -u2: " << u2 <<endl;
	cout << endl;

	//wegen +=

	u2 += t3;
	//u2 + t4 += t3; // geht nicht
	//u2 + t4 = t4; //geht nicht

	// wegen *=
	//u2 + t4 *= t3; // geht nicht
	//u2 + t4 *= t4;

	// test += und +
	Rational2 t10(1, 2), t11(7, 2), t12(9, 2), t13(21, 2);
	u2 = t10 + t11;
	cout << "ausgabe u2= t10+t11: " << u2 << endl;

	t10 += t11;
	cout << "ausgabe t10+=t11: " << t10 << endl;

	u2 = t11 + 3;
	cout << "ausgabe t11+1: " << u2 << endl;
	cout << endl;
	// testen long + rational
	Rational2 t14(1, 2), t15(7, 2), t16(10, 2);
	int zahl1 = 4;
	t14 = zahl1 + t15 ;
	cout << t14 << endl;

	

/*


	b1 += b2;//b1.addieren(b2)
	//b1.ausgeben(); 
	cout << b1 << endl;


		//Rational2 b1(1, 2), b2(1, 4), b3;
		long z = 7;

		b3 += z;

		cout << b3 << endl;

		
		//cout << "Ein neuer Bruch: " << endl;
		//cin >> b2;
		//cout << "Die rationale Zahl: " << b2 << endl;
		

		//b3 /= 0;

		cout << b3 << "  " << b2 << endl;
		b3 = b2++;
		cout << b3 << "  " << b2 << endl;
		b3 = ++b2;
		cout << b3 << "  " << b2 << endl;

		b1 += z;
		if (b1 < z) {
			cout << b1 << " < " << z << endl;
		}
		else {
			cout << b1 << " >= " << z << endl;
		}

		b1 = 7;

		cout << -b3 << endl;


	//test 2
	//b3.subtrahieren(b2);
	b3 -= b2;
	//b3.ausgeben();
	cout << b3 << endl;

	cout << endl;

	//test 3
	cout << "TEST bzgl 3 mal const" << endl;
	b1 = b2 + b3;// b1=b2.operator+(b3)
	//b1.ausgeben();
	cout << b1 << endl;

	cout << endl;



	//test 4
	b1 = b2 + 3 + b3;
	//b1.ausgeben();
	cout <<"test 4: "<<b1 << endl;

	//test 5

	b1 = b2 - b3;
	cout << "ausgabe von b1= b2-b3 <==> b1= " << b1 << endl;

	//test 6
	b2 *= b3;
	cout << "ausgabe b2 *= b3 also b1= " << b2 << endl;

	//test 7
	b2 /= b3;
	cout << "ausgabe b2/=b3 also b2= " << b2 << endl;

	//test 8 

	if (b1 <= b2) {
		cout << b1 + b2 << endl;
	}

	// test 9
	cout << b1 << "" << b2 << endl;
	b2 = b1++;
	cout << b1 << "" << b2 << endl;
	b2 = ++b1;


	//tst 10 
	//will mehere rat zahlen addieren und einer variable zuweisen
	Rational2 b4;
	//b4 = b1 + b2 + b3;
	//cout <<"ausgabe b4: " << b4 << endl;
	-b4;
	cout << "ausgabe -b4 mit unaeren minus: " << b4 << endl;
	*/

	system("pause");

	return 0;
}
