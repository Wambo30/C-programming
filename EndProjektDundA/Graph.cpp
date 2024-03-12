/*
 *  Graph.cpp
 *
 *  Speicherung eines Graphen als Adjazenzliste,
 *  Inzidenzliste bzw. Adjazenzmatrix
 */

#include "Graph.h"
#include "GraphReader.h"
#include <iostream>   // cout
#include <fstream>    // Dateien einlesen und ausgeben
#include <queue>      // STL-Container

using namespace std;

/* GKnoten */

GKnoten::GKnoten(size_t xwert, size_t ywert, size_t n)
    : x(xwert), y(ywert), nb(n), besucht(false), vorNb(-1), dist(numeric_limits<unsigned int>::max()) {}
    
size_t GKnoten::getX() const { return x;}
size_t GKnoten::getY() const { return y;}
size_t GKnoten::getNb() const { return nb;}
void GKnoten::setX(size_t x) { this->x = x;}
void GKnoten::setY(size_t y) { this->y = y;}
void GKnoten::setNb(size_t n) { nb = n;}

bool GKnoten::istBesucht() const {return besucht;}
void GKnoten::setBesucht(bool b) {besucht = b;}
int GKnoten::getVorNb() const {return vorNb;}
void GKnoten::setVorNb(int v) { vorNb = v;}

size_t GKnoten::getDistance() const { return dist; }

void GKnoten::setDistance(int d) { dist = d; }


/* GKante */
GKante::GKante() : headNb(0), tailNb(0), weight(0) {}
GKante::GKante(size_t h, size_t t, size_t w) : headNb(h), tailNb(t), weight(w) {}
size_t GKante::getHeadNb() const {return headNb;}
size_t GKante::getTailNb() const {return tailNb;}
size_t GKante::getWeight() const {return weight;}

void GKante::setHeadNb(size_t h) { headNb = h;}
void GKante::setTailNb(size_t t) { tailNb = t;}
void GKante::setWeigth(size_t w) { weight = w;}

// sortierung nach Gewichtung
bool GKante::operator < (const GKante& k) const
{
    return (weight < k.weight);
}

Graph::Graph() : gerichtet(gerichtet)
{
    knoten = vector<GKnoten>();
    kanten = vector<GKante>();
    mst = vector<GKante>();
}

/* Graph */
Graph::Graph(const char *knotenDat, const char *kantenDat, bool gerichtet) : gerichtet(gerichtet)
{
    GraphReader::knotenEinlesen(knotenDat, knoten);
    GraphReader::kantenEinlesen(kantenDat, kanten);
    
    initialisieren();
}

Graph::~Graph() {
    loeschen();
}

vector<GKnoten> Graph::getKnoten() const {return knoten;}
vector<GKante> Graph::getKanten() const {return kanten;}

vector<GKante> Graph::getMST() const
{
    return mst;
}

size_t Graph::getAnzahlKnoten() const
{
    return knoten.size();
}

// Adjazenzliste anlegen
void Graph::initialisieren() {
    adjListe = new list<size_t>[knoten.size()];
    
    // Adjazenzliste
    // Pro Knotennummer <list> mit Knotennummer der Nachbarknoten
    for(size_t i = 0; i < kanten.size(); i++) {
        // Bsp Kante mit headNb = 1 und teailNb = 3
        size_t h = kanten[i].getHeadNb();  // 1
        size_t t = kanten[i].getTailNb(); // 3
        // Knoten 3 fuegt zu seiner Liste Knoten 3 hinzu
        adjListe[h].push_front(t);  // adjListe[h] ist list von STL
        
        if( !gerichtet) {
            adjListe[t].push_front(h);
        }
    }
}

void Graph::loeschen() {
    if (adjListe)
        delete[] adjListe;
}

void Graph::printAdjListe() const {
    for (size_t i = 0; i < knoten.size(); i++) {
        cout << i << ": ";
        for(list<size_t>::iterator lit = adjListe[i].begin(); lit != adjListe[i].end(); ++lit)
            cout << *lit << " ";
        cout << endl;
    }
}

void Graph::printMST() const {
    size_t mstSumme = 0;
    for (size_t i = 0; i < mst.size(); i++) {
        GKante kante = mst[i];
        mstSumme += kante.getWeight();
        cout << "Kante " << i << ": " << kante.getHeadNb() << "-" << kante.getTailNb() << "  Gewichtung: " << kante.getWeight() << endl;
    }
    cout << "Summe der Kantengewichtung ist " << mstSumme << endl;
}

