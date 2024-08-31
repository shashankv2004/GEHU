/*
Given an unsorted array of integers and two numbers a & b. Design
an algorithm & write a program to find minimum distance b/w a & b 
in array. Minimum distance b/w any two numbers a & b present in 
array is the minimum difference b/w their indices.

INPUT FORMAT:
  - the first line contains number of test cases, T.
    - for each test case, there will be three input lines
      - first line contain size of the array, N.
      - second line contains N space-seperated integers describing array.
      - third line will take numbers "a" & "b".

OUTPUT FORMAT:
  - the output will have T number of lines.
    - for each test case, output will be the minimum distance b/w a & b.

CONSTRAINTS:
  - T > 0
  - N > 0
  - a & b should be part of array
*/

// LIBS
#include <stdio.h>
#include <stdlib.h>

// MACROS
#define NL printf("\n")

// FUNCTION DECLARATION
int minDistance(int *array, int N, int a, int b);
void inputArray(int *array, int length);
void menu();

// MAIN FUNCTION
int main() {
  menu();

  // Number of test cases
  int T;
  printf("TEST CASES : ");
  scanf("%d", &T);

  // Test cases begin
  for (int case_index = 0; case_index < T; case_index++) {
    // Length of array
    int N;
    printf("SIZE : ");
    scanf("%d", &N);
    
    // Initializing Array
    int *array;
    array = (int*) malloc(sizeof(int) * N);

    // Error Handlings
    if (array == NULL) {
      return 1;
    }

    // Inputting Array 
    printf("ARRAY : ");
    inputArray(array, N);

    int a, b;
    printf("a, b : ");
    scanf("%d %d", &a, &b);

    int min_distance;

    min_distance = minDistance(array, N, a, b);

    if (min_distance <= 0) {
      return -1;
    }

    printf("%d\n", min_distance);

    free(array);
  }

  return 0;
}

// FUNCTION DEFINITION
int minDistance(int *array, int N, int a, int b) {
  int last_a = -1;
  int last_b = -1;
  int min_distance = N;

  for (int index = 0; index < N; index++) {
    if (array[index] == a) {
      if (last_b != -1) {
        min_distance = ((index - last_b) < min_distance) ? (index - last_b) : min_distance;
      }
      last_a = index;
    }
    else if (array[index] == b) {
      if (last_a != -1) {
        min_distance = ((index - last_a) < min_distance) ? (index - last_a) : min_distance;
      }
      last_b = index;
    }
  }

  return (min_distance == N) ? -1 : min_distance;
}

void inputArray(int *array, int length) {
  if ((array == NULL) || (length <= 0)) {
    exit(1);
  }

  for (int index = 0; index < length; index++) {
    scanf(" %d", &array[index]);
  }
}

void menu() {
  printf("---------------------");
  printf(" LAB 1, Question 2 ");
  printf("---------------------\n\n");

  printf("Given an unsorted array of integers and two numbers a & b.\n"
        "Design an algorithm & write a program to find the minimum distance\n"
        "between a & b in the array. Minimum distance between any two numbers\n"
        "a & b present in the array is the minimum difference between their indices.\n\n"

        "INPUT FORMAT:\n"
        "  - the first line contains the number of test cases, T.\n"
        "    - for each test case, there will be three input lines:\n"
        "      - first line contains the size of the array, N.\n"
        "      - second line contains N space-separated integers describing the array.\n"
        "      - third line will take numbers 'a' & 'b'.\n\n"

        "OUTPUT FORMAT:\n"
        "  - the output will have T number of lines.\n"
        "    - for each test case, output will be the minimum distance between a & b.\n\n"

        "CONSTRAINTS:\n"
        "  - T > 0\n"
        "  - N > 0\n"
        "  - a & b should be part of the array.\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}