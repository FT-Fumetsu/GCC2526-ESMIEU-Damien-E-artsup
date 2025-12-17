#include "DNode.hpp"
#include "NodeFactory.hpp"

template<class DataType>
DNode<DataType>::DNode() {
    _data = DataType();
    _next = nullptr;
    _previous = nullptr;
}

template<class DataType>
DNode<DataType>::DNode(DataType data) {
    _data = data;
    _next = nullptr;
    _previous = nullptr;
}

template<class DataType>
DNode<DataType>::~DNode() {
    _next = nullptr;
    _previous = nullptr;
}

template<class DataType>
void DNode<DataType>::insertAfter(DataType data) {
    DNode<DataType>* newNode = NodeFactory<DataType>::createDNode(data);
    newNode->_next = this->_next;
    newNode->_previous = this;
    if (this->_next != nullptr)
        this->_next->_previous = newNode;
    this->_next = newNode;
}

template<class DataType>
void DNode<DataType>::insertBefore(DataType data) {
    DNode<DataType>* newNode = NodeFactory<DataType>::createDNode(data);
    newNode->_previous = this->_previous;
    newNode->_next = this;
    if (this->_previous != nullptr)
        this->_previous->_next = newNode;
    this->_previous = newNode;
}

template class DNode<int>;
template class DNode<double>;
