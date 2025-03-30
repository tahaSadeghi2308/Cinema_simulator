#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cstdlib>
#include <cctype>
#include <string>

void clearScreen(){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
        system("clear");
    #endif
}

bool isNumber(std::string sequence){
    for(char ch : sequence){
        if (!isdigit(ch)){
            return false;
        }
    }
    return true;
}

#endif 