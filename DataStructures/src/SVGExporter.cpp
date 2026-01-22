#include "SVGExporter.hpp"

#include <fstream>
#include <iostream>

namespace Data {

    template <class DataType>
    SVGExporter<DataType>::SVGExporter(int w, int h)
        : width(w), height(h)
    {
    }

    template <class DataType>
    void SVGExporter<DataType>::exportSVG(const std::string& filename,
                                          const PointSet& points,
                                          const KruskalMST<DataType>& mst)
    {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: cannot open " << filename << std::endl;
            return;
        }

        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
             << "width=\"" << width << "\" height=\"" << height << "\" "
             << "viewBox=\"0 0 " << width << " " << height << "\">\n\n";

        file << "  <rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n\n";

        file << "  <g stroke=\"#888\" stroke-width=\"1.5\">\n";
        for (const auto& edge : mst.getEdges()) {
            const Point& p1 = points[edge.u];
            const Point& p2 = points[edge.v];

            file << "    <line x1=\"" << p1.x
                 << "\" y1=\"" << p1.y
                 << "\" x2=\"" << p2.x
                 << "\" y2=\"" << p2.y
                 << "\" />\n";
        }
        file << "  </g>\n\n";

        file << "  <g fill=\"#333\">\n";
        for (const auto& point : points.getPoints()) {
            file << "    <circle cx=\"" << point.x
                 << "\" cy=\"" << point.y
                 << "\" r=\"4\" />\n";
        }
        file << "  </g>\n\n";

        file << "</svg>\n";
        file.close();

        std::cout << filename << " generated" << std::endl;
    }

    template class SVGExporter<int>;
}