void Graph::dijkstra(size_t start, size_t end)
{
    size_t knotenAnzahl = knoten.size();
    // maximum für int. quasi unendlich
    const size_t MAX = numeric_limits<size_t>::max();

    // Für Effizient braucht man NxN Matrix
    // Ein Element (i,j) der Matrix hat den Abstand von i-te Knoten zu j-te Knote
    vector<vector<size_t>> abstand(knotenAnzahl, vector<size_t>(knotenAnzahl, MAX)); // leere NxN Matrix mit den Eintrag MAX

    // Die Abstände der Kanten in Matrix speichern
    for (vector<GKante>::iterator kit = kanten.begin(); kit != kanten.end(); kit++) {
        const size_t kn1 = kit->getHeadNb();
        const size_t kn2 = kit->getTailNb();
        abstand[kn1][kn2] = kit->getWeight();
        if (!gerichtet) {
            abstand[kn2][kn1] = kit->getWeight();
        }
    }

    // Initialisierung der Dijsktra. 
    // Die Abstände auf unendlich (MAX) 
    // Die Vorgänger als unbekannt (-1) 
    for (size_t i = 0; i < knoten.size(); i++) {
        knoten[i].setBesucht(false);
        knoten[i].setVorNb(-1);
        knoten[i].setDistance( MAX );
    }
    mst.clear(); // vorsichtshalber löschen

    // Die Menge Q enthält die Knoten, zu denen noch kein kürzester Weg gefunden wurde.
    vector<size_t> Q;
    // Nur der Startknoten hat die Distanz 0. 
    knoten[start].setDistance(0);
    Q.push_back(start);

    // PSC: WHILE queue ≠ ∅ DO
    // solange Q nicht leer, sucht kürzeste Weg
    while (!Q.empty())
    {
        // PSC: u ← queue.extractMin()
        // Knoten U in Q mit kleinstem Wert in abstand suchen
        size_t uNb = Q[0];
        size_t uNbPosition = 0;
        for (size_t i = 0; i < Q.size(); i++) {
            if (knoten[Q[i]].getDistance() < knoten[uNb].getDistance())
            {
                uNb = Q[i];
                uNbPosition = i;
            }
        }
        // entferne U aus Q  
        Q.erase(Q.begin()+ uNbPosition);

        // die Knoten U ist besucht markieren,
        // damit man nicht nochmal untersucht
        knoten[uNb].setBesucht(true);
        
        // Alle Kanten, die von Knote U ausgehen werden untersucht
        for (list<size_t>::iterator lit = adjListe[uNb].begin(); lit != adjListe[uNb].end(); ++lit) {
            size_t vNb = *lit; // Knote V
            size_t distance_u_v = abstand[uNb][*lit];
            size_t alternative = knoten[uNb].getDistance() + distance_u_v;
            if (knoten[vNb].istBesucht()) continue; // Knote ist besucht, nichts zu tun

            // festsetellen, ob Knote V in Quee ist
            bool element_V_in_Q = false;
            for (size_t j = 0; j < Q.size(); j++) {
                if (Q[j] == vNb) {
                    // Element V in Quee gefunden
                    element_V_in_Q = true;
                    break;
                }
            }


            if (element_V_in_Q && knoten[vNb].getDistance() > alternative)
            {
                // besserer Weg gefunden -> update distance
                knoten[vNb].setDistance(alternative);
                knoten[vNb].setVorNb(uNb);
            } else if (knoten[vNb].getVorNb() == -1) {
                // erste mal ein Weg gefunden
                knoten[vNb].setDistance(alternative);
                knoten[vNb].setVorNb(uNb);
                // rein in Quee um weiter Knoten zu untersuchen
                Q.push_back(vNb);
            }
        }
    }

    // erstelle Kürzesten Pfad
    vector<int> pfad;
    // wenn Zielknoten keine vorgänger hat,
    // kein weg gefunden
    if (knoten[end].getVorNb() == -1) {
        cout << "kein Weg gefunden!" << endl;
    }
    else {
        // Den kürzesten Weg zu einem Zielknoten kann man nun durch Iteration über die vorgänger ermitteln
        pfad.push_back(end);
        int pNb = end; // p:= Zielknoten
        // solange ein Vorgänge existiert, aus Zielknoten bis Startknote rückwärts
        while (pNb >= 0 && knoten[pNb].getVorNb() != -1) {
            pfad.push_back(knoten[pNb].getVorNb());
            pNb = knoten[pNb].getVorNb();
        }

        // Ergebnis rückwärts ausgeben
        cout << "Dijsktra kuerzeste Weg: " << endl;
        for (int i = pfad.size() - 1; i >= 0; i--) cout << pfad[i] << "  ";
        cout << endl;
    }
    
}

