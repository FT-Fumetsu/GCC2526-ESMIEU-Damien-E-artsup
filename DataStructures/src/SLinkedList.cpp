#include "SLinkedList.hpp"
#include "SListExceptions.hpp"
#include "SListIterator.hpp"
#include <NodeFactory.hpp>
#include <cstddef>

template <class DataType>
SLinkedList<DataType>::SLinkedList() {
    head() = nullptr;
    tail() = nullptr;
    count() = 0;
}

template <class DataType>
SLinkedList<DataType>::~SLinkedList(){
    while (head() != nullptr){
        removeHead();
    }
}

template <class DataType>
void SLinkedList<DataType>::append(DataType data){
    SNode<DataType>* node = NodeFactory<DataType>::createSNode(data);    

    if (tail() == nullptr){
        head() = node;
        tail() = node;
    } else {
        tail()->next() = node;
        tail() = node;
    }
    ++count();
}

template <class DataType>
void SLinkedList<DataType>::prepend(DataType data){
    SNode<DataType>* node = NodeFactory<DataType>::createSNode(data);
    node->next() = head();
    head() = node;

    if (tail() == nullptr)
        tail() = node;

    ++count();
}

template <class DataType>
void SLinkedList<DataType>::insert(SListIterator<DataType>& itr, DataType data){
    if (head() == nullptr || itr.node() == head()){
        prepend(data);
        return;
    }

    if (itr.node() == nullptr){
        append(data);
        return;
    }

    SNode<DataType>* prev = head();
    while (prev != nullptr && prev->next() != itr.node()){
        prev = prev->next();
    }

    if (prev == nullptr){
        append(data);
        return;
    }

    SNode<DataType>* node = NodeFactory<DataType>::createSNode(data);
    node->next() = itr.node();
    prev->next() = node;
    ++count();
}

template <class DataType>
void SLinkedList<DataType>::removeHead(){
    if (head() == nullptr) return;

    SNode<DataType>* temp = head();
    head() = head()->next();

    if (head() == nullptr)
        tail() = nullptr;

    delete temp;
    --count();
}

template <class DataType>
void SLinkedList<DataType>::removeTail(){
    if (tail() == nullptr) return;

    if (head() == tail()){
        delete head();
        head() = nullptr;
        tail() = nullptr;
        count() = 0;
        return;
    }

    SNode<DataType>* cur = head();
    while (cur->next() != tail()){
        cur = cur->next();
    }

    delete tail();
    tail() = cur;
    tail()->next() = nullptr;
    --count();
}

template <class DataType>
void SLinkedList<DataType>::remove(SListIterator<DataType>& itr){
    if (!itr.isValid()) return;

    SNode<DataType>* target = itr.node();

    if (target == head()){
        removeHead();
        itr.node() = head();
        return;
    }

    SNode<DataType>* prev = head();
    while (prev != nullptr && prev->next() != target){
        prev = prev->next();
    }

    if (prev == nullptr){
        throw NodeNotFoundException("SLinkedList::remove() - node qui n'existe pas");
    }

    prev->next() = target->next();

    if (target == tail()){
        tail() = prev;
        tail()->next() = nullptr;
    }

    itr.node() = target->next();

    delete target;
    --count();
}

template class SLinkedList<int>;
template class SLinkedList<double>;