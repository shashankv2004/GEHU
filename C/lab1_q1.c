// LIBS
#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

// FUNCTION DECLARATIONS
void leftRotateArray(int *a1, int *a2, int length);

// MAIN FUNCTION
int main() {
  // Number of test cases
  int T;
  scanf("%d", &T);

  // Test cases begin
  for (int case_index = 0; case_index < T; case_index++) {
    // Length of array, Rotations
    int N, K;
    scanf("%d", &N);

    // Initializing arrays
    int *given_array;
    int *rotated_array;
    given_array = (int*) malloc(sizeof(int) * N);
    rotated_array = (int*) malloc(sizeof(int) * N);

    // Input arrays
    inputArray(given_array, N);

    // Input rotations
    scanf("%d", &K);

    // Error handlings
    if ((given_array == NULL) || (rotated_array == NULL) || (K > N) || (T <= 0)) {
      printf("Invalid Process!");
      NL;
      return 1;
    }

    for (int count = 0; count < K; count++) {
      leftRotateArray(given_array, rotated_array, N);
    }

    printArray(rotated_array, N);
  }

  return 0;
}

// FUNCTION DEFINITIONS
void leftRotateArray(int *a1, int *a2, int length) {
  for (int index = 0; index < length; index++) {
    int new_index;
    new_index = (index - 1);
    if (new_index < 0) {
      new_index = (length - 1);
      continue;
    }
    a2[new_index] = a1[index];
  }
}
