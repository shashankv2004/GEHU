/*
Write a C++ to calculate the electricity bill of a user according to the below
criteria:

INPUT:
  - the program prompts the user to enter their name and the number of units
    consumed.

CHARGES CALCULATION:
  - for the first 100 units, the charge is 60 paise per unit.
  - for the next 200 units, the charge is 80 paise per unit.
  - for units beyond 300, the charge is 90 paise per unit.
  - a minimum charge of Rs 50 is applied if the total charge is less than Rs 50.
  - if the charge exceeds Rs 300, a 15% surcharge is added.

OUTPUT:
  - the program displays the user's name, the number of units consumed, and
    the total charges in a currency format with two decimal points.
*/


// HEADER
#include <iostream>

// MACROS
#define NL cout << endl;

// NAMESPACES
using namespace std;

// CLASSES
class USER {
  private:
    string name; 
    int units_consumed;
    float charge;
    int rate;
  
  public:
    void InputUser(int user_index) {
      cout << "USER " << user_index << " : ";
      // cin >> name;
      getline(cin, name);
      // while (getchar() != '\n'); // handle extra newline

      cout<< "UNITS CONSUMED : ";
      cin >> u  << "return the updated string.\n\n"
      << "TYPICAL INPUT: \n"
      << "  - computer science is the future\n"
      << "TYPICAL OUTPUT: \n"
      << "  - compuer science is he fuure\n";s_consumed <= 0) {
        cout << "\nInvalid Units!\n" << endl;
        exit(1);  
      }
      if (units_consumed <= 100) {
        rate = 60;
      }
      else if (units_consumed <= 300) {
        rate = 80;
      }
      else if (units_consumed > 300) {
        rate = 90;
      }

      charge = rate * units_consumed;
      charge /= 100;

      if (charge < 50) {
        charge = 50;
      }
      else if (charge > 300) {
        charge += 0.15 * charge;
      }
    }

    void DisplayUser() {
      cout << "USER : ";
      cout << name << endl;
      cout << "CONSUMPTION : ";
      cout << units_consumed << endl;
      cout << "RATE APPLICABLE: ";
      cout << rate << " paise / unit"<< endl;
      cout << "TOTAL CHARGES : Rs. ";
      cout << charge;
    }
};

// FUNCTION DECALARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();

  int users_size;
  cout << "Number of USERS : ";
  cin >> users_size;
  cin.ignore();

  NL

  USER* users;
  users = new USER[users_size];

  cout <  << "return the updated string.\n\n"
      << "TYPICAL INPUT: \n"
      << "  - computer science is the future\n"
      << "TYPICAL OUTPUT: \n"
      << "  - compuer science is he fuure\n";

  for (int index = 0; index < users_size; index++) {
    users[index].InputUser(index+1);
    users[index].CalculateCharge();
    
    NL
  }

  cout << "-------------------------------------------------------" << endl;

  NL
  NL

  cout << "---------------------" << " USER CHARGES " << "---------------------" << endl;
  NL

  for (int index = 0; index < users_size; index++) {
    users[index].DisplayUser();
    
    NL
    NL
  }

  cout << "-------------------------------------------------------" << endl;

  return 0;
}

void menu() {
  cout << "---------------------" << " LAB 1, Question 1 " << "---------------------\n\n";

  cout << "Write a C++ program to calculate the electricity bill of a user according to the below\n"
       << "criteria:\n\n"
       << "INPUT:\n"
       << "  - The program prompts the user to enter their name and the number of units consumed.\n\n"
       << "CHARGES CALCULATION:\n"
       << "  - For the first 100 units, the charge is 60 paise per unit.\n"
       << "  - For the next 200 units, the charge is 80 paise per unit.\n"
       << "  - For units beyond 300, the charge is 90 paise per unit.\n"
       << "  - A minimum charge of Rs 50 is applied if the total charge is less than Rs 50.\n"
       << "  - If the charge exceeds Rs 300, a 15% surcharge is added.\n\n"
       << "OUTPUT:\n"
       << "  - The program displays the user's name, the number of units consumed, and\n"
       << "    the total charges in a currency format with two decimal points.\n";

  NL

  cout << "---------------------------------------------------------------" << endl;
  NL
}
