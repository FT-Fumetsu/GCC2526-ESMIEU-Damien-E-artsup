#include "Tree.hpp"

namespace Data{

    template<class Datatype>
    Tree<Datatype>::Tree()
    : _data(),
    _parent(nullptr),
    _children(){

    }

    template<class Datatype>
    Tree<Datatype>::Tree(const Datatype& data)
        : _data(data), _parent(nullptr), _children(){

    }
    
    template<class Datatype>
    Tree<Datatype>::~Tree()
    {
        destroy();
    }

    template<class Datatype>
    int Tree<Datatype>::count()
    {
        int total = 1;

        DListIterator<Node*> itr = _children.getIterator();
        while (itr.isValid())
        {
            total += itr.item()->count();
            itr.forth();
        }

        return total;
    }

    template<class Datatype>
    void Tree<Datatype>::destroy()
    {
        DListIterator<Node*> itr = _children.getIterator();

        while (itr.isValid())
        {
            Node* child = itr.item();

            if (child)
            {
                child->destroy();
                delete child;
            }

            itr.forth();
        }

        while (_children.count() > 0)
        {
            _children.removeHead();
        }

        _parent = nullptr;
    }

    template class Tree<int>;
}