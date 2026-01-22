#include "TestKruskalMST.hpp"
#include "SVGExporter.hpp"

#include <chrono>
#include <iostream>
#include <string>

namespace Data {

    template <class DataType>
    void TestKruskalMST<DataType>::runKruskalTest() {

        std::cout << "\n--- Tests Kruskal MST (Performance & Correctness) ---\n\n";

        const int NB_POINTS = 1000;
        const int WIDTH  = 1000;
        const int HEIGHT = 1000;

        std::cout << "Paramètres du test :\n";
        std::cout << "  Points : " << NB_POINTS << "\n";
        std::cout << "  Zone   : " << WIDTH << " x " << HEIGHT << "\n\n";

        PointSet points(NB_POINTS, WIDTH, HEIGHT);

        SVGExporter<DataType> exporter(WIDTH, HEIGHT);

        for (auto distType :
            { DistanceType::EUCLID,
              DistanceType::MANHATTAN,
              DistanceType::CHEBYSHEV })
        {
            std::string distName;
            std::string fileSuffix;

            if (distType == DistanceType::EUCLID) {
                distName = "Euclidienne";
                fileSuffix = "euclid";
            }
            else if (distType == DistanceType::MANHATTAN) {
                distName = "Manhattan";
                fileSuffix = "manhattan";
            }
            else {
                distName = "Chebyshev";
                fileSuffix = "chebyshev";
            }

            std::cout << "--- Distance " << distName << " ---\n";

            WeightedGraph graph(points, distType);

            auto startSort = std::chrono::high_resolution_clock::now();
            graph.sortEdges();
            auto endSort = std::chrono::high_resolution_clock::now();

            auto sortTime =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    endSort - startSort
                ).count();

            std::cout << "Temps tri des arêtes : "
                      << sortTime << " ms\n";

            auto startKruskal = std::chrono::high_resolution_clock::now();
            KruskalMST<DataType> mst(graph);
            auto endKruskal = std::chrono::high_resolution_clock::now();

            auto kruskalTime =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    endKruskal - startKruskal
                ).count();

            std::cout << "Temps Kruskal : "
                      << kruskalTime << " ms\n";

            std::cout << "Arêtes MST : "
                      << mst.getEdges().size()
                      << " (attendu : " << NB_POINTS - 1 << ")\n";

            std::cout << "Poids total MST : "
                      << mst.getTotalWeight() << "\n";

            std::string filename = "mst_" + fileSuffix + ".svg";
            exporter.exportSVG(filename, points, mst);

            std::cout << "SVG exporté : " << filename << "\n\n";
        }
    }

    template class TestKruskalMST<int>;
}
