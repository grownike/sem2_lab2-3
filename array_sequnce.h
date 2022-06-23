#pragma once
//#include "iostream"
#include "sequence.h"
#include "dynamic_array.h"


template<class T>
class ArraySequence : Sequence<T> {

private:
    DynamicArray<T> dynamic_array;
public:
    ArraySequence(int _size, T *_data) {
        dynamic_array = DynamicArray<T>(_size, _data);
    }
    ArraySequence(const DynamicArray<T>& _dynamic_array){
        dynamic_array = DynamicArray<T>(_dynamic_array);
    }
    ArraySequence(int _size){
        dynamic_array = DynamicArray<T>(_size);
    }
    ArraySequence(const ArraySequence<T>& _array_sequence){
        dynamic_array = _array_sequence.dynamic_array;
    }
    ArraySequence(){};
    T *GetData() {
        return dynamic_array.GetData();
    }
    T GetFirst() const {
        return dynamic_array.GetElement(0);
    }
    T GetLast() const {
        return dynamic_array.GetElement(dynamic_array.GetSize());
    }
    T GetElement(int index) const {
        return dynamic_array.GetElement(index);
    };
    int GetSize() const {
        return dynamic_array.GetSize();
    }

    void Append(T element) {
        if(dynamic_array.GetSizeRight() == 0 or dynamic_array.GetSizeLeft() == 0){
            Resize(GetSize());
        }
        dynamic_array.Append(element);
    }
    void Prepend(T element) {
        if(dynamic_array.GetSizeRight() == 0 or dynamic_array.GetSizeLeft() == 0){
            Resize(GetSize());
        }
        dynamic_array.Prepend(element);
    }
    void Replace(T element, int index){
        dynamic_array.Replace(element, index);
    }
    void Insert(T element, int index) {
        if(dynamic_array.GetSizeRight() == 0 or dynamic_array.GetSizeLeft() == 0){
            Resize(GetSize());
        }
        dynamic_array.Insert(element, index);
    }
    void Swap(int index_1, int index_2) {
        dynamic_array.Swap(index_1, index_2);
    }
    void Resize(int _size){
        dynamic_array.Resize(_size);
    }

    int IsContained(T element){
        for(int i = 0; i < dynamic_array.GetSize(); i++){
            if(dynamic_array.GetElement(i) == element){
                return 1;
            }
        }
        return 0;
    }
    void Concat(ArraySequence<T> &copy){
        dynamic_array.Concat(copy.dynamic_array);
    }
    ArraySequence<T> GetSub(int a, int b){
        return  dynamic_array.GetSub(a, b);
    }

};