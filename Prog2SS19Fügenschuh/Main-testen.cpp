#include <iostream>
using namespace std;

//test 1 referenz
void erhoehe(int a) {
	// mal auch mit diesem wert testen
	//a = 10;
	a++;

}

//test 2 referenz
void methode(int zettel) {
	zettel = 10;
	//zettel++;
	//return zettel;

}

//test 3 referenz
void f(int p) {
	p = 10;
}

void f_ref(int& q) {
	 q = 11;
}

void f_const_ref(int const& r) {
	//r = 20;
}

//test 5 referenz

double& refMin(double& a, double& b) {
	return a <= b ? a : b;
/*
dh wenn a<=b wahr ist dann gilt a<=a, ansonsten gilt a=b
<=> if (a<=b)
		a=a;
	else
		a=b;
*/
}
/*
# double& refMin(double& , double& ) --> das reicht für den header aus als signatur
 also ohne objektname!

#double& refMin(double& a , double& b){
	return ....;
}

--> das 1. & ist extrem wichtig weil wir etwas ausgeben und die eingabe parameter 
auch & haben WENN wir denn direkt den wert im arbeitsspeicher ändern
 wollen!!

#double& refMin(double a , double b) --> würde auch gehen aber dann können wir eben den wert
 im arbeitsspeicher nicht ändern!

*/

//test 6 referenz

string& message() {
	static string str = "dieser string wird zurueckgegeben!";
	return str;

}


int main() {

	/*
	//test referenzverständnis
	int a = 5;
	erhoehe(a);
	cout << a << endl;
	*/

	/*
	//test2 referenz
	int zettel=5;
	//methode(zettel);
	 zettel = 7;
	cout << "ausgabe von zettel ohne methode: " << zettel << endl;
	//ethode(zettel);
	methode(zettel);
	cout <<"ausgabe von zettel mit methode: " <<zettel << endl;
	*/

	/*
	//test3 referenz

	int t;
	t = 0;
	f(t);
	cout << "ausgabe ohne referenz: " << t << endl;
	// hier hat sich nix geändert durch fkt da wir nur mit der kopie von t arbeiten

	f_ref(t);
	cout << "ausgabe mit referenz: " << t << endl;


	f_const_ref(t);
	cout << "ausgabe von const variable: " << t << endl;
	*/

	//test 4 referenz
	/*
	const int& cref = 10;
	//int& cref2 = cref;
	//--> das ist nicht möglich! dh man kann keine referenz bzgl eines konstanten
	//objektes erstellenkann AUßer dieses objekt ist selber konstant!
	cout << "ausgabe cref: " << cref << endl;
	
	const int& cref3 = cref;
	cout << "ausgabe cref3: " << cref3 << endl;
	
	//*/

	/*
	//test 5 referenz

	double x1 = 1.1, x2 = x1 + 0.5 , y;

	y = refMin(x1, x2);
	cout << " ausgabe x1: " << x1 << endl;
	cout << " ausgabe x2: " << x2 << endl;
	cout << " ausgabe minimum also y: " << y << endl;
	// bis hier hin alles wie gewohnt--> werte wurden noch nicht verändert

	++refMin(x1, x2);
	cout << " ausgabe x1 nach aenderung: " << x1 << endl;
	cout << " ausgabe x2 nach aenderung: " << x2 << endl;
	// ausgabe: x1= 2.1 , x2=1.6 warum? da nur das minimum um 1 erhöht wurde!
	// also das ergebnis des vergleichs so gesehen!

	++refMin(x1, x2);
	cout << " ausgabe x1 nach 2.aenderung: " << x1 << endl;
	cout << " ausgabe x2 nach 2.aenderung: " << x2 << endl;
	// ausgabe: x1=2.1, x2=2.6 warum? da nun x2= min nach zweiter ausführung der fkt

	++refMin(x1, x2) = 10.1;
	cout << " ausgabe x1 nach 3.aenderung: " << x1 << endl;
	cout << " ausgabe x2 nach 3.aenderung: " << x2 << endl;
	// ausgabe: x1=10.1, x2= 2.6, warum? da nun davor x1=2.1 also das min war und 
	//dann x1=10.1 zugewiesen wurde!

	cout << "ausgabe x1 nach zuweisung: " << x1 << endl;
	// ausgabe: x1=10.1


	++refMin(x1, x2) += 5.0; // y= y+5.0
	cout << " ausgabe x1 nach 4.aenderung: " << x1 << endl;
	cout << " ausgabe x2 nach 4.aenderung: " << x2 << endl;
	// ausgabe: x1=10.1, x2=7.6, warum?

	cout << "ausgabe x2 nach zuweisung: " << x2 << endl;
	// ausgabe: x2=8.6 aber müsste 7.6 da stehen! kp wieso 8.6 da steht

	*/


	// test 6 referenz
	message() = "das teste ich hier";
	message() += "mal gucken was kommt";
	cout <<"laenge von string: " << message().length() << endl;
	/*
	wir haben hier keine variable die man in die fkt eingibt --> daher extra
	objekt erstellung nicht nötig! 
	
	
	*/
	





	system("pause"); // HINREICHEND damit konsole stehen bleibt und ausgabe sehen kann
	return 0;
}