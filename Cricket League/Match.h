#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include <iostream>
#include <graphics.h>
#include <fstream>
#include <string>
#include <time.h>
#include "Team.h"
#include "Cricket.h"
#include "Ptable.h"
using namespace std;
class Match:public Cricket{
public:
    int runs,wickets,matchNo;
    int balls;
    bool winbatfirst,losebatfirst,winbychase,losebychase,awin,bwin;
    Team a,b;
    Batsman abat[11],bbat[11];
    Bowler abowl[5],bbowl[5];
    PTable table[8];
    //Match();
    //void test_details();
    Match();
    void instructions();
    void introBat(Player);
    void introBowl(Player);
    void details();
    void toss();
    void bat(bool,int=0);
    void bowl(bool,int=0);
    void scoreboard(Team);
    void result();
    void write_back();
    void displayPoints();
    void purpleCap();
    void orangeCap();
};

#endif // MATCH_H_INCLUDED
