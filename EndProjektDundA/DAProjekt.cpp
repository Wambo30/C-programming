/*
 *  DAProjekt.cpp
 *
 */

#include "GraphReader.h"
#include <iostream>   // cout


//using namespace std;

int main(void) {

    // Testgraphen fuer Algorithmen
    Graph gerichteteGraph("knoten1.dat", "kanten1.dat", true);
    Graph ungerichteteGraph("knoten2.dat", "kanten2.dat", false);

    // Die Graphen in SVG-Format ausgeben
    GraphReader::graphToSVG(ungerichteteGraph, "graph_ungerichtet.svg");
    GraphReader::graphToSVG(gerichteteGraph, "graph_gerichtet.svg");

    // Adjazenzliste ausgeben
    cout << "*** U N G E R I C H T E T E R  G R A P H *** " << endl;
    cout << "*** Adjazenzliste der ungerichteten Graphen*** " << endl << endl;
    ungerichteteGraph.printAdjListe();
    cout << "*** G E R I C H T E T E R  G R A P H *** " << endl;
    cout << "*** Adjazenzliste der gerichteten Graphen*** " << endl << endl;
    gerichteteGraph.printAdjListe();

    
    while (1)
    {
        int opt; // menu wahl
        size_t start;  //Startknoten
        size_t end;    //Endknoten

        cout << endl << endl << " ************ MENU   ************ " << endl;
        cout << " 1:    Test 1 - Automatischer Test " << endl;
        cout << " 2:    Test 2 - Dijsktra - auf gerichteter Graph " << endl;
        cout << " 3:    Test 3 - Dijsktra - auf ungerichteter Graph " << endl;
        cout << " 4:    Test 4 - Prim - auf ungerichteter Graph " << endl;
        cout << " 5:    Test 5 - Kruskal - auf ungerichteter Graph " << endl;
        cout << " 0:    Program beendet " << endl;
        cout << " ****************************** " << endl << endl;
        cout << "Bitte Menu punkt waehlen: ";
        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 1:
            cout << " ****************************** " << endl;
            cout << "*********    Test Reihe     ********" << endl;
            cout << " ****************************** " << endl;
            cout << "********* Teil 1 - Dijkstra auf gerichtete Graph ********" << endl;
            cout << "Kürzeste Weg von Knoten 0 zu 5" << endl;
            start = 0;
            end = 5;
            gerichteteGraph.dijkstra(start, end);
            GraphReader::graphToSVG(gerichteteGraph, "test1_1_dijsktra_gerichtete_graph.svg");
            cout << endl;

            cout << "********* Teil 2 - Dijkstra auf ungerichtete Graph ********" << endl;
            cout << "Kürzeste Weg von Knoten 6 zu 5" << endl;
            start = 6;
            end = 5;
            ungerichteteGraph.dijkstra(start, end);
            GraphReader::graphToSVG(ungerichteteGraph, "test1_2_dijsktra_ungerichtete_graph.svg");
            cout << endl;

            cout << "********* Teil 3 - Prim Algorithmus ********" << endl;
            cout << "Minimale Spannbaum - startpunkt : Knote 2 " << endl;
            ungerichteteGraph.prim(2);
            GraphReader::graphToSVG(ungerichteteGraph, "test1_3_prim.svg");
            cout << endl;

            cout << "********* Teil 4 - Kruskal Algorithmus ********" << endl;
            cout << "Minimale Spannbaum" << endl;
            ungerichteteGraph.kruskal();
            GraphReader::graphToSVG(ungerichteteGraph, "test1_4_kruskal.svg");
            cout << endl;
            break;
        case 2:
            cout << "Test 2 - Dijsktra - auf gerichteter Graph " << endl;
            cout << "An welchen Knoten soll die Dijkstra starten? ";
            cin >> start;
            cout << "Zielknote: ";
            cin >> end;
            gerichteteGraph.dijkstra(start, end);
            GraphReader::graphToSVG(gerichteteGraph, "test2_dijsktra_gerichtete_graph.svg");
            cout << endl;
            break;
        case 3:
            cout << "Test 3 - Dijsktra - auf ungerichteter Graph " << endl;
            cout << "An welchen Knoten soll die Dijkstra starten? ";
            cin >> start;
            cout << "Zielknote: ";
            cin >> end;
            ungerichteteGraph.dijkstra(start, end);
            GraphReader::graphToSVG(ungerichteteGraph, "test3_dijsktra_ungerichtete_graph.svg");
            cout << endl;
            break;
        case 4:
            cout << "Test 4 - Prim Algorithmus " << endl;
            cout << "An welchen Knoten soll die Prim starten? ";
            cin >> start;
            ungerichteteGraph.prim(start);
            GraphReader::graphToSVG(ungerichteteGraph, "test4_prim.svg");
            cout << endl;
            break;
        case 5:
            cout << "Test 5 - Kruskal Algorithmus " << endl;
            ungerichteteGraph.kruskal();
            GraphReader::graphToSVG(ungerichteteGraph, "test5_kruskal.svg");
            cout << endl;
            break;
        case 0:
            exit(0); // Beenden
        default:
            break;
        }
    }

    return 0;
}
