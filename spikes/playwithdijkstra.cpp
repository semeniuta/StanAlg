#include "Dijkstra.h"
#include "WeightedDigraph.h"
#include "printutils.h"

int main() {

    WeightedDigraph g;

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    g.addEdge(3, 0, 8);


    DijkstraPreprocessingDFS preprocess(&g);
    preprocess.searchFrom(0);
    auto reachable = preprocess.copyReachabilityMap();

    g.printEdges();

    printMap<int, bool>(reachable);


    return 0;


}