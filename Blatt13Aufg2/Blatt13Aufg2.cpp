
/*
aufgabe 2 blatt 13:

2. ASCII-Tabelle. Lassen Sie sich die ASCII-Tabelle zwischen den Zeichen Nr. 33-126 so ausgeben,
dass immer 6 Zeichen mit ihren ASCII-Werten nebeneinander erscheinen:
33 !   34 "   35 #   36 $   37 %   38 &
39 '   40 (   41 )   42 *   43 +   44 ,
...
(Tipp: Spendieren Sie zwei Variablen, die parallel hochgezahlt werden.)



*/



#include <iostream>
using namespace std;

int main()
{
	char zeichen = '!'; 
	// ausgabe ---> ist char dh es werden die chars die in ascii tabelle so gespeichert sind
	//abgelaufen
	for (int ascii = 33; ascii <= 126; ++ascii)
	{
		cout << "    " << ascii << zeichen << endl; 
		// hier entsteht freie spalte links
		//cout << ascii << endl; --> mit diesem code entsteht keine freie spalte links
		if (ascii % 6 == 2)
			cout << endl;
		// ab dem if soll eine leere zeile ausgegeben werden für geweissen überblick
		//dh wenn endrest von modulorechnung 2 ist dann wird leere zeile ausgegeben
		zeichen++;
	}
	cout << endl;

	// besserer code
	/*
	for (int ascii = 33; ascii <= 126; ++ascii)
	{
		char zeichen = ascii;
		//ausgabe --> ist char wobei die int zahl hierbeiu dem zeichen zugewiesen wird

		cout << "    " << ascii << " " << zeichen;
		if (ascii % 6 == 2)
			cout << endl;
	}
	cout << endl;

	*/


	return 0;
}