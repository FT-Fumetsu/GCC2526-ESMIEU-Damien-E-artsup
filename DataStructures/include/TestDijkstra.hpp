#ifndef _TEST_DIJKSTRA_HPP_
#define _TEST_DIJKSTRA_HPP_

#include <iostream>
#include <chrono>
#include "PointSet.hpp"
#include "WeightedGraph.hpp"
#include "Dijkstra.hpp"

namespace Data {

    template <class DataType>
    class TestDijkstra {
    public:
        static void runDijkstraTest();
    };

}

#endif // _TEST_DIJKSTRA_HPP_
