#ifndef _DNODE_HPP_
#define _DNODE_HPP_

#include <cstddef>

template<class DataType>
class DNode {
    public:
    DataType _data;
    DNode<DataType>* _next;
    DNode<DataType>* _previous;

    DNode();
    DNode(DataType data);
    ~DNode();

    void insertAfter(DataType data);
    void insertBefore(DataType data);
};

#endif // _DNODE_HPP_