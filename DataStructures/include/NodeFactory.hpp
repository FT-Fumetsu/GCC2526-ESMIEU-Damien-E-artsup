#ifndef _NODE_FACTORY_HPP_
#define _NODE_FACTORY_HPP_

#include "SNode.hpp"
#include "DNode.hpp"

template <class T>
class NodeFactory{
    public:
    static SNode<T>* createSNode(T data){
        return new SNode<T>(data);
    }

    static DNode<T>* createDNode(T data){
        return new DNode<T>(data);
    }
};

#endif // NODE_FACTORY_HPP_