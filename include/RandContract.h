#ifndef RANDCONTRACT_H
#define RANDCONTRACT_H

#include "Graph.h"
#include <set>

class RandomContraction {

public:
  RandomContraction(Graph* g);
  ~RandomContraction();
  int doContraction();
  
  
private:
  Graph* originalGraph;
  void copyGraph(Graph* targetGraph);
  
};


#endif
