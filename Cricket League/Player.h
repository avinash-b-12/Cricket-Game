#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
class Player{
public:
    string name;
    string hand;
    string position;
    bool captain;
    int runs;
    int wickets;
    int bestScore;
    string bestFigures;
    int bestFigRuns,bestFigWickets;
    Player();
};



#endif // PLAYER_H_INCLUDED
