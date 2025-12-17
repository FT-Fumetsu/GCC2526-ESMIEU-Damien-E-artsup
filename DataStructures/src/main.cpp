#include <iostream>

#include "Array.hpp"

#include "SNode.hpp"
#include "SLinkedList.hpp"
#include "SListIterator.hpp"

#include "DNode.hpp"
#include "DLinkedList.hpp"
#include "DListIterator.hpp"

#include "Tree.hpp"
#include "TreeIterator.hpp"

// ----------------------Displays---------------------------------

template<class DataType>
void displayArray(Array<DataType>& arr){
    std::cout << "[ ";
    for(size_t i = 0; i < arr.size(); ++i){
        std::cout << arr.data()[i];
        if(i + 1 < arr.size()) std::cout << ", ";
    }
    std::cout << " ]\n";
}

template<class DataType>
void displayLinkedList(SLinkedList<DataType>& list){
    std::cout << "[ ";
    SNode<DataType>* cur = list.head();
    bool first = true;
    while(cur != nullptr){
        if(!first) std::cout << ", ";
        std::cout << cur->data();
        first = false;
        cur = cur->next();
    }
    std::cout << " ]";
    std::cout << " (size=" << list.count() << ")\n";
}

template<class DataType>
void displayDLinkedList(DLinkedList<DataType>& list){
    std::cout << "[ ";
    DNode<DataType>* cur = list.head();
    bool first = true;
    while(cur != nullptr){
        if(!first) std::cout << ", ";
        std::cout << cur->data();
        first = false;
        cur = cur->next();
    }
    std::cout << " ]";

    std::cout << "  (backwards: [ ";
    DNode<DataType>* back = list.tail();
    first = true;
    while(back != nullptr){
        if(!first) std::cout << ", ";
        std::cout << back->data();
        first = false;
        back = back->previous();
    }
    std::cout << " ]";
    std::cout << ", size=" << list.count() << ")\n";
}

template<class DataType>
void displayTree(Data::Tree<DataType>* node, int depth = 0)
{
    if (!node) return;

    for (int i = 0; i < depth; ++i)
        std::cout << "  ";

    std::cout << "- " << node->Data() << "\n";

    auto itr = node->Children().getIterator();
    while (itr.isValid())
    {
        displayTree(itr.item(), depth + 1);
        itr.forth();
    }
}

// ----------------------Tests------------------------------------

