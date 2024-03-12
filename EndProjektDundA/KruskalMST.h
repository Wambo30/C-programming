//
//  KruskalMST.h
//
// Kruskal Algorithmus


#ifndef KruskalMST_h
#define KruskalMST_h

#include "Graph.h"
#include <vector>

using namespace std;

class KruskalMST {
public:
    static Graph& getMST(const Graph& graph);
};

#endif /* KruskalMST_h */
