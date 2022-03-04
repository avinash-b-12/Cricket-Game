#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;
class Team{
public:
    int runs,wickets;
    int balls;
    string teamname;
    Player players[11];
    //Player temp[11];
    Team();
};


#endif // TEAM_H_INCLUDED
