// LIBRARIES
#include <iostream>
#include <string>

// MACROS
#define NL cout << endl;

// USING NAMESPACES
using namespace std;

// HOTEL CLASS
class Hotel {
  private:
    int Rno;     
    string Name; 
    float Tariff;
    int NOD;     

    // CALC FUNCTION
    float CALC() {
      float total = NOD * Tariff;
      if (total > 10000) {
        total *= 1.05;
      }
      return total;
    }

  public:
    // CHECKIN FUNCTION
    void Checkin() {
      cout << "Enter Room Number: ";
      cin >> Rno;
      cout << "Enter Customer Name: ";
      cin.ignore();
      getline(cin, Name);
      cout << "Enter Tariff per day: ";
      cin >> Tariff;
      cout << "Enter Number of Days of Stay: ";
      cin >> NOD;
    }

    // CHECKOUT FUNCTION
    void Checkout() {
      cout << "\n--- Checkout Details ---" << endl;
      cout << "Room Number: " << Rno << endl;
      cout << "Customer Name: " << Name << endl;
      cout << "Tariff per Day: " << Tariff << endl;
      cout << "Number of Days of Stay: " << NOD << endl;
      cout << "Total Amount: " << CALC() << endl;
    }
};

// FUNCTION DECLARATION
void menu();

// MAIN FUNCTION
int main() {
  menu();

  Hotel hotel;
  hotel.Checkin(); 
  hotel.Checkout();

  return 0;
}

// FUNCTION DEFINITION
void menu() {
  cout << "---------------------" << " LAB 1, Question 8 " << "---------------------\n\n";
 cout << "Define a class named `Hotel` in C++ with the following specifications:\n"
      << "Private Members:\n"
      << "- Rno: Data member to store the room number.\n"
      << "- Name: Data member to store the customer's name.\n"
      << "- Tariff: Data member to store the per-day charges.\n"
      << "- NOD: Data member to store the number of days of stay.\n"
      << "- CALC(): Function to calculate and return the total amount as `NOD * Tariff`.\n"
      << "  If the value of `NOD * Tariff` exceeds 10,000, the total amount should be calculated as `1.05 * NOD * Tariff`.\n\n"
      << "Public Members:\n"
      << "- Checkin(): Function to input the values for `Rno`, `Name`, `Tariff`, and `NOD`.\n"
      << "- Checkout(): Function to display the values of `Rno`, `Name`, `Tariff`, `NOD`, and the total amount.\n"
      << "- The total amount should be calculated by calling the `CALC()` function.\n";
  NL
}