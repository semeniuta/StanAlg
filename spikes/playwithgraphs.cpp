#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {

  Graph g;

  map<int, int> edges = {
    pair<int, int>(1, 2),
    pair<int, int>(1, 5),
    pair<int, int>(2, 7),
    pair<int, int>(5, 10),
    pair<int, int>(5, 7),
    pair<int, int>(2, 10),
    pair<int, int>(10, 1)
  };
  
  for (const pair<int, int>& p : edges) {
    
    g.addEdge(p.first, p.second);
    
  }
  
  return 0;
  

}