void Graph::prim(size_t start)
{
    size_t knotenAnzahl = knoten.size();
    // maximum für int. quasi unendlich
    const size_t MAX = numeric_limits<size_t>::max();

    // Für Effizient braucht man NxN Matrix
    // Ein Element (i,j) der Matrix hat den Abstand von i-te Knoten zu j-te Knote
    vector<vector<size_t>> abstand(knotenAnzahl, vector<size_t>(knotenAnzahl, MAX)); // leere NxN Matrix mit den Eintrag MAX

    // Die Abstände der Kanten in Matrix speichern
    for (vector<GKante>::iterator kit = kanten.begin(); kit != kanten.end(); kit++) {
        const size_t kn1 = kit->getHeadNb();
        const size_t kn2 = kit->getTailNb();
        abstand[kn1][kn2] = kit->getWeight();
        if (!gerichtet) {
            abstand[kn2][kn1] = kit->getWeight();
        }
    }

    // Initialisierung der Dijsktra. 
    // Die Abstände auf unendlich (MAX) 
    // Die Vorgänger als unbekannt (-1) 
    for (size_t i = 0; i < knoten.size(); i++) {
        knoten[i].setBesucht(false);
        knoten[i].setVorNb(-1);
        knoten[i].setDistance(MAX);
    }
    mst.clear(); // vorsichtshalber löschen

    // Die Menge Q enthält die Knoten, zu denen noch kein kürzester Weg gefunden wurde.
    vector<size_t> Q;
    // Nur der Startknoten hat die Distanz 0. 
    knoten[start].setDistance(0);
    Q.push_back(start);

    // PSC: WHILE queue ≠ ∅ DO
    // solange Q nicht leer, sucht kürzeste Weg
    while (!Q.empty())
    {
        // PSC: u ← queue.extractMin()
        // Knoten U in Q mit kleinstem Wert in abstand suchen
        size_t uNb = Q[0];
        size_t uNbPosition = 0;
        for (size_t i = 0; i < Q.size(); i++) {
            if (knoten[Q[i]].getDistance() < knoten[uNb].getDistance())
            {
                uNb = Q[i];
                uNbPosition = i;
            }
        }
        // entferne U aus Q  
        Q.erase(Q.begin() + uNbPosition);

        // die Knoten U ist besucht markieren,
        // damit man nicht nochmal untersucht
        knoten[uNb].setBesucht(true);

        // Alle Kanten, die von Knote U ausgehen werden untersucht
        for (list<size_t>::iterator lit = adjListe[uNb].begin(); lit != adjListe[uNb].end(); ++lit) {
            size_t vNb = *lit; // Knote V
            size_t distance_u_v = abstand[uNb][*lit];
            if (knoten[vNb].istBesucht()) continue; // Knote ist besucht, nichts zu tun

            // festsetellen, ob Knote V in Quee ist
            bool element_V_in_Q = false;
            for (size_t j = 0; j < Q.size(); j++) {
                if (Q[j] == vNb) {
                    // Element V in Quee gefunden
                    element_V_in_Q = true;
                    break;
                }
            }


            if (element_V_in_Q && knoten[vNb].getDistance() > distance_u_v)
            {
                // besserer Weg gefunden -> update distance
                knoten[vNb].setDistance(distance_u_v);
                knoten[vNb].setVorNb(uNb);
            }
            else if (knoten[vNb].getVorNb() == -1) {
                // erste mal ein Weg gefunden
                knoten[vNb].setDistance(distance_u_v);
                knoten[vNb].setVorNb(uNb);
                // rein in Quee um weiter Knoten zu untersuchen
                Q.push_back(vNb);
            }
        }
    }
    
    // Spannbaum leeren
    mst.clear();
    // Spannbaum erstellen
    // Jede knote hat ein Vorgänger,
    // die Kanten da zwischen
    // gehören zum Minimalen Spannbaum
    for (vector<GKnoten>::iterator knit = knoten.begin(); knit != knoten.end(); knit++) {
        size_t kNb = knit->getNb(); // Knotennummer
        size_t vNb = knit->getVorNb(); // Vorgänger von Knoten
        if (kNb == start) continue; // Bei Anfangsknote endet

        for (vector<GKante>::iterator kit = kanten.begin(); kit != kanten.end(); kit++) {
            const size_t kn1 = kit->getHeadNb();
            const size_t kn2 = kit->getTailNb();
            if ((kn1 == kNb && kn2 == vNb) || (kn1 == vNb && kn2 == kNb))
            {
                mst.push_back(*kit);
            }
        }
    }

    // Ergebnis ausgeben
    printMST();

}

void Graph::kruskal()
{
    if (gerichtet)
    {
        cerr << "Kruskal kann nur auf ungerichteten Graphen angewandt werden!" << endl << endl;
        return;
    }

    // Initialisierung der Dijsktra.
    // Sicherheitshalber neu setzen
    for (size_t i = 0; i < knoten.size(); i++) {
        knoten[i].setBesucht(false);
        knoten[i].setVorNb(-1);         // Die Vorgänger als unbekannt (-1) 
    }
    mst.clear();

    size_t N = getAnzahlKnoten();

    // steigend sortieren nach Abstand/Gewichtung
    sort(kanten.begin(), kanten.end());

    DisjointSetEinfach ds(N);


    vector<GKante>::iterator it;
    for (it = kanten.begin(); it != kanten.end(); it++) {
        const size_t kn1 = it->getHeadNb();
        const size_t kn2 = it->getTailNb();

        size_t rootKn1 = ds.Find(kn1);
        size_t rootKn2 = ds.Find(kn2);

        if (rootKn1 != rootKn2) {
            ds.Union(rootKn1, rootKn2);
            mst.push_back(*it);

        }
    }

    // Ergebnis ausgeben
    printMST();
}
