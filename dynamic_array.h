#pragma once
#include "iostream"
#include "errors.h"
#include "IndexOutOfRange.h"

template<typename T>
class DynamicArray{
private:
    T* data = nullptr;
    int size = 0;
    int size_left = 0;
    int size_right = 0;
public: //конструкторы
    DynamicArray(){};
    DynamicArray(const DynamicArray<T> &array){
        size = array.size;
        size_left = array.size_left;
        size_right = array.size_right;
        data = new T[size];
        for(int i = 0; i < size; i++){
            data[i] = 0;
        }
        for(int i = size_left; i < size; i++){
            data[i] = array.data[i];
        }
    }
    DynamicArray(int _size){
        if(_size < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        size = _size + 10;
        data = new T[size];
        size_left = 5;
        size_right = 5;
        for(int i = 0; i < _size; i++){
            data[i + size_left] = 0;
        }
    }
    DynamicArray(int _size, T* _data){
        if(_size < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        size = _size + 10;
        data = new T[size];
        size_left = 5;
        size_right = 5;
        for(int i = 0; i < size; i++){
            data[i] = 0;
        }
        for(int i = 0; i < _size; i++){
            data[i + size_left] = _data[i];
        }
    }
    DynamicArray& operator = (const DynamicArray<T> &array){
        size = array.size;
        size_left = array.size_left;
        size_right = array.size_right;
        data = new T[size];

        for(int i = size_left; i < size; i++){
            data[i] = array.data[i];
        }
        return *this;
    }
    ~DynamicArray(){
        if(data != nullptr){
            delete[] data;
        }

    }

public: //методы
    int GetSizeLeft() const{
        return size_left;
    }
    int GetSizeRight() const{
        return size_right;
    }
    int GetSize() const{
        return (size - size_left - size_right);
    }
    T* GetData(){
        T *temp = new T[GetSize()];
        for(int i = 0; i < GetSize(); i++){
            temp[i] = data[i + size_left];
        }
        delete[] temp;
        return temp;

    }

    T GetElement(int index)const{
        if(index < 0 or index >= GetSize()){
            throw new IndexOutOfRange(WrongIndex);
        }
        return data[size_left + index];
    }
    void Replace(T element, int index){
        if(index < 0 or index >= GetSize()){
            throw IndexOutOfRange(WrongIndex);
        }
        data[index + size_left] = element;
    }

    void Resize(int _size){
        if(_size < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        T* old_data = data;
        data = new T[_size + 10];
        int old_size_left = size_left;
        int old_size = GetSize();
        size_left = 5;
        size_right = 5;
        for(int i = 0; i < std::min(_size, old_size); i++){
            data[i + size_left] = old_data[i + old_size_left];
        }
        for(int i = std::min(_size, old_size); i < std::max(_size, old_size); i++){
            data[i + size_left] = 0;
        }
        size = _size + 10;
        delete[] old_data;
    }
    void Append(T element){
        Insert(element, GetSize());
    }
    void Prepend(T element){
        Insert(element, 0);
    }
    void Swap(int index_1, int index_2){
        if((index_1 >= GetSize() or index_1 < 0) or (index_2 >= GetSize() or index_2 < 0)){
            throw IndexOutOfRange(WrongIndex);
        }
        T temp = data[index_1 + size_left];
        data[index_1 + size_left] = data[index_2 + size_left];
        data[index_2 + size_left] = temp;
    }
    void Insert(T element, int index) {
        if(index > GetSize() or index < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        if(index > GetSize()/2){
            if(size_right == 0){
                if(size_left == 0){
                    throw "No memory";
                }
                else{
                    for(int i = 0; i < index + size_left; i++){
                        data[i] = data[i + 1];
                    }
                    size_left--;
                    data[index + size_left] = element;
                }
            }
            else {
                for (int i = size_left + GetSize(); i > size_left + index; i--) {
                    data[i] = data[i - 1];
                }
                data[size_left + index] = element;
                size_right--;
            }
        }

        else{
            if(size_left == 0){
                if(size_right == 0){
                    throw "No memory";
                }
                else{
                    for (int i = size_left + GetSize(); i > size_left + index; i--) {
                        data[i] = data[i - 1];
                    }
                    data[size_left + index] = element;
                    size_right--;
                }
            }
            else {
                for (int i = 0; i < index + size_left; i++) {
                    data[i] = data[i + 1];
                }
                size_left--;
                data[index + size_left] = element;
            }
        }

//
//        free_memory--;
    }
    void Concat(DynamicArray<T> &copy){
        int size_of_concat = copy.GetSize();
        int old_size = GetSize();
        int new_size_right = copy.GetSizeRight();
        int new_size_left = GetSizeLeft();
        T* new_data = new T[size_of_concat + old_size + new_size_left + new_size_right];
        for(int i = 0; i < old_size; i++){
            new_data[new_size_left + i] = GetElement(i);
        }
        for(int i = 0; i < size_of_concat; i++){
            new_data[new_size_left + old_size + i] = copy.GetElement(i);
        }
        size_left = new_size_left;
        size_right = new_size_right;
        size = size_of_concat + old_size + new_size_left + new_size_right;
        delete[] data;
        data = new_data;
    }
    DynamicArray<T> GetSub(int index_1, int index_2){
        if(index_2 < index_1){
            throw IndexOutOfRange(WrongIndex);
        }
        if((index_1 >= GetSize() or index_1 < 0) or (index_2 >= GetSize() or index_2 < 0)){
            throw IndexOutOfRange(WrongIndex);
        }
        T* temp = new T[index_2 - index_1 + 1];
        for (int i = index_1; i <= index_2; i++) {
            temp[i - index_1] = data[i + size_left];

        }
        DynamicArray<T> class_return = DynamicArray<T>(index_2 - index_1 + 1, temp);
        delete[] temp;
        return class_return;
    }



};