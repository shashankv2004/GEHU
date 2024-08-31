/*
Design an algorithm and a program to implement stack using array. The program should
implement following stack operations:
  a) Create() - create an empty stack
  b) Push(k) - push an element k into the stack
  c) Pop() - pop an element from the stack snd return it
  d) IsEmpty() - check if stack is empty or not
  e) Size() - finds the size of the stack
  f) Print() - prints the contents of stack

INPUT FORMAT:
  - Ask user first whether it wants to push/pop/find the size of the stack, then accordingly perform
  operation.

Output Format:
  - Output will be the final stack contents if push or pop operation is performed. Output will be size
  of the stack if user asks for size.
*/

// HEADERS
#include <stdio.h>
#include <stdlib.h>

// MACROS
#define NL printf("\n")

// STRUCTURES
typedef struct {
  int *ARRAY;
  int top, length;
} STACK;

// FUNCTIONS
STACK* createSTACK(int n);
int isFull(STACK* stack);
int isEmpty(STACK* stack);
int peekSTACK(STACK* stack);
int pushToSTACK(STACK* stack, int element);
int popFromSTACK(STACK* stack);
void printSTACK(STACK* stack);
int STACKsize(STACK* stack);
void menu();

// MAIN FUNCTION
int main() {
  menu();

  return 0;
}

// FUNCTION DEFINITIONS
void menu() {

  printf("---------------------");
  printf(" LAB 3, Question 1 ");
  printf("---------------------\n\n");

  printf("Design an algorithm and a program to implement stack using array. The program should\n"
       "implement the following stack operations:\n"
       "  a) Create() - create an empty stack\n"
       "  b) Push(k) - push an element k into the stack\n"
       "  c) Pop() - pop an element from the stack and return it\n"
       "  d) IsEmpty() - check if stack is empty or not\n"
       "  e) Size() - find the size of the stack\n"
       "  f) Print() - print the contents of the stack\n\n"
       "INPUT FORMAT:\n"
       "  - Ask the user first whether they want to push, pop, find the size of the stack, or perform another operation.\n"
       "    Then, accordingly perform the operation.\n\n"
       "OUTPUT FORMAT:\n"
       "  - Output will be the final stack contents if push or pop operations are performed.\n"
       "  - Output will be the size of the stack if the user asks for the size.\n");

  printf("-----CREATE STACK-----\n\nEnter STACK size : ");
  int stack_size;
  scanf("%d", &stack_size);
  
  if (getchar() != '\n') {
    return;
  }

  system("clear");

  printf("---------------------");
  printf(" LAB 3, Question 1 ");
  printf("---------------------\n\n");

  STACK* stack_a = createSTACK(stack_size);
  printf("STACK Created!\n\n");

  printf("---------------------");
  printf(" MENU ");
  printf("---------------------\n\n");

  printf("a. PUSH to STACK\n");
  printf("b. POP from STACK\n");
  printf("c. Is STACK Empty\n");
  printf("d. Print STACK\n");
  printf("e. Size of STACK\n");
  printf("q. EXIT\n");

  NL;

  char choice;
  while (choice != 'q') {
    scanf("%c", &choice);
    int element;

    switch (choice) {
      case 'a':
        printf("\nElement : ");
        scanf("%d", &element);
        if (pushToSTACK(stack_a, element)) {
          printf("%d Pushed!\n\n", element);
        }
        break;

      case 'b':
        printf("\nPopped Element -> %d\n", popFromSTACK(stack_a));
        break;
      
      case 'c':
        if (isEmpty(stack_a)) {
          printf("\nSTACK is Empty!\n");
        }
        else {
          printf("\nSTACK is not Empty!\n");
        }
        break;

      case 'd':
        printf("\nSTACK -> ");
        printSTACK(stack_a);
        break;

      case 'e':
        printf("\nElements in STACK / Size of STACK -> %d / %d\n", STACKsize(stack_a), stack_a->length);
        break;

      default:
        continue;
    }    
  }

}

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
  // if (isEmpty(stack)) {
  //   return -1;
  // }
  return (isEmpty(stack) ? -1 : stack->ARRAY[stack->top]);
}

int pushToSTACK(STACK* stack, int element) {
  if (isFull(stack)) {
    printf("STACK Overflowed!\n");
    return 0;
  }

  stack->ARRAY[++stack->top] = element;
  return 1;
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

  for (int index = 0; index < stack->top + 1; index++) {
    printf("%d ", stack->ARRAY[index]);
  }

  NL;
}

int STACKsize(STACK* stack) {
  return stack->top+1;
}