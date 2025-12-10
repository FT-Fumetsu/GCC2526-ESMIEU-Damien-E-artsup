#include "SNode.hpp"
#include "NodeFactory.hpp"

template<class DataType>
SNode<DataType>::SNode() {
    data() = DataType();
    next() = nullptr;
}


template<class DataType>
SNode<DataType>::SNode(DataType data) {
    data() = data;
    next() = nullptr;
}

template<class DataType>
SNode<DataType>::~SNode(){
    next() = nullptr;
}

template<class DataType>
void SNode<DataType>::insertAfter(DataType data){
    SNode<DataType>* newNode = NodeFactory<DataType>::createSNode(data);
    newNode->next() = this->next(); // '->' parce que pointeur == (*newNode)._next = (*this)._next
    this->next() = newNode;
}

template class SNode<int>;
template class SNode<double>;
