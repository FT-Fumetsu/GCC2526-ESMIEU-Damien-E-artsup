#ifndef _DNODE_HPP_
#define _DNODE_HPP_

#include <cstddef>

namespace Data{
    template<class>
    class Tree;

    template<class>
    class TreeIterator;

    template<class DataType>
    class DNode {
        private:
        DataType _data;
        DNode<DataType>* _next;
        DNode<DataType>* _previous;

        public:
        DNode();
        DNode(DataType data);
        ~DNode();

        void insertAfter(DataType data);
        void insertBefore(DataType data);

        DataType& data() { return _data; };
        DNode<DataType>*& next() { return _next; };
        DNode<DataType>*& previous() { return _previous; };
    };
}


#endif // _DNODE_HPP_