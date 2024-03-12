#ifndef DisjointSet_h
#define DisjointSet_h

#include <cstdlib>    // size_t

// Union by Rank Version
struct DisjointSet {
    size_t *parent; // Wurzel der Teilbaums bwz. Repraesenten
    size_t *rnk;    // Hoehe der Teilbaums

    DisjointSet(size_t n) {
        parent = new size_t[n + 1];
        rnk = new size_t[n + 1];
        // Setze Wurzel für jede Knoten selbst
        // Jede Knote ist ein Baum
        for (size_t i = 0; i <= n; i++) {
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    // Finden einen Wurzel von einem Knoten
    // 
    size_t Find(size_t u) {
        // wenn vorgänger von Knote u selbst ist, 
        // ist u ein Wurzel
        if (u == parent[u]) return parent[u];
        // anderfalls, suche Wurzel von vorgänger Knoten
        else return Find(parent[u]);
    }

    // Zusammenführen zwei Baäumen
    // 
    void Union(size_t knote1, size_t knote2) {
        // Finde Wurzeln von Bäumen
        size_t wurzel_baum1 = Find(knote1);
        size_t wurzel_baum2 = Find(knote2);

        // Wenn sie gleiche Wurzel haben,
        // sind die Knoten in selben Baum
        // Wenn sie nicht gleiche Wurzel haben,
        // baue 2 Bäume zusammen
        if (wurzel_baum1 != wurzel_baum2) {
            // In der Höhe kleiner Baum wird
            // unter längeren Baum gehängt.
            // Damit wird gesamte Länge reduziert
            if (rnk[wurzel_baum1] < rnk[wurzel_baum2]) {
                rnk[wurzel_baum2]++;
                parent[wurzel_baum1] = wurzel_baum2;
            }
            else {
                rnk[wurzel_baum1]++;
                parent[wurzel_baum2] = wurzel_baum1;
            }
        }
    }
};
#endif /* DisjointSet_h */