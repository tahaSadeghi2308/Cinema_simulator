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
// void Theater::showMovie2(){}