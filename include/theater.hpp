#ifndef THEATER_HPP
#define THEATER_HPP

class Theater {
    short _row , _col , _tn; // tn => Theater Number
    char _movie1[4][2];
    char _movie2[4][2];
    void save(int movieNumber , int row , int col);
public:
    Theater(short tn , short row , short col);
    void showMovie(short movieNumber);
    bool isFull(short movieNumber);
    bool reserve(short movieNumber , short row , short col);
};

#endif