#include <stdio.h>
#define DIM 10

int search(int list[], int elem) {
  int i;
  for(i = 0; i < DIM; i++) {
    if(list[i] == elem) {
      return i;
    }
  }
  return -1;
}

int main() {
  int list[DIM] = {11, 3, 5, 8, 10, 6, 0, 44, 9};
  int res = search(list, 44);
  if(res != 1) {
    printf("List[%d] <- %d\n", res, list[res]);
  }
  return 0;
}