#ifndef CITY_HPP
#define CITY_HPP

#include "theater.hpp"

class City {
    Theater theaters[3] = {Theater(1,3,2) , Theater(2,4,2) , Theater(3,3,2)};
    void page1(int &pageNumber , int &theaterNumber);
    void page2(int &pageNumber , int &theaterNumber, int &movieNumber);
    void page3(int &pageNumber , int &theaterNumber, int &movieNumber);
    void page4(int &pageNumber , int &theaterNumber, int &movieNumber);
public:
    void run();
};

#endif