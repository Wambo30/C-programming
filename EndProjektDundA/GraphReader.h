//
//  GraphReader.h
//
// Hilfsfunktionen zum Einlesen und Ausgeben von Graphen


#ifndef GraphReader_h
#define GraphReader_h

#include "Graph.h"
#include <vector>

using namespace std;

class GraphReader {
public:
    static void knotenEinlesen(const char *dateiName, vector<GKnoten> &knoten);
    static void kantenEinlesen(const char *dateiName, vector<GKante> &kanten);
    static void graphToSVG(const Graph& graph, const char *dateiName);
    static void graphenSchreiben(const Graph& graph, const char *datei1, const char *datei2);
};

#endif /* GraphReader_h */
