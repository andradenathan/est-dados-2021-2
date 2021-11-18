#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void printLinkedList(Node* node) {
  while(node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}

void push(Node** head, int elem) {
  Node* node = (Node*) malloc(sizeof(Node));
  if((*head) == NULL) {
    node->data = elem;
    node->next = (*head);
    (*head) = node; 
  } else {
    Node* ptr = (*head);
    while(ptr->next) {
      ptr = ptr->next;
    }
    node->data = elem;
    ptr->next = node;
  }
}

int main(void) {
  Node* node = NULL;
  push(&node, 10);
  push(&node, 15);
  push(&node, 20);
  push(&node, 50);
  printLinkedList(node);
  return 0;
}