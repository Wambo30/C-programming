/*

4.aufgabe) Schreiben Sie eine Funktion mittelPositiv() , die ein Array double const zahlen[]
mit beliebigen Werten und dessen Lange als Parameter ubergeben bekommt. Sie zahlt, wieviele
Eintrage im Array echt positiv(> 0) sind und gibt diese Anzahl sowie den Mittelwert dieser
Eintrage zuruck.Das Problem hier sind die beiden gewunschten Ruckgabewerte. Mehr als einen 
konnen wir in C++ prinzipiell nicht von einer Funktion mittels return
zuruck geben lassen. Als Ausweg konnen wir aber einer Funktion Variablenubergeben, in die sie 
etwas Bestimmtes hinein schreiben soll. Uberlegen Sie, welche Deklaration
mittelPositiv() haben kann, um diese Aufgabe zu erfullen.
Lassen Sie Ihre Funktion in main()
auf einem Beispiel-Array von beliebig initialisierten Zahlen laufen und geben Sie die beiden Ergebnisse in
main() aus, nicht in der Funktion mittelPo- sitiv()
selbst. Z.B. so:
double const zahlen[] = { 0, 2, -3, 5, -8 } ;
←
die Input-Zahlen
Anzahl pos. Zahlen = 2
←
Ausgabe in
main() ihr Mittelwert     = 3.5
̈
Uberlegen Sie auch was passieren soll, wenn das Array keine positiven Werte enthalt



*/





#include <iostream>
using namespace std;

void mittelPositiv (double const array[], int arrayLaenge, int& nPositivWerte, double& mittelwert);

int main()
{
	double const zahlen[] = { 0 , 2 , -3, 5 , -8 };
	double mittelwert = 0;
	int anzahlPositiv = 0;

	mittelPositiv (zahlen, 5, anzahlPositiv, mittelwert);

	cout << "anzahl pos. zahlen: " << anzahlPositiv << endl
	<< "Ihr Mittelwert: " << mittelwert << endl;



	return 0;
}

void mittelPositiv(double const array[], int arrayLaenge, int& anzahlPositiv, double& mittelwert)
{
	for (int i =0 ; i < arrayLaenge ; i++)
		if (array[i] > 0)
		{
			mittelwert += array[i];
			anzahlPositiv++;
		}

	if (anzahlPositiv > 0)
		mittelwert /= anzahlPositiv;
	else
		mittelwert = 0;


}