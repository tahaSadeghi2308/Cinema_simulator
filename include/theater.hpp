#ifndef THEATER_HPP
#define THEATER_HPP

class Theater {
    short _row , _col , _tn; // tn => Theater Number
    char _movie1[4][2];
    char _movie2[4][2];
public:
    Theater(short tn , short row , short col);
    void showMovie(short movieNumber);
    // void showMovie2();
};

#endif