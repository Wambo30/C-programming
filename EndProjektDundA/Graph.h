/*
 *  Graph.h
 *
 *  Breitensuche in einem Graphen
 */

#ifndef GRAPH_H
#define GRAPH_H


#include "DisjointSetEinfach.h"
#include <cstdlib>    // size_t
#include <vector>
#include <list>       // Adjazenz- und Inzidenzliste

using namespace std;

/* Ein Knoten im Graphen */
class GKnoten {
public:
    GKnoten();
    GKnoten(size_t x, size_t y, size_t nb);
    
    size_t getX() const;
    size_t getY() const;
    size_t getNb() const;
    void setX(size_t x);
    void setY(size_t x);
    void setNb(size_t x);
    bool istBesucht() const;
    void setBesucht(bool);
    int getVorNb() const;
    void setVorNb(int);
    size_t getDistance() const; // selim
    void setDistance(int); // selim

private:
    size_t x, y;           // x- und y-Koordinate
    size_t nb;             // die Nummer des Knotens
    bool besucht;        // schon besucht?
    int vorNb;           // Die Nummer des Vorgaengers auf dem Weg zum Startknoten
                         // -1 bei dem Startknoten
    int dist;            // Abstand, fuer Dijistra Algorithmus
};


/* Eine Kante im Graphen */
class GKante {
public:
    GKante();
    GKante(size_t h, size_t t, size_t w);
    
    size_t getHeadNb() const;
    size_t getTailNb() const;
    size_t getWeight() const;
    void setHeadNb(size_t h);
    void setTailNb(size_t t);
    void setWeigth(size_t w); //selim

    bool operator<(const GKante& k) const; // selim
    
private:
    size_t headNb; // Die Id vom Startknoten
    size_t tailNb; // Die Id vom Endknoten
    size_t weight; // Gewichtung // selim
};

class Graph {
public:
    const bool gerichtet; // gerichteteter/ungerichteter Graph
    
    Graph();
    // Im Konstruktor wird der Graph aus der Datei eingelesen
    // Adjazenzliste, Inzidenzlise und Adjazenzmatrix werden initialisiert
    Graph(const char *knotenDat, const char *kantenDat, bool gerichtet);
    ~Graph();
    
    vector<GKnoten> getKnoten() const;
    vector<GKante> getKanten() const;
    vector<GKante> getMST() const;
    size_t getAnzahlKnoten() const;
    
    void dijkstra(size_t start, size_t end);
    void prim(size_t start);
    void kruskal();
    
    void printAdjListe() const;  // Ausgabe Adj. Liste
    void printMST() const;       // Ausgabe Minimale Spannbaum // selim
    
private:
    vector<GKnoten> knoten;      // Alle Knoten im Graphen
    vector<GKante> kanten;       // Alle Kanten im Graphen

    list<size_t> *adjListe;      // Die Adjazenzliste: Nachbarknoten
    vector<GKante> mst;          // Minimale Spannbaum // selim
    
    // Nach Aenderungen die Listen/Matrix aktualisieren
    void loeschen();
    void initialisieren();
};

#endif // Graph_H
