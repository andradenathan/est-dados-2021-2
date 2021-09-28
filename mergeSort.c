/*
Chapter 2.2 - Merge Sort
Divide and Conquer algorithm
*/
#include <stdio.h>
#include <math.h>
#define DIM 8

void merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1];
  int R[n2 + 1];
  for(int i = 0; i < n1; i++) L[i] = A[p + i];
  for(int j = 0; j < n2; j++) R[j] = A[q + j + 1];
  
  int i = 0;
  int j = 0;
  int k = p;

  while(i < n1 && j < n2) {
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++; 
    }
    k++;
  }

  while(i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  while(j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int A[], int p, int r) {
  if (p < r) {
    int q = p + (r - p) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

void printArray(int A[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int A[DIM] = {3, 41, 52, 26, 38, 57, 9, 49};
  printArray(A, DIM);
  mergeSort(A, 0, DIM - 1);
  printArray(A, DIM);
  return 0;
}