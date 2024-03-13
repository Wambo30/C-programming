
#include "Header‹b1Aufg1.h"

/*
double maxBerechnen(double x, double y)
{
if (x < y)
{
return y;
}
return x;
}

double Aufg11()
{

//pow (base, exponent)


double x;
int n;
//n > 0;
cout << " gib x ein:" << endl;
cin >> x ;
cout << " gib n > 0 ein:" << endl;
cin >> n;

double m = pow(n, 2);
double i = maxBerechnen(pow(x, 3), -(1 / m));
// fmax == max im mathem. sinne

cout <<"Ausgabe Aufg1.1: "  << i << endl;
return i;
}
*/

// nochmal anschauen--> bricht nicht ab ! 
/*
double Aufg12 ()
{
double x;
int n;

cout << " gib x ein:" << endl;
cin >> x;
do {
cout << " gib n > 0 ein:" << endl;
cin >> n;
}
while (n > 0);

double ergebnis = 0;
for (double k = 0; ; )
{
double m = (1 - (x / n));
double ergebnis = m * m;
}

cout<< "Ausgabe Aufg1.2 :" << ergebnis << endl;
return ergebnis;
}
*/

/*
int Aufg13()
{

// array def int <nameArray>[<grˆﬂeArray>]


}


double Aufg14()
{

// wie soll man (-1)^k bestimmmen?
int k;
//k >= 0;
double a = pow(-1, k) / pow(2 * k - 1, 2);

}
*/

/*
double SummenBerAufg2punkt1(double x, int n)
{
	
	for (int k = 0; k < n; k++)
	{
		double summenzeichen = (x - (pow(-1, k) / (n + 1)));
		double ergebnis1 =+ summenzeichen;
		cout << "Ausgabe Summe: " << ergebnis1 << endl;
		return ergebnis1;
	}
	
}
*/

///*
double ProzedurAufg2punkt2()
{


	return 0;
}

double Aufg2(double x, int n)
{
	//double x; // double == da reele zahlen
	//int n;

	//if ( n > 0)
	//{
		cout << " gib x ein:" << endl;		// ausgabe
		cin >> x;
		cout << " gib n > 0 ein:" << endl;
		cin >> n;		// eingabe
		if (n <= 0)
		{
			cout << "es muss n>0 gelten!" << endl;
			return 0;
		}
		

	// summe bestimmen bzgl 2.1
	for (int k = 0; k < n; k++)
	{
		//durchlauf der summe
		double summenzeichen = (x - (pow(-1, k) / (n + 1)));
		double ergebnis1 = +summenzeichen;
		//speichern jedes einzelergebnisses in array als einzelnen eintrag
		//muss dynamischer array sein da es sonst nicht geht!!
		int const L‰ngeArray = n;
		//double ErgebnisArray[L‰ngeArray];
		double* ErgebnisArray = new double[];

		cout << "Ausgabe Summe: " << ergebnis1 << endl;
		return ergebnis1;
	}



	
	//if (n < 0)
	//{
	//cout << "n>0 muss gelten" << endl;
	//return;
	//}
	

	//double* ErgebnisArray = new double[n];
	//double z =SummenBerAufg2punkt1(x,n);


	return 0;
}
//*/
