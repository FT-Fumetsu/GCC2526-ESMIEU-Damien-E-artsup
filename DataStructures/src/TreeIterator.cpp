#include "TreeIterator.hpp"

#include <iostream>

namespace Data{

    template <class Datatype>
    TreeIterator<Datatype>::TreeIterator(Node* node)
        : _node(node){
            std::cout << "Initializing TreeIterator at node with data: " << _node->Data() << "\n";

            if (_node)
            {
                _childItr = _node->Children().getIterator();
            }

          }

    template <class Datatype>
    void TreeIterator<Datatype>::goUp()
    {
        if (_node && _node->Parent())
        {
            _node = _node->Parent();
            resetIterator();
        }
    }

    template <class Datatype>
    void TreeIterator<Datatype>::goDown()
    {
        if (!_node) return;

        auto itr = _node->Children().getIterator();
        if (itr.isValid())
        {
            _node = itr.item();
            resetIterator();
        }
    }

    template <class Datatype>
    void TreeIterator<Datatype>::goRoot()
    {
        if (!_node) return;

        while (_node->Parent())
            _node = _node->Parent();

        resetIterator();
    }

    template <class Datatype>
    void TreeIterator<Datatype>::childStart()
    {
        if (_node)
            _childItr = _node->Children().getIterator();
    }

    template <class Datatype>
    void TreeIterator<Datatype>::childEnd()
    {
        if (_node)
        {
            _childItr = _node->Children().getIterator();
            _childItr.end();
        }
    }

    template <class Datatype>
    void TreeIterator<Datatype>::childForth()
    {
        _childItr.forth();
    }

    template <class Datatype>
    void TreeIterator<Datatype>::childBack()
    {
        _childItr.back();
    }

    template <class Datatype>
    bool TreeIterator<Datatype>::isValidChild()
    {
        return _childItr.isValid();
    }

    template <class Datatype>
    typename TreeIterator<Datatype>::Node*
    TreeIterator<Datatype>::itemChild()
    {
        return _childItr.item();
    }

    template <class Datatype>
    TreeIterator<Datatype>&
    TreeIterator<Datatype>::operator=(Node* node)
    {
        _node = node;
        resetIterator();
        return *this;
    }

    template <class Datatype>
    void TreeIterator<Datatype>::resetIterator()
    {
        if (_node)
            _childItr = _node->Children().getIterator();
    }

    template class TreeIterator<int>;
}