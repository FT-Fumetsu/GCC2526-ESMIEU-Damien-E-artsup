#include "TestArray.hpp"

namespace Data{
    template<class DataType>
    void TestArray<DataType>::displayArray(Array<DataType>& arr){
        std::cout << "[ ";
        for(size_t i = 0; i < arr.size(); ++i){
            std::cout << arr.data()[i];
            if(i + 1 < arr.size()) std::cout << ", ";
        }
        std::cout << " ]\n";
    }

    template<class DataType> 
    void TestArray<DataType>::runArrayTest(){
        std::cout << "\n ---Tests Array--- \n\n";

        Array<int> intArr(5);
        Array<double> doubleArr(5);

        std::cout << "Après construction :\n";
        std::cout << " intArr    = "; TestArray<int>::displayArray(intArr);
        std::cout << " doubleArr = "; TestArray<double>::displayArray(doubleArr);
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
        std::cout << " intArr    = "; TestArray<int>::displayArray(intArr);
        std::cout << " doubleArr = "; TestArray<double>::displayArray(doubleArr);
        std::cout << '\n';

        std::cout << "Test d'insertion : insert(99, 1) dans intArr\n";
        try {
            intArr.insert(99, 1);
        }
        catch (const std::out_of_range& e) {
            std::cerr << "error (insert) : " << e.what() << '\n';
        }
        std::cout << "Après insert : intArr = "; TestArray<int>::displayArray(intArr);
        std::cout << '\n';

        std::cout << "Test de suppression : remove(2) sur intArr\n";
        try {
            intArr.remove(2);
        }
        catch (const std::out_of_range& e) {
            std::cerr << "error (remove) : " << e.what() << '\n';
        }
        std::cout << "Après remove : intArr = "; TestArray<int>::displayArray(intArr);
        std::cout << '\n';
        std::cout << "---Fin Test Array--- \n\n";
    }
    template class TestArray<int>;
    template class TestArray<double>;
}