#include "city.hpp"
#include "utility.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void City::page1(int &pageNumber , int &theaterNumber){
    string text = R"(
1. Theater 1
2. Theater 2
3. Theater 3
4. Exit
)";
    cout << text;
    // command handler
    cout << "Please select by number (or exit): ";
    string line , number , rest; 
    getline(cin , line);
    stringstream stream(line);
    stream >> number; getline(stream , rest);
    if (isNumber(number) && rest == ""){
        int n = stoi(number);
        if(n == 1 || n == 2 || n == 3){pageNumber++; theaterNumber = n - 1;} 
        else if (n == 4) pageNumber = 0;
        else cout << "Invalid number entered!!!!";
    }
    else {
        cout << "Invalid command entered!!!!";
    }
}

void City::page2(int &pageNumber , int &theaterNumber , int &movieNumber){
    cout << "Theater number : " << theaterNumber + 1;
    string text = R"(
1. Movie 1
2. Movie 2
3. Back
4. Exit
)";
    cout << text;
    // command handler
    cout << "Please select by number (or exit or back): ";
    string line , number , rest; 
    getline(cin , line);
    stringstream stream(line);
    stream >> number; getline(stream , rest);
    if (isNumber(number) && rest == ""){
        int n = stoi(number);
        if(n == 1 || n == 2) {pageNumber++; movieNumber = n;}
        else if (n == 3) pageNumber--;
        else if (n == 4) pageNumber = 0;
        else cout << "Invalid number entered!!!!";
    }
    else {
        cout << "Invalid command entered!!!!";
    }
}

void City::page3(int &pageNumber , int &theaterNumber , int &movieNumber){
    cout << "Movie number : " << movieNumber << " Seats\n";
    theaters[theaterNumber].showMovie(movieNumber);
    string text = R"(
1. Reserve
2. Back
3. Exit
)";
    cout << text;
    // command handler
    cout << "Please select by number (or exit or back): ";
    string line , number , rest; 
    getline(cin , line);
    stringstream stream(line);
    stream >> number; getline(stream , rest);
    if (isNumber(number) && rest == ""){
        int n = stoi(number);
        if(n == 1) {pageNumber++;}
        else if (n == 2) pageNumber--;
        else if (n == 3) pageNumber = 0;
        else cout << "Invalid number entered!!!!";
    }
    else {
        cout << "Invalid command entered!!!!";
    }
}

void City::page4(int &pageNumber , int &theaterNumber , int &movieNumber){
    cout << "Movie number : " << movieNumber << " Seats\n";
    theaters[theaterNumber].showMovie(movieNumber);
    if(theaters[theaterNumber].isFull(movieNumber)){
        cout << "All seats already reserved!!!!\n";
        pageNumber -= 2;
    }
    else {
        cout << "Please enter your seat with patter ([row] [col]): ";
        string line , row , col , rest; 
        getline(cin , line);
        stringstream stream(line);
        stream >> row >> col; getline(stream , rest);
        if (isNumber(row) && isNumber(col) && rest == ""){
            int r = stoi(row) - 1;
            int c = stoi(col) - 1;
            bool isReserved = theaters[theaterNumber].reserve(movieNumber , r , c);
            if (isReserved) {cout << "Reserve done successfully\n"; pageNumber = 3;}
            else pageNumber--;
        }
        else {
            cout << "Invalid pattern entered . Reserve again\n";
        }
    }
}

void City::run(){
    cout << "Welcome to my cinema seat reservation app";
    int pageNumber {1} , theaterNumber , movieNumber;
    while(pageNumber != 0){
        if (pageNumber == 1) page1(pageNumber , theaterNumber);
        else if (pageNumber == 2) page2(pageNumber , theaterNumber , movieNumber);
        else if (pageNumber == 3) page3(pageNumber , theaterNumber , movieNumber);
        else if (pageNumber = 4) page4(pageNumber , theaterNumber , movieNumber);
    }
}
