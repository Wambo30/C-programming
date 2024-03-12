/*
 *  Graph-Main.cpp
 *
 */


/*
#include "Graph.h"
#include "GraphReader.h"
#include <iostream>   // cout
using namespace std;

int main (void) {
    
    // Breitensuche auf einem ungerichteten Graphen durchfuehren 
    // Graphen in einer Adjazenliste speichern
    
    Graph graph("knoten.dat", "kanten.dat", false);
   
    // Den Graphen in SVG-Format ausgeben
    GraphReader::graphToSVG(graph,"graph.svg");
   
    cout << "*** U N G E R I C H T E T E R  G R A P H *** " << endl << endl;
    // Adjazenzliste ausgeben
    cout << "*** Adjazenzliste *** " << endl;
    graph.printAdjListe();
   
    // Breitensuche ausfuehren
    int start;  //Startknoten
    cout << "An welchen Knoten soll die Breitensuche starten? ";
    cin >> start;
   
    graph.breitensuche(start);
   
    // Den Graphen mit Suchbaum der Breitensuche in SVG-Format ausgeben
    GraphReader::graphToSVG(graph, "graphB.svg");
   

    
    /* Breitensuche in einem gerichteten Graphen betrachten */
    /*
    cout <<  endl << endl << "*** G E R I C H T E T E R  G R A P H *** " << endl << endl;
    // Graphen in einer Adjazenliste speichern
    Graph digraph("knoten.dat", "kanten.dat", true);
   
    // Den Graphen in SVG-Format ausgeben
    GraphReader::graphToSVG(digraph,"digraph.svg");
   
    // Adjazenzliste ausgeben
    cout << "*** Adjazenzliste *** " << endl;
    digraph.printAdjListe();
    
    cout << endl << " B R E I T E N S U C H E " << endl;
   
    digraph.breitensuche(0);
   
    // Den Graphen mit Suchbaum der Breitensuche in SVG-Format ausgeben
    GraphReader::graphToSVG(digraph, "digraphB.svg");
     */
    
    //return 0;
//}

