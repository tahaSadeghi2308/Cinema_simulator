#include "city.hpp"
#include "utility.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void City::run(){
    clearScreen();
    cout << R"(Welcome to the Cinema!)";
    bool layer1Menu {false};
    while (!layer1Menu){
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
                bool layer2Menu {false};
                cout << "This is Theater 1\n";
                while (!layer2Menu){
                    clearScreen();
                    cout << "Select a movie\nYou can exit program or back to previous menu";
                    cout << R"(
1. Movie 1
2. Movie 2
3. Back
4. Exit
)";
                    cout << "Please select a number (or exit or back): ";
                    getline(cin , command);
                    stream.str(command);
                    stream >> number; getline(stream , rest);
                    cout << number << rest;
                    if (isNumber(number) && rest == ""){
                        short n = stoi(number);
                        if (n == 1){
                            // theaters[n - 1].showMovie1();
                        }
                        else if (n == 2){
                            // theaters[n - 1].showMovie2();
                        }
                        else if (n == 3){
                            layer2Menu = true;
                            cout << "3";
                        }   
                        else if (n == 4){
                            cout << "4";
                            layer2Menu = true;
                            layer1Menu = true;
                        }
                        else {
                            cout << "Invalid number entered";
                        }
                    }
                    else {
                        clearScreen();
                        cout << "Invalid Command entered";
                    }
                }
            }   
            else if (num == 2){
                bool layer2Menu {false};
                while (!layer2Menu){
                    clearScreen();
                    cout << "This is Theater 2\n";
                    cout << "Select a movie\nYou can exit program or back to previous menu";
                    cout << R"(
1. Movie 1
2. Movie 2
3. Back
4. Exit)";
                    cout << "Please select a number (or exit or back): ";
                    getline(cin , command);
                    stream.str(command);
                    stream >> number; getline(stream , rest);
                    if (isNumber(number) && rest == ""){

                    }
                    else {

                    }
                }
            }
            else if (num == 3){
                bool layer2Menu {false};
                while (!layer2Menu){
                    clearScreen();
                    cout << "This is Theater 3\n";
                    cout << "Select a movie\nYou can exit program or back to previous menu";
                    cout << R"(
1. Movie 1
2. Movie 2
3. Back
4. Exit)";
                    cout << "Please select a number (or exit or back): ";
                    getline(cin , command);
                    stream.str(command);
                    stream >> number; getline(stream , rest);
                    if (isNumber(number) && rest == ""){

                    }
                    else {

                    }
                }
            }
            else if (num == 4){
                clearScreen();
                cout << "Have a good day bro";
                layer1Menu = true;
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
