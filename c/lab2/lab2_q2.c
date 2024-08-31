/*
Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
algorithm and a program to find which row has maximum number of 1's. 

TIME COMPLEXITY -> O(N)

INPUT FORMAT:
  - first line contains m and n (the size of matrix).
  - for next m input lines, each line contains space-separated n integers describing each row of the
    matrix.

OUTPUT FORMAT:
  - output will be row number which has maximum number of 1's. If all the elements of matrix are 0
    then print “Not Present”.
*/


// LIBS
#include <stdio.h>

// MACROS
#define NL printf("\n")

// FUNCTION DECLARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();

  int m, n;
  printf("ROW, COL : ");
  scanf("%d %d", &m, &n);

  int matrix[m][n];
  printf("MATRIX : ");
  for (int r_index = 0; r_index < m; r_index++) {
    for (int c_index = 0; c_index < n; c_index++) {
      scanf("%d", &matrix[r_index][c_index]);
    }
  }

  int maxRowIndex = -1;
  int maxCount = -1;
  int c_index = n - 1; // Start from the last column

  // Iterate through each row
  for (int r_index = 0; r_index < m; r_index++) {
    // Move left while the current cell is 1
    while (c_index >= 0 && matrix[r_index][c_index] == 1) {
      c_index--;
    }

    // Count of 1's in the current row
    int count = n - c_index - 1;

    // Update maxCount and maxRowIndex
    if (count > maxCount) {
      maxCount = count;
      maxRowIndex = r_index;
    }
  }

  // Print result
  if (maxCount > 0) {
    printf("%d\n", maxRowIndex);
  } else {
    printf("Not Present\n");
  }

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  printf("---------------------");
  printf(" LAB 2, Question 1 ");
  printf("---------------------\n\n");

  printf("Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted,\n"
       "write an algorithm and a program to find which row has the maximum number of 1's.\n\n"
       "TIME COMPLEXITY -> O(N)\n\n"
       "INPUT FORMAT:\n"
       "  - first line contains m and n (the size of the matrix).\n"
       "  - for the next m input lines, each line contains space-separated n integers describing each row of the\n"
       "    matrix.\n\n"
       "OUTPUT FORMAT:\n"
       "  - Output will be the row number which has the maximum number of 1's. If all the elements of the matrix are 0\n"
       "    then print \"Not Present\".\n");

  NL;
  printf("---------------------------------------------------------------\n");
  NL;
}
