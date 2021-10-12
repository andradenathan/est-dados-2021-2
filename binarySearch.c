#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int elem) {
  int left = 0;
  int right = size;
  for(int i = left; i < right; i++) {
    int middle = left + (right - left)/2;
    if(right < left) exit(1);
    if(arr[middle] == elem) return middle;
    if(arr[middle] < elem)
      left = middle + 1;
    if(arr[middle] > elem)
      right = middle - 1;
  }
}

int main(void) {
  int arr[] = {3, 9, 17, 21, 28, 50, 68, 81, 87, 90};
  int size = sizeof(arr)/sizeof(arr[0]);
  int result = binarySearch(arr, size - 1, 90);
  printf("Resultado: %d\n", result);
  return 0;
}