/*
 *  Projekt2 - Median-Suche
 *  BildDatei.cpp
 *
 *  
 * Aysel Kannici    810560
 * Ekrem Tokgöz     841530
 * Okhtay Wahid Far 870485
 * Okan Bieber      874666
 *
 */

#include "BildDatei.h"

// txt-Datei mit Pixelinfo: x y grauwert in die Liste <vpixel> mit Pixeln speichern,
// dann die Matrix <mpixel> initialisieren
BildDatei::BildDatei(const char *dateiName) {
    ifstream eingabe(dateiName);
	if (!eingabe.is_open())   
		cerr << "Datei \"" << dateiName << "\" nicht gefunden." << endl;
	else {
		while( !eingabe.eof() ) {
			size_t x, y, w;
			eingabe >> x >> y >>  w;
            if( !eingabe.fail() ) {
                Pixel p(x,y,w);
                vpixel.push_back(p);
            }
		}
		eingabe.close();
    }
    
    // Die Eintraege aus vpixel in einer Matrix speichern
    xpix = vpixel[vpixel.size()-1].getX()+1;    // wegen 0 0 Pixel
    ypix = vpixel[vpixel.size()-1].getY()+1;
    
    // Speicherplatz fuer die Matrix anfordern
    mpixel = new size_t*[xpix];
    for(size_t i = 0; i < xpix; i++) {
        mpixel[i] = new size_t[ypix];
    }
    // Pixelwerte in die Matrix uebertragen
    for(size_t i = 0; i < vpixel.size(); i++) {
        mpixel[vpixel[i].getX()][vpixel[i].getY()] = vpixel[i].getWert();
    }
}

// Destruktor
BildDatei::~BildDatei() {
    for(size_t i = 0; i < xpix; i++) {
        delete[] mpixel[i];
    }
    delete[] mpixel;
}

// Das Bild in svg-Format speichern
// Die Methode benutzt vpixel, den Vektor mit Pixeln
// -> dieser muss nach dem entrauschen aktualisiert werden
void BildDatei::svgSchreiben(const char *dateiName) const {
	ofstream ausgabe(dateiName);
		
	if ( !ausgabe.is_open() )   
		cerr << "Datei \"" << dateiName << "\" nicht gefunden." << endl; 
	else {
        ausgabe << "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\"";
        ausgabe << " xmlns:xlink=\"http://www.w3.org/1999/xlink\" id=\"body\"";
        ausgabe << " xml:space=\"preserve\" width=\"300\" height=\"300\">" << endl << endl;
        for(size_t i = 0; i < vpixel.size() ; i++) {
            size_t w = vpixel[i].getWert();
            ausgabe << "<circle cx=\"" << vpixel[i].getX() << "\" cy=\"" << vpixel[i].getY();
            ausgabe << "\" r=\"1\" style=\"fill:rgb(" << w << "," << w << "," <<  w << ")\"/>" << endl;
        }
        ausgabe << endl << "</svg>" << endl;
		ausgabe.close();
	}
}

// Teilt das Filtermatrixarray in Werte kleiner x, 
// Werte gleich x und Werte größer x
int zerlege(int fMatrix[], int links, int rechts) {
    int x = fMatrix[rechts];
    int i = links;
    for (int j = links; j <= rechts - 1; j++) {
        if (fMatrix[j] <= x) {
            int temp1 = fMatrix[i];
            fMatrix[i] = fMatrix[j];
            fMatrix[j] = temp1;
            i++;
        }
    }
    int temp2 = fMatrix[i];
    fMatrix[i] = fMatrix[rechts];
    fMatrix[rechts] = temp2;
    return i;
}

int median(int fMatrix[], int links, int rechts, int k) // k muss im vorhinein die Mitte der Reihe 
{                                                       // ohne die Minus Einsen sein. Wird beim 
                                                        // Aufrufen der Methode in betracht gezogen                    

    // Zuerst zerlegen und index finden
    int i = zerlege(fMatrix, links, rechts);
    
    if (i - links == k - 1)         // gesuchter Wert gefunden
        return fMatrix[i];      
    else if (i - links > k - 1)     // gesuchter Wert liegt links von i
        return median(fMatrix, links, i - 1, k);
    else                            // gesuchter Wert liegt rechts von i
        return median(fMatrix, i + 1, rechts, k - i + links - 1);
}

