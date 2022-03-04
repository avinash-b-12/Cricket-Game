#ifndef PTABLE_H_INCLUDED
#define PTABLE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class PTable{
public:
    string teamname;
    int matches,won,lost,draw,points;
    PTable();
};
#endif // PTABLE_H_INCLUDED
