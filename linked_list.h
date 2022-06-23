#pragma once
#include "iostream"
#include "IndexOutOfRange.h"

using namespace std;
template<class T>
class LinkedList{
private:
    typedef struct List{
        T data;
        struct List* next;
    }List;
    List* head = nullptr;
    List* tail = nullptr;
    int size = 0;
public:
    LinkedList(){};
    LinkedList(int _size, T* _data){
        if(_size < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        for(int i = 0; i < _size; i++){
            Append(_data[i]);
        }
    }
    LinkedList& operator = (const LinkedList<T> &array){
        for(int i = 0; i < array.GetSize(); i++){
            Append(array.GetElement(i));
        }
        return *this;
    }
    LinkedList(int _size){
        if(_size < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        for(int i = 0; i < _size; i++){
            Append(0);
        }
    }
    LinkedList(const LinkedList<T>& linked_list){
        for(int i = 0; i < linked_list.GetSize(); i++){
            Append(linked_list.GetElement(i));
        }
    }

    void Prepend(T element){
        List * temp = new List;
        temp->data = element;
        temp->next = nullptr;
        size++;
        if(head == nullptr){
            head = temp;
            tail = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void Append(T element){
        List * temp = new List;
        temp->data = element;
        temp->next = nullptr;
        size++;
        if(head == nullptr){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }

    void Insert(T element, int index){
        if(index >= GetSize() or index < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        if(index == 0){
            Prepend(element);
            return;
        }
        if(index == size){
            Append(element);
            return;
        }
        List* new_list = new List;
        new_list->data = element;
        List *temp, *pred = head, *pred_next;
        for(int i = 0; i < index; i++){
            if(i + 1 == index){
                temp = pred;
            }
            pred = pred->next;
        }
        pred_next = pred->next;
        temp->next = new_list;
        new_list->next = pred;
        size++;
    }
    T GetFirst()const{
        if(size == 0){
            throw IndexOutOfRange(WrongIndex);
        }
        return head->data;
    }
    T GetLast()const{
        if(size == 0){
            throw IndexOutOfRange(WrongIndex);
        }
        return tail->data;
    }
    int GetSize()const{
        return size;
    }
    T GetElement(int index)const{
        if(index >= GetSize() or index < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        List* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }

    void Resize(int _size){
        if(_size < 0){
            throw IndexOutOfRange(WrongIndex);
        }
        T* temp = new T[_size];
        int minsize = min(_size, size);
        int oldsize = size;
        for (int i = 0; i < minsize; i++){
            temp[i] = GetElement(i);
        }

        List *temp2 = head;
        while(temp2!= nullptr){
            List *tmp = temp2->next;
            delete temp2;
            temp2 = tmp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
        for(int i = 0; i < minsize; i++){
            Append(temp[i]);
        }
        for(int i = minsize; i < _size; i++){
            Append(0);
        }
        delete[] temp;

    }
    void Replace(T element, int index) {
        if(index < 0 or index >= GetSize()){
            throw IndexOutOfRange(WrongIndex);
        }
        List *temp = head;
        for (int i = 0; i < size; i++) {
            if (i == index) {
                temp->data = element;
                return;
            }
            temp = temp->next;
        }
    }
    void Swap(int index_1, int index_2){
        if((index_1 >= GetSize() or index_1 < 0) or (index_2 >= GetSize() or index_2 < 0)){
            throw IndexOutOfRange(WrongIndex);
        }
        T _1 = this->GetElement(index_1);
        T _2 = this->GetElement(index_2);
        List *temp = head;
        for(int i = 0; i < size; i++){
            if(i == index_1){
                temp->data = _2;
            }
            if(i == index_2){
                temp->data = _1;
            }
            temp = temp->next;
        }

    }
    void Concat(LinkedList<T> &copy){
        T* final = new T[copy.size + copy.size + 5];
        int newsize = size + copy.size;
        for(int i = 0; i < size; i++){
            final[i] = GetElement(i);
        }
        for(int i = 0; i < copy.size; i++){
            final[i + size] = copy.GetElement(i);
        }
        List *temp2 = head;
        while(temp2!= nullptr){
            List *tmp = temp2->next;
            delete temp2;
            temp2 = tmp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
        for(int i = 0;i < newsize; i++){
            Append(final[i]);
        }
        delete[] final;

    }
    LinkedList<T> GetSub(int index_1, int index_2){
        if((index_1 >= GetSize() or index_1 < 0) or (index_2 >= GetSize() or index_2 < 0)){
            throw IndexOutOfRange(WrongIndex);
        }
        T temp[size];
        for(int i = index_1; i <= index_2; i++){
            temp[i - index_1] = GetElement(i);
        }
        LinkedList<T> class_return = LinkedList<T>(index_2 - index_1 + 1, temp);
        return class_return;
    }

    void Size(){
        size++;
    }
    ~LinkedList(){
        List *temp = head;
        while(temp!= nullptr){
            List *tmp = temp->next;
            delete temp;
            temp = tmp;
        }
    }



};