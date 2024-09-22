/*
Construct a C++ program that removes a specific character from a given string and
return the updated string.

TYPICAL INPUT: 
  - computer science is the future
TYPICAL OUTPUT: 
  - compuer science is he fuure
*/


// LIBS
#include <iostream>
#include <string>

// MACROS
#define NL cout << endl;

// NAMESPACES
using namespace std;

// FUNCTION DECALARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();

  string input_string;
  cout << "STRING : ";
  getline(cin, input_string);

  char character;
  cout << "CHARACTER : ";
  character = getchar();
  cin.ignore();

  for (int index = 0; index < input_string.length(); ) {
    if (input_string[index] == character) {
      input_string.erase(index, 1);
    }
    else {
      ++index;
    }
  }

  cout << "EDITED STRING : " << input_string << endl;

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  cout << "---------------------" << " LAB 1, Question 2 " << "---------------------\n\n";

  cout << "Construct a C++ program that removes a specific character from a given string and\n"
       << "return the updated string.\n\n"
       << "TYPICAL INPUT: \n"
       << "  - computer science is the future\n"
       << "TYPICAL OUTPUT: \n"
       << "  - compuer science is he fuure\n";

  NL

  cout << "---------------------------------------------------------------" << endl;
  NL
}
