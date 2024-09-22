// LIBRARIES
#include <iostream>

// MACROS
#define NL cout << endl;

// USING NAMESPACES
using namespace std;

// CLASSES
class Student {
  private:
    int scores[5];

  public:
    // INPUT FUNCTION
    void input() {
      cout << "Enter 5 exam scores: ";
      for (int i = 0; i < 5; i++) {
        cin >> scores[i];
      }
    }

    // CALCULATION FUNCTION
    int calculateTotalScore() {
      int total = 0;
      for (int i = 0; i < 5; i++) {
        total += scores[i];
      }
      return total;
    }
};

// FUNCTION DECLARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();
  Student anna;
  anna.input();
  
  // Calculate and display total score
  int totalScore = anna.calculateTotalScore();
  cout << "Total score: " << totalScore << endl;

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  cout << "---------------------" << " LAB 1, Question 9 " << "---------------------\n\n";
    cout << "Anna is a contender for valedictorian of her high school. She wants to know how many students (if any) have\n"
         << "scored higher than her in the exams given during this semester.\n"
         << "Create a class named Student with the following specifications:\n"
         << "• An instance variable named scores holds a student's 5 exam scores.\n"
         << "• A void input() function reads 5 integers and saves them to scores.\n"
         << "• An int calculateTotalScore() function that returns the sum of the student's scores.\n"
         << "Input Format:\n"
         << "In the void Student::input() function, you must read 5 scores from standard input and save them to your scores\n"
         << "instance variable.\n"
         << "Output Format: \n"
         << "In the int Student::calculateTotalScore() function, you must return the student's total grade (the sum of the values"
         << "in scores) The code in the editor will determine how many scores are larger than Anna’s and print that number to the console.\n";
  NL
}