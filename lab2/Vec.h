#ifndef MY_CLASS_VEC
#define MY_CLASS_VEC

#include<iostream>
#include <complex>
#include "LLDA.h"
#include "Seq.h"

template <typename T>
class Vector
{
private:
    Sequence<T>* myvector;
public:
    Vector(LinkedListSequence<T>* list)
    {
        this->myvector = list;
    }
    Vector(ArraySequence<T>* list)
    {
        this->myvector = list;
    }
    Vector()
    {
        myvector = nullptr;
    }
    Vector* VecSumm(Vector<T> secondvector)
    {
        if (this->myvector->GetLength() != secondvector.myvector->GetLength())
        {
            Vector<T>* a = new Vector<T>();
            return a;
        }
        T* arr = new T[this->myvector->GetLength()];
        for (int i = 0; i < this->myvector->GetLength(); i++)
        {
            arr[i] = this->myvector->Get(i) + secondvector.myvector->Get(i);
        }
        LinkedListSequence<T>* seqfin = new LinkedListSequence<T>(arr, this->myvector->GetLength());
        Vector<T>* a = new Vector<T>( seqfin );
        return a;
    }
    Vector* ScalarMult(T scalar)
    {
        if (!this->myvector)
        {
            Vector<T>* a = new Vector<T>();
            return a;
        }
        T* arr = new T[this->myvector->GetLength()];
        for (int i = 0; i < this->myvector->GetLength(); i++)
        {
            arr[i] = this->myvector->Get(i) * scalar;
        }
        LinkedListSequence<T>* seqfin = new LinkedListSequence<T>(arr, this->myvector->GetLength());
        Vector<T>* a = new Vector<T>(seqfin);
        return a;
    }
    T ScalarSumm(Vector<T> secondvector)
    {
        T summ;
        for (int i = 0; i < this->myvector->GetLength(); i++)
        {
            if (i == 0) summ = this->myvector->Get(i) * secondvector.myvector->Get(i);
            else summ += this->myvector->Get(i) * secondvector.myvector->Get(i);
        }
        return summ;
    }
    template <typename T2>
    T2 normacalc()
    {
        T2 norma;
        for (int i = 0; i < this->myvector->GetLength(); i++)
        {
            if (i == 0) norma = (T2)(this->myvector->Get(i) * this->myvector->Get(i));
            else norma += (T2)(this->myvector->Get(i) * this->myvector->Get(i));
        }

        return sqrt(norma);
    }
    void out()
    {
        if(myvector)myvector->outseq();
    }
    T Get(int index)
    {
        return myvector->Get(index);
    }

};

#endif
