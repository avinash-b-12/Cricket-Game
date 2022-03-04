#ifndef BATSMAN_H_INCLUDED
#define BATSMAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
class Batsman{
public:
    string name;
    bool captain;
    int runs;
    int balls;
    bool didbat,status,introduced;
    Batsman();
};


#endif // BATSMAN_H_INCLUDED
