#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "Graph.h"

class Digraph : public Graph {

public:

    list<AdjacentVertex>& getListOfReverseAdjacentVertices(int v);

protected:

    virtual void addAdjacencyInfo(int v, int w, int edgeIndex);

    map<int, list<AdjacentVertex>> adjReverse;

};

#endif
