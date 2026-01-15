#include "SListIterator.hpp"
#include "SLinkedList.hpp"
#include "SListExceptions.hpp"

namespace Data{
    template <class DataType>
    SListIterator<DataType>::SListIterator(SLinkedList<DataType>* list){
        this->_list = list;
        this->_node = list->head();
    }

    template <class DataType>
    SListIterator<DataType>::SListIterator(SLinkedList<DataType>& list){
        this->_list = &list;
        this->_node = list.head();
    }

    template <class DataType>
    void SListIterator<DataType>::start(){
        if(this->_list != nullptr){
            this->_node = this->_list->head();
        }
    }

    template <class DataType>
    void SListIterator<DataType>::forth(){
        if(this->_node != nullptr){
            this->_node = this->_node->next();
        }
    }

    template <class DataType>
    DataType& SListIterator<DataType>::item(){
        if(this->_node == nullptr){
            throw NodeNotFoundException("SListIterator::item() - node qui n'existe pas");
        }
        return this->_node->data();
    }

    template <class DataType>
    bool SListIterator<DataType>::isValid(){
        return this->_node != nullptr;
    }

    template <class DataType>
    bool SListIterator<DataType>::hasNext(){
        return this->_node != nullptr && this->_node->next() != nullptr;
    }

    template class SListIterator<int>;
    template class SListIterator<double>;
}
