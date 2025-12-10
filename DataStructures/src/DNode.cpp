#include "DNode.hpp"
#include "NodeFactory.hpp"

template<class DataType>
DNode<DataType>::DNode() {
    data() = DataType();
    next() = nullptr;
    previous() = nullptr;
}

template<class DataType>
DNode<DataType>::DNode(DataType Data) {
    data() = Data;
    next() = nullptr;
    previous() = nullptr;
}

template<class DataType>
DNode<DataType>::~DNode() {
    next() = nullptr;
    previous() = nullptr;
}

template<class DataType>
void DNode<DataType>::insertAfter(DataType data) {
    DNode<DataType>* newNode = NodeFactory<DataType>::createDNode(data);
    newNode->next() = this->next();
    newNode->previous() = this;
    if (this->next() != nullptr)
        this->next()->previous() = newNode;
    this->next() = newNode;
}

template<class DataType>
void DNode<DataType>::insertBefore(DataType data) {
    DNode<DataType>* newNode = NodeFactory<DataType>::createDNode(data);
    newNode->previous() = this->previous();
    newNode->next() = this;
    if (this->previous() != nullptr)
        this->previous()->next() = newNode;
    this->previous() = newNode;
}

template class DNode<int>;
template class DNode<double>;
