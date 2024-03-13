#include <cstdlib>      // für atoi()
#include "artikel.h"


int main(int narg, char* argv[])
{
	/***  gebe ggf. Usage aus  ***/

	if (narg < 4								// nicht genug Argumente
		|| atoi(argv[2]) < 10					// breite zu klein
		|| atoi(argv[3]) <  1					// nSpalten zu klein
		|| (atoi(argv[3]) > 1			// wenn mehr als 1 Spalte,
			&& (narg < 5					//    muss zwRaum >= 1
				|| atoi(argv[4]) < 1		//    gegeben sein
				)))
	{
		cout << "usage: " << argv[0]
			<< " dateiName breite nSpalten zwRaum" << endl;
		cout << "       dateiName: Name einer ASCII-Datei" << endl;
		cout << "       breite   : ganze Zahl >= 10" << endl;
		cout << "       nSpalten : ganze Zahl >=  1" << endl;
		cout << "       zwRaum   : ganze Zahl >=  1" << endl;
		cout << "Liest die Datei dateiName und schreibt sie auf" << endl;
		cout << "cout mit breite Zeichen, nSpalten Spalten mit" << endl;
		cout << "zwRaum Leerzeichen zwischen den Spalten." << endl;

		return 0;
	}

	/***  lese Datei in einen String ein  ***/

	char const* dateiName = argv[1];
	string      rohartikel = leseArtikel(dateiName);
	//string    rohartikel =
	//"Das Trennzeichen in \"Erprobung\" muss verschwinden und die beiden Absaetze muessen optisch getrennt bleiben.";

	if (rohartikel.empty())
		cerr << "kann Datei " << dateiName << " nicht oeffnen!" << endl;

	/***  gebe ganzen Artikel im Spaltensatz auf cout aus  ***/

	else
	{
		// gebe zur Kontrolle den Rohartikel aus
		if (rohartikel.size() <= 400)
		{
			cout << "Rohartikel:" << endl;
			cout << string(40, '-') << endl;
			cout << rohartikel << endl;
			cout << string(40, '-') << endl;
			cout << endl;
		}

		// lese Kommandozeilenargumente
		size_t breite = atoi(argv[2]);
		size_t nSpalten = atoi(argv[3]);
		size_t zwRaum = 1;
		if (nSpalten > 1)
			zwRaum = atoi(argv[4]);

		// erzeuge Mehrspaltensatz
		schreibeArtikel(rohartikel, breite, nSpalten, zwRaum);
	}

	return 0;

}  // main()