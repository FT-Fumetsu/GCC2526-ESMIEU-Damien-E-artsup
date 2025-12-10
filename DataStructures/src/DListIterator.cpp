#include "DListIterator.hpp"
#include "DLinkedList.hpp"
#include "SListExceptions.hpp"

template<class DataType>
DListIterator<DataType>::DListIterator(DLinkedList<DataType>* list) {
    list() = list;
    node() = list->head();
}

template<class DataType>
void DListIterator<DataType>::start() {
    if (list()) node() = list()->head();
}

template<class DataType>
void DListIterator<DataType>::end() {
    if (list()) node() = list()->tail();
}

template<class DataType>
void DListIterator<DataType>::forth() {
    if (node()) node() = node()->next();
}

template<class DataType>
void DListIterator<DataType>::back() {
    if (node()) node() = node()->previous();
}

template<class DataType>
DataType& DListIterator<DataType>::item() {
    if (!node())
        throw NodeNotFoundException("DListIterator::item() - node qui n'existe pas");
    return node()->data();
}

template<class DataType>
bool DListIterator<DataType>::isValid() {
    return node() != nullptr;
}

template<class DataType>
bool DListIterator<DataType>::hasNext() {
    return node() && node()->next() != nullptr;
}

template<class DataType>
bool DListIterator<DataType>::hasPrevious() {
    return node() && node()->previous() != nullptr;
}

template class DListIterator<int>;
template class DListIterator<double>;
