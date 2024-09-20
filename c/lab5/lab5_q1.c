/*
Design an algorithm and a program to implement queue using array. 
The program should implement following queue operations:
  a) Create() - create a queue
  b) EnQueue(k) - insert an element k into the queue
  c) DeQueue() - delete an element from the queue
  d) IsEmpty() - check if queue is empty or not
  e) Size() - finds the size of the queue
*/

// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include "../queue.h"

// MACROS
#define NL printf("\n");

// FUNCTION DECLARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  printf("---------------------");
  printf(" LAB 5, Question 1 ");
  printf("---------------------\n\n");

  printf("Design an algorithm and a program to implement queue using array.\n\n"
        "The program should implement the following queue operations:\n\n"
        "  - EnQueue(k) - insert an element k into the queue\n"
        "  - DeQueue() - delete an element from the queue\n"
        "  - IsEmpty() - check if queue is empty or not\n"
        "  - Size() - find the size of the queue\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;

  printf("----- CREATE QUEUE -----\n\nEnter QUEUE size : ");

  int queue_size;
  scanf("%d", &queue_size);

  // while (getchar() != '\n');

  QUEUE* queue = CreateQUEUE(queue_size);

  printf("  1) EnQueue() - Insert an element into the queue\n"
         "  2) DelQueue() - Delete an element from the queue\n"
         "  3) QUEUE Empty?\n"
         "  4) Size Of QUEUE\n"
         "  5) Print QUEUE\n");
  
  NL;

  char choice = getchar();

  while (choice != 'q') {
    choice = getchar();
    int element;

    switch (choice - '0') {
      case 1:
        if (queue->tail == queue->size - 1) {
          printf("\nPROMPT!\n  - QUEUE is full.\n");
          break;
        }    

        printf("\nELEMENT : ");
        scanf("%d", &element);

        while (getchar() != '\n');

        EnQUEUE(queue, element);
        printf("Added %d\n\n", queue->ARRAY[queue->tail]);
        PrintQUEUE(queue);
        printf("\n");
        break;
      case 2:
        if (DelQUEUE(queue) == -1) {
          printf("\nPROMPT!\n  - QUEUE already Empty.\n");
          PrintQUEUE(queue);
          printf("\n");
          break;
        }

        printf("\nELEMENT %d DELETED\n", DelQUEUE(queue));
        break;
      case 3:
        (IsEmptyQUEUE(queue)) ? printf("\nQUEUE EMPTY!\n") : printf("\nQUEUE NOT EMPTY\n");
        break;
      case 4:
        printf("\nSize of QUEUE -> %d / %d\n", SizeQUEUE(queue), queue->size);
        break;
      case 5:
        PrintQUEUE(queue);
        break;
    }
  }
}
