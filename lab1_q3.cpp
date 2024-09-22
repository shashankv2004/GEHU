/*
Create two namespaces, Math and Physics, each containing a function calculate().
The calculate() function in the Math namespace should display a message indicating a
mathematical calculation, while the calculate() function in the Physics namespace
should display a message indicating a physical calculation. Use these functions in the
main program without causing naming conflicts.
*/

// LIBS
#include <iostream>

// MACROS
#define NL cout << endl;

// NAMSPACES
using namespace std;

namespace MATH {
  string calculate() {
    return "Math Function :)\n";
  }
}

namespace PHYSICS {
  string calculate() {
    return "Physics Function :)\n";
  }
}

// FUNCTION DECLARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();

  cout << MATH::calculate();
  cout << PHYSICS::calculate();

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  cout << "---------------------" << " LAB 1, Question 3 " << "---------------------\n\n";

  cout << "Create two namespaces, Math and Physics, each containing a function calculate().\n"
       << "The calculate() function in the Math namespace should display a message indicating a\n"
       << "mathematical calculation, while the calculate() function in the Physics namespace\n"
       << "should display a message indicating a physical calculation. Use these functions in the\n"
       << "main program without causing naming conflicts.\n";

  NL

  cout << "---------------------------------------------------------------" << endl;
  NL
}