#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP

#include <vector>
#include "PointSet.hpp"

enum class DistanceType {
    EUCLID,
    MANHATTAN,
    CHEBYSHEV
};

struct WeightedEdge {
    int u;
    int v;
    double weight;

    bool operator<(const WeightedEdge& other) const {
        return weight < other.weight;
    }
};

class WeightedGraph {
private:
    int n;
    std::vector<WeightedEdge> edges;

public:
    WeightedGraph(const PointSet& points, DistanceType type);

    void sortEdges();
    int getVertexCount() const;
    const std::vector<WeightedEdge>& getEdges() const;
};

#endif // WEIGHTEDGRAPH_HPP