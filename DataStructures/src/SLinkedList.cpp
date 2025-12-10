#include "SLinkedList.hpp"
#include "SListExceptions.hpp"
#include "SListIterator.hpp"
#include <NodeFactory.hpp>
#include <cstddef>

template <class DataType>
SLinkedList<DataType>::SLinkedList() {
    _head = nullptr;
    _tail = nullptr;
    _count = 0;
}

template <class DataType>
SLinkedList<DataType>::~SLinkedList(){
    while (_head != nullptr){
        removeHead();
    }
}

template <class DataType>
void SLinkedList<DataType>::append(DataType data){
    SNode<DataType>* node = NodeFactory<DataType>::createSNode(data);    

    if (_tail == nullptr){
        _head = node;
        _tail = node;
    } else {
        _tail->_next = node;
        _tail = node;
    }
    ++_count;
}

template <class DataType>
void SLinkedList<DataType>::prepend(DataType data){
    SNode<DataType>* node = NodeFactory<DataType>::createSNode(data);
    node->_next = _head;
    _head = node;

    if (_tail == nullptr)
        _tail = node;

    ++_count;
}

template <class DataType>
void SLinkedList<DataType>::insert(SListIterator<DataType>& itr, DataType data){
    if (_head == nullptr || itr.node() == _head){
        prepend(data);
        return;
    }

    if (itr.node() == nullptr){
        append(data);
        return;
    }

    SNode<DataType>* prev = _head;
    while (prev != nullptr && prev->_next != itr.node()){
        prev = prev->_next;
    }

    if (prev == nullptr){
        append(data);
        return;
    }

    SNode<DataType>* node = NodeFactory<DataType>::createSNode(data);
    node->_next = itr.node();
    prev->_next = node;
    ++_count;
}

template <class DataType>
void SLinkedList<DataType>::removeHead(){
    if (_head == nullptr) return;

    SNode<DataType>* temp = _head;
    _head = _head->_next;

    if (_head == nullptr)
        _tail = nullptr;

    delete temp;
    --_count;
}

template <class DataType>
void SLinkedList<DataType>::removeTail(){
    if (_tail == nullptr) return;

    if (_head == _tail){
        delete _head;
        _head = nullptr;
        _tail = nullptr;
        _count = 0;
        return;
    }

    SNode<DataType>* cur = _head;
    while (cur->_next != _tail){
        cur = cur->_next;
    }

    delete _tail;
    _tail = cur;
    _tail->_next = nullptr;
    --_count;
}

template <class DataType>
void SLinkedList<DataType>::remove(SListIterator<DataType>& itr){
    if (!itr.isValid()) return;

    SNode<DataType>* target = itr.node();

    if (target == _head){
        removeHead();
        itr.node() = _head;
        return;
    }

    SNode<DataType>* prev = _head;
    while (prev != nullptr && prev->_next != target){
        prev = prev->_next;
    }

    if (prev == nullptr){
        throw NodeNotFoundException("SLinkedList::remove() - node qui n'existe pas");
    }

    prev->_next = target->_next;

    if (target == _tail){
        _tail = prev;
        _tail->_next = nullptr;
    }

    itr.node() = target->_next;

    delete target;
    --_count;
}

template <class DataType>
SListIterator<DataType> SLinkedList<DataType>::getIterator(){
    return SListIterator<DataType>(this);
}

template class SLinkedList<int>;
template class SLinkedList<double>;