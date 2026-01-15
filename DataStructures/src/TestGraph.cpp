#include "TestGraph.hpp"

namespace Data {

    template <class DataType>
    void TestGraph<DataType>::runGraphTest() {
        std::cout << "\n--- Tests Graph (Performance) ---\n\n";

        const int NB_SOMMETS = 10000;
        const int NB_EDGES  = 50000;

        std::cout << "Paramètres du test :\n";
        std::cout << "  Sommets : " << NB_SOMMETS << "\n";
        std::cout << "  Arêtes  : " << NB_EDGES << "\n\n";

        std::cout << "--- Test parcours naïf ---\n";

        Graph<DataType> graphNaif(NB_SOMMETS, NB_EDGES);

        auto startNaif = std::chrono::high_resolution_clock::now();
        graphNaif.naifTraversal();
        auto endNaif = std::chrono::high_resolution_clock::now();

        auto durationNaif =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                endNaif - startNaif
            ).count();

        std::cout << "Temps parcours naïf : "
                  << durationNaif << " ms\n\n";

        std::cout << "--- Test parcours optimisé (union par taille) ---\n";

        Graph<DataType> graphOpt(NB_SOMMETS, NB_EDGES);

        auto startOpt = std::chrono::high_resolution_clock::now();
        graphOpt.optimisedTraversal();
        auto endOpt = std::chrono::high_resolution_clock::now();

        auto durationOpt =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                endOpt - startOpt
            ).count();

        std::cout << "Temps parcours optimisé : "
                  << durationOpt << " ms\n\n";
    }

    template class TestGraph<int>;
}
