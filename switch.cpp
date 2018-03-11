#include <fstream>
#include <limits>
#include "controller.hpp"

using namespace std;
// enum lights{RED=1, BLUE, YELLOW, GREEN, PINK};

int main() {
  int option;
  int noOfLights, noOfColours;
  bool valid = false;

  try {  
    cout << "Do you want to run the program in default mode or custom mode?" << endl
      << "1: Default mode. 2: Custom mode." << endl;
    while(!valid){
      cin >> option;
      if(option == 1 || option == 2) {
          valid = true;
          break;
      } else {
          cin.clear();
          cout << "Please enter either Option 1 or Option 2.\n";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Please select your program option: ";
      }
    }
    valid = false;

    if(option == 1) {
      Controller controller(20);
      controller.defaultInit();
      controller.run();
    }

    if(option == 2) {
      cout << "How many lights would you like: ";
      while(!valid){
        cin >> noOfLights;
        if(cin.good()) {
          valid = true;
          break;
        } else {
          cin.clear();
          cout << "Please enter an integer value!\n";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "How many lights would you like: ";
        }
      }
      valid = false;
      cout << "How many colours would you like: ";
      while(!valid){
        cin >> noOfColours;
        if(cin.good()) {
          valid = true;
          break;
        } else {
          cin.clear();
          cout << "Please enter an integer value!\n";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "How many colours would you like: ";
        }
      }

      Controller controller(noOfLights);
      controller.initialize(noOfColours);
      controller.run();
    } 
  } catch (exception& e) {
    cout << "Error encountered: " << e.what() << endl;
  }   
  return 0;   
}       

