#ifndef MY_CLASS_SEQ
#define MY_CLASS_SEQ

#include<iostream>
#include <complex>
#include "LLDA.h"

using namespace std;


template <typename T>
class Sequence
{
public:
    virtual void outseq() = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
};

template <typename T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
public:

    ArraySequence(T* items, int count)
    {
        DynamicArray<T>* item = new DynamicArray<T>(items, count);
        this->items = item;

    }
    ArraySequence()
    {
        DynamicArray<T>* items = new DynamicArray<T>(0);
    }
    ArraySequence(const DynamicArray <T>& dynamicArray)
    {
        DynamicArray<T>* item = new DynamicArray<T>(dynamicArray);
        this->items = item;
    }
    T GetFirst()
    {
        return items->Get(0);
    }
    T GetLast()
    {
        return items->Get(items->GetSize() - 1);
    }
    T Get(int index)
    {
        return items->Get(index);
    }
    int GetLength()
    {
        return items->GetSize();
    }
    void Append(T item)
    {
        items->Set(items->GetSize(), item);
    }
    void Prepend(T item)
    {
        items->Set(0, item);
    }
    void InsertAt(T item, int index)
    {
        items->Set(index, item);
    }
    void outseq()
    {

        cout << "seq = ";
        items->out();

        cout << endl;
    }
    Sequence<T>* GetSubsequence(int startindex, int endindex)
    {
        DynamicArray<T>* newitem = new DynamicArray<T>(0);
        for (int i = 0; i < -startindex + endindex; i++)
        {
            newitem->Set(i, this->items->Get(startindex + i));
        }
        Sequence<T>* fin = new ArraySequence<T>(*newitem);
        delete newitem;
        return fin;
    }
    Sequence <T>* Concat(Sequence <T>* list)
    {
        DynamicArray<T>* newitem = new DynamicArray<T>(0);
        int i;
        for (i = 0; i < this->GetLength(); i++)
        {
            newitem->Set(i, this->items->Get(i));
        }
        for (i = this->GetLength(); i < this->GetLength() + list->GetLength(); i++)
        {
            newitem->Set(i, list->Get(i - this->GetLength()));
        }
        
        Sequence<T>* fin = new ArraySequence<T>(*newitem);
        delete newitem;
        return fin;
    }
};
template <typename T>
class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T>* list;
public:
    LinkedListSequence(T* items, int count)
    {
        LinkedList<T>* list = new LinkedList<T>(items, count);
        this->list = list;
    }
    LinkedListSequence()
    {
        LinkedList<T>* list = new LinkedList<T>();
        this->list = list;
    }
    LinkedListSequence(const LinkedList <T>& list)
    {
        LinkedList<T>* listnew = new LinkedList<T>(list);
        this->list = listnew;
    }
    T GetFirst()
    {
        return list->GetFirst();
    }
    T GetLast()
    {
        return list->GetLast();
    }
    T Get(int index)
    {
        return list->Get(index);
    }
    Sequence<T>* GetSubsequence(int startindex, int endindex)
    {
        Sequence<T>* newlist = new LinkedListSequence<T>(*(this->list->GetSubList(startindex, endindex)));;
        return newlist;
    }
    int GetLength()
    {
        return list->GetLength();
    }
    void Append(T item)
    {
        list->Append(item);
    }
    void Prepend(T item)
    {
        list->Prepend(item);
    }
    void InsertAt(T item, int index)
    {
        list->InsertAt(item, index - 1);
    }
    void outseq()
    {
        cout << "list = ";
        this->list->out();
    }
    Sequence<T>* Concat(Sequence <T>* list)
    {
        int len = list->GetLength();
        T* arr = new T[len];
        int i;
        for (i = 0; i < list->GetLength(); i++)
        {
            arr[i] = list->Get(i);
        }
        
        LinkedList<T> listcopy = { arr,list->GetLength() };
        Sequence<T>* seq = new LinkedListSequence<T>(*(this->list->Concat(&listcopy)));
        delete[]arr;
        return seq;
    }
    
};

#endif