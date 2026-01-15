#include "BinaryTree.hpp"

namespace Data
{
    template<class Datatype>
    BinaryTree<Datatype>::BinaryTree()
        : _data(), _left(nullptr), _right(nullptr), _parent(nullptr)
    {
    }

    template<class Datatype>
    BinaryTree<Datatype>::BinaryTree(const Datatype& data)
        : _data(data), _left(nullptr), _right(nullptr), _parent(nullptr)
    {
    }

    template<class Datatype>
    BinaryTree<Datatype>::~BinaryTree()
    {
        destroy();
    }

    template<class Datatype>
    void BinaryTree<Datatype>::destroy()
    {
        if (_left)
        {
            delete _left;
            _left = nullptr;
        }

        if (_right)
        {
            delete _right;
            _right = nullptr;
        }

        _parent = nullptr;
    }

    template<class Datatype>
    void BinaryTree<Datatype>::setLeft(Node* node)
    {
        _left = node;
        if (node)
            node->_parent = this;
    }

    template<class Datatype>
    void BinaryTree<Datatype>::setRight(Node* node)
    {
        _right = node;
        if (node)
            node->_parent = this;
    }

    template<class Datatype>
    bool BinaryTree<Datatype>::hasLeft() const
    {
        return _left != nullptr;
    }

    template<class Datatype>
    bool BinaryTree<Datatype>::hasRight() const
    {
        return _right != nullptr;
    }

    template<class Datatype>
    bool BinaryTree<Datatype>::isLeaf() const
    {
        return !_left && !_right;
    }

    template<class Datatype>
    int BinaryTree<Datatype>::count() const
    {
        int total = 1;

        if (_left)
            total += _left->count();

        if (_right)
            total += _right->count();

        return total;
    }

    template class BinaryTree<int>;
}