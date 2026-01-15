#include "Graph.hpp"

namespace Data{
    template <class DataType>
    Graph<DataType>::Graph(int nbSommets, int nbEdges)
        : nbSommets(nbSommets), nbEdges(nbEdges)
    {
        edges.resize(nbEdges);
        components.resize(nbSommets);

        for (int i = 0; i < nbSommets; i++) {
            components[i] = i;
        }

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        generateEdges();
    }

    template <class DataType>
    void Graph<DataType>::generateEdges() {
        for (int i = 0; i < nbEdges; i++) {
            edges[i].u = std::rand() % nbSommets;
            edges[i].v = std::rand() % nbSommets;
        }
    }

    template <class DataType>
    void Graph<DataType>::naifTraversal() {
        for (int i = 0; i < nbEdges; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if (components[u] != components[v]) {
                int compU = components[u];
                int compV = components[v];

                for (int k = 0; k < nbSommets; k++) {
                    if (components[k] == compU) {
                        components[k] = compV;
                    }
                }
            }
        }
    }

    template <class DataType>
    void Graph<DataType>::optimisedTraversal() {
        std::vector<std::vector<int>> compLists(nbSommets);

        for (int v = 0; v < nbSommets; ++v) {
            components[v] = v;
            compLists[v].push_back(v);
        }

        for (int i = 0; i < nbEdges; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;

            int cu = components[u];
            int cv = components[v];

            if (cu != cv) {
                if (compLists[cu].size() > compLists[cv].size()) {
                    std::swap(cu, cv);
                }

                for (int x : compLists[cu]) {
                    components[x] = cv;
                    compLists[cv].push_back(x);
                }

                compLists[cu].clear();
            }
        }
    }

    template <class DataType>
    void Graph<DataType>::displayEdges() const {
        for (int i = 0; i < nbEdges; i++) {
            std::cout << "Edge " << i
                    << " : (" << edges[i].u
                    << ", " << edges[i].v << ")\n";
        }
    }

    template <class DataType>
    void Graph<DataType>::displayComponents() const {
        for (int i = 0; i < nbSommets; i++) {
            std::cout << "Sommet " << i
                    << " -> component " << components[i] << "\n";
        }
    }

template class Graph<int>;
}

