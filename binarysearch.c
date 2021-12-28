#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int binarySearch(int *arr, int size, int target) {
  int left = 0, right = size - 1;
  int middle;
  while(left <= right) {
    middle = left + (right - left)/2;
    if(arr[middle] == target) return middle;
    if(arr[middle] < target) left = middle + 1;
    else right = middle - 1;
  }

  return -1;
}

int main(void) {
  int* arr = (int*) malloc(DIM * sizeof(int));
  int k = 5;
  for(int i = 0; i < DIM; i++) {
    arr[i] = k; 
    if(i % 2 == 0) {
      k += (2 * 5 * 3) + 77;
    } else {
      k += (2 * 2 * 2) + 43;
    }
  }

  //arr = [5, 112, 163, 270, 321, 428, 479, 586, 637, 744]

  printf("Position of element 163: %d\n", binarySearch(arr, DIM, 163));
  printf("Position of element 2000: %d\n", binarySearch(arr, DIM, 2000));
  
  return 0;
}