#include <iostream>
using namespace std;


int main() {
	double dwert = 1.7;
	double* dz = &dwert;

	*dz = 5.6;
	//dwert kriegt wert 1.7

	double &dwert2 = dwert;
	dwert2 = 1.7;
	// dwert = 1.7 dh haben wieder geändert

	int iwert = 11;
	int *zi1, zi2; // zi2 ist vom typ int und nicht int*
	int &ri = zi2; // &ri ist wie zi2 also ist alias dafür dh zweiter name 

	// FALSXH zi2 = &iwert da geht nicht da int = int* 
	// korrekt wäre
	zi2 = iwert;

	// zi1 = ri FALSXH da int* = int

	// korrekt wäre
	//frage: geht auch *zi1 = 4 ?eigentlich nicht da zi1 keiner adresse zugewiesen wird

	zi1 = &ri;// adresse von ri wird zi1 zugreweisen da zi1 davor als zeiger def wurde
	*zi1 = ri;// wert von ri wird *zi1 zugewiesen
	*zi1 = 3;
	cout << ri << endl; // ri hat wert 3

	//was ist wenns const ist? also const *zi1 gilt man kann wert von *zi1



	zi2 = iwert;
	
	// FALSXH	ri = &iwert;  geht nicht da int = *int
	//korrekt wäre
	ri = iwert;


//FALSCH	dz = zi1 da double* = int* dh da double 8 bytes und int 4 bytes hat
//kann man das nicht einander zuweisen
	
	//korrekt wäre
	*dz = *zi1; // 


	// probeklausur aufg 1.8
	float varA = 0.1;
	float varB = 3.2;
	float *zvar = &varA;
	float &varC = varA;
	cout <<"ausgabe varC wegen &varC = varA: " <<varC << endl;
	cout << "ausgabe &varC: " << &varC << endl;
	// dh durch &varC = varA wird varC ein alias von varA dh varC == varA
	// schreibweise ist hierzu bissel ungewohnt aber ist korrekt1!

	*zvar = -2.3;
	varC = varB;
	cout << "ausgabe varC wegen &varC = varA: " << varA << endl;






	system("pause");
	return 0;
}
