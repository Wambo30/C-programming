/**
NUTZEN projekt 4 für blatt21aufg2!!!

* Prog1b WS2017/18
* 4. Projekt: kleiner Shellrechner
Dateiname: Tokgoez_Wahidfar_4.cpp
*
* Autoren:
Tokgoez, Ekrem	Mtklnr: 841 530
*	Wahid Far, Okhtay Mtklnr: 870 485

Algorithmische Strategie:

Level 1: Hier haben wir mit Konstanten die Literale für folgende Operationen festgelegt:
also für die Addition, Subtraktion, Division, Multiplikation.

Level 2:
1)Testfkt zur Feststellung ob x eine natürliche Zahl ist. Der Input ist eine Gleitkommazahl x.
Der Datentyp des Outputs ist ein boolescher Wert.
2)Definition der reellen Modulofkt, wobei der Input zwei Gleitkommazahlen x und y sind.
Der Output hat den Datentyp double also ist eine Gleitkommazahl.

Level 3:Berechnung des größten gemeinsamen Teiler, wobei der Input zwei ganze Zahlen m und n mit
Datentyp long long sind. Der Datentyp des Outputs ist long long.

Level 4: Berechnung des Binomialkoeffizienten, wobei der Input zwei ganze Zahlen n und k sind.
Der Datentyp des Outputs ist long long.


*/

#include <iostream>
using namespace std;


// (Level 2) ist x eine natürliche Zahl?
/*
Hier haben wir eine Testfkt, um zu bestimmen ob x eine natürliche Zahl ist.
Der Input ist eine Gleitkommazahl x. Da x von double in int umgewandelt wird, wird x abgerundet.
Daher existieren keine Nachkommastellen mehr. Zudem wird das abgerundete x in y gespeichert.

Falls x <0 oder x-y>0  gilt, dann ist x keine natürliche Zahl.Andernfalls ist x eine natürliche
Zahl.

*/
bool istNatuerlich(double x)		//Eingabe von Gleitkommazahl
{
	int y = x;		//Datentyp double wird zu int , daher entsteht eine Abrundung von x
	if (x < 0 || x - y >0)
		return false;		// falls x eine Gleitkommazahl ist 
	return true;			//falls x>0 und x Integer ist
}	// ENDE istNatuerlich()


	// (Level 2) reelle Modulofunktion
	/*
	Der Input sind zwei Gleitkommazahlen x und y. Der Quotient x/y wird durch die Datentypumwandlung
	von double in int abgerundet.
	Falls für diesen abgerundeten Quotienten x/y > 0 gilt, dann wird die Modulofkt wie gewöhnlich
	ausgeführt und gibt den Rest aus.
	Falls für diesen abgerundeten Quotienten x/y < 0 gilt, dann wird durch die Datentypumwandlung
	von double in int falsch abgerundet. Daher addieren wir den Quotienten mit -1 , um eine korekte
	Abrundung entgegen gesetzt zum Ursprung zu bezwecken.

	*/
double mod(double x, double y)	//Eingabe von zwei  Gleitkommazahlen
{
	if (int(x / y) > 0)
		return x - int(x / y) *y;	//wenn x mod y nach Abrundung ist
	else
		return x - int(x / y - 1)*y;	//wenn x mod y negativ, dann wird um -1 aufgerundet 								
}  // ENDE mod()


   // (Level 3) größter gemeinsamer Teiler
   /*
   Der Input sind zwei ganze Zahlen m und n. Falls m ungleich n gilt, so wird die Funktion
   ausgeführt. Andernfalls wird m ausgeben.
   Wenn m ungleich n gilt, dann können folgende Fälle auftreten.

   Fall 1: m > n , dann wird m-n in m gespeichert.
   Fall 2: n > m , dann wird n-m in n gespeichert.

   Jeweils beide Vorgänge werden solange wiederholt, bis die Bedingung im Whileschleifenkopf
   falsch ist. Daraufhin wird der ggT also m ausgegeben.
   */
long long ggT(long long m, long long n)	// Eingabe von zwei ganzen zahlen
{
	while (m != n)		//falls m ungleich n gilt
	{
		if (m > n)
			m = m - n;	// positives Ergebnis in m gespeichert
		else
			n = n - m;	//andernfalls Ergebnis in n gespeichert
	}
	return m;	// ausgabe größter gemeinsamer Teiler

}  // ENDE ggT()


   // (Level 4) Binomialkoeffizient "n über k"
   /*
   Der Input sind zwei integer n und k. Falls k==0 oder k==n gilt, so wird 1 ausgegeben.
   Falls k >0 gilt, dann wird nach folgendem Gesetz der Binomialkoeffizient berechnet:
   (n*(n-1)*...*(n-k+1))/k!
   Der Wert des Binomialkoeffizienten wird in ergebnis abgespeichert.

   */
