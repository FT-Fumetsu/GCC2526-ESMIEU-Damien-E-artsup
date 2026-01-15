#include "TestBinaryTree.hpp"

namespace Data{
    template <class DataType>
    void TestBinaryTree<DataType>::runBinaryTreeTraversalTest(){
        std::cout << "\n--- Tests pour BinaryTree<int> + Parcours ---\n\n";

        using BT = BinaryTree<int>;
        using BTT = BinaryTreeTraversal<int>;

        /*
                Arbre créé :

                        1
                    /   \
                    2     3
                    / \     \
                4   5     6

            PreOrder  : 1 2 4 5 3 6
            InOrder   : 4 2 5 1 3 6
            PostOrder : 4 5 2 6 3 1
            BFS       : 1 2 3 4 5 6
        */

        std::cout << "Création de l'arbre binaire\n";

        BT* BTroot = new BT(1);
        BTroot->setLeft(new BT(2));
        BTroot->setRight(new BT(3));

        BTroot->Left()->setLeft(new BT(4));
        BTroot->Left()->setRight(new BT(5));

        BTroot->Right()->setRight(new BT(6));

        std::cout << "Total nodes = " << BTroot->count() << "\n\n";

        // -------- PREORDER --------
        std::cout << "Parcours PreOrder : ";
        BTT::PreOrder(BTroot, [](BT* node) {
            std::cout << node->Data() << " ";
        });
        std::cout << "\n";

        // -------- INORDER --------
        std::cout << "Parcours InOrder  : ";
        BTT::InOrder(BTroot, [](BT* node) {
            std::cout << node->Data() << " ";
        });
        std::cout << "\n";

        // -------- POSTORDER --------
        std::cout << "Parcours PostOrder: ";
        BTT::PostOrder(BTroot, [](BT* node) {
            std::cout << node->Data() << " ";
        });
        std::cout << "\n";

        // -------- BFS --------
        std::cout << "Parcours BFS      : ";
        BTT::BFS(BTroot, [](BT* node) {
            std::cout << node->Data() << " ";
        });
        std::cout << "\n\n";

        std::cout << "Destruction de l'arbre binaire\n";
        delete BTroot;

        std::cout << "\n--- Fin des tests BinaryTree ---\n\n";
    }

    template class TestBinaryTree<int>;
}