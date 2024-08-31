/*
Given an empty stack, design an algorithm and a program to reverse a 
string using this stack
(with and without recursion).

INPUT FORMAT:
  - the first line contains number of test cases, T.
  - for each test case, there will be string of characters.

OUTPUT FORMAT:
  - the output will have T number of lines. For each test case, 
    output will be new reversed string.
*/

// LIBS
#include "../stack.h"
#include <string.h>

// MACROS
#define MAX_STR 100
#define NL printf("\n")

// FUNCTION DECALARATION
char* reverseString(char*);
void menu();

// MAIN FUNCTION
int main() {
  menu();

  int T;
  printf("TEST CASES : ");
  scanf("%d", &T);
  while (getchar() != '\n');

  NL;
  NL;

  for (int case_index = 0; case_index < T; case_index++) {
    char string[MAX_STR];
    STACK* rev_string;
    printf("STRING : ");
    fgets(string, (MAX_STR + 1), stdin);
    if (string[strlen(string) - 1] == '\n') {
      string[strlen(string) - 1] = '\0';
    }

    NL;

    printf("REVERSED STRING : %s\n", reverseString(string));
    
    NL;
    NL;
  }

  return 0;
}

// FUNCTION DEFINITION
char* reverseString(char* string) {
  STACK *stack;
  stack = createSTACK(strlen(string));

  for (int index = 0; index < (strlen(string) + 1); index++) {
    pushToSTACK(stack, string[index]);
  }

  for (int index = 0; index < (strlen(string) + 1); index++) {
    string[index] = stack->ARRAY[stack->top];
    popFromSTACK(stack);
  }

  return string;
}

void menu() {
  printf("---------------------");
  printf(" LAB 4, Question 1 ");
  printf("---------------------\n\n");

  printf("Given an empty stack, design an algorithm and a program to reverse a \n"
       "string using this stack (with and without recursion).\n\n"
       "INPUT FORMAT:\n"
       "  - The first line contains the number of test cases, T.\n"
       "  - For each test case, there will be a string of characters.\n\n"
       "OUTPUT FORMAT:\n"
       "  - The output will have T number of lines. For each test case, \n"
       "    output will be the new reversed string.\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}

