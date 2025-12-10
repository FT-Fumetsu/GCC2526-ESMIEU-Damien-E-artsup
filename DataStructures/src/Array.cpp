#include <Array.hpp>
#include <stdexcept>
#include <string>

static size_t grow_capacity(size_t old_capacity, size_t min_needed) {
    if (old_capacity == 0) return std::max<size_t>(1, min_needed);
    size_t capacity = old_capacity;
    while (capacity < min_needed) {
        capacity = capacity * 2;
    }
    return capacity;
}

template<class DataType>
Array<DataType>::Array(size_t size){
    _size = size;
    _capacity = size;
    if (_capacity == 0) _array = nullptr;
    else _array = new DataType[_capacity];

    for(size_t i = 0; i < _size; ++i){
        _array[i] = DataType(0);
    }
}

template<class DataType>
Array<DataType>::~Array(){
    if(_array != nullptr){
        delete[] _array;
        _array = nullptr;
    } else {
        _array = nullptr;
    }
}

template<class DataType>
void Array<DataType>::insert(DataType item, size_t index){
    if(index > _size){
        throw std::out_of_range("insert: index out of range (" + std::to_string(index) + " >= " + std::to_string(_size) + ")");
    }

    if (_size + 1 > _capacity) {
        size_t newCap = grow_capacity(_capacity, _size + 1);
        reserve(newCap);
    }

    for (size_t i = _size; i > index; --i) {
        _array[i] = _array[i - 1];
    }

    _array[index] = item;
    ++_size;
}

template<class DataType>
void Array<DataType>::remove(size_t index){
    if(index > _size){
        throw std::out_of_range("remove: index out of range (" + std::to_string(index) + " >= " + std::to_string(_size) + ")");
    }

    for(size_t i = index; i + 1 < _size; ++i){
        _array[i] = _array[i + 1];
    }

    --_size;
    if (_size > 0) _array[_size] = DataType();
}

template<class DataType>
void Array<DataType>::resize(size_t newSize) {
    if (newSize == _size) return;

    if (newSize > _capacity) {
        size_t newCapacity = grow_capacity(_capacity, newSize);
        reserve(newCapacity);
    }

    if (newSize > _size) {
        for (size_t i = _size; i < newSize; ++i) {
            _array[i] = DataType();
        }
    } else {
        for (size_t i = newSize; i < _size; ++i) {
            _array[i] = DataType();
        }
    }

    _size = newSize;
}

template<class DataType>
void Array<DataType>::reserve(size_t newCapacity) {
    if (newCapacity <= _capacity) return;
    DataType* new_array = new DataType[newCapacity];
    for (size_t i = 0; i < _size; ++i) {
        new_array[i] = _array[i];
    }

    for (size_t i = _size; i < newCapacity; ++i) {
        new_array[i] = DataType();
    }
    delete[] _array;
    _array = new_array;
    _capacity = newCapacity;
}

template<class DataType>
size_t Array<DataType>::size(){
    return _size;
}

template<class DataType>
DataType* Array<DataType>::data(){
    return _array;
}

template<class DataType>
DataType& Array<DataType>::operator[] (size_t index){
    if(index >= _size){
        throw std::out_of_range("operator: index out of range (" + std::to_string(index) + " >= " + std::to_string(_size) + ")");
    }

    return _array[index];
}

template class Array<int>;
template class Array<double>;