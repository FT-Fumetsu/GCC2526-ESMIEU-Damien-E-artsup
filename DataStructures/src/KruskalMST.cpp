#include "KruskalMST.hpp"
namespace Data{
    template <class DataType>
    KruskalMST<DataType>::KruskalMST(const WeightedGraph& graph) {
        int n = graph.getVertexCount();
        std::vector<int> component(n);

        for (int i = 0; i < n; ++i)
            component[i] = i;

        totalWeight = 0;

        for (const auto& e : graph.getEdges()) {
            if (component[e.u] != component[e.v]) {
                mst.push_back(e);
                totalWeight += e.weight;

                int oldC = component[e.u];
                int newC = component[e.v];

                for (int i = 0; i < n; ++i)
                    if (component[i] == oldC)
                        component[i] = newC;

                if (mst.size() == n - 1)
                    break;
            }
        }
    }

    template <class DataType>
    const std::vector<WeightedEdge>& KruskalMST<DataType>::getEdges() const {
        return mst;
    }

    template <class DataType>
    double KruskalMST<DataType>::getTotalWeight() const {
        return totalWeight;
    }

    template class KruskalMST<int>;
}