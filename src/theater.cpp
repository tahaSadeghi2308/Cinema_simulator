#include "theater.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// well doneeeeeeee 
Theater::Theater(short tn , short row , short col) : _row(row) , _col(col) , _tn(tn){
    // initialize all with -
    for(short i {}; i < 4; i++)
        for (short j {}; j < 2; j++){
            _movie1[i][j] = '-';
            _movie2[i][j] = '-';
        }

    // fill right cordinates
    for(short i {}; i < _row; i++)
        for (short j {}; j < _col; j++){
            _movie2[i][j] = ' ';
            _movie1[i][j] = ' ';
        }

    // read reserved seats form file
    string fileAddr = "../data/theater" + to_string(tn) + ".dat";
    ifstream file;
    file.open(fileAddr);
    if(file.is_open()){
        string line;
        while(getline(file , line)){
            stringstream stream(line);
            string t , m , r , c;
            stream >> t >> m >> r >> c;
            if (tn == stoi(t)){
                if (m == "1"){
                    _movie1[stoi(r)][stoi(c)] = 'X';
                }
                else {
                    _movie2[stoi(r)][stoi(c)] = 'X';
                }
            }
        }
        file.close();
    }
    else {
        cout << "fuuuuucccckkk";
    }
}

// welll doooneeeee
void Theater::showMovie(short movieNumber){
    if (movieNumber == 1){
        for(short i {}; i < _row; i++){
            for(short j {}; j < _col; j++){
                cout << '[' << _movie1[i][j] << "] ";
            }
            cout << '\n';
        }
    }
    else {
        for(short i {}; i < _row; i++){
            for(short j {}; j < _col; j++){
                cout << '[' << _movie2[i][j] << "] ";
            }
            cout << '\n';
        }
    }
}

bool Theater::isFull(short movieNumber){
    int count = 0;
    if (movieNumber == 1){
        for(short i {}; i < _row; i++)
            for(short j {}; j < _col; j++)
                if (_movie1[i][j] == 'X') count++;
    }
    else {
        for(short i {}; i < _row; i++)
            for(short j {}; j < _col; j++)
                if (_movie1[i][j] == 'X') count++;
    }
    return count == _row * _col;
}

bool Theater::reserve(short movieNumber , short row , short col){
    bool status {false};
    if (row < _row && col < _col){
        if (movieNumber == 1){
            if (_movie1[row][col] == ' ') {_movie1[row][col] = 'X'; status = true; save(movieNumber , row , col);}
            else cout << "Its fulll\n";
        }
        else {
            if (_movie2[row][col] == ' ') {_movie2[row][col] = 'X'; status = true; save(movieNumber , row , col);}
            else cout << "Its fulll\n";
        }   
    }
    else {
        cout << "Is there any seat like this ??? \n";
    }
    return status;
}

void Theater::save(int movieNumber , int row , int col) {
    string fileAddr = "../data/theater" + to_string(_tn) + ".dat";
    ofstream file;
    file.open(fileAddr , ios::app);
    if (file.is_open()){
        string text = to_string(_tn) + " " + to_string(movieNumber) + " " + to_string(row) + " " + to_string(col) + '\n';
        file << text;
        file.close();
    }
}