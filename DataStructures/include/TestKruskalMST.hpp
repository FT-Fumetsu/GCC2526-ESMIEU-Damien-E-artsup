#ifndef _TEST_KRUSKAL_MST_HPP_
#define _TEST_KRUSKAL_MST_HPP_

#include <iostream>
#include <chrono>

#include "PointSet.hpp"
#include "WeightedGraph.hpp"
#include "KruskalMST.hpp"

namespace Data {
    template <class DataType>
    class TestKruskalMST {
    public:
        static void runKruskalTest();
    };
}

#endif // _TEST_KRUSKAL_MST_HPP_
