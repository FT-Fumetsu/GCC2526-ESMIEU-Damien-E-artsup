#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <utility>
#include "WeightedGraph.hpp"

struct DijkstraResult {
    std::vector<int> path;
    double distance;
};

class Dijkstra {
public:
    static DijkstraResult shortestPath(
        const WeightedGraph& graph,
        int source,
        int target
    );
};

#endif // DIJKSTRA_HPP