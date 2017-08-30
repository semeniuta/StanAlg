#include "Digraph.h"
#include "Graph.h"
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

int main() {

    Digraph g;
    //Graph g;

    vector<pair<int, int>> edges = {
      pair<int, int>(1, 5),
      pair<int, int>(5, 4),
      pair<int, int>(4, 1),
      pair<int, int>(2, 3),
      pair<int, int>(3, 6),
      pair<int, int>(6, 2),
      pair<int, int>(6, 7),
      pair<int, int>(7, 2),
      pair<int, int>(5, 2)

    };

    cout << "Adding edge pairs:" << endl;
    for (const pair<int, int>& p : edges) {
      cout << p.first << ", " << p.second << endl;
      g.addEdge(p.first, p.second);
    }

    cout << "The original graph:" << endl;
    printGraphState(&g);


}
