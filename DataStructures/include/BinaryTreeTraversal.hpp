#ifndef _BINARY_TREE_TRAVERSAL_HPP_
#define _BINARY_TREE_TRAVERSAL_HPP_

#include "BinaryTree.hpp"
#include <queue>
#include <functional>

namespace Data
{
    template<class Datatype>
    class BinaryTreeTraversal
    {
    public:
        typedef BinaryTree<Datatype> Node;

        // Parcours en profondeur
        static void PreOrder(Node* node, std::function<void(Node*)> visit);
        static void InOrder(Node* node, std::function<void(Node*)> visit);
        static void PostOrder(Node* node, std::function<void(Node*)> visit);

        // Parcours en largeur
        static void BFS(Node* node, std::function<void(Node*)> visit);
    };
}

#endif // _BINARY_TREE_TRAVERSAL_HPP_
