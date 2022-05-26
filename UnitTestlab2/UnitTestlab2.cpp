#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../lab2/LLDA.h"
#include "../lab2/Vec.h"
#include "../lab2/TM.h"
#include "../lab2/Seq.h"

#include <complex>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab2
{
	TEST_CLASS(UnitTestlab2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

            int t1 = 2;
            int t2 = 10;
            int t3 = 3;
            int* ds = new int[t1];
            int* ar2 = new int[t2];
            for (int i = 0; i < t1; i++) {
                ds[i] = 43 + i * 21;
            }
            for (int i = 0; i < t2; i++) {
                ar2[i] = 94 + i * 7;
            }
            ArraySequence<int>* ssd2 = new ArraySequence<int>(ar2, t2);
            Sequence<int>* resseq = ssd2;
            Assert::IsTrue(resseq->GetFirst() == 94);
            Assert::IsTrue(resseq->GetLast() == 157);
            Assert::IsTrue(resseq->Get(t3) == 115);
            Assert::IsTrue(resseq->GetLength() == 10);
            
            resseq->InsertAt(1613, t3);
            Assert::IsTrue(resseq->Get(t3) == 1613);
            Sequence<int>* resseq2 = resseq->GetSubsequence(2, 6);
            Assert::IsTrue(resseq2->GetLength() == 4);
            Sequence<int>* resseq3 = resseq->Concat(resseq2);
            Assert::IsTrue(resseq3->GetLength() == 15);
            Assert::IsTrue(resseq3->Get(-8) == 94);
		}
        
	};
    TEST_CLASS(UnitTestlab21)
    {
    public:
        TEST_METHOD(U2)
        {

            int t1 = 5;
            int t2 = 10;
            int t3 = 3;
            int* ds = new int[t1];
            int* ar2 = new int[t2];
            for (int i = 0; i < t1; i++) {
                ds[i] = 43 + i * 21;
            }
            for (int i = 0; i < t2; i++) {
                ar2[i] = 94 + i * 7;
            }
            LinkedListSequence<int>* ssd = new LinkedListSequence<int>(ds, t1);
            LinkedListSequence<int>* ssd2 = new LinkedListSequence<int>(ar2, t2);
            Sequence<int>* resseq = ssd;
            Assert::IsTrue(resseq->GetFirst() == 43);
            Assert::IsTrue(resseq->GetLast() == 127);
            Assert::IsTrue(resseq->Get(t3) == 106);
            Assert::IsTrue(resseq->GetLength() == 5);
            resseq->InsertAt(1234, t3);
            Assert::IsTrue(resseq->Get(t3) == 1234);
            Sequence<int>* resseq2 = resseq->GetSubsequence(1, 3);
            Assert::IsTrue(resseq2->GetLength() == 3);
            Sequence<int>* resseq3 = resseq->Concat(resseq2);
            Assert::IsTrue(resseq3->GetLength() == 9);
            Assert::IsTrue(resseq3->Get(6) == 64);
        }
    };
    TEST_CLASS(UnitTestlab22)
    {
    public:
        TEST_METHOD(U2)
        {

            int t1 = 5;
            int t2 = 5;

            int* ds = new int[t1];
            int* ar2 = new int[t2];
            for (int i = 0; i < t1; i++) {
                ds[i] = 43 + i * 21;
            }
            for (int i = 0; i < t2; i++) {
                ar2[i] = 94 + i * 7;
            }
            LinkedListSequence<int>* ssd1 = new LinkedListSequence<int>(ds, t1);
            ArraySequence<int>* ssd2 = new ArraySequence<int>(ar2, t2);

            Vector<int>* vec1 = new Vector<int>(ssd1);
            Vector<int>* vec2 = new Vector<int>(ssd2);
            Vector<int>* vec3 = vec1->VecSumm(*vec2);
            Assert::IsTrue(vec3->Get(1) == 165);
            Vector<int>* vec4 = vec3->ScalarMult(8);
            Assert::IsTrue(vec4->Get(1) == 1320 );
            Assert::IsTrue(vec1->normacalc<float>() > 201.332 && vec1->normacalc<float>() < 201.334);
            Assert::IsTrue(vec2->ScalarSumm(*vec1) == 47370);
        }
    };
    TEST_CLASS(UnitTestlab23)
    {
    public:
        TEST_METHOD(U2)
        {
            int i,j,t1 = 3;
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
                    mat2[i][j] = { i * 3 + 1 + j * 4,i * 2 + 7 + i * 4 };
                    mat1[i][j] = { i * 3 + j * 2 + 9 + (j - 2) * 3,j * 2 + 7 - 1 + i * 2 };
                }
                lmat[i] = { mat1[i],t1 - i };
                lmat2[i] = { mat2[i], t1 - i };

            }
            TrangleMatrix<complex<int>>* matr1 = new  TrangleMatrix<complex<int>>(lmat, t1, true);
            TrangleMatrix<complex<int>>* matr2 = new  TrangleMatrix<complex<int>>(lmat2, t1, true);
            TrangleMatrix<complex<int>>* matr3 = matr1->matrsumm(*matr2);
            Assert::IsTrue(matr3->Mnorma().real() == 59 && matr3->Mnorma().imag() == 0);
            Assert::IsTrue(matr3->Lnorma().real() == 69 && matr3->Lnorma().imag() == 0);
            Assert::IsTrue(matr3->Knorma<complex<float>>().real() < 36 && matr3->Knorma<complex<float>>().real() > 35 && matr3->Knorma<complex<float>>().imag() < 49 && matr3->Knorma<complex<float>>().imag() > 48);
            TrangleMatrix<complex<int>>* matr4 = matr3->ScalarMultiplication(8);
            Assert::IsTrue(matr4->Get(1, 2).real() == 152 && matr4->Get(1, 2).imag() == 184);
        }
    };
    TEST_CLASS(UnitTestlab234)
    {
        TEST_METHOD(U2)
        {
            int i, j, t1 = 3;
            int** mat1 = new int* [t1];
            ArraySequence<int>* lmat = new  ArraySequence<int>[t1];
            int** mat2 = new int* [t1];
            LinkedListSequence<int>* lmat2 = new LinkedListSequence<int>[t1];
            for (i = 0; i < t1; i++)
            {
                mat1[i] = new int[i + 1];
                mat2[i] = new int[i + 1];
                for (j = 0; j < i + 1; j++)
                {
                    mat2[i][j] = i * 3 + 9 + j * 3;
                    mat1[i][j] = i * 4 - 1 - j * 2;
                }
                lmat[i] = { mat1[i],i + 1 };
                lmat2[i] = { mat2[i], i + 1 };
                lmat[i].outseq();
            }
            for (i = 0; i < t1; i++)
            {
                for (j = 0; j < i + 1; j++)
                {
                    cout << mat1[i][j] << " ";
                }
                cout << endl;
            }
            TrangleMatrix<int>* matr1 = new  TrangleMatrix<int>(lmat, t1, false);
            matr1->out();
            TrangleMatrix<int>* matr2 = new  TrangleMatrix<int>(lmat2, t1, false);
            matr2->out();
            ;
            TrangleMatrix<int>* matr3 = matr1->matrsumm(*matr2);
            Assert::IsTrue(matr3->Mnorma() == 69);
            Assert::IsTrue(matr3->Lnorma() == 45 );
            Assert::IsTrue(matr3->Knorma<float>() < 47 && matr3->Knorma<float>() > 46);
            TrangleMatrix<int>* matr4 = matr3->ScalarMultiplication(8);
            Assert::IsTrue(matr4->Get( 1,0) == 120);
        }
    };
}
