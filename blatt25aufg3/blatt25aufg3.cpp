#include <iostream>
#include <string>
using namespace std;

/* fkt
input: hexzahl
output: dezimalahl

long long hex2dec(string const& ziffern)
{
	string const hexa1 = "0123456789abcdef";
	long long wert = 0;
	for (int i = 0; i < ziffern.size(); i++)
		wert = wert * 16 + ziffern[i];
	return wert;


}
*/



int main()
{

	//cout << hex2dec("deadbeef") << endl;

	

	string ziffern = "abcxdex";
	long long wert = 0;
	for (int i = 0; i < ziffern.size(); i++)	//beginn mit a == 97 ascii wert
		if ( (ziffern[i] >= 97 && ziffern[i] <= 102 ) || ( ziffern[i] >= 48 && ziffern[i] <= 57))
		{
		/* 48 <= 57 --> alles zwischen 0 und 9
			97 <= 102 --> alles zwischen a und f

			die bedingung ist wichtig da wir jene buchstaben ignorieren sollen, die nicht zwischen
			a und f liegen --> da macht der algorithmus einfach nix bei x zb

		*/
			ziffern[i] = ziffern[i] - 'a';
			ziffern[i] = ziffern[i] + 10 ;	// da a in hexa 10 ist-> das ist extrem wichtig da sonst
			// keine umwandlung zu dezimal zahl möglich ist!! grundlage für berechnung allgemein
			// für zahlen brauchen wir das ja nicht da wir ja so einfach mit zahlen rechnen können
		
			wert = wert * 16 + ziffern[i];	
			//allgemeine berechnung von hexa in dezimalzahl


			cout << wert << endl;
		}
	
	cout << wert << endl;
	
	
	



	return 0;
}