#ifndef _TEST_DLINKED_LIST_HPP
#define _TEST_DLINKED_LIST_HPP

#include "DNode.hpp"
#include "DLinkedList.hpp"
#include "DListIterator.hpp"

#include <iostream>

namespace Data{
    template <class DataType>
    class TestDLinkedList{
        public:
        static void displayDLinkedList(DLinkedList<DataType>& list);
        static void runDLinkedListTest();
    };
}

#endif // _TEST_DLINKED_LIST_HPP