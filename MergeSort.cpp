#include "MergeSort.h"

MergeSort::MergeSort()
{
    //ctor
}

void MergeSort::mergeSortAux(float *X, int n, float *tmp) {
   int i = 0;
   int j = n/2;
   int ti = 0;

   while (i<n/2 && j<n) {
      if (X[i] < X[j]) {
         tmp[ti] = X[i];
         ti++; i++;
      } else {
         tmp[ti] = X[j];
         ti++; j++;
      }
   }
   while (i<n/2) {
      tmp[ti] = X[i];
      ti++; i++;
   }
   while (j<n) {
      tmp[ti] = X[j];
      ti++; j++;
   }
   std::memcpy(X, tmp, n*sizeof(float));
}

void MergeSort::mergeSort(float *X, int n, float *tmp)
{
   if (n < 64)
   {
      float* last = X+n;
      std::sort(X, last);
   }
   else
   #pragma omp taskgroup
   {
         #pragma omp task shared(X) untied if(n>= (1<<14))
         mergeSort(X, n/2, tmp);
         #pragma omp task shared(X) untied if(n>= (1<<14))
         mergeSort(X+(n/2), n-(n/2), tmp + n/2);
         #pragma omp taskyield
   }
   mergeSortAux(X, n, tmp);
}

bool MergeSort::isSorted(float *a, int size){
   for(int i = 0; i < size - 1; i++)
      if(a[i] > a[i + 1])
        return false;
   return true;
}


void MergeSort::print(vector<float> &v)
{
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

