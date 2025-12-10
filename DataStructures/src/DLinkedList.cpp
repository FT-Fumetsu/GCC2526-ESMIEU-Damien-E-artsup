#include "DLinkedList.hpp"
#include "DListIterator.hpp"
#include "NodeFactory.hpp"
#include "SListExceptions.hpp"

template<class DataType>
DLinkedList<DataType>::DLinkedList()
{
    _head = nullptr;
    _tail = nullptr;
    _count = 0;
}

template<class DataType>
DLinkedList<DataType>::~DLinkedList()
{
    while (_head != nullptr)
        removeHead();
}

template<class DataType>
void DLinkedList<DataType>::append(DataType data)
{
    DNode<DataType>* node = NodeFactory<DataType>::createDNode(data);
    if (_tail == nullptr)
    {
        _head = _tail = node;
    }
    else
    {
        _tail->_next = node;
        node->_previous = _tail;
        _tail = node;
    }
    ++_count;
}

template<class DataType>
void DLinkedList<DataType>::prepend(DataType data)
{
    DNode<DataType>* node = NodeFactory<DataType>::createDNode(data);
    if (_head == nullptr)
    {
        _head = _tail = node;
    }
    else
    {
        node->_next = _head;
        _head->_previous = node;
        _head = node;
    }
    ++_count;
}

template<class DataType>
void DLinkedList<DataType>::insert(DListIterator<DataType>& itr, DataType data)
{
    if (_head == nullptr || !itr.isValid())
    {
        prepend(data);
        return;
    }
    if (!itr.isValid())
    {
        append(data);
        return;
    }
    itr.node()->insertBefore(data);
    if (itr.node() == _head->_previous) _head = itr.node()->_previous;
    ++_count;
}

template<class DataType>
void DLinkedList<DataType>::removeHead()
{
    if (!_head) return;
    DNode<DataType>* temp = _head;
    _head = _head->_next;
    if (_head) _head->_previous = nullptr;
    else _tail = nullptr;
    delete temp;
    --_count;
}

template<class DataType>
void DLinkedList<DataType>::removeTail()
{
    if (!_tail) return;
    DNode<DataType>* temp = _tail;
    _tail = _tail->_previous;
    if (_tail) _tail->_next = nullptr;
    else _head = nullptr;
    delete temp;
    --_count;
}

template<class DataType>
void DLinkedList<DataType>::remove(DListIterator<DataType>& itr)
{
    if (!itr.isValid()) return;
    DNode<DataType>* target = itr.node();
    if (target == _head)
    {
        removeHead();
        itr.node() = _head;
        return;
    }
    if (target == _tail)
    {
        removeTail();
        itr.node() = nullptr;
        return;
    }

    DNode<DataType>* prev = target->_previous;
    DNode<DataType>* next = target->_next;
    if (prev) prev->_next = next;
    if (next) next->_previous = prev;

    itr.node() = next;
    delete target;
    --_count;
}

template<class DataType>
DListIterator<DataType> DLinkedList<DataType>::getIterator()
{
    return DListIterator<DataType>(this);
}

template class DLinkedList<int>;
template class DLinkedList<double>;
