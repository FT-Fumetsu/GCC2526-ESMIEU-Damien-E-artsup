#include "DListIterator.hpp"
#include "DLinkedList.hpp"
#include "SListExceptions.hpp"

template<class DataType>
DListIterator<DataType>::DListIterator(DLinkedList<DataType>* List) {
    _list = List;
    _node = List->head();
}

template<class DataType>
void DListIterator<DataType>::start() {
    if (_list) _node = _list->head();
}

template<class DataType>
void DListIterator<DataType>::end() {
    if (_list) _node = _list->tail();
}

template<class DataType>
void DListIterator<DataType>::forth() {
    if (_node) _node = _node->next();
}

template<class DataType>
void DListIterator<DataType>::back() {
    if (_node) _node = _node->previous();
}

template<class DataType>
DataType& DListIterator<DataType>::item() {
    if (!_node)
        throw NodeNotFoundException("DListIterator::item() - node qui n'existe pas");
    return _node->data();
}

template<class DataType>
bool DListIterator<DataType>::isValid() {
    return _node != nullptr;
}

template<class DataType>
bool DListIterator<DataType>::hasNext() {
    return _node && _node->next() != nullptr;
}

template<class DataType>
bool DListIterator<DataType>::hasPrevious() {
    return _node && _node->previous() != nullptr;
}

template class DListIterator<int>;
template class DListIterator<double>;
