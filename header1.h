// LIBS
#include <stdio.h>

// MACORS
#define NL printf("\n")

// FUNCTIONS
void inputArray(int *array, int length) {
  for (int index = 0; index < length; index++) {
    scanf("%d ", &array[index]);
  }
}

void printArray(int *array, int length) {
  printf("[ ");
  for (int index = 0; index < length; index++) {
    printf("%d ", array[index]);
  }
  printf("]\n");
}