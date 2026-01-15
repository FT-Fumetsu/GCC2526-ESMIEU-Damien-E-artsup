#ifndef _TEST_TREE_HPP_
#define _TEST_TREE_HPP_

#include "Tree.hpp"
#include "TreeIterator.hpp"

#include <iostream>

namespace Data{
    template <class DataType>
    class TestTree{
        public:
        static void displayTree(Tree<DataType>* node, int depth = 0);
        static void runTreeTest();
    };
}

#endif // _TEST_TREE_HPP_