#include <iostream>
#include <string>

#define NL cout << endl;

using namespace std;

// STUDENT CLASS
class STUDENT {
  private:
    string name;
    int roll_number;
    float marks;

  public:
    // PARAMETERIZED CONSTRUCTOR
    STUDENT(string name = "", int roll_number = 0, float marks = 0.0) {
      this->name = name;
      this->roll_number = roll_number;
      this->marks = marks;
    }

    // DISPLAY FUNCTION
    void display_data() {
      cout << "Name: " << name << endl;
      cout << "Roll Number: " << roll_number << endl;
      cout << "Marks: " << marks << endl;
    }
};

// MENU FUNCTION
void menu() {
  cout << "---------------------" << " LAB 1, Question 7 " << "---------------------\n\n";
  cout << "Write a C++ program to store and display the record of N Students.\n";
  cout << "---------------------------------------------------------------" << endl;
  NL;
}

// MAIN FUNCTION
int main() {
  menu();

  int N;
  cout << "Enter the number of students: ";
  cin >> N;

  // DYNAMIC ARRAY OF STUDENT OBJECTS
  STUDENT* students = new STUDENT[N];  // Default constructor used

  // INPUT STUDENT RECORDS
  for (int index = 0; index < N; index++) {
    string name;
    int roll_number;
    float marks;

    cout << "Enter details for student " << index + 1 << ":" << endl;
    cout << "Name: ";
    cin.ignore(); // To clear any newline character in the input buffer
    getline(cin, name); // Use getline for full name
    cout << "Roll Number: ";
    cin >> roll_number;
    cout << "Marks: ";
    cin >> marks;

    // Manually set each student object
    students[index] = STUDENT(name, roll_number, marks);
    NL;
  }

  // DISPLAY STUDENT RECORDS
  cout << "---------------------" << " STUDENT RECORDS " << "---------------------" << endl;
  for (int index = 0; index < N; index++) {
    cout << "Details for student " << index + 1 << ":" << endl;
    students[index].display_data();
    NL;
  }

  // CLEAN UP
  delete[] students;

  return 0;
}
