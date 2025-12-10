#include "DLinkedList.hpp"
#include "DListIterator.hpp"
#include "NodeFactory.hpp"
#include "SListExceptions.hpp"

template<class DataType>
DLinkedList<DataType>::DLinkedList() {
    head() = nullptr;
    tail() = nullptr;
    count() = 0;
}

template<class DataType>
DLinkedList<DataType>::~DLinkedList() {
    while (head() != nullptr)
        removeHead();
}

template<class DataType>
void DLinkedList<DataType>::append(DataType data) {
    DNode<DataType>* node = NodeFactory<DataType>::createDNode(data);
    if (tail() == nullptr) {
        head() = tail() = node;
    } else {
        tail()->next() = node;
        node->previous() = tail();
        tail() = node;
    }
    ++count();
}

template<class DataType>
void DLinkedList<DataType>::prepend(DataType data) {
    DNode<DataType>* node = NodeFactory<DataType>::createDNode(data);
    if (head() == nullptr) {
        head() = tail() = node;
    } else {
        node->next() = head();
        head()->previous() = node;
        head() = node;
    }
    ++count();
}

template<class DataType>
void DLinkedList<DataType>::insert(DListIterator<DataType>& itr, DataType data) {
    if (head() == nullptr || !itr.isValid()) {
        prepend(data);
        return;
    }
    if (!itr.isValid()) {
        append(data);
        return;
    }
    itr.node()->insertBefore(data);
    if (itr.node() == head()->previous()) head() = itr.node()->previous();
    ++count();
}

template<class DataType>
void DLinkedList<DataType>::removeHead() {
    if (!head()) return;
    DNode<DataType>* temp = head();
    head() = head()->next();
    if (head()) head()->previous() = nullptr;
    else tail() = nullptr;
    delete temp;
    --count();
}

template<class DataType>
void DLinkedList<DataType>::removeTail() {
    if (!tail()) return;
    DNode<DataType>* temp = tail();
    tail() = tail()->previous();
    if (tail()) tail()->next() = nullptr;
    else head() = nullptr;
    delete temp;
    --count();
}

template<class DataType>
void DLinkedList<DataType>::remove(DListIterator<DataType>& itr) {
    if (!itr.isValid()) return;
    DNode<DataType>* target = itr.node();
    if (target == head()) {
        removeHead();
        itr.node() = head();
        return;
    }
    if (target == tail()) {
        removeTail();
        itr.node() = nullptr;
        return;
    }

    DNode<DataType>* prev = target->previous();
    DNode<DataType>* next = target->next();
    if (prev) prev->next() = next;
    if (next) next->previous() = prev;

    itr.node() = next;
    delete target;
    --count();
}

template<class DataType>
DListIterator<DataType> DLinkedList<DataType>::getIterator() {
    return DListIterator<DataType>(this);
}

template class DLinkedList<int>;
template class DLinkedList<double>;
