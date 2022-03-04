#define _WIN32_WINNT 0x05232
#include <graphics.h>
#include <string>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include "Cricket.h"
#include "Timeline.h"
using namespace std;
/*class Cricket{
public:
    void ground();
    void Maximize(){
        HWND consoleWindow= GetConsoleWindow();
        ShowWindow(consoleWindow,SW_MAXIMIZE);
    }
    void Restore(){
        HWND consoleWindow= GetConsoleWindow();
        ShowWindow(consoleWindow,SW_MINIMIZE);
    }
};*/
// to be added to parameter list opponent score - int opponent
                              // batfirst - bool batfirst
                              // Target is not yet displayed correctly. Display it correctly. Also draw border lines
void Cricket::ground(string batting_team,string bowling_team,Team t,Batsman batsman1,Batsman batsman2,Bowler bowler,Timeline time_line,bool onstrike,int opponent,bool batfirst){
    int x=getmaxx();
    int y=getmaxy();
    line(175,430,450,430);
    line(225,150,375,150);
    line(175,430,225,150);
    line(450,430,375,150);
    line(0,100,640,100);
    line(600,60,600,100);
    line(0,60,640,60);
    setfillstyle(SOLID_FILL,RED);
    floodfill(400,400,WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(100,120,WHITE);

    line(300,150,300,120);
    line(292,150,292,120);
    line(308,150,308,120);
    line(292,120,308,120);


    line(200,0,200,60);
    line(0,30,200,30);
    line(218,0,218,60);
    outtextxy(205,0,"B");
    outtextxy(206,19,"A");
    outtextxy(206,40,"T");
    line(440,0,440,60);
    line(458,0,458,60);

    outtextxy(445,0,"B");
    outtextxy(445,15,"O");
    outtextxy(445,28,"w");
    outtextxy(445,42,"L");

    line(50,0,50,60);
    line(120,0,120,60);
    line(360,0,360,60);
    line(218,30,440,30);
    line(458,30,640,30);
    line(540,0,540,30);

    int ashade,bshade;
    int acolor,bcolor;
    if(!batting_team.compare("CSK")){
        ashade=YELLOW;
        acolor=BLACK;
    }
    else if(!batting_team.compare("MI")){
        ashade=BLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("SRH")){
        ashade=DARKGRAY;
        acolor=WHITE;
    }
    else if(!batting_team.compare("RCB")){
        ashade=LIGHTGREEN;
        acolor=BLACK;
    }
    else if (!batting_team.compare("RR")){
        ashade=LIGHTBLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KKR")){
        ashade=MAGENTA;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KXIP")){
        ashade=LIGHTMAGENTA;
        acolor=BLACK;
    }
    else if(!batting_team.compare("DC")){
        ashade=LIGHTRED;
        acolor=BLACK;
    }

    if(!bowling_team.compare("CSK")){
        bshade=YELLOW;
        bcolor=BLACK;
    }
    else if(!bowling_team.compare("MI")){
        bshade=BLUE;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("SRH")){
        bshade=DARKGRAY;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("RCB")){
        bshade=LIGHTGREEN;
        bcolor=BLACK;
    }
    else if(!bowling_team.compare("RR")){
        bshade=LIGHTBLUE;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("KKR")){
        bshade=MAGENTA;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("KXIP")){
        bshade=LIGHTMAGENTA;
        bcolor=BLACK;
    }
    else if(!bowling_team.compare("DC")){
        bshade=LIGHTRED;
        bcolor=BLACK;
    }
    setfillstyle(SOLID_FILL,ashade);
    floodfill(10,5,WHITE);
    floodfill(150,5,WHITE);
    floodfill(480,38,WHITE);
    setfillstyle(SOLID_FILL,bshade);
    floodfill(10,38,WHITE);
    floodfill(150,38,WHITE);
    floodfill(520,5,WHITE);
    floodfill(620,5,WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    if(!onstrike)
        floodfill(240,5,WHITE);
    else
        floodfill(240,38,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(110,5,WHITE);
    floodfill(110,38,WHITE);
    line(488,30,488,60);
    line(518,30,518,60);
    line(548,30,548,60);
    line(578,30,578,60);
    line(608,30,608,60);
    int len1=batting_team.length(),len2=bowling_team.length(),it;
    char st1[len1+1];
    char st2[len2+1];
    for(it=0;it<len1;it++){
        st1[it]=batting_team[it];
    }
    st1[len1]='\0';
    for(it=0;it<len2;it++){
        st2[it]=bowling_team[it];
    }
    st2[len2]='\0';
    int ov,ball;
    ov=t.balls/6;
    ball=t.balls%6;
    string ovstr=to_string(ov),ballstr=to_string(ball);
    int ov_len=ovstr.length(),ball_len=ballstr.length();
    char ov_ca[ov_len+1],ball_ca[ball_len+1];
    for(it=0;it<ov_len;it++){
        ov_ca[it]=ovstr[it];
    }
    ov_ca[ov_len]='\0';
    for(it=0;it<ball_len;it++){
        ball_ca[it]=ballstr[it];
    }
    ball_ca[ball_len]='\0';
    int bats1_name_len=batsman1.name.length(),bats2_name_len=batsman2.name.length(),bowl_name_len=bowler.name.length();
    char bats1[bats1_name_len+1],bats2[bats2_name_len+1],bowl[bowl_name_len+1];
    for(it=0;it<bats1_name_len;it++){
        bats1[it]=batsman1.name[it];
    }
    bats1[bats1_name_len]='\0';
    for(it=0;it<bats2_name_len;it++){
        bats2[it]=batsman2.name[it];
    }
    bats2[bats2_name_len]='\0';
    for(it=0;it<bowl_name_len;it++){
        bowl[it]=bowler.name[it];
    }
    bowl[bowl_name_len]='\0';
    string runstr=to_string(t.runs);
    int run_len=runstr.length();
    char run_ca[run_len+1];
    for(it=0;it<run_len;it++){
        run_ca[it]=runstr[it];
    }
    run_ca[run_len]='\0';
    string wicketstr=to_string(t.wickets);
    int wicket_len=wicketstr.length();
    char wicket_ca[wicket_len+1];
    for(it=0;it<wicket_len;it++){
        wicket_ca[it]=wicketstr[it];
    }
    wicket_ca[wicket_len]='\0';
    string bats1_run=to_string(batsman1.runs),bats1_ball=to_string(batsman1.balls),bats2_run=to_string(batsman2.runs),bats2_ball=to_string(batsman2.balls);
    int bats1_run_len=bats1_run.length(),bats1_ball_len=bats1_ball.length(),bats2_run_len=bats2_run.length(),bats2_ball_len=bats2_run.length();
    char bats1_run_ca[bats1_run_len+1],bats1_ball_ca[bats1_ball_len+1],bats2_run_ca[bats2_run_len+1],bats2_ball_ca[bats2_ball_len+1];
    for(it=0;it<bats1_run_len;it++){
        bats1_run_ca[it]=bats1_run[it];
    }
    bats1_run_ca[bats1_run_len]='\0';
    for(it=0;it<bats1_ball_len;it++){
        bats1_ball_ca[it]=bats1_ball[it];
    }
    bats1_ball_ca[bats1_ball_len]='\0';
    for(it=0;it<bats2_run_len;it++){
        bats2_run_ca[it]=bats2_run[it];
    }
    bats2_run_ca[bats2_run_len]='\0';
    for(it=0;it<bats2_ball_len;it++){
        bats2_ball_ca[it]=bats2_ball[it];
    }
    bats2_ball_ca[bats2_ball_len]='\0';
    int bowl_ball_count=bowler.balls%6,bowl_ov_count=bowler.balls/6;
    string bowl_run=to_string(bowler.runs),bowl_wicket=to_string(bowler.wickets),bowl_ov=to_string(bowl_ov_count),bowl_ball=to_string(bowl_ball_count);
    int bowl_run_len=bowl_run.length(),bowl_wicket_len=bowl_wicket.length(),bowl_ov_len=bowl_ov.length(),bowl_ball_len=bowl_ball.length();
    char bowl_run_ca[bowl_run_len+1],bowl_wicket_ca[bowl_wicket_len+1],bowl_ov_ca[bowl_ov_len+1],bowl_ball_ca[bowl_ball_len+1];
    for(it=0;it<bowl_run_len;it++){
        bowl_run_ca[it]=bowl_run[it];
    }
    bowl_run_ca[bowl_run_len]='\0';
    for(it=0;it<bowl_wicket_len;it++){
        bowl_wicket_ca[it]=bowl_wicket[it];
    }
    bowl_wicket_ca[bowl_wicket_len]='\0';
    for(it=0;it<bowl_ov_len;it++){
        bowl_ov_ca[it]=bowl_ov[it];
    }
    bowl_ov_ca[bowl_ov_len]='\0';
    for(it=0;it<bowl_ball_len;it++){
        bowl_ball_ca[it]=bowl_ball[it];
    }
    bowl_ball_ca[bowl_ball_len]='\0';
    float runrate=0;
    if(t.balls>0)
        runrate= (t.runs/(float)t.balls)*6;
    char runratestr[6];
    snprintf(runratestr,sizeof(runratestr),"%0.2f",(runrate));

    int projected=0;
    int remball,reqruns,target;
    float reqrate;
    if(batfirst && t.balls>0){
        projected=(int)(runrate*(float)20);
    }
    else{
        target=opponent+1;
        remball=120-t.balls;
        reqruns=opponent-t.runs+1;
        reqrate=(reqruns/(float)remball)*6;
    }
    char projected_ca[to_string(projected).length()+1],remball_ca[to_string(remball).length()+1],reqruns_ca[to_string(reqruns).length()+1],target_ca[to_string(target).length()+1],reqrate_ca[to_string(reqrate).length()+1];
    sprintf(projected_ca,"%d",projected);
    sprintf(remball_ca,"%d",remball);
    sprintf(reqruns_ca,"%d",reqruns);
    sprintf(target_ca,"%d",target);
    snprintf(reqrate_ca,sizeof(reqrate_ca),"%0.2f",reqrate);
    setcolor(acolor);
    setbkcolor(ashade);
    outtextxy(10,5,st1);
    setcolor(bcolor);
    setbkcolor(bshade);
    outtextxy(10,38,st2);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(67,5,"Score");
    outtextxy(67,38,"Overs");
    setcolor(acolor);
    setbkcolor(ashade);
    outtextxy(135,5,run_ca);
    outtextxy(163,5,"/");
    outtextxy(170,5,wicket_ca);
    setcolor(bcolor);
    setbkcolor(bshade);
    outtextxy(135,38,ov_ca);
    outtextxy(152,38,".");
    outtextxy(157,38,ball_ca);
    outtextxy(168,38,"(20)");

    //determine onstriker
    if(!onstrike){
        setcolor(WHITE);
        setbkcolor(GREEN);
        outtextxy(250,5,bats1);
        graphdefaults();
        outtextxy(250,38,bats2);
    }
    else{
        setcolor(WHITE);
        setbkcolor(GREEN);
        outtextxy(250,38,bats2);
        graphdefaults();
        outtextxy(250,5,bats1);
    }
    outtextxy(370,5,bats1_run_ca);
    outtextxy(400,5,"(");
    outtextxy(407,5,bats1_ball_ca);
    outtextxy(427,5,")");
    outtextxy(370,38,bats2_run_ca);
    outtextxy(400,38,"(");
    outtextxy(407,38,bats2_ball_ca);
    outtextxy(427,38,")");
    setcolor(bcolor);
    setbkcolor(bshade);
    outtextxy(465,5,bowl);
    outtextxy(550,5,bowl_run_ca);
    outtextxy(575,5,"/");
    outtextxy(580,5,bowl_wicket_ca);
    outtextxy(595,5,"(");
    outtextxy(600,5,bowl_ov_ca);
    outtextxy(609,5,".");
    outtextxy(613,5,bowl_ball_ca);
    outtextxy(624,5,")");
    setcolor(acolor);
    setbkcolor(ashade);
    int i,startpoint=470;
    for(i=0;i<time_line.limit;i++){
        char s[]={time_line.timeline[i],'\0'};
        outtextxy(startpoint,38,s);
        startpoint+=30;
    }
    graphdefaults();
    outtextxy(10,68,"Runrate : ");
    outtextxy(75,68,runratestr);
    if(batfirst){
        line(115,60,115,100);
        line(230,60,230,100);
        outtextxy(125,68,"Projected : ");
        outtextxy(197,68,projected_ca);
    }
    else{
        line(115,60,115,100);
        line(242,60,242,100);
        line(115,81,242,81);
        line(417,60,417,100);
        outtextxy(125,62,"Req. Rate : ");
        outtextxy(197,62,reqrate_ca);
        outtextxy(125,83,"Target : ");
        outtextxy(180,83,target_ca);
        outtextxy(250,68,"Need ");
        outtextxy(288,68,reqruns_ca);
        outtextxy(317,68,"from");
        outtextxy(351,68,remball_ca);
        outtextxy(379,68,"balls");
    }


    //real Stump lines
    line(310,430,310,360);
    line(295,430,295,360);
    line(325,430,325,360);
    line(295,360,325,360);


    line(195,415,199,395);
    line(428,415,422,395);
    line(240,165,360,165);
    line(239,170,241,160);
    line(361,170,359,160);
}

void Cricket::stumped_ground(string batting_team,string bowling_team,Team t,Batsman batsman1,Batsman batsman2,Bowler bowler,Timeline time_line,bool onstrike,int opponent,bool batfirst){
    int x=getmaxx();
    int y=getmaxy();
    line(175,430,450,430);
    line(225,150,375,150);
    line(175,430,225,150);
    line(450,430,375,150);
    line(0,100,640,100);
    line(600,60,600,100);
    line(0,60,640,60);
    setfillstyle(SOLID_FILL,RED);
    floodfill(400,400,WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(100,120,WHITE);

    line(300,150,300,120);
    line(292,150,292,120);
    line(308,150,308,120);
    line(292,120,308,120);


    line(200,0,200,60);
    line(0,30,200,30);
    line(218,0,218,60);
    outtextxy(205,0,"B");
    outtextxy(206,19,"A");
    outtextxy(206,40,"T");
    line(440,0,440,60);
    line(458,0,458,60);

    outtextxy(445,0,"B");
    outtextxy(445,15,"O");
    outtextxy(445,28,"w");
    outtextxy(445,42,"L");


    line(50,0,50,60);
    line(120,0,120,60);
    line(360,0,360,60);
    line(218,30,440,30);
    line(458,30,640,30);
    line(540,0,540,30);

    int ashade,bshade;
    int acolor,bcolor;
    if(!batting_team.compare("CSK")){
        ashade=YELLOW;
        acolor=BLACK;
    }
    else if(!batting_team.compare("MI")){
        ashade=BLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("SRH")){
        ashade=DARKGRAY;
        acolor=WHITE;
    }
    else if(!batting_team.compare("RCB")){
        ashade=LIGHTGREEN;
        acolor=BLACK;
    }
    else if (!batting_team.compare("RR")){
        ashade=LIGHTBLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KKR")){
        ashade=MAGENTA;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KXIP")){
        ashade=LIGHTMAGENTA;
        acolor=BLACK;
    }
    else if(!batting_team.compare("DC")){
        ashade=LIGHTRED;
        acolor=BLACK;
    }

    if(!bowling_team.compare("CSK")){
        bshade=YELLOW;
        bcolor=BLACK;
    }
    else if(!bowling_team.compare("MI")){
        bshade=BLUE;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("SRH")){
        bshade=DARKGRAY;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("RCB")){
        bshade=LIGHTGREEN;
        bcolor=BLACK;
    }
    else if(!bowling_team.compare("RR")){
        bshade=LIGHTBLUE;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("KKR")){
        bshade=MAGENTA;
        bcolor=WHITE;
    }
    else if(!bowling_team.compare("KXIP")){
        bshade=LIGHTMAGENTA;
        bcolor=BLACK;
    }
    else if(!bowling_team.compare("DC")){
        bshade=LIGHTRED;
        bcolor=BLACK;
    }
    setfillstyle(SOLID_FILL,ashade);
    floodfill(10,5,WHITE);
    floodfill(150,5,WHITE);
    floodfill(480,38,WHITE);
    setfillstyle(SOLID_FILL,bshade);
    floodfill(10,38,WHITE);
    floodfill(150,38,WHITE);
    floodfill(520,5,WHITE);
    floodfill(620,5,WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    if(!onstrike)
        floodfill(240,5,WHITE);
    else
        floodfill(240,38,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(110,5,WHITE);
    floodfill(110,38,WHITE);
    line(488,30,488,60);
    line(518,30,518,60);
    line(548,30,548,60);
    line(578,30,578,60);
    line(608,30,608,60);
    int len1=batting_team.length(),len2=bowling_team.length(),it;
    char st1[len1+1];
    char st2[len2+1];
    for(it=0;it<len1;it++){
        st1[it]=batting_team[it];
    }
    st1[len1]='\0';
    for(it=0;it<len2;it++){
        st2[it]=bowling_team[it];
    }
    st2[len2]='\0';
    int ov,ball;
    ov=t.balls/6;
    ball=t.balls%6;
    string ovstr=to_string(ov),ballstr=to_string(ball);
    int ov_len=ovstr.length(),ball_len=ballstr.length();
    char ov_ca[ov_len+1],ball_ca[ball_len+1];
    for(it=0;it<ov_len;it++){
        ov_ca[it]=ovstr[it];
    }
    ov_ca[ov_len]='\0';
    for(it=0;it<ball_len;it++){
        ball_ca[it]=ballstr[it];
    }
    ball_ca[ball_len]='\0';
    int bats1_name_len=batsman1.name.length(),bats2_name_len=batsman2.name.length(),bowl_name_len=bowler.name.length();
    char bats1[bats1_name_len+1],bats2[bats2_name_len+1],bowl[bowl_name_len+1];
    for(it=0;it<bats1_name_len;it++){
        bats1[it]=batsman1.name[it];
    }
    bats1[bats1_name_len]='\0';
    for(it=0;it<bats2_name_len;it++){
        bats2[it]=batsman2.name[it];
    }
    bats2[bats2_name_len]='\0';
    for(it=0;it<bowl_name_len;it++){
        bowl[it]=bowler.name[it];
    }
    bowl[bowl_name_len]='\0';
    string runstr=to_string(t.runs);
    int run_len=runstr.length();
    char run_ca[run_len+1];
    for(it=0;it<run_len;it++){
        run_ca[it]=runstr[it];
    }
    run_ca[run_len]='\0';
    string wicketstr=to_string(t.wickets);
    int wicket_len=wicketstr.length();
    char wicket_ca[wicket_len+1];
    for(it=0;it<wicket_len;it++){
        wicket_ca[it]=wicketstr[it];
    }
    wicket_ca[wicket_len]='\0';
    string bats1_run=to_string(batsman1.runs),bats1_ball=to_string(batsman1.balls),bats2_run=to_string(batsman2.runs),bats2_ball=to_string(batsman2.balls);
    int bats1_run_len=bats1_run.length(),bats1_ball_len=bats1_ball.length(),bats2_run_len=bats2_run.length(),bats2_ball_len=bats2_run.length();
    char bats1_run_ca[bats1_run_len+1],bats1_ball_ca[bats1_ball_len+1],bats2_run_ca[bats2_run_len+1],bats2_ball_ca[bats2_ball_len+1];
    for(it=0;it<bats1_run_len;it++){
        bats1_run_ca[it]=bats1_run[it];
    }
    bats1_run_ca[bats1_run_len]='\0';
    for(it=0;it<bats1_ball_len;it++){
        bats1_ball_ca[it]=bats1_ball[it];
    }
    bats1_ball_ca[bats1_ball_len]='\0';
    for(it=0;it<bats2_run_len;it++){
        bats2_run_ca[it]=bats2_run[it];
    }
    bats2_run_ca[bats2_run_len]='\0';
    for(it=0;it<bats2_ball_len;it++){
        bats2_ball_ca[it]=bats2_ball[it];
    }
    bats2_ball_ca[bats2_ball_len]='\0';
    int bowl_ball_count=bowler.balls%6,bowl_ov_count=bowler.balls/6;
    string bowl_run=to_string(bowler.runs),bowl_wicket=to_string(bowler.wickets),bowl_ov=to_string(bowl_ov_count),bowl_ball=to_string(bowl_ball_count);
    int bowl_run_len=bowl_run.length(),bowl_wicket_len=bowl_wicket.length(),bowl_ov_len=bowl_ov.length(),bowl_ball_len=bowl_ball.length();
    char bowl_run_ca[bowl_run_len+1],bowl_wicket_ca[bowl_wicket_len+1],bowl_ov_ca[bowl_ov_len+1],bowl_ball_ca[bowl_ball_len+1];
    for(it=0;it<bowl_run_len;it++){
        bowl_run_ca[it]=bowl_run[it];
    }
    bowl_run_ca[bowl_run_len]='\0';
    for(it=0;it<bowl_wicket_len;it++){
        bowl_wicket_ca[it]=bowl_wicket[it];
    }
    bowl_wicket_ca[bowl_wicket_len]='\0';
    for(it=0;it<bowl_ov_len;it++){
        bowl_ov_ca[it]=bowl_ov[it];
    }
    bowl_ov_ca[bowl_ov_len]='\0';
    for(it=0;it<bowl_ball_len;it++){
        bowl_ball_ca[it]=bowl_ball[it];
    }
    bowl_ball_ca[bowl_ball_len]='\0';
    float runrate=0;
    if(t.balls>0)
        runrate= (t.runs/(float)t.balls)*6;
    char runratestr[6];
    snprintf(runratestr,sizeof(runratestr),"%0.2f",(runrate));

    int projected=0;
    int remball,reqruns,target;
    float reqrate;
    if(batfirst && t.balls>0){
        projected=(int)(runrate*(float)20);
    }
    else{
        target=opponent+1;
        remball=120-t.balls;
        reqruns=opponent-t.runs+1;
        reqrate=(reqruns/(float)remball)*6;
    }
    char projected_ca[to_string(projected).length()+1],remball_ca[to_string(remball).length()+1],reqruns_ca[to_string(reqruns).length()+1],target_ca[to_string(target).length()+1],reqrate_ca[to_string(reqrate).length()+1];
    sprintf(projected_ca,"%d",projected);
    sprintf(remball_ca,"%d",remball);
    sprintf(reqruns_ca,"%d",reqruns);
    sprintf(target_ca,"%d",target);
    snprintf(reqrate_ca,sizeof(reqrate_ca),"%0.2f",reqrate);
    setcolor(acolor);
    setbkcolor(ashade);
    outtextxy(10,5,st1);
    setcolor(bcolor);
    setbkcolor(bshade);
    outtextxy(10,38,st2);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(67,5,"Score");
    outtextxy(67,38,"Overs");
    setcolor(acolor);
    setbkcolor(ashade);
    outtextxy(135,5,run_ca);
    outtextxy(163,5,"/");
    outtextxy(170,5,wicket_ca);
    setcolor(bcolor);
    setbkcolor(bshade);
    outtextxy(135,38,ov_ca);
    outtextxy(152,38,".");
    outtextxy(157,38,ball_ca);
    outtextxy(168,38,"(20)");

    //determine onstriker
    if(!onstrike){
        setcolor(WHITE);
        setbkcolor(GREEN);
        outtextxy(250,5,bats1);
        graphdefaults();
        outtextxy(250,38,bats2);
    }
    else{
        setcolor(WHITE);
        setbkcolor(GREEN);
        outtextxy(250,38,bats2);
        graphdefaults();
        outtextxy(250,5,bats1);
    }
    outtextxy(370,5,bats1_run_ca);
    outtextxy(400,5,"(");
    outtextxy(407,5,bats1_ball_ca);
    outtextxy(427,5,")");
    outtextxy(370,38,bats2_run_ca);
    outtextxy(400,38,"(");
    outtextxy(407,38,bats2_ball_ca);
    outtextxy(427,38,")");
    setcolor(bcolor);
    setbkcolor(bshade);
    outtextxy(465,5,bowl);
    outtextxy(550,5,bowl_run_ca);
    outtextxy(575,5,"/");
    outtextxy(580,5,bowl_wicket_ca);
    outtextxy(595,5,"(");
    outtextxy(600,5,bowl_ov_ca);
    outtextxy(609,5,".");
    outtextxy(613,5,bowl_ball_ca);
    outtextxy(624,5,")");
    setcolor(acolor);
    setbkcolor(ashade);
    int i,startpoint=470;
    for(i=0;i<time_line.limit;i++){
        char s[]={time_line.timeline[i],'\0'};
        outtextxy(startpoint,38,s);
        startpoint+=30;
    }
    graphdefaults();
    outtextxy(10,68,"Runrate : ");
    outtextxy(75,68,runratestr);
    if(batfirst){
        line(115,60,115,100);
        line(230,60,230,100);
        outtextxy(125,68,"Projected : ");
        outtextxy(197,68,projected_ca);
    }
    else{
        line(115,60,115,100);
        line(242,60,242,100);
        line(115,81,242,81);
        line(417,60,417,100);
        outtextxy(125,62,"Req. Rate : ");
        outtextxy(197,62,reqrate_ca);
        outtextxy(125,83,"Target : ");
        outtextxy(180,83,target_ca);
        outtextxy(250,68,"Need ");
        outtextxy(288,68,reqruns_ca);
        outtextxy(317,68,"from");
        outtextxy(351,68,remball_ca);
        outtextxy(379,68,"balls");
    }

    /*
    setcolor(acolor);
    line(255,415,285,415);
    line(285,415,300,390);
    line(270,415,285,390);
    line(255,415,270,390);

    arc(265,387,325,20,7);
    arc(295,387,325,20,7);

    line(270,385,260,365);
    line(300,385,290,365);
    arc(290,360,155,190,30);
    arc(220,345,358,15,80);

    arc(291,246,262,275,80);
    line(262,348,282,322);
    line(282,323,282,313);
    arc(279,320,343,32,20);
    arc(297,336,70,126,27);
    line(292,325,292,315);
    line(292,315,296,315);
    line(296,312,305,312);
    line(305,312,305,310);
    line(290,365,300,345);
    line(260,365,291,365);
    setfillstyle(SOLID_FILL,ashade);
    floodfill(270,410,acolor);
    floodfill(270,400,acolor);
    floodfill(298,387,acolor);
    floodfill(265,360,acolor);
    floodfill(290,315,acolor);
    floodfill(303,311,acolor);

    // Yet to design Hand And Bat for straight Poistion
    line(285,335,298,340);
    line(285,340,302,345);
    line(302,345,320,336);
    line(298,340,320,333);
    line(298,328,320,332);
    line(298,334,320,336);
    line(320,332,320,336);
    line(320,333,320,332);
    line(295,338,295,343); // Shirt Hand Separator
    setfillstyle(SOLID_FILL,RGB(0xED,0xAC,0x69));
    floodfill(296,340,acolor);
    floodfill(300,340,acolor);
    floodfill(299,329,acolor);

    //  Bat Design
    setcolor(BLACK);
    line(321,333,340,323);
    line(321,336,341,326);
    line(321,333,321,336);
    line(340,323,341,326);
    line(340,323,340,318);
    line(341,326,346,330);
    line(340,318,375,302);
    line(346,330,382,314);
    arc(378.5,309,300,120,8);
    setfillstyle(SOLID_FILL,RGB(0x55,0xff,0x55));
    floodfill(322,334,BLACK);
    setfillstyle(SOLID_FILL,RGB(0x8D,0x55,0x24));
    floodfill(377,309,BLACK);
    graphdefaults();
    // Bats Design End

    //Stumps
    line(310,430,310,360);
    line(295,430,295,360);
    line(325,430,325,360);
    line(295,360,325,360);
    // Stumps Design End
    */
    //line(198,405,425,405);

    //real Stump lines
    //line(310,430,310,360);
    //line(295,430,295,360);
    //line(325,430,325,360);
    //line(295,360,325,360);
    line(310,430,295,350);
    line(295,430,285,350);
    line(325,430,340,350);

    line(265,420,280,410);
    line(335,410,350,420);

    line(195,415,199,395);
    line(428,415,422,395);
    line(240,165,360,165);
    line(239,170,241,160);
    line(361,170,359,160);
}
void Cricket::normal_pos(string batting_team){
    int acolor,ashade;
    if(!batting_team.compare("CSK")){
        ashade=YELLOW;
        acolor=BLACK;
    }
    else if(!batting_team.compare("MI")){
        ashade=BLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("SRH")){
        ashade=DARKGRAY;
        acolor=WHITE;
    }
    else if(!batting_team.compare("RCB")){
        ashade=LIGHTGREEN;
        acolor=BLACK;
    }
    else if (!batting_team.compare("RR")){
        ashade=LIGHTBLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KKR")){
        ashade=MAGENTA;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KXIP")){
        ashade=LIGHTMAGENTA;
        acolor=BLACK;
    }
    else if(!batting_team.compare("DC")){
        ashade=LIGHTRED;
        acolor=BLACK;
    }
    setcolor(acolor);
    line(255,415,285,415);
    line(285,415,300,390);
    line(270,415,285,390);
    line(255,415,270,390);

    arc(265,387,325,20,7);
    arc(295,387,325,20,7);

    line(270,385,260,365);
    line(300,385,290,365);
    arc(290,360,155,190,30);
    arc(220,345,358,15,80);

    arc(291,246,262,275,80);
    line(262,348,282,322);
    line(282,323,282,313);
    arc(279,320,343,32,20);
    arc(297,336,70,126,27);
    line(292,325,292,315);
    line(292,315,296,315);
    line(296,312,305,312);
    line(305,312,305,310);
    line(290,365,300,345);
    line(260,365,291,365);
    setfillstyle(SOLID_FILL,ashade);
    floodfill(270,410,acolor);
    floodfill(270,400,acolor);
    floodfill(298,387,acolor);
    floodfill(265,360,acolor);
    floodfill(290,315,acolor);
    floodfill(303,311,acolor);

    line(283,334,285,352);
    line(290,334,291,348);
    line(286,352,298,365);
    line(291,348,300,365);
    line(298,365,300,365);
    line(284,344,290,344);
    setfillstyle(SOLID_FILL,RGB(0xED,0xAC,0x69));
    floodfill(287,346,acolor);
    floodfill(298,364,acolor);
    setcolor(BLACK);
    line(296,365,301,365);
    line(303,380,308,379);
    line(296,365,303,380);
    line(301,365,308,379);
    line(303,380,301,382);
    line(308,379,311,378);
    line(301,382,312,415);
    line(311,378,324,415);
    arc(318,415,180,360,6);
    setfillstyle(SOLID_FILL,RGB(0x55,0xff,0x55));
    floodfill(297,366,BLACK);
    setfillstyle(SOLID_FILL,RGB(0x8D,0x55,0x24));
    floodfill(318,415,BLACK);
    setcolor(abs(acolor-WHITE));
    line(292,317,297,317);
    line(292,320,297,320);
    line(292,322,297,322);
    graphdefaults();
    line(310,430,310,360);
    line(295,430,295,360);
    line(325,430,325,360);
    line(295,360,325,360);

    line(198,405,425,405);
}
void Cricket::right_pos(string batting_team){
    int acolor,ashade;
    if(!batting_team.compare("CSK")){
        ashade=YELLOW;
        acolor=BLACK;
    }
    else if(!batting_team.compare("MI")){
        ashade=BLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("SRH")){
        ashade=DARKGRAY;
        acolor=WHITE;
    }
    else if(!batting_team.compare("RCB")){
        ashade=LIGHTGREEN;
        acolor=BLACK;
    }
    else if (!batting_team.compare("RR")){
        ashade=LIGHTBLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KKR")){
        ashade=MAGENTA;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KXIP")){
        ashade=LIGHTMAGENTA;
        acolor=BLACK;
    }
    else if(!batting_team.compare("DC")){
        ashade=LIGHTRED;
        acolor=BLACK;
    }
    setcolor(acolor);
    line(255,415,285,415);
    line(285,415,300,390);
    line(270,415,285,390);
    line(255,415,270,390);

    arc(265,387,325,20,7);
    arc(295,387,325,20,7);

    line(270,385,260,365);
    line(300,385,290,365);
    arc(290,360,155,190,30);
    arc(220,345,358,15,80);

    arc(291,246,262,275,80);
    //line(297,325,297,200);
    line(262,348,282,322);
    line(282,323,282,313);
    //line(297,324,297,315);
    arc(279,320,343,32,20);
    arc(297,336,70,126,27);
    line(292,325,292,315);
    line(292,315,296,315);
    line(296,312,305,312);
    line(305,312,305,310);
    // commented line(290,365,305,330);
    line(290,365,300,345);
    line(260,365,291,365);
    setfillstyle(SOLID_FILL,ashade);
    floodfill(270,410,acolor);
    floodfill(270,400,acolor);
    floodfill(298,387,acolor);
    floodfill(265,360,acolor);
    floodfill(290,315,acolor);
    floodfill(303,311,acolor);

    setcolor(abs(acolor-WHITE));
    line(292,317,297,317);
    line(292,320,297,320);
    line(292,322,297,322);
    //line(285,400,285,200);
    //line(285,337,350,337);
    setcolor(acolor);
    line(283,334,302,338);
    line(283,340,303,344);
    line(302,338,315,339);
    line(303,344,315,343);
    line(295,336,295,341);
    line(315,339,315,343);
    line(283,334,283,340);

    setcolor(BLACK);
    line(316,343,330,343);
    line(316,339,330,339);
    line(316,343,316,339);
    line(330,343,330,339);
    line(330,343,332,347);
    line(330,339,332,335);
    line(332,347,370,347);
    line(332,335,370,335);
    arc(367,341,290,60,8);
    setfillstyle(SOLID_FILL,RGB(0xED,0xAC,0x69));
    floodfill(302,340,acolor);
    floodfill(297,338,acolor);
    setfillstyle(SOLID_FILL,RGB(0x55,0xff,0x55));
    floodfill(320,341,BLACK);
    setfillstyle(SOLID_FILL,RGB(0x8D,0x55,0x24));
    floodfill(340,341,BLACK);
    graphdefaults();
    line(310,430,310,360);
    line(295,430,295,360);
    line(325,430,325,360);
    line(295,360,325,360);

    line(198,405,425,405);
}
void Cricket::left_pos(string batting_team){
    int acolor,ashade;
    if(!batting_team.compare("CSK")){
        ashade=YELLOW;
        acolor=BLACK;
    }
    else if(!batting_team.compare("MI")){
        ashade=BLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("SRH")){
        ashade=DARKGRAY;
        acolor=WHITE;
    }
    else if(!batting_team.compare("RCB")){
        ashade=LIGHTGREEN;
        acolor=BLACK;
    }
    else if (!batting_team.compare("RR")){
        ashade=LIGHTBLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KKR")){
        ashade=MAGENTA;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KXIP")){
        ashade=LIGHTMAGENTA;
        acolor=BLACK;
    }
    else if(!batting_team.compare("DC")){
        ashade=LIGHTRED;
        acolor=BLACK;
    }
    setcolor(acolor);
    line(255,415,285,415);
    line(285,415,300,390);
    line(270,415,285,390);
    line(255,415,270,390);

    arc(265,387,325,20,7);
    arc(295,387,325,20,7);

    line(270,385,260,365);
    line(300,385,290,365);
    arc(290,360,155,190,30);
    arc(220,345,358,15,80);

    arc(291,246,262,275,80);
    //line(297,325,297,200);
    line(262,348,282,322);
     //HEAD

/*
    line(282,323,282,313);   // Back of Head
    //line(297,324,297,315);
    arc(279,320,343,32,20);    // Front Face
    arc(297,336,70,126,27);     // Top Head
    line(292,325,292,315);
    line(292,315,296,315); // Helmet Lines
    line(296,312,305,312);   // Cap Attacher
    line(305,312,305,310);      // Cap attacher to Cap Gap Filler

*/
    // End of Head

    // New Head

    line(297,325,297,311);
    arc(300,318,144,200,20);
    arc(275,360,65,95,55);
    line(270,305,281,308);
    line(280,312,289,314);
    line(289,314,289,325);


    // commented line(290,365,305,330);
    line(290,365,300,345);
    line(260,365,291,365);
    setfillstyle(SOLID_FILL,ashade);
    floodfill(270,410,acolor);
    floodfill(270,400,acolor);
    floodfill(298,387,acolor);
    floodfill(265,360,acolor);
    floodfill(290,315,acolor); //   Helmet Filler
    floodfill(280,307,acolor); // Cap Extension Filler
    floodfill(279,306,acolor);
    setcolor(abs(acolor-WHITE));
    line(288,317,281,317);
    line(288,320,282,320);
    line(288,322,282,322);

        // New Hand and Bat
    setcolor(acolor);
    line(290,334,300,338);
    line(290,340,300,344);
    line(295,337,295,342); // Shirt Hand Separator
    line(275,330,255,325);
    line(274,335,255,328);
    line(255,325,255,328);

    line(266,340,258,328);
    line(263,345,256,328);
    line(258,328,256,328);
    setfillstyle(SOLID_FILL,RGB(0xED,0xAC,0x69));
    floodfill(274,331,acolor);
    floodfill(265,341,acolor);
    floodfill(296,338,acolor);

    // Now I have to design the bat
    setcolor(BLACK);
    line(254,325,234,322);
    line(254,328,233,325);
    line(234,322,233,325);
    line(254,325,254,328);
    line(234,322,232,316);
    line(233,325,226,330);
    line(232,316,190,311);
    line(226,330,190,327);
    arc(190,319,90,270,8);
    setfillstyle(SOLID_FILL,RGB(0x55,0xff,0x55));
    floodfill(253,326,BLACK);
    setfillstyle(SOLID_FILL,RGB(0x8D,0x55,0x24));
    floodfill(190,319,BLACK);
    graphdefaults();
    // Bats Design End

    //Stumps
    line(310,430,310,360);
    line(295,430,295,360);
    line(325,430,325,360);
    line(295,360,325,360);

    line(198,405,425,405);
}
void Cricket::straight_pos(string batting_team){
    int acolor,ashade;
    if(!batting_team.compare("CSK")){
        ashade=YELLOW;
        acolor=BLACK;
    }
    else if(!batting_team.compare("MI")){
        ashade=BLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("SRH")){
        ashade=DARKGRAY;
        acolor=WHITE;
    }
    else if(!batting_team.compare("RCB")){
        ashade=LIGHTGREEN;
        acolor=BLACK;
    }
    else if (!batting_team.compare("RR")){
        ashade=LIGHTBLUE;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KKR")){
        ashade=MAGENTA;
        acolor=WHITE;
    }
    else if(!batting_team.compare("KXIP")){
        ashade=LIGHTMAGENTA;
        acolor=BLACK;
    }
    else if(!batting_team.compare("DC")){
        ashade=LIGHTRED;
        acolor=BLACK;
    }
    setcolor(acolor);
    line(255,415,285,415);
    line(285,415,300,390);
    line(270,415,285,390);
    line(255,415,270,390);

    arc(265,387,325,20,7);
    arc(295,387,325,20,7);

    line(270,385,260,365);
    line(300,385,290,365);
    arc(290,360,155,190,30);
    arc(220,345,358,15,80);

    arc(291,246,262,275,80);
    line(262,348,282,322);
    line(282,323,282,313);
    arc(279,320,343,32,20);
    arc(297,336,70,126,27);
    line(292,325,292,315);
    line(292,315,296,315);
    line(296,312,305,312);
    line(305,312,305,310);
    line(290,365,300,345);
    line(260,365,291,365);
    setfillstyle(SOLID_FILL,ashade);
    floodfill(270,410,acolor);
    floodfill(270,400,acolor);
    floodfill(298,387,acolor);
    floodfill(265,360,acolor);
    floodfill(290,315,acolor);
    floodfill(303,311,acolor);

    // Yet to design Hand And Bat for straight Poistion
    line(285,335,298,340);
    line(285,340,302,345);
    line(302,345,320,336);
    line(298,340,320,333);
    line(298,328,320,332);
    line(298,334,320,336);
    line(320,332,320,336);
    line(320,333,320,332);
    line(295,338,295,343); // Shirt Hand Separator
    setfillstyle(SOLID_FILL,RGB(0xED,0xAC,0x69));
    floodfill(296,340,acolor);
    floodfill(300,340,acolor);
    floodfill(299,329,acolor);

    //  Bat Design
    setcolor(BLACK);
    line(321,333,340,323);
    line(321,336,341,326);
    line(321,333,321,336);
    line(340,323,341,326);
    line(340,323,340,318);
    line(341,326,346,330);
    line(340,318,375,302);
    line(346,330,382,314);
    arc(378.5,309,300,120,8);
    setfillstyle(SOLID_FILL,RGB(0x55,0xff,0x55));
    floodfill(322,334,BLACK);
    setfillstyle(SOLID_FILL,RGB(0x8D,0x55,0x24));
    floodfill(377,309,BLACK);
    graphdefaults();
    // Bats Design End

    //Stumps
    line(310,430,310,360);
    line(295,430,295,360);
    line(325,430,325,360);
    line(295,360,325,360);

    line(198,405,425,405);
}
void Cricket::ball_left(char dir,float xpoint,int ypoint,string batting_team,string bowling_team,Team t,Batsman batsman1,Batsman batsman2,Bowler bowler,Timeline time_line,bool onstrike,int opponent,bool batfirst){
    int i;
    float x,m;
    m=(ypoint-250)/(float)(xpoint);
    for(i=ypoint;i>250;i--){
        cleardevice();
        ground(batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
            if(dir=='o'){
                normal_pos(batting_team);
            }
            else if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        delay(2);
        x=xpoint-(ypoint-i)/m;
        circle(x,i,7);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(x,i-2,WHITE);
        floodfill(x,i+2,WHITE);
        floodfill(x-1,i+2,WHITE);
        floodfill(x+1,i-2,WHITE);
        //floodfill(x,i,WHITE);
    }
}
void Cricket::ball_straight(char dir,float xpoint,int ypoint,string batting_team,string bowling_team,Team t,Batsman batsman1,Batsman batsman2,Bowler bowler,Timeline time_line,bool onstrike,int opponent,bool batfirst){
    int i;
    float x,m;
    m=(ypoint-100)/(float)(xpoint-280);
    for(i=ypoint;i>100;i--){
        cleardevice();
        ground(batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
            if(dir=='o'){
                normal_pos(batting_team);
            }
            else if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        x=xpoint-(ypoint-i)/m;
        circle(x,i,7);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(x,i-2,WHITE);
        floodfill(x,i+2,WHITE);
        floodfill(x-1,i+2,WHITE);
        floodfill(x+1,i-2,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        //floodfill(x,i,WHITE);
        delay(2);
    }
}
void Cricket::ball_right(char dir,float xpoint,int ypoint,string batting_team,string bowling_team,Team t,Batsman batsman1,Batsman batsman2,Bowler bowler,Timeline time_line,bool onstrike,int opponent,bool batfirst){
    int i;
    float x,m;
    m=(ypoint-210)/(float)(xpoint-640);
    for(i=ypoint;i>210;i--){
        cleardevice();
        ground(batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
            if(dir=='o'){
                normal_pos(batting_team);
            }
            else if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        x=xpoint-(ypoint-i)/m;
        circle(x,i,7);
        setfillstyle(SOLID_FILL,WHITE);
        //floodfill(x,i,WHITE);
        floodfill(x,i-2,WHITE);
        floodfill(x,i+2,WHITE);
        floodfill(x-1,i+2,WHITE);
        floodfill(x+1,i-2,WHITE);
        delay(2);
    }
}
int Cricket::bowled(string batting_team,string bowling_team,Team t,Batsman batsman1,Batsman batsman2,Bowler bowler,Timeline time_line,bool onstrike,int opponent,bool batfirst){
    int run=0;
    int i;
    float xvalue,slope1,slope2;
    bool hitted=false,checkshot=false,interrupt=false,strike=false,done=false,reached=false;
    char dir='o';
    int xpitch,ypitch,endpoint,hit_y_point;
    //for(i=125;i<450;i++){
        srand(time(0));
        int random=rand()%3;
        switch(random){
        case 0:
            xpitch=250;
            break;
        case 1:
            xpitch=320;
            break;
        case 2:
            xpitch=370;
            break;
        }
        srand(time(0));
        random=rand()%2;
        switch(random){
        case 0:
            ypitch=300;
            break;
        case 1:
            ypitch=370;
            break;
        }
        if(ypitch==300){
            if(xpitch==250){
                random=rand()%2;
                switch(random){
                case 0:
                    endpoint=310;
                    break;
                case 1:
                    endpoint=410;
                    break;
                }
            }
            else if(xpitch==320){
                random=rand()%2;
                switch(random){
                case 0:
                    endpoint=310;
                    break;
                case 1:
                    endpoint=410;
                    break;
                }
            }
            else{
                random=rand()%2;
                switch(random){
                case 0:
                    endpoint=310;
                    break;
                case 1:
                    endpoint=410;
                    break;
                }
            }
        }
        else{
            if(xpitch==250){
                endpoint=310;
            }
            else if(xpitch==320){
                random=rand()%2;
                switch(random){
                case 0:
                    endpoint=310;
                    break;
                case 1:
                    endpoint=410;
                    break;
                }
            }
            else{
                random=rand()%2;
                switch(random){
                case 0:
                    endpoint=310;
                    break;
                case 1:
                    endpoint=410;
                    break;
                }
            }
        }
        slope1=(xpitch-330)/(float)(ypitch-125);
        slope2=(xpitch-endpoint)/(float)(ypitch-440);
        // Details of batsman and other stats yet to be displayed. // DONE

        // check once more for limit points . i.e., ball delivery , after pitch and final hit range.  // DONE
        //endpoint is still not determined. // DONE
        //ball is not yet designed properly, fix the ball graphics  // DONE
        // first for loop goes from 125 to ypitch. Second for loop goes from ypitch to endpoint . draw the line of shift accordingly. // DONE

        // define the functions for the ball after hit movement.  // DONE
        //make changes in Match so that the run or wicket is dispalyed correctly.  // DONE
        // Timeline area is not yet touched fix it properly.  // DONE
        // Determine Color codes and Fill in shades in the score Bar.  // DONE
        // Determine points to display wicket or 6 or anything in Match.cpp  // DONE
        // Calculate and display current Run-rate. And also the runs required or the projected Score // DONE
        // Design all the functions in such a way that the parameter list is appropriate
        // Pass arguments for ground and other functions in a proper way.
        // Design Functions for batsman position.  // DONE
        // Put Toss and return result.
        // Write back into files.
        // Design Main Function.
        // Check the Code.
    for(i=125;i<ypitch;i++){
        char direction[]={dir,'\0'};
        //outtextxy(10,300,direction);
        if(!reached){
            normal_pos(batting_team);
        }
        if(hitted && i>300){
            reached=true;
            if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        }
        xvalue=slope1*(float)(i-125)+330;
        if(kbhit() && !hitted){
            dir=getch();
            if(dir=='q' || dir=='Q'){
                dir='o';
                for(;;){
                    if(kbhit()){
                        char conti=getch();
                        if(conti=='q' || conti=='Q')
                            break;
                    }
                }
                dir='o';
            }
            if(dir=='a' || dir=='w' || dir=='d' || dir=='A' || dir=='W' || dir=='D'){
                hitted=true;
                hit_y_point=i;
            }
            else{
                dir='o';
            }
        }
        delay(0.5);
        cleardevice();

        ground(batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
        if(!reached){
            normal_pos(batting_team);
        }
        if(hitted && i>300){
            reached=true;
            if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        }
        circle(xvalue,i,7);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(xvalue,i-2,WHITE);
        floodfill(xvalue,i+2,WHITE);
        floodfill(xvalue-1,i+2,WHITE);
        floodfill(xvalue+1,i-2,WHITE);
        delay(1);
        //circle(xvalue,i,10);
        //delay(1);
    }
    Beep(3000,5);
    for(i=ypitch;i<440;i++){
        //display batsman position / movement
        char direction[]={dir,'\0'};
        //outtextxy(10,300,direction);
        if(!reached){
            normal_pos(batting_team);
        }
        if(hitted && i>300){
            reached=true;
            if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        }
        xvalue=slope2*(i-ypitch)+xpitch;
        if(kbhit() && !hitted){
            dir=getch();
            if(dir=='q' || dir=='Q'){
                for(;;){
                    if(kbhit()){
                        char conti=getch();
                        if(conti=='q' || conti=='Q')
                            break;
                    }
                }
            }
            else if(dir=='a' || dir=='w' || dir=='d' || dir=='A' || dir=='W' || dir=='D'){
                hitted=true;
                hit_y_point=i;
            }
            else{
                dir='o';
            }
        }
        if(hitted && !checkshot){
            checkshot=true;
            if(endpoint==410 && (dir=='a' || dir=='A' || dir=='w' || dir=='W')){
                done=true;
                run=0;
            }
            if(!done){
                if(ypitch==300){
                    if(xpitch==250){
                        if(endpoint==310 && (dir=='a' || dir=='A')){
                            strike=true;
                        }
                        else if(endpoint==310 && (dir=='d' || dir=='D' || dir=='W' || dir=='w')){
                            run=9;
                        }
                        else if(endpoint==410 && (dir=='d' || dir=='D')){
                            strike=true;
                        }
                    }
                    if(xpitch==320){
                        if(endpoint==310 && (dir=='a' || dir=='A')){
                            strike=true;
                        }
                        else if(endpoint==310 && (dir=='d' || dir=='D' || dir=='w' || dir=='W')){
                            run=9;
                        }
                        else if(endpoint==410 && (dir=='d' || dir=='D')){
                            strike=true;
                        }
                    }
                    else{
                        if(endpoint==310 && (dir=='a' || dir=='A' || dir=='W' || dir=='w')){
                            strike=true;
                        }
                        else if(endpoint==310 && (dir=='d' || dir=='D')){
                            run=9;
                        }
                        else if(endpoint==410 && (dir=='d' || dir=='D')){
                            strike=true;
                        }
                    }
                }
                // ypitch 370
                else{
                    if(xpitch==250){
                        if(dir=='a' || dir=='A'){
                            strike=true;
                        }
                        else{
                            run=8;
                        }
                    }
                    else if(xpitch==320){
                        if(endpoint==310 && (dir=='a' || dir=='A' || dir=='w' || dir=='W')){
                            strike=true;
                        }
                        else if(endpoint==310 && (dir=='d' || dir=='D')){
                            run=8;
                        }
                        else if(endpoint==410 && (dir=='d' || dir=='D')){
                            strike=true;
                        }
                    }
                    else{
                        if(endpoint==310 && (dir=='w' || dir=='W')){
                            strike=true;
                        }
                        else if(endpoint==310 && (dir=='a' || dir=='A' || dir=='D' || dir=='d')){
                            run=8;
                        }
                        else if(endpoint==410 && (dir=='d' || dir=='D')){
                            strike=true;
                        }
                    }
                }
            }
        }
        // movement of ball when it is striked by the batsman
        if(i>370 && strike && ((hit_y_point>300 && ypitch==300) || (hit_y_point>370 && ypitch==370)) && hit_y_point<430){
            int point=(i>hit_y_point)?i:hit_y_point;
            if(dir=='A' || dir=='a'){
                ball_left(dir,xvalue,point,batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
            }
            else if(dir=='W' || dir=='w'){
                ball_straight(dir,xvalue,point,batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
            }
            else{
                ball_right(dir,xvalue,point,batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
            }
            break;
        }
        delay(0.5);
        cleardevice();

        ground(batting_team,bowling_team,t,batsman1,batsman2,bowler,time_line,onstrike,opponent,batfirst);
        if(!reached){
            normal_pos(batting_team);
        }
        if(hitted && i>300){
            reached=true;
            if(dir=='a' || dir=='A'){
                left_pos(batting_team);
            }
            else if(dir=='w' || dir=='W'){
                straight_pos(batting_team);
            }
            else{
                right_pos(batting_team);
            }
        }
        circle(xvalue,i,7);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(xvalue,i-2,WHITE);
        floodfill(xvalue,i+2,WHITE);
        floodfill(xvalue-1,i+2,WHITE);
        floodfill(xvalue+1,i-2,WHITE);
        delay(1);
    }
    if((!hitted || hit_y_point<300 || hit_y_point>430) && endpoint==310){
        if(ypitch==300){
            run=9;
        }
        else{
            if(!hitted){
                run=8;
            }
            else if(hit_y_point<370){
                run=8;
            }
        }
    }
    if(strike && (hit_y_point>300 && hit_y_point<430)){
        if(ypitch==300){
            if(hit_y_point>390 && hit_y_point<430)
                run=3;
            else if(hit_y_point>360){
                int random=rand()%2;
                if(random)
                    run=4;
                else
                    run=6;
            }
            else if(hit_y_point>320){
                int random=rand()%2;
                if(random)
                    run=1;
                else
                    run=2;
            }
            else if(hit_y_point>300)
                run=7;
        }
        else if(ypitch==370 && hit_y_point>370){
            if(hit_y_point>420 && hit_y_point<430){
                run=3;
            }
            else if(hit_y_point>395){
                int random=rand()%2;
                if(random)
                    run=4;
                else
                    run=6;
            }
            else if(hit_y_point>380){
                int random=rand()%2;
                if(random)
                    run=1;
                else
                    run=2;
            }
            else if(hit_y_point>370){
                run=7;
            }
        }
    }
    return run;
}
