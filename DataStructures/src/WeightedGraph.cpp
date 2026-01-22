#include "WeightedGraph.hpp"
#include <algorithm>

WeightedGraph::WeightedGraph(const PointSet& points, DistanceType type) {
    n = points.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = 0.0;

            if (type == DistanceType::EUCLID)
                d = points[i].distanceEuclid(points[j]);
            else if (type == DistanceType::MANHATTAN)
                d = points[i].distanceManhattan(points[j]);
            else
                d = points[i].distanceChebyshev(points[j]);

            edges.push_back({i, j, d});
        }
    }
}

void WeightedGraph::sortEdges() {
    std::sort(edges.begin(), edges.end());
}

int WeightedGraph::getVertexCount() const {
    return n;
}

const std::vector<WeightedEdge>& WeightedGraph::getEdges() const {
    return edges;
}
