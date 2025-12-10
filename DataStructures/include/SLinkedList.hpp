#ifndef _SLINKED_LIST_HPP_
#define _SLINKED_LIST_HPP_

#include "SNode.hpp"
#include <cstddef>

template<class>
class SListIterator;


template <class DataType>
class SLinkedList{
    private: 
    SNode<DataType>* _head;
    SNode<DataType>* _tail;
    size_t _count;

    public :

    SLinkedList();
    ~SLinkedList();

    void append(DataType data); // Ajouter après la tail et nouvelle node = tail
    void prepend(DataType data); // Ajouter avant la head et nouvelle node = head
    void insert(SListIterator<DataType>& itr, DataType data);

    void removeHead();
    void removeTail();
    void remove(SListIterator<DataType>& itr);

    SListIterator<DataType> getIterator(); // return SListIterator<DataType>(this);

    SNode<DataType>* head();
    SNode<DataType>* tail();
    size_t count();
};

#endif // _SLINKED_LIST_HPP_