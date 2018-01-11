#include "Dijkstra.h"
#include "printutils.h"
#include <queue>

struct UnprocessedVertexComparator {
    bool operator()(const UnprocessedVertex& left, const UnprocessedVertex& right) {
        return left.score > right.score;
    }
};

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

    std::priority_queue<UnprocessedVertex, std::vector<UnprocessedVertex>, UnprocessedVertexComparator> pq;
    pq.push({0, 10});
    pq.push({1, 5});
    pq.push({2, 11});
    pq.push({3, 20});

    // Should be 1, 0, 2, 3
    auto pq_size = pq.size();
    for (int i = 0; i < pq_size; i++) {
        auto el = pq.top();
        std::cout << el.index << " ";
        pq.pop();
    }
    std::cout << std::endl;

    return 0;


}