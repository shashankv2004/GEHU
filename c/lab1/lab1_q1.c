/*
Given an array of integers, write an algorithm and a 
program to left rotate the array by a specific number
of elements.

INPUT FORMAT:
  - the first line contains the number of test cases, T.
    - for each test cases there will be three input lines.
      - first line contains the size of array, N.
      - second line contains N space-seperated integers 
        describing array.
      - third line will take number of rotations, K.

OUTPUT FORMAT:
  - the output will contain T number of lines.
    - for each line output will be the rotated array for
      that test case.

CONSTRAINTS:
  - T > 0
  - N > 0
  - K > 0
*/


// LIBS
#include <stdio.h>
#include <stdlib.h>

// MACROS
#define NL printf("\n")

// FUNCTION DECLARATION
void leftRotateArray(int *, int *, int, int);
void inputArray(int *array, int length);
void printArray(int *array, int length);
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
    // Length of array, Rotations
    int N, K;
    printf("SIZE OF ARRAY : ");
    scanf("%d", &N);

    // Initializing arrays
    int *given_array;
    int *rotated_array;
    given_array = (int*) malloc(sizeof(int) * N);
    rotated_array = (int*) malloc(sizeof(int) * N);

    // Input rotations
    printf("ROTATIONS : ");
    scanf("%d", &K);

    // Error handlings
    if ((given_array == NULL) || (rotated_array == NULL) || (K < 0) || (T <= 0) || (N <= 0)) {
      free(given_array);
      free(rotated_array);
      return -1;
    }

    // Input Array, Left Rotate Array, Print Array
    printf("ARRAY : ");
    inputArray(given_array, N);

    leftRotateArray(given_array, rotated_array, N, K);
    printArray(rotated_array, N);

    // Clean up memory
    // free(given_array);
    // free(rotated_array);
  }

  return 0;
}

// FUNCTION DEFINITION
void leftRotateArray(int *a1, int *a2, int length, int rotations) {
  if ((a1 == NULL) || (a2 == NULL) || (length <= 0) || (rotations <= 0)) {
    exit(1);
  }

  rotations = rotations % length;

  for (int index = 0; index < length; index++) {
    int new_index;
    new_index = (index + length - rotations) % length;
    a2[new_index] = a1[index];
  }
}

void inputArray(int *array, int length) {
  if ((array == NULL) || (length <= 0)) {
    exit(1);
  }

  for (int index = 0; index < length; index++) {
    scanf(" %d", &array[index]);
  }
}

void printArray(int *array, int length) {
  if ((array == NULL) || (length <= 0)) {
    exit(1);
  }

  printf("[ ");
  for (int index = 0; index < length; index++) {
    printf("%d ", array[index]);
  }
  printf("]\n");
}

void menu() {
  printf("---------------------");
  printf(" LAB 1, Question 1 ");
  printf("---------------------\n\n");

  printf("Given an array of integers, write an algorithm and a \n"
        "program to left rotate the array by a specific number\n"
        "of elements.\n\n"
        "INPUT FORMAT:\n"
        "  - the first line contains the number of test cases, T.\n"
        "    - for each test case there will be three input lines.\n"
        "      - first line contains the size of array, N.\n"
        "      - second line contains N space-separated integers\n"
        "        describing the array.\n"
        "      - third line will take the number of rotations, K.\n\n"
        "OUTPUT FORMAT:\n"
        "  - the output will contain T number of lines.\n"
        "    - for each line, output will be the rotated array for\n"
        "      that test case.\n\n"
        "CONSTRAINTS:\n"
        "  - T > 0\n"
        "  - N > 0\n"
        "  - K > 0\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}