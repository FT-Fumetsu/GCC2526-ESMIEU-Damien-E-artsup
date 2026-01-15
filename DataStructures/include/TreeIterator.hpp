#ifndef _TREE_ITERATOR_HPP_
#define _TREE_ITERATOR_HPP_

#include "Tree.hpp"
#include "DListIterator.hpp"

namespace Data 
{
    template <class Datatype>
    class TreeIterator
    {
        public:
        typedef Tree<Datatype> Node;
        Node* _node;
        DListIterator<Node*> _childItr;

        TreeIterator(Node* node);

        void goUp();
        void goDown();
        void goRoot();

        void childStart();
        void childEnd();
        void childForth();
        void childBack();

        bool isValidChild();
        Node* itemChild();

        TreeIterator<Datatype>& operator= (Node* node);

        protected:

        void resetIterator();
    };
}

#endif // _TREE_ITERATOR_HPP_