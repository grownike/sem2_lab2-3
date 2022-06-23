#pragma once
#include "iostream"

template<class T>
class Sequence{
public:
    virtual void Replace(T element, int index) = 0;
    virtual T GetFirst()const = 0;
    virtual T GetLast()const = 0;
    virtual T GetElement(int index)const = 0;
    virtual int GetSize()const = 0;
    virtual void Append(T element) = 0;
    virtual void Prepend(T element) = 0;
    virtual void Insert(T element, int index) = 0;
    virtual void Swap(int index_1, int index_2) = 0;
};