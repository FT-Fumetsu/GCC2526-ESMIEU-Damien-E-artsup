#include "RunAllTests.hpp"

namespace Data{
    template<class DataType>
    void RunAllTests<DataType>::runAllTests(){
        std::cout << "\n=== Lancement du programme de structures de données ===\n\n";

        //Tests Array

        TestArray<DataType>::runArrayTest();

        //Test SLinkedList

        TestSLinkedList<DataType>::runSLinkedListTest();

        //Test DLinkedList

        TestDLinkedList<DataType>::runDLinkedListTest();

        //Test Tree

        TestTree<DataType>::runTreeTest();

        //Test BinaryTree & Parcours 

        TestBinaryTree<DataType>::runBinaryTreeTraversalTest();

        //Test Parcours de Graphs

        TestGraph<DataType>::runGraphTest();
    }

    template class RunAllTests<int>;
}