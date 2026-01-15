#ifndef _SNODE_HPP_
#define _SNODE_HPP_

#include <cstddef>

namespace Data{
    template<class DataType>
    class SNode{
        private:
        DataType _data;
        SNode<DataType>* _next;

        public:
        SNode();
        SNode(DataType data);
        ~SNode();

        void insertAfter(DataType data);

        DataType& data() { return _data; };
        SNode<DataType>*& next() { return _next; };
    };
}


#endif // _SNode_HPP_