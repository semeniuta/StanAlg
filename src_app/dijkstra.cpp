/*
 * Find shortest path in a weighted digraph using the Dijkstra algorithm
 *
 * Usage examples:
 * ./dijkstra -f ../../data/dijkstraData.txt -s 1
 * ./dijkstra -f ../../data/dijkstraData.txt -s 1 -v 7 37 59 82 99 115 133 165 188 197
 *
 */

#include <iostream>
#include <vector>
#include "WeightedDigraph.h"
#include "Dijkstra.h"
#include "ioutils.h"

int main(int argc, char *argv[]) {

    WeightedDigraph g;
    int start_vertex;
    std::string filename;
    std::vector<int> vertices_of_interest;
    bool all_vertices_are_of_interest = true;

    if (argc < 5) {
        std::cout << "Wrong arguments supplied\n";
        exit(0);
    }

    bool flags_ok = (strcmp(argv[1], "-f") == 0 && strcmp(argv[3], "-s") == 0);

    if (flags_ok) {

        filename = argv[2];

        try {
            start_vertex = std::stoi(argv[4]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Wrong format for starting vertex supplied\n";
            exit(0);
        }

    } else {
        std::cout << "Wrong arguments supplied\n";
        exit(0);
    }

    if (argc > 6 && strcmp(argv[5], "-v") == 0) {

        try {

            for (int i = 6; i < argc; i++) {
                int v = std::stoi(argv[i]);
                vertices_of_interest.push_back(v);
            }

            all_vertices_are_of_interest = false;

        } catch (const std::exception& e) {
            std::cout << "Invalid syntax of vetices of interest specification\n";
        }

    }

    std::cout << "Opening " << filename << "\n";
    std::cout << "Starting vertex: " << start_vertex << "\n";
    if (all_vertices_are_of_interest) {
        std::cout << "All vertices are of interest\n";
    } else {
        std::cout << "Vertices of interest: ";
        for (const auto& v : vertices_of_interest) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }

    try {

        FileReader fr;
        fr.open(filename);
        readWeightedGraphFromFile(&fr, &g);

    } catch (const std::exception& e) {
        std::cout << "Exception occured when reading " << filename << "\n";
    }

    Dijkstra dijkstra{&g, start_vertex};

    dijkstra.computeShortestPaths();

    std::vector<int>& vertices = vertices_of_interest;
    if (all_vertices_are_of_interest) {
        vertices = g.getVerticesVector();
    }

    for (auto& v : vertices) {
        std::cout << v << " -> " << dijkstra.getShortestPath(v) << "\n";
    };



}
