#ifndef _TEST_ARRAY_HPP
#define _TEST_ARRAY_HPP

#include <iostream>

#include "Array.hpp"

namespace Data{
    template<class DataType>
    class TestArray{
        public:
        static void displayArray(Array<DataType>& arr);
        static void runArrayTest();
    };
}

#endif //_TEST_ARRAY_HPP