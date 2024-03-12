//
//  GraphReader.cpp
//
// Hilfsfunktionen zum Einlesen und Ausgeben von Graphen


#include "GraphReader.h"

#include <iostream>   // cout
#include <fstream>    // Dateien einlesen und ausgeben
using namespace std;

// Die Klasse Graph muss die Listen vector<GKnoten> und vector<GKante> haben

// Knoten einlesen
void GraphReader::knotenEinlesen(const char *knotenDat, vector<GKnoten> &knoten) {
    
    ifstream knotenEingabe(knotenDat);
    
    // Knoten einlesen
    // pro Zeile: < die laufende Nummer> <x> <y> (Koordinaten)
    if (!knotenEingabe.is_open())
        cerr << "Datei \"" << knotenDat << "\" nicht gefunden." << endl;
    else {
        while( !knotenEingabe.eof() ) {
            size_t nb, x, y;
            knotenEingabe >> nb >> x >>  y;
            if( !knotenEingabe.fail() )
                knoten.push_back(GKnoten(x, y, nb));
                // fortlaufend nummeriert, beginnend bei 0
        }
        knotenEingabe.close();
    }
}
    
// Kanten einlesen
void GraphReader::kantenEinlesen(const char *kantenDat, vector<GKante> &kanten) {
    ifstream kantenEingabe(kantenDat);
    if (!kantenEingabe.is_open())
        cerr << "Datei \"" << kantenDat << "\" nicht gefunden." << endl;
    else {
        while( !kantenEingabe.eof() ) {
            size_t headNb, tailNb, weight;
            kantenEingabe >> headNb >> tailNb >> weight;
            if( !kantenEingabe.fail() )
                if( headNb != tailNb )
                    kanten.push_back(GKante(headNb, tailNb, weight));
        }
        kantenEingabe.close();
    }
}


/* A U S G A B E */

