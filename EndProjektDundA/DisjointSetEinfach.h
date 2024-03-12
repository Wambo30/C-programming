#ifndef DisjointSet_h
#define DisjointSet_h

#include <cstdlib>    // size_t


struct DisjointSetEinfach {
    size_t *parent; // Wurzel der Teilbaums bwz. Repraesenten

    DisjointSetEinfach(size_t n) {
        parent = new size_t[n + 1];
        // Setze Wurzel f�r jede Knoten selbst
        // Jede Knote ist ein Baum
        for (size_t i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Finden einen Wurzel von einem Knoten
    // 
    size_t Find(size_t u) {
        // wenn vorg�nger von Knote u selbst ist, 
        // ist u ein Wurzel
        if (u == parent[u]) return parent[u];
        // anderfalls, suche Wurzel von vorg�nger Knoten
        else return Find(parent[u]);
    }

    // Zusammenf�hren zwei Ba�umen
    // 
    void Union(size_t knote1, size_t knote2) {
        // Finde Wurzeln von B�umen
        size_t wurzel_baum1 = Find(knote1);
        size_t wurzel_baum2 = Find(knote2);

        // Wenn sie gleiche Wurzel haben,
        // sind die Knoten in selben Baum
        // Wenn sie nicht gleiche Wurzel haben,
        // erste baum wird unter zweiten angeh�ngt
        if (wurzel_baum1 != wurzel_baum2) {
            parent[wurzel_baum1] = wurzel_baum2;
        }
    }
};
#endif /* DisjointSet_h */