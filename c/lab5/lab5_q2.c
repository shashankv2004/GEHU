// #include <stdio.h>
// #include "../stack.h"
// #include "../queue.h"

// #define NL printf("\n");

// void reverseQUEUE(QUEUE* queue);
// void menu();


// int main() {
//   menu();

//   return 0;
// }

// void menu() {
//   printf("---------------------");
//   printf(" LAB 5, Question 2 ");
//   printf("---------------------\n\n");

//   printf("Design an algorithm and write a program to reverse a queue.\n\n");
//   printf("---------------------------------------------------------------\n");

//   printf("QUEUE LENGTH : ");

//   int queue_length;
//   scanf("%d", &queue_length);
  
//   while (getchar() != '\n');

//   QUEUE* queue;
//   queue = CreateQUEUE(queue_length);

//   printf("---------------------");
//   printf(" MENU ");
//   printf("---------------------\n\n");

//   printf("a.) EnQUEUE\n");
//   printf("b.) DelQUEUE\n");
//   printf("c.) Print Reversed QUEUE\n");

//   NL

//   char choice = '0';
  
//   while (choice != 'q') {
//     printf("CHOICE : ");
//     scanf("%c", &choice);

//     while (getchar() != '\n');

//     int element;

//     switch (choice) {
//       case 'a':
//         printf("ELEMENT : ");
//         scanf("%d", &element);

//         EnQUEUE(queue, element);
//         break;
//       case 'b':
//         printf("Removed element -> %d\n", DelQUEUE(queue));
//         break;
//       case 'c':
//         printf("Original QUEUE -> ");
//         PrintQUEUE(queue);
//         printf("Reversed QUEUE -> ");
//         reverseQUEUE(queue);
//         PrintQUEUE(queue);
//         break;
//       default:
//         printf("Invalid Choice\n");
//     }
//   }

// }

// void reverseQUEUE(QUEUE* queue) {
//   STACK* stack;
//   stack = CreateSTACK(SizeQUEUE(queue));

//   while (! IsEmptyQUEUE(queue)) {
//     PushToSTACK(stack, DelQUEUE(queue));
//   }

//   while (! IsEmptySTACK(stack)) {
//     EnQUEUE(queue, PopFromSTACK(stack));
//   }
// }









#include <stdio.h>
#include "../stack.h"
#include "../queue.h"

#define NL printf("\n");

void reverseQUEUE(QUEUE* queue);
void menu();
void debugPrintQUEUE(QUEUE* queue); // New function to debug internal pointers


int main() {
  menu();
  return 0;
}

void menu() {
  printf("---------------------");
  printf(" LAB 5, Question 2 ");
  printf("---------------------\n\n");

  printf("Design an algorithm and write a program to reverse a queue.\n\n");
  printf("---------------------------------------------------------------\n");

  printf("QUEUE LENGTH : ");

  int queue_length;
  scanf("%d", &queue_length);
  
  while (getchar() != '\n');  // Clear input buffer

  QUEUE* queue;
  queue = CreateQUEUE(queue_length);

  printf("---------------------");
  printf(" MENU ");
  printf("---------------------\n\n");

  printf("a.) EnQUEUE\n");
  printf("b.) DelQUEUE\n");
  printf("c.) Print Reversed QUEUE\n");

  NL

  char choice = '0';
  
  while (choice != 'q') {
    printf("CHOICE : ");
    scanf("%c", &choice);

    while (getchar() != '\n');  // Clear input buffer

    int element;

    switch (choice) {
      case 'a':
        printf("ELEMENT : ");
        scanf("%d", &element);
        while (getchar() != '\n');
        EnQUEUE(queue, element);
        break;
      case 'b':
        printf("Removed element -> %d\n", DelQUEUE(queue));
        break;
      case 'c':
        printf("Original QUEUE -> ");
        PrintQUEUE(queue);  // Print original queue
        debugPrintQUEUE(queue); // Print internal debug info
        printf("Reversed QUEUE -> ");
        reverseQUEUE(queue);    // Reverse the queue
        PrintQUEUE(queue);      // Print reversed queue
        debugPrintQUEUE(queue); // Print internal debug info again
        break;
    }
  }
}

void reverseQUEUE(QUEUE* queue) {
  STACK* stack;
  stack = CreateSTACK(SizeQUEUE(queue));  // Create stack with size of queue

  // Dequeue all elements and push them onto the stack
  while (!IsEmptyQUEUE(queue)) {
    PushToSTACK(stack, DelQUEUE(queue));
  }

  // Pop all elements from stack and enqueue them back to the queue
  while (!IsEmptySTACK(stack)) {
    EnQUEUE(queue, PopFromSTACK(stack));
  }
}

// New debug function to print the internal state of the queue
void debugPrintQUEUE(QUEUE* queue) {
    printf("\n[DEBUG] Queue Internal State: ");
    printf("Front = %d, Rear = %d, Size = %d\n", queue->head, queue->tail, SizeQUEUE(queue));
}
