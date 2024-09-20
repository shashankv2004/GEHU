// HEADERS
#include <stdio.h>
#include <stdlib.h>

// STRUCTURE
typedef struct {
  int head, tail, size;
  int* ARRAY;
} QUEUE;

// FUNCTION DECLARATION
QUEUE* CreateQUEUE(int length);
void EnQUEUE(QUEUE* queue, int element);
int DelQUEUE(QUEUE* queue);
int IsEmptyQUEUE(QUEUE* queue);
int SizeQUEUE(QUEUE* queue);
void PrintQUEUE(QUEUE* queue);

// FUNCTION DEFINITION
QUEUE* CreateQUEUE(int length) {
  QUEUE* queue;
  queue = (QUEUE*) calloc(sizeof(QUEUE), 1);
  if (!queue) {
    exit(1);
  }

  queue->ARRAY = (int*) calloc(sizeof(int), length);
  if (!queue->ARRAY) {
    exit(1);
  }

  queue->head = -1;
  queue->tail = -1;
  queue ->size = length;

  return queue;
}

void EnQUEUE(QUEUE* queue, int element) {
  if ((queue->tail == queue->size - 1) || (queue->tail+1 == queue->head)) {
    // printf("\nPROMPT!\n  - QUEUE is full.\n");
    return;
  }

  if (queue->tail+1 == queue->size) {
    queue->tail = -1;
  }

  queue->ARRAY[++queue->tail] = element;
}

int DelQUEUE(QUEUE* queue) {
  if (IsEmptyQUEUE(queue)) {
    return -1;
  }

  if (queue->head+1 == queue->size) {
    queue->head = -1;
  }

  int head_element = queue->ARRAY[queue->head++];
  queue->ARRAY[queue->head] = 0;
  return head_element;
}

int IsEmptyQUEUE(QUEUE* queue) {
  return queue->head == queue->tail;
}

int SizeQUEUE(QUEUE* queue) {
  return ((queue->tail - queue->head) < 0) ? (0 - (queue->tail - queue->head)) : (queue->tail - queue->head);
}

void PrintQUEUE(QUEUE* queue) {
  int head = queue->head;
  int tail = queue->tail;

  for (int index = head + 1; index <= tail; index++) {
    printf("%d ", queue->ARRAY[index]);
  }

  printf("\n");
}