#ifndef CONTRACTABLEGRAPH_H
#define CONTRACTABLEGRAPH_H

#include "Graph.h"

class ContractableGraph : public Graph  {

public:
  
  int contractEdge(int edgeIndex);
  
private:
  
  void shrinkAdjOnContraction(int v_keep, int v_away);
  void renameInEdgesMapOnContraction(int v_keep, int v_away);
  void removeSelfLoopsAfterContraction(int v_keep, int v_away);
  
};


#endif
