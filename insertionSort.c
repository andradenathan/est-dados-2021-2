/*
Chapter 2.1 -> Analysis of Insertion Sort 
*/

#include <stdio.h>
#define DIM 6

void result(int* arr) {
  for(int i = 0; i < DIM; i++) {
    printf("A[%d] <- %d\n", i, arr[i]);
  }
} 

int main(void) {
  int arr[DIM] = {5, 2, 4, 6, 1, 3};
  for(int i = 1; i < DIM; i++) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = key; 
  }
  result(arr);
  return 0;
}