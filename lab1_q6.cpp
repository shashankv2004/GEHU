#include <iostream>

#define NL cout << endl;

using namespace std;

// NUMBER CLASS
class NUMBER {
  private:
    int number;
  
  public:
    // CONSTRUCTOR
    NUMBER(int number) {
      this->number = number;
    }

    // SQUARE
    int square() {
      return number * number;
    }

    // PRIME
    bool prime() {
      if (number <= 1) return false;
      for (int index = 2; index <= number / 2; index++) {
        if (number % index == 0) {
          return false;
        }
      }
      return true;
    }

    // EVEN OR ODD
    bool even_odd() {
      return (number % 2 == 0);
    }

    // CUBE
    long int cube() {
      return number * number * number;
    }

    // FACTORIAL
    int factorial(int num) {
      return (num <= 1) ? (1) : (num * factorial(num - 1));
    }

    // FACTORIAL WRAPPER
    int factorial() {
      return factorial(number);
    }

    // NUMBER OF DIGITS
    int number_of_digits() {
      int number_copy = number;
      int count = 0;

      while (number_copy > 0) {
        number_copy /= 10;
        count++;
      }

      return count;
    }

    // SUM OF DIGITS
    int sum_of_digits() {
      int number_copy = number;
      int sum = 0;

      while (number_copy > 0) {
        sum += number_copy % 10;
        number_copy /= 10;
      }

      return sum;
    }

    // REVERSE NUMBER
    int reverseNumber() {
      int reversed_number = 0;
      int number_copy = number;
      
      while (number_copy > 0) {
          int digit = number_copy % 10;  
          reversed_number = reversed_number * 10 + digit;  
          number_copy /= 10;  
      }
      return reversed_number;
    }

    // DISPLAY MENU
    void menu() {
      cout << "Actions to perform on the number : \n"
           << "1. Square the number\n"
           << "2. Prime determination\n"
           << "3. Even or Odd determination\n"
           << "4. Cube the number\n"
           << "5. Factorial of the number\n"
           << "6. Digits in number\n"
           << "7. Sum of the digits\n"
           << "8. Reverse the number\n"
           << "0. TO QUIT\n"
           << endl;
      
      int choice;
      do {
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
          case 1:
            cout << number << " squared is -> " << square() << endl;
            break;
          case 2:
            if (prime()) {
              cout << number << " IS a prime number" << endl;
            } else {
              cout << number << " IS NOT a prime number" << endl;
            }
            break;
          case 3:
            if (even_odd()) {
              cout << number << " is EVEN" << endl;
            } else {
              cout << number << " is ODD" << endl;
            }
            break;
          case 4:
            cout << number << " cubed is -> " << cube() << endl;
            break;
          case 5:
            cout << number << "'s factorial is -> " << factorial() << endl;
            break;
          case 6:
            cout << number << " has " << number_of_digits() << " digits" << endl;
            break;
          case 7:
            cout << "Sum of all digits in " << number << " is -> " << sum_of_digits() << endl;
            break;
          case 8:
            cout << number << " reversed is -> " << reverseNumber() << endl;
            break;
          case 0:
            cout << "Exiting..." << endl;
            break;
          default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        NL;
      } while (choice != 0);
    }
};

// MENU FUNCTION
void menu() {
  cout << "---------------------" << " LAB 1, Question 6 " << "---------------------\n\n";

  cout << "Implement a C++ program to demonstrate the concept of data abstraction using the concept of Class and Objects.\n" << endl;

  cout << "---------------------------------------------------------------" << endl;
  NL;
}

// MAIN FUNCTION
int main() {
  menu();

  int number;
  cout << "Enter the number: ";
  cin >> number;

  NUMBER number_class(number);
  number_class.menu();

  return 0;
}
