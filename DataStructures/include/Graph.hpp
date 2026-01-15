#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <vector>

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace Data{
    struct Edge {
        int u;
        int v;
    };

    template <class DataType>
    class Graph {
    private:
        int nbSommets;
        int nbEdges;

        std::vector<Edge> edges;
        std::vector<int> components;

    public:
        Graph(int nbSommets, int nbEdges);

        void generateEdges();

        void naifTraversal();
        void optimisedTraversal();

        void displayEdges() const;
        void displayComponents() const;
    };
}
#endif // _GRAPH_HPP_