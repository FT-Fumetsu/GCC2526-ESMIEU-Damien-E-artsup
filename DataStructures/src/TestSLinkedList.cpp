#include "TestSLinkedList.hpp"

namespace Data{
    template<class DataType>
    void TestSLinkedList<DataType>::displayLinkedList(SLinkedList<DataType>& list){
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
    void TestSLinkedList<DataType>::runSLinkedListTest(){
        std::cout << "\n--- Tests pour SLinkedList<int> ---\n\n";

        SLinkedList<int> list;
        std::cout << "Liste initiale (vide) : ";
        TestSLinkedList<int>::displayLinkedList(list);

        std::cout << "Append 10, 20, 30\n";
        list.append(10);
        list.append(20);
        list.append(30);
        std::cout << "Après append : ";
        TestSLinkedList<int>::displayLinkedList(list);

        std::cout << "Prepend 5\n";
        list.prepend(5);
        std::cout << "Après prepend : ";
        TestSLinkedList<int>::displayLinkedList(list);

        std::cout << "removeHead()\n";
        list.removeHead();
        std::cout << "Après removeHead : ";
        TestSLinkedList<int>::displayLinkedList(list);

        std::cout << "removeTail()\n";
        list.removeTail();
        std::cout << "Après removeTail : ";
        TestSLinkedList<int>::displayLinkedList(list);

        std::cout << "Suppression jusqu'à vider la liste (removeHead en boucle)\n";
        while(list.count() != 0){
            list.removeHead();
            TestSLinkedList<int>::displayLinkedList(list);
        }

        std::cout << "Appels sur liste vide : removeHead(), removeTail()\n";
        list.removeHead();
        list.removeTail();
        std::cout << "Après appels sur vide : ";
        TestSLinkedList<int>::displayLinkedList(list);

        std::cout << "\n--- Fin des tests Slinked list ---\n\n";
    }

    template class TestSLinkedList<int>;
}