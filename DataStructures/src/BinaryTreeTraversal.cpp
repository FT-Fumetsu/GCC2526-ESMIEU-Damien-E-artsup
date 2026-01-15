#include "BinaryTreeTraversal.hpp"

namespace Data
{
    // -------- PREORDER --------
    template<class Datatype>
    void BinaryTreeTraversal<Datatype>::PreOrder(Node* node, std::function<void(Node*)> visit)
    {
        if (!node) return;

        visit(node);
        PreOrder(node->Left(), visit);
        PreOrder(node->Right(), visit);
    }

    // -------- INORDER --------
    template<class Datatype>
    void BinaryTreeTraversal<Datatype>::InOrder(Node* node, std::function<void(Node*)> visit)
    {
        if (!node) return;

        InOrder(node->Left(), visit);
        visit(node);
        InOrder(node->Right(), visit);
    }

    // -------- POSTORDER --------
    template<class Datatype>
    void BinaryTreeTraversal<Datatype>::PostOrder(Node* node, std::function<void(Node*)> visit)
    {
        if (!node) return;

        PostOrder(node->Left(), visit);
        PostOrder(node->Right(), visit);
        visit(node);
    }

    // -------- BFS --------
    template<class Datatype>
    void BinaryTreeTraversal<Datatype>::BFS(Node* node, std::function<void(Node*)> visit)
    {
        if (!node) return;

        std::queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            visit(current);

            if (current->Left())
                q.push(current->Left());

            if (current->Right())
                q.push(current->Right());
        }
    }

    template class BinaryTreeTraversal<int>;
}
