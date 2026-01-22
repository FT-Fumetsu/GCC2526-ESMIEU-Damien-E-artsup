#ifndef SVGEXPORTER_HPP
#define SVGEXPORTER_HPP

#include <string>
#include "PointSet.hpp"
#include "KruskalMST.hpp"

namespace Data {
    template <class DataType>
    class SVGExporter {
    private:
        int width;
        int height;

    public:
        SVGExporter(int w, int h);
        void exportSVG(const std::string& filename,
                    const PointSet& points,
                    const KruskalMST<DataType>& mst);
    };
}
#endif
