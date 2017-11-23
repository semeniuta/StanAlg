#include "Dijkstra.h"
#include "WeightedDigraph.h"
#include "printutils.h"
#include "Heap.h"

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


    Heap<int> my_heap;

    for (int x : std::vector<int>{ 11, 9, 13, 12, 4, 5, 8, 7, 6 }) {
        my_heap.insert(x);
        my_heap.printData();
    }

    my_heap.remove( my_heap.findIndex(5) );
    my_heap.printData();


//    std::cout << "Popping ... \n";
//    while (my_heap.size() > 0) {
//        std::cout << my_heap.pop() << std::endl;
//        my_heap.printData();
//    }




    return 0;


}