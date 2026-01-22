#ifndef _KRUSKALMST_HPP_
#define _KRUSKALMST_HPP_

#include <vector>
#include "WeightedGraph.hpp"

namespace Data{
    template <class DataType>
    class KruskalMST {
    private:
        std::vector<WeightedEdge> mst;
        double totalWeight;

    public:
        KruskalMST(const WeightedGraph& graph);

        const std::vector<WeightedEdge>& getEdges() const;
        double getTotalWeight() const;
    };
}
#endif // _KRUSKALMST_HPP_