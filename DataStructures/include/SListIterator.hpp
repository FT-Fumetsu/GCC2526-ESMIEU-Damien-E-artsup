#ifndef _SLIST_ITERATOR_HPP_
#define _SLIST_ITERATOR_HPP_

#include "SLinkedList.hpp"
#include <cstddef>

namespace Data{
    template <class DataType> class SLinkedList;

    template <class DataType>
    class SListIterator {
    private:
        SLinkedList<DataType>* _list;
        SNode<DataType>* _node;
    public:
        SListIterator(SLinkedList<DataType>* list = nullptr);
        SListIterator(SLinkedList<DataType>& list);

        void start();
        void forth();

        DataType& item();
        bool isValid();
        bool hasNext();

        SNode<DataType>*& node() { return _node; }
        SLinkedList<DataType>*& list() { return _list; };
    };
}


#endif // _SLIST_ITERATOR_HPP_