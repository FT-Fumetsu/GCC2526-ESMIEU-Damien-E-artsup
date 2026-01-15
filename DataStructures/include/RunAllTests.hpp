#ifndef _RUN_ALL_TESTS_HPP
#define _RUN_ALL_TESTS_HPP

#include <iostream>

#include "TestArray.hpp"
#include "TestSLinkedList.hpp"
#include "TestDLinkedList.hpp"
#include "TestTree.hpp"
#include "TestBinaryTree.hpp"
#include "TestGraph.hpp"

namespace Data{
    template<class DataType>
    class RunAllTests{
        public : 
        void runAllTests();
    };
}

#endif // _RUN_ALL_TESTS_HPP