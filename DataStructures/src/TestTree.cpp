#include "TestTree.hpp"

#include <exception>
#include <iostream>

namespace Data{
    template<class DataType>
    void TestTree<DataType>::displayTree(Tree<DataType>* node, int depth)
    {
        if (!node){
            return;
        };

        for (int i = 0; i < depth; ++i)
            std::cout << "  ";

        std::cout << "- " << node->Data() << "\n";

        auto itr = node->Children().getIterator();
        while (itr.isValid())
        {
            TestTree<int>::displayTree(itr.item(), depth + 1);
            itr.forth();
        }
    }

    template<class DataType>
    void TestTree<DataType>::runTreeTest(){
        std::cout << "\n--- Tests pour Tree<int> ---\n\n";

        Tree<int>* root = new Tree<int>(0);
        try{
            TreeIterator<int> itr(root);
        
            std::cout << "Création de l'arbre :\n";
            TestTree<int>::displayTree(root);
            std::cout << "Total nodes = " << root->count() << "\n";

            std::cout << "Ajout enfants à la racine (2, 3)\n";
            root->appendChild(2);
            root->appendChild(3);

            TestTree<int>::displayTree(root);
            std::cout << "Total nodes = " << root->count() << "\n";

            std::cout << "Descente dans le noeud 2\n";
            itr.goDown();

            root->appendChild(4);
            root->appendChild(5);

            TestTree<int>::displayTree(root);
            std::cout << "Total nodes = " << root->count() << "\n";

            std::cout << "Navigation parmi les enfants de 2 :\n";
            itr.childStart();
            while (itr.isValidChild())
            {
                std::cout << " Child = " << itr.itemChild()->Data() << "\n";
                itr.childForth();
            }
            std::cout << "\n";

            std::cout << "Retour à la racine\n";
            itr.goRoot();
            TestTree<int>::displayTree(root);
            std::cout << "\n";

            std::cout << "Suppression du premier enfant de la racine (2)\n";
            itr.childStart();
            if (itr.isValidChild())
            {
                auto childItr = root->Children().getIterator();
                root->Children().remove(childItr);
            }
        }
        catch(const std::exception& e){
            std::cerr << "Erreur lors de la création de TreeIterator : " << e.what() << '\n';            
        }

        TestTree<int>::displayTree(root);
        std::cout << "Total nodes = " << root->count() << "\n";

        std::cout << "Destruction complète de l'arbre\n";
        delete root;

        std::cout << "\n--- Fin des tests Tree ---\n\n";
    }

    template class TestTree<int>;
}