#ifndef MY_CLASS_TM
#define MY_CLASS_TM

#include<iostream>
#include <complex>
#include "LLDA.h"
#include "Seq.h" 
complex<float> max(complex<float> a, complex<float> b)
{
    if (a.real() > b.real())
    {
        return a;
    }
    else return b;
}
complex<int> max(complex<int> a, complex<int> b)
{
    if (a.real() > b.real())
    {
        return a;
    }
    else return b;
}
template <typename T>
class TrangleMatrix
{
private:
    Sequence<T>** matrix;
    int matrsize;
    bool isupper;
public:
    TrangleMatrix(LinkedListSequence<T>* matrix, int matrsize, bool isupper)
    {
        int i, j;

        this->matrsize = matrsize;
        this->isupper = isupper;
        this->matrix = new Sequence<T>*[matrsize];
        for (i = 0; i < matrsize; i++)
        {
            this->matrix[i] = new LinkedListSequence<T>(matrix[i]);
        }
    }
    TrangleMatrix(ArraySequence<T>* matrix, int matrsize, bool isupper)
    {
        int i, j;
        this->matrix = new Sequence<T>*[matrix[0].GetLength()];
        this->matrsize = matrsize;
        this->isupper = isupper;
        this->matrix = new Sequence<T>*[matrsize];

        for (i = 0; i < matrsize; i++)
        {
            this->matrix[i] = new ArraySequence<T>(matrix[i]);
        }
    }
    void out()
    {
        for (int i = 0; i < matrsize; i++)
            (matrix[i])->outseq();

    }
    T Get(int i, int j)
    {
        if (isupper)
        {
            if (j >= i && j < matrsize)
                return matrix[i]->Get(j - i);
        }
        else
        {
            if (j <= i && i < matrsize)
                return matrix[i]->Get(j);
        }
        return matrix[0]->Get(0);
    }
    int GetLength()
    {
        return this->matrsize;
    }
    TrangleMatrix* matrsumm( TrangleMatrix<T> secondmatrix)
    {
        if (this->isupper != secondmatrix.isupper || this->matrsize != secondmatrix.matrsize)
        {
            ArraySequence<T>* lmat = new ArraySequence<T>[1];
            lmat[0] = {};
            TrangleMatrix<T>* res = new TrangleMatrix<T>(lmat, this->matrsize, this->isupper);
            return res;
        }
        int len = this->GetLength();
        T** arr = new T * [len];
        int i, j;
        ArraySequence<T>* lmat = new ArraySequence<T>[len];
        for (i = 0; i < len; i++)
        {
            
            if (this->isupper)
            {
                arr[i] = new T[len - i];
                for (j = 0; j < len - i; j++)
                {
                    arr[i][j] = this->Get(i, j + i) + secondmatrix.Get(i, j + i);
                }
                lmat[i] = { arr[i],len - i };
            }
            else
            {
                arr[i] = new T[i+1];
                for (j = 0; j < i + 1; j++)
                {
                    arr[i][j] = this->Get(i, j) + secondmatrix.Get(i, j);
                }
                lmat[i] = { arr[i], 1 + i };
            }
        }
        TrangleMatrix<T>* res = new TrangleMatrix<T>(lmat, this->matrsize, this->isupper);
        return  res;
    }
    T Mnorma()
    {
        int i, j, len;
        len = this->GetLength();
        T mnorma, newmnorma;
        for (i = 0; i < len; i++)
        {

            if (isupper)
            {
                for (j = 0; j < len - i; j++)
                {

                    if (j == 0) newmnorma = abs(this->Get(i, j + i));
                    else newmnorma += abs(this->Get(i, j + i));
                    //cout << Get(i, j + i) << " " << abs(Get(i, j+i)) <<" | ";
                }
            }
            else
            {
                for (j = 0; j < i + 1; j++)
                {
                    if (j == 0) newmnorma = abs(this->Get(i, j));
                    else newmnorma += abs(this->Get(i, j));
                    //cout << newmnorma << " " << Get(i, j + i) << " " << abs(Get(i, j+i)) << " | ";
                }
            }
            
            if (i == 0)mnorma = newmnorma;
            else mnorma = max(newmnorma, mnorma);
            //cout <<endl<< mnorma << " " << newmnorma << endl;
        }
        return mnorma;
    }
    T Lnorma()
    {
        int i, j, len;
        len = this->GetLength();
        T lnorma, newlnorma;
        for (j = 0; j < len; j++)
        {
            if (isupper)
            {
                for (i = 0; i < len - j; i++)
                {
                    if (i == 0) newlnorma = abs(this->Get(i, j + i));
                    else newlnorma += abs(this->Get(i, j + i));
                    //cout<< Get(i, j + i) << " " << abs(Get(i, j+i)) << " | ";
                }

                if (j == 0)lnorma = newlnorma;
                else lnorma = max(newlnorma, lnorma);
                //cout <<endl<< lnorma << " " << newlnorma << endl;
            }
            else
            {
                for (i = j; i < matrsize; i++)
                {
                    if (i == j) newlnorma = abs(this->Get(i, j));
                    else newlnorma += abs(this->Get(i, j));
                    //cout << newlnorma << " : " << Get(i, j) <<" | ";
                }
                if (j == 0)lnorma = newlnorma;
                else lnorma = max(newlnorma, lnorma);
                //cout << endl << lnorma << " " << newlnorma << endl;
            }
        }
        return lnorma;
    }
    template <typename T2>
    T2 Knorma()
    {
        int i, j, len;
        len = this->GetLength();
        T2 knorma;
        for (i = 0; i < len; i++)
        {
            if (isupper) {
                for (j = 0; j < len - i; j++)
                {
                    if (j == 0 && i == 0) knorma = this->Get(i, j + i) * this->Get(i, j + i);
                    else knorma += this->Get(i, j + i) * this->Get(i, j + i);
                }
            }
            else
            {
                for (j = 0; j < i + 1; j++)
                {
                    if (j == 0 && i == 0) knorma = this->Get(i, j) * this->Get(i, j);
                    else knorma += this->Get(i, j) * this->Get(i, j);
                }
            }
        }
        knorma = sqrt(knorma);
        return knorma;
    }
    TrangleMatrix* ScalarMultiplication(T scalar)
    {

        int len = this->GetLength();
        T** arr = new T * [len];
        int i, j;
        //cout << len;
        ArraySequence<T>* lmat = new ArraySequence<T>[len];
        if (isupper) {
            for (i = 0; i < len; i++)
            {
                arr[i] = new T[len - i];
                for (j = 0; j < len - i; j++)
                {
                    arr[i][j] = this->Get(i, j + i) * scalar;
                }
                lmat[i] = { arr[i],len - i };
            }
        }
        else
        {
            for (i = 0; i < len; i++)
            {
                arr[i] = new T[i + 1];
                for (j = 0; j < i + 1; j++)
                {
                    arr[i][j] = this->Get(i, j) * scalar;
                }
                lmat[i] = { arr[i],i + 1 };
            }
        }
        TrangleMatrix<T>* res = new TrangleMatrix<T>(lmat, this->matrsize, this->isupper);
        return res;
    }
};

#endif