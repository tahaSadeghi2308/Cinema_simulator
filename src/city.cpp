#include "city.hpp"
#include "utility.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void City::run(){
    clearScreen();
    cout << R"(Welcome to the Cinema!)";
    while (true){
        cout << R"(
1. Theater 1
2. Theater 2
3. Theater 3
4. Exit)";
        cout << "\nPlease select a theater by number (or exit): ";
        string command , rest , number; 
        getline(cin , command);
        stringstream stream(command);
        stream >> number; getline(stream , rest);
        // these if are right
        if (isNumber(number) && rest == ""){
            short num = stoi(number);
            if (num == 1){
                
            }   
            else if (num == 2){

            }
            else if (num == 3){
                
            }
            else if (num == 4){
                clearScreen();
                cout << "Have a good day bro";
                break;
            }
            else {
                clearScreen();
                cout << "Invalid menu option entered";
            }
        }
        else {
            clearScreen();
            cout << "Invalid command !!!";
        }
    }
}
