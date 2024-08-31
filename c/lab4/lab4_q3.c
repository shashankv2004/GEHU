/*
Given an expression in the form of postfix representation, design an algorithm and a program to
find result of this expression.

INPUT FORMAT :
  - The first line contains number of test cases, T.
  - For each test case, there will be expression string.

OUTPUT FORMAT :
  - the output will have T number of lines. For each test case, output will be the
    result of the evaluated expression.
*/

// LIBS
#include "../stack.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

// MACROS
#define MAX_STR 100

// ENUM
enum OPERATOR {
  sub = 45, add = 43, divide = 47, multiply = 42, exponent = 94
};


// FUNCTION DECALARTION
int calculate(char* expression);

// MAIN FUNCTION
int main() {
  char expression[MAX_STR];
  printf("EXPESSION : ");
  fgets(expression, (MAX_STR + 1), stdin);
  if (expression[strlen(expression) - 1] == '\n') {
    expression[strlen(expression) - 1] = '\0';
  }

  NL;
  NL;

  printf("\n\nSOLUTION : %d", calculate(expression));

  NL;

  return 0;
}

// FUNCTION DEFINITION
int calculate(char* expression) {
  STACK* stack;
  stack = createSTACK(strlen(expression));

  int sum = 0;

  for (int index = 0; index < strlen(expression) - 1; index++) {
    int operand_2 = 0;
    int operand_1 = 0;
    if (expression[index] >=48 && expression[index] <= 57) {
      pushToSTACK(stack, expression[index]); // if the expression[index] at index is an operand
    }

    else if (expression[index] == sub || expression[index] == add || expression[index] == divide || expression[index] == multiply || expression[index] == exponent) {
      operand_2 = popFromSTACK(stack);
      operand_1 = popFromSTACK(stack);
      
      switch (expression[index]) {
        case '-':
          printf("\nsum -> %d\tbefore -> %c\n", sum, expression[index]);
          sum += operand_1 - operand_2;
          pushToSTACK(stack, sum);
          printf("\nop1 -> %c\top2 -> %c\n", operand_1, operand_2);
          printf("\nsum -> %d\tafter %c\n", sum, expression[index]);
          break;
        case '+':
          printf("\nsum -> %d\tbefore -> %c\n", sum, expression[index]);
          sum += operand_1 + operand_2;
          printf("\nsum -> %d\tbefore -> %c\n", sum, expression[index]);
          pushToSTACK(stack, sum);
          printf("\nop1 -> %c\top2 -> %c\n", operand_1, operand_2);
          printf("\nsum -> %d\tafter %c\n", sum, expression[index]);
          break;
        case '/':
          printf("\nsum -> %d\tbefore -> %c\n", sum, expression[index]);
          sum += operand_1 / operand_2;
          pushToSTACK(stack, sum);
          printf("\nop1 -> %c\top2 -> %c\n", operand_1, operand_2);
          printf("\nsum -> %d\tafter %c\n", sum, expression[index]);
          break;
        case '*':
          printf("\nsum -> %d\tbefore -> %c\n", sum, expression[index]);
          sum += operand_1 * operand_2;
          pushToSTACK(stack, sum);
          printf("\nop1 -> %c\top2 -> %c\n", operand_1, operand_2);
          printf("\nsum -> %d\tafter %c\n", sum, expression[index]);
          break;
        case '^':
          printf("\nsum -> %d\tbefore -> %c\n", sum, expression[index]);
          sum = pow(operand_1, operand_2);
          pushToSTACK(stack, sum);
          printf("\nop1 -> %c\top2 -> %c\n", operand_1, operand_2);
          printf("\nsum -> %d\tafter %c\n", sum, expression[index]);
          break;
        default:
          break;
      }
    }
  }

  // printSTACK(stack);

  return sum;
}