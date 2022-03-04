#ifndef CRICKET_H_INCLUDED
#define CRICKET_H_INCLUDED
#define _WIN32_WINNT 0x05232
#include <graphics.h>
#include <string>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>
#include "Batsman.h"
#include "Bowler.h"
#include "Team.h"
#include "Timeline.h"
using namespace std;
class Cricket{
public:
    //void ground();
    void ground(string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
    void stumped_ground(string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
    //void stumped_ground(string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
    //int bowled();
    int bowled(string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
    void normal_pos(string);
    void left_pos(string);
    void straight_pos(string);
    void right_pos(string);
    void ball_left(char,float,int,string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
    void ball_right(char,float,int,string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
    void ball_straight(char,float,int,string,string,Team,Batsman,Batsman,Bowler,Timeline,bool,int,bool);
};


#endif // CRICKET_H_INCLUDED
