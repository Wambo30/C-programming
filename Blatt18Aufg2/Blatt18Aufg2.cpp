/*
name:pascal.cpp
aufgabe2 von blatt 18

*/

#include <iomanip>       // f ̈ur setw()
int main()
{
	// lese n ein
	int n;
	cout << "n = ";
	cin >> n;
	// merke Spaltenbreiten
	int spalte[67]                           // L ̈ange s.u.
	for (int k = 0; k <= n; ++k)
		spalte[k] = breite(binom(n, k)) + 1;
	spalte[k] = breite(binom(n, k)) + 1;
	// gebe Pascalsches Dreieck aus
	for (int m = 0; m <= n; ++m)            // Zeilen
	{
		for (int k = 1; k <= m; ++k)        // Spalten
			cout << setw(spalte[k]) << binom(m, k)
			setw(spalte[k]) << binom(m, k)
		cout << endl;
	}
	return 0;  // alles OK
}  // main()