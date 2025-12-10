#ifndef _DLINKED_LIST_HPP_
#define _DLINKED_LIST_HPP_

#include "DNode.hpp"
#include <cstddef>

template<class>
class DListIterator;

template<class DataType>
class DLinkedList {
public:
    DNode<DataType>* _head;
    DNode<DataType>* _tail;
    size_t _count;

    DLinkedList();
    ~DLinkedList();

    void append(DataType data);
    void prepend(DataType data);
    void insert(DListIterator<DataType>& itr, DataType data);

    void removeHead();
    void removeTail();
    void remove(DListIterator<DataType>& itr);

    DListIterator<DataType> getIterator();
};

#endif // _DLINKED_LIST_HPP_