void run_test(){
    std::cout << "\n=== Lancement du programme de structures de données ===\n\n";

    Array<int> intArr(5);
    Array<double> doubleArr(5);

    std::cout << "Après construction :\n";
    std::cout << " intArr    = "; displayArray(intArr);
    std::cout << " doubleArr = "; displayArray(doubleArr);
    std::cout << '\n';

    std::cout << "Essai d'assignations (avec accès hors-limites provoquant des exceptions) :\n";
    try {
        intArr[0] = 10;
        intArr[1] = 20;
        intArr[2] = 30;
        intArr[99] = 100;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "error (intArr) : " << e.what() << '\n';
    }

    try {
        doubleArr[0] = 10.9;
        doubleArr[1] = 20.1;
        doubleArr[2] = 30.6;
        doubleArr[99] = 100.25;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "error (doubleArr) : " << e.what() << '\n';
    }

    std::cout << "\nAprès quelques assignations :\n";
    std::cout << " intArr    = "; displayArray(intArr);
    std::cout << " doubleArr = "; displayArray(doubleArr);
    std::cout << '\n';

    std::cout << "Test d'insertion : insert(99, 1) dans intArr\n";
    try {
        intArr.insert(99, 1);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "error (insert) : " << e.what() << '\n';
    }
    std::cout << "Après insert : intArr = "; displayArray(intArr);
    std::cout << '\n';

    std::cout << "Test de suppression : remove(2) sur intArr\n";
    try {
        intArr.remove(2);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "error (remove) : " << e.what() << '\n';
    }
    std::cout << "Après remove : intArr = "; displayArray(intArr);
    std::cout << '\n';

    //
    // SINGLE LINKED LISTS TESTS
    //

    std::cout << "\n--- Tests pour SLinkedList<int> ---\n\n";

    SLinkedList<int> list;
    std::cout << "Liste initiale (vide) : ";
    displayLinkedList(list);

    std::cout << "Append 10, 20, 30\n";
    list.append(10);
    list.append(20);
    list.append(30);
    std::cout << "Après append : ";
    displayLinkedList(list);

    std::cout << "Prepend 5\n";
    list.prepend(5);
    std::cout << "Après prepend : ";
    displayLinkedList(list);

    std::cout << "removeHead()\n";
    list.removeHead();
    std::cout << "Après removeHead : ";
    displayLinkedList(list);

    std::cout << "removeTail()\n";
    list.removeTail();
    std::cout << "Après removeTail : ";
    displayLinkedList(list);

    std::cout << "Suppression jusqu'à vider la liste (removeHead en boucle)\n";
    while(list.count() != 0){
        list.removeHead();
        displayLinkedList(list);
    }

    std::cout << "Appels sur liste vide : removeHead(), removeTail()\n";
    list.removeHead();
    list.removeTail();
    std::cout << "Après appels sur vide : ";
    displayLinkedList(list);

    std::cout << "\n--- Fin des tests linked list ---\n\n";
    //
    // DOUBLE LINKED LISTS TESTS
    //
    std::cout << "\n--- Tests pour DLinkedList<int> ---\n\n";

    DLinkedList<int> dlist;
    std::cout << "Liste double initiale (vide) : ";
    displayDLinkedList(dlist);

    std::cout << "Append 10, 20, 30\n";
    dlist.append(10);
    dlist.append(20);
    dlist.append(30);
    std::cout << "Après append : ";
    displayDLinkedList(dlist);

    std::cout << "Prepend 5\n";
    dlist.prepend(5);
    std::cout << "Après prepend : ";
    displayDLinkedList(dlist);

    std::cout << "Test insert via itérateur : insert before second node (insert 15 before 10)\n";
    {
        DListIterator<int> itr = dlist.getIterator();
        itr.start();
        itr.forth();
        dlist.insertBefore(itr, 15);
        std::cout << "Après insert via itr : ";
        displayDLinkedList(dlist);
    }

    std::cout << "removeHead()\n";
    dlist.removeHead();
    std::cout << "Après removeHead : ";
    displayDLinkedList(dlist);

    std::cout << "removeTail()\n";
    dlist.removeTail();
    std::cout << "Après removeTail : ";
    displayDLinkedList(dlist);

    std::cout << "Test remove via itérateur (suppression d'un élément du milieu)\n";
    {
        DListIterator<int> itr = dlist.getIterator();
        itr.start();
        itr.forth();
        itr.forth();
        if (itr.isValid()){
            std::cout << "Itérateur pointe sur : " << itr.item() << " -> suppression via remove(itr)\n";
            dlist.remove(itr);
            std::cout << "Après remove via itr : ";
            displayDLinkedList(dlist);
        } else {
            std::cout << "Itérateur invalide — pas de suppression via itr\n";
        }
    }

    std::cout << "Suppression jusqu'à vider la DLinkedList (removeHead en boucle)\n";
    while(dlist.count() != 0){
        dlist.removeHead();
        displayDLinkedList(dlist);
    }

    std::cout << "Appels sur DLinkedList vide : removeHead(), removeTail()\n";
    dlist.removeHead();
    dlist.removeTail();
    std::cout << "Après appels sur vide : ";
    displayDLinkedList(dlist);

    std::cout << "\n--- Fin des tests DLinkedList ---\n\n";
    //
    // TREE TESTS
    //
    std::cout << "\n--- Tests pour Tree<int> ---\n";

    using Data::Tree;
    using Data::TreeIterator;

    // Création de la racine
    Tree<int>* root = new Tree<int>(1);
    TreeIterator<int> itr(root);

    std::cout << "Création de l'arbre :\n";
    displayTree(root);
    std::cout << "Total nodes = " << root->count() << "\n\n";

    // =======================
    // Ajout d'enfants à la racine
    // =======================
    std::cout << "Ajout enfants à la racine (2, 3)\n";
    itr.appendChild(2);
    itr.appendChild(3);

    displayTree(root);
    std::cout << "Total nodes = " << root->count() << "\n\n";

    // =======================
    // Descente dans le noeud 2
    // =======================
    std::cout << "Descente dans le noeud 2\n";
    itr.goDown(); // va sur 2

    itr.appendChild(4);
    itr.appendChild(5);

    displayTree(root);
    std::cout << "Total nodes = " << root->count() << "\n\n";

    // =======================
    // Navigation enfant
    // =======================
    std::cout << "Navigation parmi les enfants de 2 :\n";
    itr.childStart();
    while (itr.isValidChild())
    {
        std::cout << " Child = " << itr.itemChild()->Data() << "\n";
        itr.childForth();
    }
    std::cout << "\n";

    // =======================
    // Remontée vers la racine
    // =======================
    std::cout << "Retour à la racine\n";
    itr.goRoot();
    displayTree(root);
    std::cout << "\n";

    // =======================
    // Suppression d'un enfant
    // =======================
    std::cout << "Suppression du premier enfant de la racine (2)\n";
    itr.childStart();
    if (itr.isValidChild())
    {
        auto childItr = root->Children().getIterator();
        root->Children().remove(childItr);
    }

    displayTree(root);
    std::cout << "Total nodes = " << root->count() << "\n\n";

    // =======================
    // Destruction complète
    // =======================
    std::cout << "Destruction complète de l'arbre\n";
    delete root;

    std::cout << "\n--- Fin des tests Tree ---\n";

    std::cout << "\n=== Fin des tests ===\n\n";
}

int main(){
    run_test();
    return EXIT_SUCCESS;
};