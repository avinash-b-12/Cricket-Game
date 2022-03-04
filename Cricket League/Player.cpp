#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

Player::Player(){
        name="";
        hand="RIGHT";
        position="BAT";
        captain=false;
        runs=0;
        wickets=0;
        bestScore=0;
        bestFigures="";
        bestFigRuns=0;
        bestFigWickets=0;
}
