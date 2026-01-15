#ifndef _TEST_SLINKED_LIST_
#define _TEST_SLINKED_LIST_

#include "SNode.hpp"
#include "SLinkedList.hpp"
#include "SListIterator.hpp"

#include <iostream>

namespace Data{
    template <class DataType>
    class TestSLinkedList{
        public :
        static void displayLinkedList(SLinkedList<DataType>& list);
        static void runSLinkedListTest();
    };
}

#endif //_TEST_SLINKED_LIST_