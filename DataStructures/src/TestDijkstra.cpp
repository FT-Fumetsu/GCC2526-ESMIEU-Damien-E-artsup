#include "TestDijkstra.hpp"

#include <chrono>
#include <iostream>
#include <string>

namespace Data {

    template <class DataType>
    void TestDijkstra<DataType>::runDijkstraTest() {

        std::cout << "\n--- Tests Dijkstra (Performance & Correctness) ---\n\n";

        const int NB_POINTS = 500;
        const int WIDTH  = 800;
        const int HEIGHT = 600;

        std::cout << "Paramètres du test :\n";
        std::cout << "  Points : " << NB_POINTS << "\n";
        std::cout << "  Zone   : " << WIDTH << " x " << HEIGHT << "\n\n";

        PointSet points(NB_POINTS, WIDTH, HEIGHT);

        for (auto distType : { DistanceType::EUCLID,
                               DistanceType::MANHATTAN,
                               DistanceType::CHEBYSHEV })
        {
            std::string distName;
            if (distType == DistanceType::EUCLID)
                distName = "Euclidienne";
            else if (distType == DistanceType::MANHATTAN)
                distName = "Manhattan";
            else
                distName = "Chebyshev";

            std::cout << "--- Distance " << distName << " ---\n";

            WeightedGraph graph(points, distType);

            int source = 0;
            int target = NB_POINTS - 1;

            auto startDijkstra = std::chrono::high_resolution_clock::now();
            auto result = Dijkstra::shortestPath(graph, source, target);
            auto endDijkstra = std::chrono::high_resolution_clock::now();

            auto elapsed =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    endDijkstra - startDijkstra
                ).count();

            std::cout << "Temps Dijkstra : " << elapsed << " ms\n";

            if (!result.path.empty()) {
                std::cout << "Chemin de " << source << " → " << target << " : ";
                for (auto v : result.path)
                    std::cout << v << " ";
                std::cout << "\nDistance totale : " << result.distance << "\n\n";
            }
            else {
                std::cout << "Pas de chemin possible entre " 
                          << source << " et " << target << "\n\n";
            }
        }
    }
    template class TestDijkstra<int>;
}