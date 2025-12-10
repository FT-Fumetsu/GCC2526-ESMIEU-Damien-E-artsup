#include "SListIterator.hpp"
#include "SLinkedList.hpp"
#include "SListExceptions.hpp"

template <class DataType>
SListIterator<DataType>::SListIterator(SLinkedList<DataType>* list){
    this->list() = list;
    this->node() = list->head();
}

template <class DataType>
SListIterator<DataType>::SListIterator(SLinkedList<DataType>& list){
    this->list() = &list;
    this->node() = list.head();
}

template <class DataType>
void SListIterator<DataType>::start(){
    if(this->list() != nullptr){
        this->node() = this->list()->head();
    }
}

template <class DataType>
void SListIterator<DataType>::forth(){
    if(this->node() != nullptr){
        this->node() = this->node()->next();
    }
}

template <class DataType>
DataType& SListIterator<DataType>::item(){
    if(this->node() == nullptr){
        throw NodeNotFoundException("SListIterator::item() - node qui n'existe pas");
    }
    return this->node()->data();
}

template <class DataType>
bool SListIterator<DataType>::isValid(){
    return this->node() != nullptr;
}

template <class DataType>
bool SListIterator<DataType>::hasNext(){
    return this->node() != nullptr && this->node()->next() != nullptr;
}

template class SListIterator<int>;
template class SListIterator<double>;