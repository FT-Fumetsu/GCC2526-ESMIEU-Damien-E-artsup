#include "TestDLinkedList.hpp"

namespace Data{
    template<class DataType>
    void TestDLinkedList<DataType>::displayDLinkedList(DLinkedList<DataType>& list){
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
    void TestDLinkedList<DataType>::runDLinkedListTest(){
        std::cout << "\n--- Tests pour DLinkedList<int> ---\n\n";

        DLinkedList<int> dlist;
        std::cout << "Liste double initiale (vide) : ";
        TestDLinkedList<int>::displayDLinkedList(dlist);

        std::cout << "Append 10, 20, 30\n";
        dlist.append(10);
        dlist.append(20);
        dlist.append(30);
        std::cout << "Après append : ";
        TestDLinkedList<int>::displayDLinkedList(dlist);

        std::cout << "Prepend 5\n";
        dlist.prepend(5);
        std::cout << "Après prepend : ";
        TestDLinkedList<int>::displayDLinkedList(dlist);

        std::cout << "Test insert via itérateur : insert before second node (insert 15 before 10)\n";
        {
            DListIterator<int> itr = dlist.getIterator();
            itr.start();
            itr.forth();
            dlist.insertBefore(itr, 15);
            std::cout << "Après insert via itr : ";
            TestDLinkedList<int>::displayDLinkedList(dlist);
        }

        std::cout << "removeHead()\n";
        dlist.removeHead();
        std::cout << "Après removeHead : ";
        TestDLinkedList<int>::displayDLinkedList(dlist);

        std::cout << "removeTail()\n";
        dlist.removeTail();
        std::cout << "Après removeTail : ";
        TestDLinkedList<int>::displayDLinkedList(dlist);

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
                TestDLinkedList<int>::displayDLinkedList(dlist);
            } else {
                std::cout << "Itérateur invalide — pas de suppression via itr\n";
            }
        }

        std::cout << "Suppression jusqu'à vider la DLinkedList (removeHead en boucle)\n";
        while(dlist.count() != 0){
            dlist.removeHead();
            TestDLinkedList<int>::displayDLinkedList(dlist);
        }

        std::cout << "Appels sur DLinkedList vide : removeHead(), removeTail()\n";
        dlist.removeHead();
        dlist.removeTail();
        std::cout << "Après appels sur vide : ";
        TestDLinkedList<int>::displayDLinkedList(dlist);

        std::cout << "\n--- Fin des tests DLinkedList ---\n\n";
    }

    template class TestDLinkedList<int>;
}