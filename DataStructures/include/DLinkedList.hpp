#ifndef _DLINKED_LIST_HPP_
#define _DLINKED_LIST_HPP_

#include "DNode.hpp"
#include "SListIterator.hpp"
#include <cstddef>

template<class>
class DListIterator;

template<class DataType>
class DLinkedList {
private: 
    DNode<DataType>* _head;
    DNode<DataType>* _tail;
    size_t _count;

public:
    DLinkedList();
    ~DLinkedList();

    void append(DataType data);
    void prepend(DataType data);
    void insertBefore(DListIterator<DataType>& itr, DataType data);
    void insertAfter(DListIterator<DataType>& itr, DataType data);

    void removeHead();
    void removeTail();
    void remove(DListIterator<DataType>& itr);

    DListIterator<DataType> getIterator();

    DNode<DataType>*& head() { return _head; };
    DNode<DataType>*& tail() { return _tail; };
    size_t& count() { return _count; };
};

#endif // _DLINKED_LIST_HPP_