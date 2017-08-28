#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "Graph.h"

class Digraph : public Graph {

protected:
  void addAdjacencyInfo(int v, int w, int edgeIndex);
  
};

#endif