void quickSort(int fMatrix[], int links, int rechts) {
    if (links < rechts) {
        int i = zerlege(fMatrix, links, rechts);

        quickSort(fMatrix, links, i - 1);
        quickSort(fMatrix, i + 1, rechts);
    }

}


void BildDatei::entrauschen() {
    
    // Genauigkeit angeben, also wie groß die Filtermatrix werden soll
    cout << "Medianfilter: " << endl;
    cout << "n bestimmt wie gross die Filtermatrix werden soll, also wie verschwommen das" << endl;
    cout << "Bild am Ende wird. Die Kantenlaenge der Matrix wird wie folgt berechnet" << endl;
    cout << "Kantenlaenge= 2*n+1          (also n=1 entspricht einer 3x3 Matrix)" << endl;
    cout << "Geben Sie ein n an -> ";

    int n, fMatrixSize;
    cin >> n;   // n = 1 entspricht einer 3x3 Matrix, n=2 entspricht einer 5x5 Matrix
                // je größer die Matrix desto Mehr verschwimmt das Bild

    vpixel.clear(); // alten Bild-Vektor löschen

    fMatrixSize = (2 * n + 1)*(2 * n + 1);     
    int* fMatrix = new int[fMatrixSize];        // Filtermatrix ist Array mit eingespeicherten Grauwerten
    int laufVar= 0;

    for (int i = 0; i < (int)xpix; i++) {
        for (int j = 0; j < (int)ypix; j++) {

            // Filtermatrix aufstellen als Vektor mit allen Werten um das Sortieren zu vereinfachen
            // wenn die Matrix über den Rand geht wird für die Werte die ausserhalb des Bildes sind -1 eingesetzt
            for (int k = i - n; k <= i + n; k++) {
                for (int l = j - n; l <= j + n; l++) {
                    if ((k >= 0 && k < (int)xpix) && (l >= 0 && l < (int)ypix) ) {
                        fMatrix[laufVar] = mpixel[k][l];
                    }
                    else {
                        fMatrix[laufVar] = -1;      // die Filtermatrix läuft über den Rand
                    }
                    laufVar++;
                }
            }
            laufVar = 0;

            // Median bilden, Die -1en müssen ausgeschlossen werden 
            // -1en zählen
            int minuEins = 0;
            for (int p = 0; p < fMatrixSize; p++) {
                if (fMatrix[p] == -1) {
                    int temp = fMatrix[minuEins];
                    fMatrix[minuEins] = fMatrix[p];
                    fMatrix[p] = temp;
                    minuEins++;
                }
            }


            /***    METHODE 1   ***/
            
            int k = minuEins + (fMatrixSize - minuEins) / 2 + 1;
            if ((fMatrixSize - minuEins) % 2 == 0) 
                mpixel[i][j] = (median(fMatrix, 0, fMatrixSize - 1, k - 1) + median(fMatrix, 0, fMatrixSize - 1, k)) / 2;
            else
                mpixel[i][j] = median(fMatrix, 0, fMatrixSize - 1, k);
            

            
            /***    METHODE 2    ***/
            /*
            quickSort(fMatrix, 0, fMatrixSize - 1);
            
            if ((fMatrixSize - minuEins) % 2 == 0)     // Ist gerade  
                mpixel[i][j] = (fMatrix[minuEins + (fMatrixSize - minuEins) / 2] + fMatrix[minuEins + (fMatrixSize - minuEins) / 2 + 1]) / 2;
            else                   // ist ungerade
                mpixel[i][j] = fMatrix[minuEins + (fMatrixSize - minuEins) / 2 ];
            */


            // Werte auch in den Vektor eintragen 
            Pixel p((size_t)i,(size_t)j,(size_t)mpixel[i][j]);
            vpixel.push_back(p);

        }        
    }
    cout <<"hallo" <<endl;

} // entrauschen()
