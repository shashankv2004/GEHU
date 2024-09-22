/*
Implement a C++ program to find the non-repeating characters in a string.

TYPICAL INPUT: graphic era university
TYPICAL OUTPUT: c g h n p s t u v y
*/

// LIBS
#include <iostream>
#include <string>
#include <cstring>

// MACROS
#define NL cout << endl;

// NAMESPACES
using namespace std;

// FUNCTION DECLARATION
string InputString();
void logic(string given_string);
void menu();

// MAIN FUNCTION
int main() {
  menu();
  
  cout << "STRING : ";
  string input_string = InputString();

  cout << input_string << endl;

  logic(input_string);

  return 0;
}

// FUNCTION DEFINITION
string InputString() {
  string input_string;
  getline(cin, input_string);
  return input_string;
}

void logic(string given_string) {
  int frequency_array[56] = {};
  int frequency_index = -1;

  // update frequency array
  for (int index = 0; index < given_string.length(); index++) {
    if (given_string[index] >= 'a' && given_string[index] <= 'z') {
      frequency_index = given_string[index] - 70;
      frequency_array[frequency_index]++;
    }

    else if (given_string[index] >= 'A' && given_string[index] <= 'Z') {
      frequency_index = given_string[index] - 65;
      frequency_array[frequency_index]++;
    }
  }

  for (int index = 0; index < 56; index++) {
    if (frequency_array[index] == 1) {
      if (index > 26) {
        printf("%c ", index + 70);
      }
      else {
        printf("%c ", index + 65);
      }
    }
    
  }
  cout << endl;
}

void menu() {
  cout << "---------------------" << " LAB 1, Question 4 " << "---------------------\n\n";

    cout << "Implement a C++ program to find the non-repeating characters in a string.\n\n"
         << "TYPICAL INPUT: graphic era university\n"
         << "TYPICAL OUTPUT: c g h n p s t u v y" << endl;

  cout << "---------------------------------------------------------------" << endl;
  NL
}
