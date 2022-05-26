
#include <iostream>
#include "LLDA.h"
#include "Vec.h"
#include "TM.h"
#include "Seq.h"

#include <complex>

using namespace std;

int main()
{
    int t1 = 3;
    int t2 = 3;
    int t3 = 3;
    int i, j;
    /*int* ds = new int[t1];
    int* ar2 = new int[t2];

    complex<int>** mat1 = new complex<int>*[t1];
    ArraySequence<complex<int>>* lmat = new  ArraySequence<complex<int>>[t1];
    complex<int>** mat2 = new complex<int>*[t1];
    LinkedListSequence<complex<int>>* lmat2 = new LinkedListSequence<complex<int>>[t1];
    for (i = 0; i < t1; i++)
    {
        mat1[i] = new complex<int>[t1 - i];
        mat2[i] = new complex<int>[t1 - i];
        for (j = 0; j < t1 - i; j++)
        {
            mat2[i][j] = { i * 3 +1+ j*4,i * 2 + 7+i*4 };
            mat1[i][j] = { i * 3 + j * 2+9+(j-2)*3,j * 2 + 7 - 1 + i * 2};
        }
        lmat[i] = { mat1[i],t1 - i };
        lmat2[i] = { mat2[i], t1 - i };

    }
    TrangleMatrix<complex<int>>* matr1 = new  TrangleMatrix<complex<int>>(lmat,t1,true);
    matr1->out();
    TrangleMatrix<complex<int>>* matr2 = new  TrangleMatrix<complex<int>>(lmat2,t1, true);
    matr2->out();
    cout << "summ" << endl;
    TrangleMatrix<complex<int>>* matr3 = matr1->matrsumm(*matr2);
    matr3->out();
    int n1, n2, n3;
    cout << matr3->Mnorma() << endl;
    cout << matr3->Lnorma() << endl;
    cout << matr3->Knorma<complex<float>>() << endl;
    TrangleMatrix<complex<int>>* matr4 = matr3->ScalarMultiplication(8);
    matr4->out();
    cout << matr4->Get(1, 2);
    return 0;*/
    /*int** mat1 = new int* [t1];
    ArraySequence<int>* lmat = new  ArraySequence<int>[t1];
    int** mat2 = new int*[t1];
    LinkedListSequence<int>* lmat2 = new LinkedListSequence<int>[t1];
    for (i = 0; i < t1; i++)
    {
        mat1[i] = new int[i+1];
        mat2[i] = new int[i+1];
        for (j = 0; j <i+1; j++)
        {
            mat2[i][j] = i * 3 + 9+j*3;
            mat1[i][j] = i * 4 - 1-j*2;
        }
        lmat[i] = { mat1[i],i+1 };
        lmat2[i] = { mat2[i], i+1};
        lmat[i].outseq();
    }
    for (i = 0; i < t1; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            cout<<mat1[i][j]<<" ";
        }
        cout << endl;
    }
    TrangleMatrix<int>* matr1 = new  TrangleMatrix<int>(lmat, t1, false);
    matr1->out();
    TrangleMatrix<int>* matr2 = new  TrangleMatrix<int>(lmat2, t1, false);
    matr2->out();
;
    TrangleMatrix<int>* matr3 = matr1->matrsumm(*matr2);
    matr3->out();
    cout << "Mnorma "<<endl;
    cout << matr3->Mnorma() << endl;
    cout << "Lnorma" << endl;
    cout << matr3->Lnorma() << endl;
    cout << "Knorma" << endl;
    matr3->out();
    cout << matr3->Knorma<float>() << endl;
    TrangleMatrix<int>* matr4 = matr3->ScalarMultiplication(8);
    matr4->out();
    cout << matr4->Get(1, 0);
    return 0;*/
}
