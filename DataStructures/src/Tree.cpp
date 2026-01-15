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
        if(_children.head() == nullptr) { return; }
        DListIterator<Node*> itr = _children.getIterator();

        while (itr.isValid())
        {
            Node* child = itr.item();
            itr.forth();
            delete child;
        }

        while (_children.count() > 0)
        {
            _children.removeHead();
        }

        _parent = nullptr;
    }

    template<class Datatype>
    void Tree<Datatype>::appendChild(const Datatype& data)
    {
        Node* child = new Node(data);
        child->_parent = this;
        _children.append(child);
    }

    template<class Datatype>
    void Tree<Datatype>::prependChild(const Datatype& data)
    {
        Node* child = new Node(data);
        child->_parent = this;
        _children.prepend(child);
    }

    template<class Datatype>
    void Tree<Datatype>::insertChildBefore(DListIterator<Node*>& itr, const Datatype& data)
    {
        if (!itr.isValid()) return;

        Node* child = new Node(data);
        child->_parent = this;
        _children.insertBefore(itr, child);
    }

    template<class Datatype>
    void Tree<Datatype>::insertChildAfter(DListIterator<Node*>& itr, const Datatype& data)
    {
        if (!itr.isValid()) return;

        Node* child = new Node(data);
        child->_parent = this;
        _children.insertAfter(itr, child);
    }

    template<class Datatype>
    void Tree<Datatype>::removeChild(DListIterator<Node*>& itr)
    {
        if (!itr.isValid()) return;

        Node* child = itr.item();
        _children.remove(itr);
        delete child;
    }

    template class Tree<int>;
}