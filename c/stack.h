// HEADERS
#include <stdio.h>
#include <stdlib.h>

#define NL printf("\n")

// STRUCTURES
typedef struct {
  int *ARRAY;
  int top, length;
} STACK;

// FUNCTIONS DECLARATION
STACK* createSTACK(int n);
int isFull(STACK* stack);
int isEmpty(STACK* stack);
int peekSTACK(STACK* stack);
void pushToSTACK(STACK* stack, int element);
int popFromSTACK(STACK* stack);
void printSTACK(STACK* stack);

// FUNCTION DEFINITION
STACK* createSTACK(int n) {
  // creation of a stack
  STACK* stack;

  stack = (STACK*) calloc(sizeof(STACK), 1);
  if (stack == NULL) {
    printf("Memory not allocated!\n");
    return NULL;
  }
  
  stack->ARRAY = (int*) calloc(sizeof(int), n);
  if (stack->ARRAY == NULL) {
    printf("Memory not allocated!\n");
    return NULL;
  }
  
  stack->top = -1;
  stack->length = n;

  return stack;
} 

int isFull(STACK* stack) {
  return (stack->top == (stack->length - 1));
}

int isEmpty(STACK* stack) {
  return (stack->top == -1);
}

int peekSTACK(STACK* stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return (isEmpty(stack) ? -1 : stack->ARRAY[stack->top]);
}

void pushToSTACK(STACK* stack, int element) {
  if (isFull(stack)) {
    return;
  }

  stack->ARRAY[++stack->top] = element;
}

int popFromSTACK(STACK* stack) {
  if (isEmpty(stack)) {
    return -1;
  }

  int element = stack->ARRAY[stack->top];

  stack->ARRAY[stack->top--] = 0;
  return element;
}

void printSTACK(STACK* stack) {
  if (isEmpty(stack)) {
    return;
  }

  for (int index = 0; index < stack->length; index++) {
    printf("%d ", stack->ARRAY[index]);
  }

  NL;
}