// Den Graphen zur Anzeige in svg-Format speichern
void  GraphReader::graphToSVG(const Graph& graph, const char *dateiName)
{
    ofstream ausgabe(dateiName);
    
    if ( !ausgabe.is_open() )
        cerr << "Datei \"" << dateiName << "\" nicht gefunden." << endl;
    else {
        ausgabe << "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\"";
        ausgabe << " xmlns:xlink=\"http://www.w3.org/1999/xlink\" id=\"body\"";
        ausgabe << " xml:space=\"preserve\" width=\"600\" height=\"600\">" << endl << endl;
        
        ausgabe << "<marker id=\"pf1\" viewBox=\"0 0 20 10\" refX=\"30\" refY=\"5\""<< endl;
        ausgabe << "markerUnits=\"strokeWidth\"" << endl;
        ausgabe << "markerWidth=\"20\" markerHeight=\"20\"" << endl ;
        ausgabe << "orient=\"auto\">" << endl;
        ausgabe << "<path d=\"M 0,0 L 20,5 L 0,10 z\" />" << endl;
        ausgabe << "</marker>" << endl << endl;
        
        ausgabe << "<marker id=\"pf2\" viewBox=\"0 0 20 10\" refX=\"30\" refY=\"5\""<< endl;
        ausgabe << "markerUnits=\"strokeWidth\"" << endl;
        ausgabe << "markerWidth=\"20\" markerHeight=\"20\"" << endl ;
        ausgabe << "orient=\"auto\">" << endl;
        ausgabe << "<path d=\"M 0,0 L 20,5 L 0,10 z\" fill=\"red\" stroke=\"red\" />" << endl;
        ausgabe << "</marker>" << endl << endl;
        
        const int SCAL = 5;
        
        vector<GKnoten> knoten = graph.getKnoten();
        vector<GKante> kanten = graph.getKanten();
        // Kanten zeichnen - pro Knoten seine inzidenten Kanten ausgeben
        for(size_t i = 0; i < kanten.size(); i++) {
            size_t w = kanten[i].getWeight(); // selim

            size_t h = kanten[i].getHeadNb();
            size_t xh = knoten[h].getX();
            size_t yh = knoten[h].getY();
            
            size_t t = kanten[i].getTailNb();
            size_t xt = knoten[t].getX();
            size_t yt = knoten[t].getY();
            
            ausgabe << "<line x1=\"" << SCAL * xh << "\" y1=\""<< SCAL * yh;
            ausgabe << "\" x2=\"" << SCAL * xt << "\" y2=\"" << SCAL * yt;
            if (graph.gerichtet)
                ausgabe << "\" style=\"stroke:grey;stroke-width:2;\" marker-end=\"url(#pf1)\" />" << endl;
            else
                ausgabe << "\" style=\"stroke:grey;stroke-width:2;\" />" << endl;
            // selim
            // Gewichtung zeichnen
            // Auf der Mittelpunkt der Kante
            double m_x = SCAL * (xt + xh) / 2;
            double m_y = SCAL * (yt + yh) / 2;
            ausgabe << "<text x=\"" << m_x - 7 << "\" y=\"" << m_y + 5;
            ausgabe << "\" style=\"font-size:14; font-family:Arial\">" << w << "</text>" << endl;
        }

        // selim
        // Minimale Spannbaum zeichnen
        vector<GKante> mst = graph.getMST();
        for (size_t i = 0; i < mst.size(); i++) {
            size_t w = mst[i].getWeight();

            size_t h = mst[i].getHeadNb();
            size_t xh = knoten[h].getX();
            size_t yh = knoten[h].getY();

            size_t t = mst[i].getTailNb();
            size_t xt = knoten[t].getX();
            size_t yt = knoten[t].getY();

            ausgabe << "<line x1=\"" << SCAL * xh << "\" y1=\"" << SCAL * yh;
            ausgabe << "\" x2=\"" << SCAL * xt << "\" y2=\"" << SCAL * yt;
            ausgabe << "\" style=\"stroke:blue;stroke-width:3;\" />" << endl;
        }
        
        // Suchbaum zeichnen
        for(size_t i = 0; i < knoten.size(); i++) {
            if (knoten[i].getVorNb() != -1) {
                size_t h = knoten[i].getVorNb();
                ausgabe << "<line x1=\"" << SCAL * knoten[h].getX() << "\" y1=\""<< SCAL * knoten[h].getY();
                ausgabe << "\" x2=\"" << SCAL * knoten[i].getX() << "\" y2=\"" << SCAL * knoten[i].getY();
                ausgabe << "\" style=\"stroke:red;stroke-width:1;\" marker-end=\"url(#pf2)\" />" << endl;
            }
        }
        
        // Knoten zeichnen
        for(size_t i = 0; i < knoten.size(); i++) {
            ausgabe << "<circle cx=\"" <<  SCAL * knoten[i].getX() << "\" cy=\"" << SCAL * knoten[i].getY();
            if (knoten[i].istBesucht()) {
                ausgabe << "\" r=\"10\" style=\"fill:yellow;stroke:rgb(0,0,255);stroke-width:1\"/>" << endl;
            }
            else {
                ausgabe << "\" r=\"10\" style=\"fill:white;stroke:rgb(0,0,255);stroke-width:1\"/>" << endl;
            }
            ausgabe << "<text x=\"" << SCAL * knoten[i].getX() - 7<< "\" y=\"" << SCAL * knoten[i].getY()+5;
            ausgabe << "\" style=\"font-size:14; font-family:Arial\">" << knoten[i].getNb() << "</text>" << endl;
        }
        
        ausgabe << endl << "</svg>" << endl;
        ausgabe.close();
    }
}

// Den Graphen in knoten.dat und kanten.dat schreiben
void  GraphReader::graphenSchreiben(const Graph& graph, const char* dateiKnoten, const char* dateiKanten)
{
    // Knoten
    ofstream ausgabe(dateiKnoten);
    
    if ( !ausgabe.is_open() )
        cerr << "Datei \"" << dateiKnoten << "\" nicht gefunden." << endl;
    else {
        vector<GKnoten> knoten = graph.getKnoten();
        for(size_t i = 0; i < knoten.size(); i++)
            ausgabe << i << " " << knoten[i].getX() << " " << knoten[i].getY() << endl;
    }
    ausgabe.close();
    
    // Kanten
    ofstream aus(dateiKanten);
    
    if ( !aus.is_open() )
        cerr << "Datei \"" << dateiKanten << "\" nicht gefunden." << endl;
    else {
        vector<GKante> kanten = graph.getKanten();
        for(size_t i = 0; i < kanten.size(); i++)
            aus << kanten[i].getHeadNb() << " " << kanten[i].getTailNb() << endl;
    }
    aus.close();
}
        
