/*
Given a matrix of size n X n, where every row and every column is sorted in increasing order.
Write an algorithm and a program to find whether the given key element is present in the matrix
or not. 

TIME COMPLEXITY -> O(N)

INPUT FORMAT:
  - first line contains n (the size of matrix).
  - for next n input lines, each line contains space-separated n integers describing each row of the
    matrix.
  - last line of input will contain key integer to be searched

OUTPUT FORMAT:
  - Output will be “Present” if the key element is found in the array, otherwise print “Not Present”.
*/


// LIBS
#include <stdio.h>

// MACROS
#define NL printf("\n")

// FUNCTION DECALARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();
  
  printf("SIZE : ");
  int N;
  scanf("%d", &N);

  int matrix[N][N];
  printf("MATRIX : ");
  for (int r_index = 0; r_index < N; r_index++) {
    for (int c_index = 0; c_index < N; c_index++) {
      scanf("%d", &matrix[r_index][c_index]);
    }
  }

  int num;
  printf("KEY : ");
  scanf("%d", &num);

  int i = 0, j = N - 1;

  while (i < N && j >= 0) {
    if (matrix[i][j] == num) {
      printf("NUMBER FOUND AT : row -> %d\tcol -> %d", i, j);
      NL;
      return 0;
    }
    else if (matrix[i][j] > num) {
      j--;
    }
    else {
      i++;
    }
  }

  printf("NUMBER NOT FOUND.");
  NL;

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  printf("---------------------");
  printf(" LAB 2, Question 1 ");
  printf("---------------------\n\n");

  printf("Given a matrix of size n X n, where every row and every column is sorted in increasing order.\n"
       "Write an algorithm and a program to find whether the given key element is present in the matrix\n"
       "or not.\n\n"
       "TIME COMPLEXITY -> O(N)\n\n"
       "INPUT FORMAT:\n"
       "  - first line contains n (the size of the matrix).\n"
       "  - for the next n input lines, each line contains space-separated n integers describing each row of the\n"
       "    matrix.\n"
       "  - the last line of input will contain the key integer to be searched.\n\n"
       "OUTPUT FORMAT:\n"
       "  - Output will be “Present” if the key element is found in the matrix, otherwise print “Not Present”.\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}