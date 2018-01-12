#include "Dijkstra.h"
#include "printutils.h"
#include <queue>


int main() {

    WeightedDigraph g;

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 5, 5);
    g.addEdge(3, 5, 4);
    g.addEdge(3, 4, 3);
    g.addEdge(1, 4, 7);

    g.printGraph();

    DijkstraPreprocessingDFS preprocess(&g);
    preprocess.searchFrom(0);
    auto reachable = preprocess.copyReachabilityMap();

    int start_vertex = 0;
    Dijkstra dijkstra{&g, start_vertex};

    dijkstra.computeShortestPaths();

    for (auto& v : g.getVerticesVector()) {
        std::cout << v << " -> " << dijkstra.getShortestPath(v) << "\n";
    }

    return 0;


}