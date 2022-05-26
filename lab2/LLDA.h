
#ifndef LLDA 
#define LLDA
#include <iostream>
#include <complex>
#include <math.h>
using namespace std;

void input(int* a)
{
    cin >> *a;
}
void input(complex<int>* a)
{
    int im, re;
    cin >> re >> im;
    *a = { re,im };
}
void input(complex<float>* a)
{
    float im, re;
    cin >> re >> im;
    *a = { re,im };
}
void input(float* a)
{
    cin >> *a;
}
template <typename T>
class DynamicArray
{
private:
    T* items;
    int count;
public:
    DynamicArray()
    {
        items = nullptr;
        count = 0;
    }
    DynamicArray(T* items, int count)
    {
        this->items = new T[count];
        this->count = count;
        for (int i = 0; i < count; i++)
        {
            this->items[i] = items[i];
        }
    }
    DynamicArray(int size)
    {
        if (size <= 0)
        {
            items = nullptr;
            count = 0;
        }
        else
        {
            this->items = new T[size];
            count = size;
            for (int i = 0; i < size; i++)
                input(&items[i]);
        }
    }
    DynamicArray(const DynamicArray<T>& dynamicArray)
    {
        this->count = dynamicArray.count;
        this->items = new T[this->count];
        int i;
        for (i = 0; i < this->count; i++)
        {
            this->items[i] = dynamicArray.items[i];
        }
    }
    void out()
    {
        for (int i = 0; i < count; i++)
            cout << items[i] << " ";
        cout << endl;
    }
    T Get(int index)
    {
        if (index >= count || index < 0)
        {

            return this->Get(0);
        }
        return this->items[index];
    }
    int GetSize()
    {
        return count;
    }
    void Set(int index, T value)
    {
        if (index<0 || index>this->count) return;
        this->count++;
        int i;

        T* itemsnew = new T[count];
        itemsnew[index] = value;
        for (i = 0; i < index; i++)
        {
            itemsnew[i] = this->items[i];
        }


        for (i = index + 1; i < count; i++)
        {
            itemsnew[i] = this->items[i - 1];
        }
        delete[] this->items;
        this->items = itemsnew;
    }
    void Resize(int newSize)
    {
        if (newSize < 0) return;
        T* items = new T[newSize];
        int i;
        for (i = 0; i < newSize; i++)
        {
            if (this->count > i) items[i] = this->items[i];
            else items[i] = 0;
        }
        delete[] this->items;
        count = newSize;
        this->items = items;
    }
    ~DynamicArray()
    {
        delete[] items;
    }
};
template <typename T>
class Node
{
    T data;
    Node* next;
    template<class T> friend class LinkedList;
};
template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    LinkedList(T* items, int count)
    {
        head = nullptr;
        tail = nullptr;
        this->count = 0;
        Node<T>* ptr = nullptr;
        this->count = count;
        int i;
        if (count <= 0) return;
        ptr = new Node<T>;
        for (i = 0; i < count; i++)
        {
            if (i != count - 1) ptr->next = new Node<T>;
            if (!i) head = ptr;
            ptr->data = items[i];
            if (i == count - 1)
            {
                ptr->next = nullptr;
                tail = ptr;
            }
            else ptr = ptr->next;

        }

    }
    void out()
    {
        Node<T>* ptr = head;

        for (int i = 0; i < count; i++)
        {
            //cout << " | " << ptr->next << " ";
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        count = 0;
    }
    LinkedList(const LinkedList<T>& list)
    {
        this->head = nullptr;
        this->tail = nullptr;
        Node<T>* ptr = nullptr;
        Node<T>* ptrlist = list.head;
        this->count = list.count;
        int i;
        if (count == 0) return;
        ptr = new Node<T>;
        for (i = 0; i < count; i++)
        {
            if (i != count - 1) ptr->next = new Node<T>;
            if (!i) this->head = ptr;
            ptr->data = ptrlist->data;
            if (i == count - 1)
            {
                ptr->next = nullptr;
                tail = ptr;
            }
            else
            {
                ptr = ptr->next;
                ptrlist = ptrlist->next;
            }
        }
    }
    T GetFirst()
    {
        return head->data;
    }
    T GetLast()
    {
        return tail->data;
    }
    T Get(int index)
    {
        if (index < 0 || count <= index) {
            return this->Get(0);
        }
        Node<T>* ptr = head;
        for (int i = 0; i < index; i++)
        {

            ptr = ptr->next;
        }
        return ptr->data;
    }
    LinkedList<T>* GetSubList(int startindex, int endindex)
    {
        int len;
        if (startindex < 0 || endindex <= startindex || endindex >= count)
        {
            LinkedList<T> *list = new LinkedList<T>;
            return list;
        }
        len = -startindex + endindex + 1;
        Node<T>* ptr = this->head;
        for (int i = 0; i < startindex; i++)
        {
            ptr = ptr->next;
        }
        T* arr = new T[len];
        for (int i = 0; i < len; i++)
        {
            
            arr[i] = ptr->data;
            ptr = ptr->next;
        }
        LinkedList<T>* g = new LinkedList<T>(arr, len);
        return g;
    }
    int GetLength()
    {
        return count;
    }
    void Append(T item)
    {
        count++;
        Node<T>* ptr = new Node<T>;
        tail->next = ptr;
        tail = ptr;
        ptr->data = item;
    }
    void Prepend(T item)
    {
        count++;
        Node<T>* ptr = new Node<T>;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
    }
    void InsertAt(T item, int index)
    {
        if (index<0 || index> count) return;
        Node<T>* ptrnew = new Node<T>;
        Node<T>* ptr = head;
        ptrnew->data = item;
        count++;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        ptrnew->next = ptr->next;
        ptr->next = ptrnew;
    }
    LinkedList<T>* Concat(LinkedList<T>* list)
    {
        int len = this->count + list->GetLength();
        T* arr = new T[len];
        Node<T>* ptr = this->head;
        int i;
        for (i = 0; i < this->count; i++)
        {
            arr[i] = ptr->data;
            ptr = ptr->next;
        }
        ptr = list->head;

        for (i = this->count; i < len; i++)
        {
            arr[i] = ptr->data;
            ptr = ptr->next;
        }
        LinkedList<T>* listnew = new LinkedList<T>(arr, this->count + list->count);
        delete[]arr;
        return listnew;
    }
     ~LinkedList()
     {
         Node<T> *ptr = this->head;
         if (!count) return;
         Node<T>* ptrnext = ptr->next;
         delete ptr;
         for (int i = 0; i < count-1; i++)
         {            
             ptr = ptrnext;
             ptrnext = ptrnext->next;
             delete ptr;
         }
     }
};


#endif