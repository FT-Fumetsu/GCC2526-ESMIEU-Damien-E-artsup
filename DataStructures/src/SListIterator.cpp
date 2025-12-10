#include "SListIterator.hpp"
#include "SListExceptions.hpp"

template <class DataType>
SListIterator<DataType>::SListIterator(SLinkedList<DataType>* list){
    this->_list = list;
    if(list != nullptr){
        this->_node = list->_head;
    }
}

template <class DataType>
SListIterator<DataType>::SListIterator(SLinkedList<DataType>& list){
    this->_list = &list;
    if(list != nullptr){
        this->_node = list._head;
    }
}

template <class DataType>
void SListIterator<DataType>::start(){
    if(this->_list != nullptr){
        this->_node = this->_list->_node
    }    
}

template <class DataType>
void SListIterator<DataType>::forth(){
    if(this->_node != nullptr){
        this->_node = this->_node->_next
    }
}

template <class DataType>
DataType& SListIterator<DataType>::item(){
    if(this->_node == nullptr){
        throw NodeNotFoundException("SListIterator::item() - node qui n'existe pas");
    }
    return this->_node->_data;
}

template <class DataType>
bool SListIterator<DataType>::isValid(){
    return this->_node != nullptr;
}

template <class DataType>
bool SListIterator<DataType>::hasNext(){
    return this->_node != nullptr && this->_node->_next != nullptr;
}

template class SListIterator<int>;
template class SListIterator<double>;