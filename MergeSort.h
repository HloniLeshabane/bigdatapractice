#ifndef MERGESORT_H
#define MERGESORT_H
#include <assert.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class MergeSort
{
    public:
        MergeSort();
        void mergeSortAux(float*,int,float*);
        void mergeSort(float*, int, float*);
        bool isSorted(float*,int);
        void print(vector<float>&);

    protected:

    private:
        bool sorted;
};

#endif // MERGESORT_H