long long binom(int n, int k)
{
	long long ergebnis = 1;	 //initialisierung von ergebnis

	if (k == 0 || k == n)	//falls k==0 oder k == n gilt, so wird 1 ausgegeben
		return 1;

	else

		if (k > 0)		//falls k > 0 gilt
		{
			for (int i = 1; i <= k; i++)
				ergebnis = ergebnis * (n - i + 1) / i;	//Berechnung des Binomialkoeffizienten
			return ergebnis;		//Ausgabe Binomialkoeffizient
		}
}  // ENDE binom()


   /***  Hauptprogramm  *************************************************/

   //Level 1: globale Konstanten
   /*
   Hier haben wir die globalen Konstanten für die Main Methode festgelegt, die im gesamten Code und
   von jeder einzelnen Funktion im Programm abgerufen werden können.
   Für Level 1 haben wir die globalen Konstanten für die Addition, Subtraktion, Division und
   Multiplikation festgelegt.
   */
char const ADDITION = '+'; // globale Konstante für Addition
char const SUBTRAKTION = '-'; // globale Konstante für Subtraktion
char const MULTIPLIKATION = '*'; // globale Konstante für Multiplikation
char const DIVISION = '/'; // globale Konstante für Division
char const MODULAR = '%'; // globale Konstante für Modular
char const GEMEINSAMER_TEILER = 'g'; // globale Konstante für größter gemeinsamer Teiler
char const GEM_TEILER = 'G';		// globale Konstante für größter gemeinsamer Teiler
char const BIONOMIAL_KOEFFIZIENT = 'b';		//globale Konstante für Binomialkoeffizient
char const BINOM_KOEFF = 'B';		//globale Konstante für Binomialkoeffizient


