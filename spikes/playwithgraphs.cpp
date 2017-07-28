#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {

  Graph g;

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
  g.printGraph();
  g.printEdges();

  cout << "Num vertices: " << g.countVertices() << endl;
  cout << "Num edges: " << g.countEdges() << endl;
  
  int edge_to_contract = 1;
  pair<int, int> e = g.edgeEndpoints(edge_to_contract);
  
  g.contractEdge(edge_to_contract);
  
  cout << "Graph after contracting " << e.first << " and " << e.second << endl;
  
  g.printGraph();
  g.printEdges();
  
  cout << "Num vertices: " << g.countVertices() << endl;
  cout << "Num edges: " << g.countEdges() << endl;
  
  return 0;


}
