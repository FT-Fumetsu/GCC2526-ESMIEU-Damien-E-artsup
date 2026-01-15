#include "SNode.hpp"
#include "NodeFactory.hpp"

namespace Data{
    template<class DataType>
    SNode<DataType>::SNode() {
        _data = DataType();
        _next = nullptr;
    }


    template<class DataType>
    SNode<DataType>::SNode(DataType data) {
        _data = data;
        _next = nullptr;
    }

    template<class DataType>
    SNode<DataType>::~SNode(){
        _next = nullptr;
    }

    template<class DataType>
    void SNode<DataType>::insertAfter(DataType data){
        SNode<DataType>* newNode = NodeFactory<DataType>::createSNode(data);
        newNode->_next = this->_next; // '->' parce que pointeur == (*newNode)._next = (*this)._next
        this->_next = newNode;
    }

    template class SNode<int>;
    template class SNode<double>;
}