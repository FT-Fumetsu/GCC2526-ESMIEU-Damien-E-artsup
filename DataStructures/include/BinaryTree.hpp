#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

namespace Data
{
    template<class Datatype>
    class BinaryTree
    {
    public:
        typedef BinaryTree<Datatype> Node;

    private:
        Datatype _data;
        Node* _left;
        Node* _right;
        Node* _parent;

    public:
        BinaryTree();
        BinaryTree(const Datatype& data);
        ~BinaryTree();

        void destroy();

        Datatype& Data() { return _data; }
        Node*& Left() { return _left; }
        Node*& Right() { return _right; }
        Node*& Parent() { return _parent; }

        void setLeft(Node* node);
        void setRight(Node* node);

        bool hasLeft() const;
        bool hasRight() const;
        bool isLeaf() const;

        int count() const;
    };
}

#endif // _BINARY_TREE_HPP_