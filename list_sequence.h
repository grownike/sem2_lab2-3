#pragma once
#include "iostream"
#include "linked_list.h"
#include "sequence.h"

template<class T>
class ListSequence : Sequence<T>{
private:
    LinkedList<T> linked_list;

public:
    ListSequence(const LinkedList<T>& _linked_list){
        linked_list = LinkedList<T>(_linked_list);
    }
    ListSequence(const ListSequence<T>& _linked_list){
        linked_list = _linked_list.linked_list;
    }
    ListSequence(int size, T* data){
        linked_list = LinkedList<T>(size, data);
    }
    ListSequence(int size){
        linked_list = LinkedList<T>(size);
    }
    ListSequence(){};


    int GetSize()const{
        return linked_list.GetSize();
    }

    T GetElement(int index)const{
        return linked_list.GetElement(index);
    }
    T GetLast()const{
        return linked_list.GetLast();
    }
    T GetFirst()const{
        return linked_list.GetFirst();
    }
    void Replace(T element, int index){
        linked_list.Replace(element, index);
    }
    void Append(T element){
        linked_list.Append(element);
    }
    void Prepend(T element){
        linked_list.Prepend(element);
    }
    void Insert(T element, int index){
        linked_list.Insert(element, index);
    }
    void Resize(int new_size){
        linked_list.Resize(new_size);
    }
    void Swap(int index_1, int index_2){
        linked_list.Swap(index_1, index_2);
    }
    void print(){
        linked_list.print();
    }
    void Concat(ListSequence<T> &copy){
        linked_list.Concat(copy.linked_list);
    }
    ListSequence<T> GetSub(int a, int b){
        return linked_list.GetSub(a,b);
    }













};