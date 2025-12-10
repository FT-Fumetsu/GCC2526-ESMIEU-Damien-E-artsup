#ifndef _DLIST_ITERATOR_HPP_
#define _DLIST_ITERATOR_HPP_

#include "DNode.hpp"
#include "DLinkedList.hpp"

template<class DataType>
class DListIterator {
private:
    DLinkedList<DataType>* _list;
    DNode<DataType>* _node;

public:
    DListIterator(DLinkedList<DataType>* list = nullptr);

    void start();
    void end();
    void forth();
    void back();

    DataType& item();
    
    bool isValid();
    bool hasNext();
    bool hasPrevious();

    DNode<DataType>*& node() { return _node; }
};

#endif // _DLIST_ITERATOR_HPP_