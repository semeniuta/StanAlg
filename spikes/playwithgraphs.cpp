#include "ContractableGraph.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printGraphState(Graph* g) {

  g->printGraph();
  cout << "Edges:" << endl;
  g->printEdges();

  cout << "Num vertices: " << g->countVertices() << endl;
  cout << "Num edges: " << g->countEdges() << endl;

}

void contractAndShow(ContractableGraph* g, int edgeToContract) {
  pair<int, int> e = g->edgeEndpoints(edgeToContract);
  g->contractEdge(edgeToContract);
  cout << "Graph after contracting " << e.first << " and " << e.second << endl;
  printGraphState(g);
}

int main () {

  ContractableGraph g;

  vector<pair<int, int>> edges = {
    pair<int, int>(1, 2),
    pair<int, int>(1, 5),
    pair<int, int>(2, 7),
    pair<int, int>(5, 10),
    pair<int, int>(5, 7),
    pair<int, int>(10, 7),
    pair<int, int>(2, 10),
    pair<int, int>(10, 1)
  };

  cout << "Adding edge pairs:" << endl;
  for (const pair<int, int>& p : edges) {
    cout << p.first << ", " << p.second << endl;
    g.addEdge(p.first, p.second);
  }

  cout << "The original graph:" << endl;
  printGraphState(&g);

  // Testing for wrong indices contraction
  //g.contractEdge(40);

  contractAndShow(&g, 1);
  contractAndShow(&g, 7);

  return 0;


}
