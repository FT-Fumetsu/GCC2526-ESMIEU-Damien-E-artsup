#ifndef _TREE_HPP_
#define _TREE_HPP_

#include "DLinkedList.hpp"
#include "DListIterator.hpp"

namespace Data
{
    template<class Datatype>
    class Tree
    {
    private:
        typedef Tree<Datatype> Node;
        Datatype _data;
        Node* _parent;
        DLinkedList<Node*> _children;
    
    public:
        Tree();
        Tree(const Datatype& data);
        ~Tree();

        int count();
        void destroy();

        void appendChild(const Datatype& data);
        void prependChild(const Datatype& data);
        void insertChildBefore(DListIterator<Node*>& itr, const Datatype& data);
        void insertChildAfter(DListIterator<Node*>& itr, const Datatype& data);
        void removeChild(DListIterator<Node*>& itr);

        Datatype& Data() { return _data; };
        Node*& Parent() { return _parent; };
        DLinkedList<Node*>& Children() { return _children; };
    };
}

#endif // _TREE_HPP_