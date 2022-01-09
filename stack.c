#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Stack {
  Node* top;
  int size;
} Stack;

void print(Stack* stack) {
  Node* node = stack->top; 
  while(node != NULL) {
    printf("%d\n", node->data);
    node = node->next;
  }
}

Stack* constructor() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

int push(Stack* stack, int elem) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = elem;
  node->next = stack->top;
  stack->top = node;
  stack->size++;
  return stack->top->data;
}

int pop(Stack* stack) {
  Node* node = (Node*) malloc(sizeof(Node));
  if(stack->size > 0) {
    node = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    return stack->top->data;
  }
  printf("Stack is empty\n");
  return -1;
}

int peek(Stack* stack) {
  if(stack->size > 0) {
    return stack->top->data;
  }
  printf("Stack is empty\n");
  return -1;
}

int main(void) {
  Stack* stack = constructor();
  printf("----- PUSHING ELEMENTS ------\n");
  push(stack, 10);
  push(stack, 3);
  push(stack, 22);
  push(stack, 17);
  push(stack, 48);
  print(stack);
  printf("----- POPPING ELEMENT -----\n");
  pop(stack);
  print(stack);
  printf("----- PEEKING ELEMENT -----\n");
  printf("%d\n", peek(stack));
  return 0;
}