#ifndef CITY_HPP
#define CITY_HPP

#include "theater.hpp"

class City {
    Theater theaters[3] = {Theater() , Theater() , Theater()};
public:
    void run();
};

#endif 