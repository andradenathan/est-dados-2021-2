/*
Chapter 2.2 - Merge Sort
Divide and Conquer algorithm
*/

#include <stdio.h>
#include <math.h>
#define DIM 9

void merge(int A[], int begin, int middle, int end) {
  int n1 = (middle - begin) + 1;
  int n2 = end - middle;
  int B[n1 + 1];
  int C[n2 + 1];

  for(int i = 0; i < n1; i++)
    B[i] = A[begin + i];

  for(int j = 0; j < n2; j++)
    C[j] = A[middle + j + 1];
  
  int i = 0;
  int j = 0;
  int k = begin;

  while(i < n1 && j < n2) {
    if(B[i] <= C[j]) {
      A[k] = B[i];
      i++;
    } else {
      A[k] = C[j];
      j++;
    }
    k++;
  }
  
  while(i < n1) {
    A[k] = B[i];
    i++;
    k++;
  }

  while(j < n2) {
    A[k] = C[j];
    j++;
    k++;
  }
}

void mergeSort(int A[], int begin, int end) {
  if(begin < end) {
    int middle = begin + (end - begin) / 2; 
    mergeSort(A, begin, middle);
    mergeSort(A, middle + 1, end);
    merge(A, begin, middle, end);
  }
}

void printArray(int arr[], int size) {
  printf("[ ");
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int main() {
  int A[DIM] = {2, 9, 22, 19, 17, 150, 15, 191, 117};
  
  printf("Before: ");
  printArray(A, DIM);
  
  mergeSort(A, 0, DIM - 1);

  printf("After: ");
  printArray(A, DIM);
}