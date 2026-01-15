#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>

namespace Data{
    template<class DataType>
    class Array{
    private:
        DataType* _array;
        size_t _size;
        size_t _capacity;

    public:
        Array(size_t size);
        ~Array();

        void insert(DataType item, size_t index);
        void remove(size_t index);
        void resize(size_t size);
        void reserve(size_t newCapacity);

        //Getter and operators

        size_t size();
        DataType* data();

        DataType& operator[] (size_t index); //array[0]
    };
}


#endif // _ARRAY_HPP_