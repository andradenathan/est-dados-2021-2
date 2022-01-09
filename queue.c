#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Queue {
  struct Node* start;
  struct Node* end;
  int size;
} Queue;

void print(Queue* queue) {
  Node* node = queue->start; 
  while(node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

Queue* constructor() {
  Queue* queue = malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  queue->size = 0; 
  return queue;
}

int push(Queue* queue, int elem) {
  Node* node = malloc(sizeof(Node));
  node->data = elem; 
  if(queue->end == NULL) {
    queue->end = node;
  } else {
    queue->end->next = node;
    queue->end = node;
  }

  if(queue->start == NULL) {
    queue->start = node;
  }

  queue->size++;
  return queue->end->data;
}

int pop(Queue* queue) {
  if(queue->start != NULL) {
    Node* elem = queue->start;
    queue->start = queue->start->next;
    queue->size--;
    free(elem);
    return elem->data;
  }
  printf("Queue is empty!\n");
  return -1;
}

int peek(Queue* queue) {
  if(queue->start != NULL) {
    return queue->start->data;
  }
  printf("Queue is empty!\n");
  return -1;
}

int main(void) {
  Queue* queue = constructor();
  printf("----- PUSHING ELEMENTS ------\n");
  push(queue, 1);
  push(queue, 2);
  push(queue, 7);
  push(queue, 8);
  push(queue, 9);
  print(queue);
  printf("----- POPPING ELEMENTS ------\n");
  pop(queue);
  print(queue);
  printf("----- PEEKING ELEMENTS ------\n");
  printf("%d\n", peek(queue));
  return 0;
}