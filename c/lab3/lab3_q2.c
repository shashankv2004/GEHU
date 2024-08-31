/*
Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”,
design an algorithm and a program to check whether this expression has balanced paranthesis or
not.

INPUT FORMAT:
  - the first line contains number of test cases, T.
  - for each test case, there will be expression string.

OUTPUT FORMAT:
  - the output will have T number of lines. For each test case, output will be “Balance”, if brackets
    are balanced otherwise print “Unbalanced”.
*/

// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NL printf("\n")
#define MAX_STR_SIZE 100

// STRUCTURES
typedef struct {
  int *ARRAY;
  int top, length;
} STACK;

// FUNCTION DECALARTION
STACK* createSTACK(int n);
int isFull(STACK* stack);
int isEmpty(STACK* stack);
int peekSTACK(STACK* stack);
void pushToSTACK(STACK* stack, int element);
int popFromSTACK(STACK* stack);
void printSTACK(STACK* stack);
void menu();

// MAIN FUNCTION
int main() {
  menu();

  int T;
  printf("TEST CASES : ");
  scanf("%d", &T);
  while (getchar() != '\n');

  for (int case_index = 0; case_index < T; case_index++) {
    char* brackets;
    brackets = (char*) calloc(sizeof(char), MAX_STR_SIZE);
    printf("BRACKETS : ");
    fgets(brackets, MAX_STR_SIZE, stdin);
    if (brackets[strlen(brackets) - 1] == '\n') {
      brackets[strlen(brackets) - 1] = '\0';
    }

    STACK* stack_a;
    stack_a = createSTACK(strlen(brackets));

    int balance = 0;

    for (int index = 0; index < strlen(brackets); index++) {
      pushToSTACK(stack_a, brackets[index]);

      switch (stack_a->ARRAY[stack_a->top]) {
        case 40:
          balance--;
          break;
        case 91:
          balance = balance - 2;
          break;
        case 123:
          balance = balance - 3;
          break;
        case 41:
          balance++;
          break;
        case 93:
          balance = balance + 2;
          break;
        case 125:
          balance = balance + 3;
          break;

        default:
          printf("Not a Valid Sequence\n");
          return -1;
      }
    }

    if (balance == 0) {
      printf("BALANCED BRACKETS\n");
    }
    else {
      printf("UNBALANCED BRACKETS\n");
    }

  }
  return 0;
}

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

void menu() {
  printf("---------------------");
  printf(" LAB 3, Question 2 ");
  printf("---------------------\n\n");

  printf("Given an expression string consisting of opening and closing brackets \"{\", \"}\", \"(\", \")\", \"[\", \"]\", \n"
       "design an algorithm and a program to check whether this expression has balanced parentheses or not.\n\n"
       "INPUT FORMAT:\n"
       "  - The first line contains the number of test cases, T.\n"
       "  - For each test case, there will be an expression string.\n\n"
       "OUTPUT FORMAT:\n"
       "  - The output will have T number of lines. For each test case, output will be \"Balanced\" if the brackets\n"
       "    are balanced; otherwise, print \"Unbalanced\".\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}
