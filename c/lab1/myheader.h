// LIBS
#include <stdio.h>
#include <stdlib.h>

// MACORS
#define NL printf("\n")

// FUNCTIONS
/*
Return values:
  - 0 -> Success
  - "-1" -> Failure
*/

int inputArray(int *array, int length) {
  if ((array == NULL) || (length <= 0)) {
    return -1;
  }

  for (int index = 0; index < length; index++) {
    scanf(" %d", &array[index]);
  }
  return 0;
}

int printArray(int *array, int length) {
  if ((array == NULL) || (length <= 0)) {
    return -1;
  }

  printf("[ ");
  for (int index = 0; index < length; index++) {
    printf("%d ", array[index]);
  }
  printf("]\n");

  return 0;
}

int bubbleSortArray(int *array, int N) {
  if ((! N) || (array == NULL)) {
    return -1;
  }

  for (int index1 = 0; index1 < N; index1++) {
    for (int index2 = 0; index2 < (N - index1 - 1); index2++) {
      if (array[index2 + 1] < array[index2]) {
        int temp;
        temp = array[index2];
        array[index2] = array[index2 + 1];
        array[index2 + 1] = temp;
      }
    }
  }

  return 0;
}