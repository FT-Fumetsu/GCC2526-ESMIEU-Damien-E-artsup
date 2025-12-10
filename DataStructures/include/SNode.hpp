#ifndef _SNODE_HPP_
#define _SNODE_HPP_

#include <cstddef>

template<class DataType>
class SNode{
    public:
    DataType _data;
    SNode<DataType>* _next;

    SNode();
    SNode(DataType data);
    ~SNode();

    void insertAfter(DataType data);
};

#endif // _SNode_HPP_