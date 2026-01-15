#include "DLinkedList.hpp"
#include "DListIterator.hpp"
#include "NodeFactory.hpp"
#include "SListExceptions.hpp"

namespace Data{
    template<class DataType>
    DLinkedList<DataType>::DLinkedList() {
        _head = nullptr;
        _tail = nullptr;
        _count = 0;
    }

    template<class DataType>
    DLinkedList<DataType>::~DLinkedList() {
        while (_head != nullptr)
            removeHead();
    }

    template<class DataType>
    void DLinkedList<DataType>::append(DataType data) {
        DNode<DataType>* node = NodeFactory<DataType>::createDNode(data);
        if (_tail == nullptr) {
            _head = _tail = node;
        } else {
            _tail->next() = node;
            node->previous() = _tail;
            _tail = node;
        }
        ++_count;
    }

    template<class DataType>
    void DLinkedList<DataType>::prepend(DataType data) {
        DNode<DataType>* node = NodeFactory<DataType>::createDNode(data);
        if (_head == nullptr) {
            _head = _tail = node;
        } else {
            node->next() = _head;
            _head->previous() = node;
            _head = node;
        }
        ++_count;
    }

    template<class DataType>
    void DLinkedList<DataType>::insertBefore(DListIterator<DataType>& itr, DataType data) {
        if (_head == nullptr || itr.node() == _head) {
            prepend(data);
            return;
        }
        if (!itr.isValid()) {
            append(data);
            return;
        }
        itr.node()->insertBefore(data);
        if (itr.node() == _head->previous()){
            _head = itr.node()->previous();
        }
        ++_count;
    }

    template <class DataType>
    void DLinkedList<DataType>::insertAfter(DListIterator<DataType>& itr, DataType data){
        if (_head == nullptr){
            prepend(data);
            return;
        }

        if (!itr.isValid() || itr.node() == _tail){
            append(data);
            return;
        }

        itr.node()->insertAfter(data);
        if(itr.node() == _tail->next()){
            _tail = itr.node()->next();
        }
        ++_count;
    }

    template<class DataType>
    void DLinkedList<DataType>::removeHead() {
        if (!_head) return;
        DNode<DataType>* temp = _head;
        _head = _head->next();
        if (_head) _head->previous() = nullptr;
        else _tail = nullptr;
        delete temp;
        --_count;
    }

    template<class DataType>
    void DLinkedList<DataType>::removeTail() {
        if (!_tail) return;
        DNode<DataType>* temp = _tail;
        _tail = _tail->previous();
        if (_tail) _tail->next() = nullptr;
        else _head = nullptr;
        delete temp;
        --_count;
    }

    template<class DataType>
    void DLinkedList<DataType>::remove(DListIterator<DataType>& itr) {
        if (!itr.isValid()) return;
        DNode<DataType>* target = itr.node();
        if (target == _head) {
            removeHead();
            itr.node() = _head;
            return;
        }
        if (target == _tail) {
            removeTail();
            itr.node() = nullptr;
            return;
        }

        DNode<DataType>* prev = target->previous();
        DNode<DataType>* next = target->next();
        if (prev) prev->next() = next;
        if (next) next->previous() = prev;

        itr.node() = next;
        delete target;
        --_count;
    }

    template<class DataType>
    DListIterator<DataType> DLinkedList<DataType>::getIterator() {
        if (!this){
            throw std::runtime_error("getIterator() sur liste nulle");
        }
        return DListIterator<DataType>(this);
    }

    template class DLinkedList<int>;
    template class DLinkedList<double>;
    template class DLinkedList<Tree<int>*>;
    template class DLinkedList<TreeIterator<int>*>;
}