int main(/**
 * Prog1b WS2017/18
 * 4. Projekt: kleiner Shellrechner
	Dateiname: Tokgoez_Wahidfar_4.cpp
 *
 * Autoren: 
	Tokgoez, Ekrem	Mtklnr: 841 530
 *	Wahid Far, Okhtay Mtklnr: 870 485
 
 Algorithmische Strategie:

Level 1: Hier haben wir mit Konstanten die Literale für folgende Operationen festgelegt: 
also für die Addition, Subtraktion, Division, Multiplikation.

Level 2: 
1)Testfkt zur Feststellung ob x eine natürliche Zahl ist. Der Input ist eine Gleitkommazahl x.
Der Datentyp des Outputs ist ein boolescher Wert.
2)Definition der reellen Modulofkt, wobei der Input zwei Gleitkommazahlen x und y sind.
Der Output hat den Datentyp double also ist eine Gleitkommazahl.

Level 3:Berechnung des größten gemeinsamen Teiler, wobei der Input zwei ganze Zahlen m und n mit
Datentyp long long sind. Der Datentyp des Outputs ist long long.

Level 4: Berechnung des Binomialkoeffizienten, wobei der Input zwei ganze Zahlen n und k sind.
Der Datentyp des Outputs ist long long.


 */

#include <iostream>
using namespace std ;


// (Level 2) ist x eine natürliche Zahl?
/*
Hier haben wir eine Testfkt, um zu bestimmen ob x eine natürliche Zahl ist.
Der Input ist eine Gleitkommazahl x. Da x von double in int umgewandelt wird, wird x abgerundet.
Daher existieren keine Nachkommastellen mehr. Zudem wird das abgerundete x in y gespeichert.

Falls x <0 oder x-y>0  gilt, dann ist x keine natürliche Zahl.Andernfalls ist x eine natürliche
Zahl.

*/
bool istNatuerlich ( double x )		//Eingabe von Gleitkommazahl
{
	int y = x;		//Datentyp double wird zu int , daher entsteht eine Abrundung von x
	if (x < 0 || x - y >0)	
		return false;		// falls x eine Gleitkommazahl ist 
	return true ;			//falls x>0 und x Integer ist
}	// ENDE istNatuerlich()


// (Level 2) reelle Modulofunktion
/*
Der Input sind zwei Gleitkommazahlen x und y. Der Quotient x/y wird durch die Datentypumwandlung
von double in int abgerundet.
Falls für diesen abgerundeten Quotienten x/y > 0 gilt, dann wird die Modulofkt wie gewöhnlich
ausgeführt und gibt den Rest aus.
Falls für diesen abgerundeten Quotienten x/y < 0 gilt, dann wird durch die Datentypumwandlung
von double in int falsch abgerundet. Daher addieren wir den Quotienten mit -1 , um eine korekte
Abrundung entgegen gesetzt zum Ursprung zu bezwecken.

*/
double mod ( double x, double y )	//Eingabe von zwei  Gleitkommazahlen
{
	if ( int(x / y) > 0 )
		return x - int(x / y) *y;	//wenn x mod y nach Abrundung ist
	else
		return x - int(x / y - 1)*y;	//wenn x mod y negativ, dann wird um -1 aufgerundet 								
}  // ENDE mod()


// (Level 3) größter gemeinsamer Teiler
/*
Der Input sind zwei ganze Zahlen m und n. Falls m ungleich n gilt, so wird die Funktion
ausgeführt. Andernfalls wird m ausgeben.
Wenn m ungleich n gilt, dann können folgende Fälle auftreten.

Fall 1: m > n , dann wird m-n in m gespeichert.
Fall 2: n > m , dann wird n-m in n gespeichert.

Jeweils beide Vorgänge werden solange wiederholt, bis die Bedingung im Whileschleifenkopf
falsch ist. Daraufhin wird der ggT also m ausgegeben.
*/
long long ggT ( long long m, long long n )	// Eingabe von zwei ganzen zahlen
{
	while (m != n)		//falls m ungleich n gilt
	{
		if (m > n)
			m = m - n;	// positives Ergebnis in m gespeichert
		else
			n = n - m;	//andernfalls Ergebnis in n gespeichert
	}
	return m;	// ausgabe größter gemeinsamer Teiler
	
}  // ENDE ggT()


   // (Level 4) Binomialkoeffizient "n über k"
   /*
   Der Input sind zwei integer n und k. Falls k==0 oder k==n gilt, so wird 1 ausgegeben.
   Falls k >0 gilt, dann wird nach folgendem Gesetz der Binomialkoeffizient berechnet:
   (n*(n-1)*...*(n-k+1))/k!
   Der Wert des Binomialkoeffizienten wird in ergebnis abgespeichert.
   
   */
long long binom(int n, int k)
{
	long long ergebnis = 1;	 //initialisierung von ergebnis

	if (k == 0 || k == n)	//falls k==0 oder k == n gilt, so wird 1 ausgegeben
		return 1;

	else

		if (k > 0)		//falls k > 0 gilt
		{
			for (int i = 1; i <= k; i++)		
				ergebnis = ergebnis * (n - i + 1) / i;	//Berechnung des Binomialkoeffizienten
			return ergebnis;		//Ausgabe Binomialkoeffizient
		}
}  // ENDE binom()


/***  Hauptprogramm  *************************************************/

//Level 1: globale Konstanten
/*
Hier haben wir die globalen Konstanten für die Main Methode festgelegt, die im gesamten Code und 
von jeder einzelnen Funktion im Programm abgerufen werden können.
Für Level 1 haben wir die globalen Konstanten für die Addition, Subtraktion, Division und 
Multiplikation festgelegt.
*/
char const ADDITION = '+' ; // globale Konstante für Addition
char const SUBTRAKTION = '-' ; // globale Konstante für Subtraktion
char const MULTIPLIKATION = '*' ; // globale Konstante für Multiplikation
char const DIVISION = '/' ; // globale Konstante für Division
char const MODULAR = '%'; // globale Konstante für Modular
char const GEMEINSAMER_TEILER = 'g'; // globale Konstante für größter gemeinsamer Teiler
char const GEM_TEILER = 'G';		// globale Konstante für größter gemeinsamer Teiler
char const BIONOMIAL_KOEFFIZIENT = 'b';		//globale Konstante für Binomialkoeffizient
char const BINOM_KOEFF = 'B';		//globale Konstante für Binomialkoeffizient


int main (int narg, char* argv[])
{
	// gebe kurze Bedienungsanleitung aus
	cout << "Gib eine Rechenaufgabe ein:  x op y" << endl ;
	cout << "x, y sind reelle Zahlen" << endl ;
	cout << "Rechenoperatoren:  op = '+' '-' '*' '/' '%'" << endl ;
	cout << "nur fuer natuerliche x, y:" << endl ;
	cout << "    op = 'g' 'G' : ggT( x, y )" << endl ;
	cout << "    op = 'b' 'B' : binom( x, y )" << endl ;
	cout << "Ende, wenn x = y = 0 ist oder op eine Ziffer." << endl ;
	cout << endl ;

	while ( true )
	{
		double x, y ;	//Deklaration von x und y
		char   op ;		// Deklaration von op, was ein Platzhalter für Operator ist

		// gebe Prompt aus, lese Ausdruck von Tastatur ein
		cout << "x op y = " ;
		cin >> x >> op >> y ;

		// prüfe ob Schluss gemacht werden soll 
		if ((x == 0 && y == 0) || ('0' <= op && op <= '9'))
			break;
		
		// berechne den Ausdruck, gebe Ergebnis aus
		switch ( op )
		{
		case ADDITION:
			cout << x + y << endl;
			break;

		case SUBTRAKTION:
			cout << x - y << endl;
			break;

		case MULTIPLIKATION:
			cout << x*y << endl;
			break;

		case DIVISION: 
			if (y != 0)
				cout << x / y << endl;
			else
				cerr << "kann nicht durch 0 dividiert werden. " << endl;
			break;

		case MODULAR:
			if (y != 0)
				cout << mod(x, y) << endl;
			else
				cerr << "kann nicht durch 0 dividiert werden. " << endl ;
			break;

		case GEM_TEILER:
		case GEMEINSAMER_TEILER: 
			if ((x== int(x)) && (x > 0) 
				&& (y == int(y)) && (y > 0))
				cout << ggT( x, y ) << endl;
				
			else
				cerr << "x,y muessen natuerliche Zahlen sein!" << endl;
			break;

		case BIONOMIAL_KOEFFIZIENT:
		case BINOM_KOEFF: 
			if ((x == int(x))
				&& (y == int(y))
				&& (x >= y))
				cout << binom(x, y) << endl;
			else
				cerr << "x,y muessen natuerliche Zahlen sein mit x >= y !" << endl;
			break;


		default: 
			cerr << op << "Operator nicht erkannt!" << endl;

		}  // ENDE switch ( op ) 
		cout << endl; //Ausgabe mit Zusatzzeile am Ende
	}  // ENDE while ( true )

	return 0 ;     // alles OK

}  // ENDE main()



)
{
	// gebe kurze Bedienungsanleitung aus
	cout << "Gib eine Rechenaufgabe ein:  x op y" << endl;
	cout << "x, y sind reelle Zahlen" << endl;
	cout << "Rechenoperatoren:  op = '+' '-' '*' '/' '%'" << endl;
	cout << "nur fuer natuerliche x, y:" << endl;
	cout << "    op = 'g' 'G' : ggT( x, y )" << endl;
	cout << "    op = 'b' 'B' : binom( x, y )" << endl;
	cout << "Ende, wenn x = y = 0 ist oder op eine Ziffer." << endl;
	cout << endl;

	while (true)
	{
		double x, y;	//Deklaration von x und y
		char   op;		// Deklaration von op, was ein Platzhalter für Operator ist

						// gebe Prompt aus, lese Ausdruck von Tastatur ein
		cout << "x op y = ";
		cin >> x >> op >> y;

		// prüfe ob Schluss gemacht werden soll 
		if ((x == 0 && y == 0) || ('0' <= op && op <= '9'))
			break;

		// berechne den Ausdruck, gebe Ergebnis aus
		switch (op)
		{
		case ADDITION:
			cout << x + y << endl;
			break;

		case SUBTRAKTION:
			cout << x - y << endl;
			break;

		case MULTIPLIKATION:
			cout << x*y << endl;
			break;

		case DIVISION:
			if (y != 0)
				cout << x / y << endl;
			else
				cerr << "kann nicht durch 0 dividiert werden. " << endl;
			break;

		case MODULAR:
			if (y != 0)
				cout << mod(x, y) << endl;
			else
				cerr << "kann nicht durch 0 dividiert werden. " << endl;
			break;

		case GEM_TEILER:
		case GEMEINSAMER_TEILER:
			if ((x == int(x)) && (x > 0)
				&& (y == int(y)) && (y > 0))
				cout << ggT(x, y) << endl;

			else
				cerr << "x,y muessen natuerliche Zahlen sein!" << endl;
			break;

		case BIONOMIAL_KOEFFIZIENT:
		case BINOM_KOEFF:
			if ((x == int(x))
				&& (y == int(y))
				&& (x >= y))
				cout << binom(x, y) << endl;
			else
				cerr << "x,y muessen natuerliche Zahlen sein mit x >= y !" << endl;
			break;


		default:
			cerr << op << "Operator nicht erkannt!" << endl;

		}  // ENDE switch ( op ) 
		cout << endl; //Ausgabe mit Zusatzzeile am Ende
	}  // ENDE while ( true )

	return 0;     // alles OK

}  // ENDE main()



