#include "Digraph.h"
#include "Graph.h"
#include "DFS.h"
#include "Kosaraju.h"
#include "printutils.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MyDFSDirected : public DFSDirected {

public:

    MyDFSDirected(Digraph* g) : DFSDirected(g) { }

protected:

    virtual void onEntry(int startVertex) {
        std::cout << startVertex << std::endl;
    }

    virtual void onExit(int startVertex) {
        std::cout << "\t" << startVertex << std::endl;
    }
};

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

    for (const pair<int, int>& p : edges) {
      g.addEdge(p.first, p.second);
    }

    cout << "The original graph:" << endl;
    g.printGraph();

    cout << "Vertices:" << endl;
    vector<int> vertices;
    g.getVerticesVector(vertices, false);
    printVector(vertices);

    cout << "The reversed graph:" << endl;
    g.printReversedGraph();

    cout << "DFS" << endl;
    MyDFSDirected dfs1(&g);
    dfs1.searchFrom(1);

    cout << "DFS (reverse):" << endl;
    MyDFSDirected dfs2(&g);
    dfs2.reverseSearchFrom(7);

    map<int, int> f;
    Digraph graph_ftimes;

    kosarajuComputeFinishingTimes(&g, &graph_ftimes, f);

    cout << "Graph of finishing times" << endl;
    graph_ftimes.printGraph();

    cout << "Finishing times map:" << endl;
    printMap(f);

}
