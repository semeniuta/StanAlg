#ifndef RANDCONTRACT_H
#define RANDCONTRACT_H

#include "Graph.h"

class RandomContraction {

public:
  RandomContraction(Graph* g);
  ~RandomContraction();
  
  
private:
  Graph* originalGraph;
  Graph contractedGraph;
  void copyGraph();
  
};


#endif
