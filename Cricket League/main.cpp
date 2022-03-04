#include <iostream>
#include "Team.h"
#include "Cricket.h"
#include "Match.h"
using namespace std;

int main()
{
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"");
    while(true){
        Match m;
        m.instructions();
        m.details();
        m.toss();
        m.result();
        delay(5000);
        cleardevice();
        m.write_back();
        m.displayPoints();
        delay(10000);
        cleardevice();
        m.orangeCap();
        delay(10000);
        cleardevice();
        m.purpleCap();
        delay(10000);
        cleardevice();
        N:
        outtextxy(100,100,"Do you want to play another match? Press Y for yes or N for no");
        char choice=getch();
        if(choice=='y' || choice=='Y' || choice=='n' || choice=='N'){
            outtextxy(400,200,"OK");
            if(choice=='n' || choice=='N'){
                break;
            }
            else
                continue;
        }
        else{
            outtextxy(400,100,"Wrong choice enter again");
            goto N;
        }
    }
    getch();
    closegraph();
    return 0;
}
