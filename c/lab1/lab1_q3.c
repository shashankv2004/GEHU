/*
Given an array of non-negative integers, where all numbers occur even number
of times except one number which occurs odd numbers of times.
Write an algorithm and a program to find this number.

TIME COMPLEXITY = O(N).

INPUT FORMAT:
  - the first line contains numbers of test cases, T.
  - for each test case, there be will two input lines.
  - first line contains the size of array, N.
  - second line contains space-seperated integers describing array.

OUTPUT FORMAT:
  - the ouput will have T number of lines.
  - for each test case, output will be the element which occured odd numbers of times,
    if no such element is present in the array, then print "No such element present.".
*/

// LIBS
#include <stdio.h>
#include <stdlib.h>

#define NL printf("\n")

// FUNCTION DECLARATION
void output(int *array, int N);
void inputArray(int* array, int length);
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
      return -1;
    }

    printf("ARRAY : ");
    inputArray(array, N);

    output(array, N);
  }

  return 0;
}

// FUNCTION DEFINITION
void output(int *array, int N) {
  int *store_frequency;
  store_frequency = (int*) calloc(sizeof(int), 10);
  if (store_frequency == NULL) {
    return;
  }

  for (int index = 0; index < N; index++) {
    store_frequency[array[index]]++;
  }

  for (int index = 0; index < N; index++) {
    if (store_frequency[index] % 2 != 0) {
      printf("ODD NUMBER : %d\n", index);
      return;
    }
  }

  printf("No such element present.\n");
  return;
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
  printf(" LAB 1, Question 3 ");
  printf("---------------------\n\n");

  printf("Given an array of non-negative integers, where all numbers occur an even number\n"
        "of times except one number which occurs an odd number of times.\n"
        "Write an algorithm and a program to find this number.\n\n"
        "TIME COMPLEXITY = O(N).\n\n"
        "INPUT FORMAT:\n"
        "  - the first line contains the number of test cases, T.\n"
        "  - for each test case, there will be two input lines:\n"
        "    - first line contains the size of the array, N.\n"
        "    - second line contains space-separated integers describing the array.\n\n"
        "OUTPUT FORMAT:\n"
        "  - the output will have T number of lines.\n"
        "  - for each test case, output will be the element which occurred an odd number of times,\n"
        "    if no such element is present in the array, then print \"No such element present.\".\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}