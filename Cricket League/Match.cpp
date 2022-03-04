#include <iostream>
#include <graphics.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <sstream>
#include "Match.h"
#include "Batsman.h"
#include "Bowler.h"
#include "PTable.h"
using namespace std;

/*Match::Match(){
    cout<<"Obj";
}
void Match::test_details(){
    ifstream fin;
    string teamname="CSKA";
    string afile,bfile;
    afile="Team "+teamname+".txt";
    //bfile="Team "+b.teamname+".txt";
    fin.open(afile);
    if(fin){
        cout<<"Success";
    }
    else{
        cout<<"Fail";
    }
}*/
Match::Match(){
    winbatfirst=false;
    winbychase=false;
    losebatfirst=false;
    losebychase=false;
}
void Match::instructions(){
    int start=10;
    outtextxy(10,start,"Welcome to our Real Cricket Game.");
    start+=20;
    outtextxy(10,start,"Here are the instructions of this game.");
    start+=20;
    outtextxy(10,start,"Read it carefully and enjoy the game!!!!");
    start+=40;
    outtextxy(10,start,"1. The game is an entire IPL season");
    start+=20;
    outtextxy(10,start,"2. First you will get a toss and you have to choose heads/tails");
    start+=20;
    outtextxy(10,start,"3. If you win the toss you have to choose bat/field. If you don't win CPU will make the choice");
    start+=20;
    outtextxy(10,start,"4. Batting is manual and bowling is autoplay");
    start+=20;
    outtextxy(10,start,"5. There are only 3 controls.");
    start+=20;
    outtextxy(10,start,"6. A- Left drive , W- Straight drive , D- Right drive");
    start+=20;
    outtextxy(10,start,"7. Try your best to win matches, you can choose your team for each match");
    start+=20;
    outtextxy(10,start,"8. The runs you hit are calculated by the time at which your strike the bat");
    start+=20;
    outtextxy(10,start,"9. Wait for the ball to pitch which gives a TICK sound. Else it will be counted as dot/wicket");
    start+=20;
    outtextxy(10,start,"10. Run calculation is totally by timing. Understand the game as you play it");
    start+=20;
    outtextxy(10,start,"11. To pause the game press Q.");
    start+=20;
    outtextxy(10,start,"12. To continue the game press Q once again");
    start+=20;
    start+=40;
    outtextxy(10,start,"Enjoy the game.");
    start+=60;
    outtextxy(10,start,"Press any key to continue");
    getch();
    cleardevice();
}
void Match::details(){
    int i;
    ifstream fin;
    string an,bn;
    fin.open("Match Number.txt");
    fin>>matchNo;
    fin.close();
    fin.open("Scheduled.txt");
    /*for(i=0;i<matchNo;i++){
        fin>>a.teamname>>b.teamname;
    }*/

    for(i=0;i<matchNo;i++){
        fin>>an>>bn;
    }
    string anst="a) "+an;
    string bnst="b) "+bn;
    char anAr[anst.length()+1],bnAr[bnst.length()+1];
    strcpy(anAr,anst.c_str());
    strcpy(bnAr,bnst.c_str());
    V:
    outtextxy(100,100,"Choose your team.Enter a or b.");
    outtextxy(50,150,anAr);
    outtextxy(150,150,bnAr);
    char getchoice;
    getchoice=getch();
    if(getchoice=='a' || getchoice=='A' || getchoice=='b' || getchoice=='B'){
        outtextxy(10,10,"Ok");
        delay(2000);
        cleardevice();
    }
    else{
        outtextxy(10,10,"Wrong choice.Enter Again");
        delay(2000);
        cleardevice();
        goto V;
    }
    if(getchoice=='a' || getchoice=='A'){
        a.teamname=an;
        b.teamname=bn;
    }
    else{
        a.teamname=bn;
        b.teamname=an;
    }
    //outtextxy();
    string afile,bfile;
    afile="Team "+a.teamname+".txt";
    bfile="Team "+b.teamname+".txt";
    //a.teamname="RCB";
    //b.teamname="MI";
    //afile="Team MI.txt";
    //bfile="Team CSK.txt";
    fin.close();
    fin.open(afile);
    //fin.open("Team CSK.txt");
    i=0;
    while(fin>>a.players[i].name>>a.players[i].hand>>a.players[i].position>>a.players[i].captain>>a.players[i].runs>>a.players[i].wickets>>a.players[i].bestScore>>a.players[i].bestFigures){
        stringstream ss(a.players[i].bestFigures);
        string substr;
        getline(ss,substr,'/');
        stringstream  number1(substr);
        number1>>a.players[i].bestFigRuns;
        getline(ss,substr,'/');
        stringstream number2(substr);
        number2>>a.players[i].bestFigWickets;
        //cout<<"BestFigRuns : "<<a.players[i].bestFigRuns<<"\t\t\t"<<"BestFigWickets : "<<a.players[i].bestFigWickets<<"\n\n";
        i++;
    }
    fin.close();
    fin.open(bfile);
    i=0;
    while(fin>>b.players[i].name>>b.players[i].hand>>b.players[i].position>>b.players[i].captain>>b.players[i].runs>>b.players[i].wickets>>b.players[i].bestScore>>b.players[i].bestFigures){
        stringstream ss(b.players[i].bestFigures);
        string substr;
        getline(ss,substr,'/');
        stringstream  number1(substr);
        number1>>b.players[i].bestFigRuns;
        getline(ss,substr,'/');
        stringstream number2(substr);
        number2>>b.players[i].bestFigWickets;
        i++;
    }
    //while(fin>>b.players[i].name>>b.players[i].hand>>b.players[i].position>>b.players[i].captain>>b.players[i].runs>>b.players[i].bestScore>>b.players[i].bestFigures){
      //  i++;
    //}



    for(i=0;i<11;i++){
        int j;
        abat[i].name=a.players[i].name;
        bbat[i].name=b.players[i].name;
        //for(j=0;b.players[i].name.length();j++){
         //   bbat[i].name[j]=b.players[i].name[j];
        //}
        abat[i].captain=a.players[i].captain;
        bbat[i].captain=b.players[i].captain;
        if(abat[i].captain){
            abat[i].name+="(c)";
        }
        if(bbat[i].captain){
            bbat[i].name+="(c)";
        }
    }
    for(i=0;i<5;i++){
        int j;
        abowl[i].name=a.players[i+6].name;
        bbowl[i].name=b.players[i+6].name;
        //for(j=0;j<a.players[i+6].name.length();j++){
         //   abowl[i].name[j]=a.players[i+6].name[j];
       //}
        //for(j=0;j<b.players[i+6].name.length();j++){
          //  bbowl[i].name[j]=b.players[i+6].name[j];
        //}
    }
    /*ifstream fin;
    fin.open("Team CSK.txt");
    string s;
    int i;
    string h;
    string p;
    bool c;
    int r;
    string bes="";
    string bowl="";
    while(fin>>s>>h>>p>>c>>r>>bes>>bowl){
            //string s;
            //fin>>s;
            //int i;
            //fin>>i;
        //getline(fin,line);
        //cout<<line<<endl;
        cout<<s<<"\t"<<h<<"\t"<<p<<"\t"<<c<<"\t"<<r<<"\t"<<bes<<"\t"<<bowl<<endl;
    }
    fin.close();*/
    fin.close();
    i=0;
    fin.open("Points Table.txt");
    while(fin>>table[i].teamname>>table[i].matches>>table[i].won>>table[i].lost>>table[i].draw>>table[i].points){
        i++;
    }
    fin.close();
}
void Match::introBat(Player p){
    string name,hand,posi,run,bst;
    name="Name : "+p.name;
    hand="Hand : "+p.hand;
    posi="Position : "+p.position;
    run="Runs : "+to_string(p.runs);
    bst="Best Score : "+to_string(p.bestScore);
    char nameAr[name.length()+1],handAr[hand.length()+1],posiAr[posi.length()+1],runAr[run.length()+1],bstAr[bst.length()+1];
    strcpy(nameAr,name.c_str());
    strcpy(handAr,hand.c_str());
    strcpy(posiAr,posi.c_str());
    strcpy(runAr,run.c_str());
    strcpy(bstAr,bst.c_str());
    outtextxy(450,150,nameAr);
    outtextxy(450,170,handAr);
    outtextxy(450,190,posiAr);
    outtextxy(450,210,runAr);
    outtextxy(450,230,bstAr);
}
void Match::introBowl(Player p){
    string name,wic,bst;
    name="Name : "+p.name;
    wic="Wickets : "+to_string(p.wickets);
    bst="Best Figures : "+p.bestFigures;
    char nameAr[name.length()],wicAr[wic.length()],bstAr[bst.length()];
    strcpy(nameAr,name.c_str());
    strcpy(wicAr,wic.c_str());
    strcpy(bstAr,bst.c_str());
    outtextxy(450,150,nameAr);
    outtextxy(450,170,wicAr);
    outtextxy(450,190,bstAr);
}
void Match::toss(){
    L:
    outtextxy(100,10,"Enter T for tails and H for heads");
    char t;
    t=getch();
    if(t=='T' || t=='t' || t=='H' || t=='h'){
        outtextxy(400,100,"Ok");
    }
    else{
        outtextxy(400,100,"Wrong choice, enter Again");
        delay(2000);
        cleardevice();
        goto L;
    }
    srand(time(0));
    int ran=rand()%2;
    delay(1000);
    outtextxy(100,100,"Spinning.........");
    delay(2000);
    //settextstyle(6,0,10);
    //setcolor(GREEN);
    circle(218,205,40);
    if(ran)
        outtextxy(200,200,"Heads");
    else
        outtextxy(200,200,"Tails");
    delay(2000);
    if((ran && (t=='H' || t=='h')) || (!ran && (t=='T' || t=='t'))){
        C:
        outtextxy(100,300,"You won the toss. Enter B for Batting and F for bowling/fielding.");
        char ch=getch();
        if(ch=='B' || ch=='b' || ch=='f' || ch=='F'){
            outtextxy(400,400,"Ok");
            delay(2000);
        }
        else{
            outtextxy(400,400,"Wrong choice, enter Again");
            delay(2000);
            cleardevice();
            outtextxy(100,10,"Enter T for tails and H for heads");
            outtextxy(400,100,"Ok");
            outtextxy(100,100,"Spinning.........");
            circle(218,205,40);
            if(ran)
                outtextxy(200,200,"Heads");
            else
                outtextxy(200,200,"Tails");
            goto C;
        }
        cleardevice();
        if(ch=='b' || ch=='B'){
            bat(true,0);
            delay(1000);
            cleardevice();
            scoreboard(a);
            delay(10000);
            cleardevice();
            bowl(false,a.runs);
            delay(1000);
            cleardevice();
            scoreboard(b);
            delay(10000);
            cleardevice();
        }
        else{
            bowl(true,0);
            delay(1000);
            cleardevice();
            scoreboard(b);
            delay(10000);
            cleardevice();
            bat(false,b.runs);
            delay(1000);
            cleardevice();
            scoreboard(a);
            delay(10000);
            cleardevice();
        }
    }
    else{
        outtextxy(100,300,"You lost the toss");
        delay(2000);
        int r=rand()%2;
        if(r){
            outtextxy(100,320,"CPU chooses to bat first");
            delay(2000);
            cleardevice();
            bowl(true,0);
            delay(1000);
            cleardevice();
            scoreboard(b);
            delay(10000);
            cleardevice();
            bat(false,b.runs);
            delay(1000);
            cleardevice();
            scoreboard(a);
            delay(10000);
            cleardevice();
        }
        else{
            outtextxy(100,320,"CPU chooses to field/Bowl first");
            delay(2000);
            cleardevice();
            bat(true,0);
            delay(1000);
            cleardevice();
            scoreboard(a);
            delay(10000);
            cleardevice();
            bowl(false,a.runs);
            delay(1000);
            cleardevice();
            scoreboard(b);
            delay(10000);
            cleardevice();
        }
    }
    // select bat or bowl
    //graphdefaults();
    //settextstyle(DEFAULT_FONT,0,2);
}
void Match::bat(bool batfirst,int opponent){// opponent is Opponent Score
    //Batsman abat[11];
    //Bowler bbowl[5];
    Timeline timel;

    int strikers[]={0,1};
    int onstrike=0,bowler=0,hitrun=0;
    while(a.wickets!=10 && a.balls!=120){
        if(!batfirst){
            if((opponent-a.runs)<0){
                winbychase=true;
                break;
            }
        }
        if(!abat[strikers[0]].didbat){
            abat[strikers[0]].didbat=true;
        }
        if(!abat[strikers[1]].didbat){
            abat[strikers[1]].didbat=true;
        }
        ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
        if(!abat[strikers[onstrike]].introduced){
            introBat(a.players[strikers[onstrike]]);
            delay(7000);
            cleardevice();
            abat[strikers[onstrike]].introduced=true;
        }
        ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
        if(!bbowl[bowler].introduced){
            introBowl(b.players[bowler+6]);
            delay(7000);
            cleardevice();
            bbowl[bowler].introduced=true;
        }
        hitrun=bowled(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
        delay(1000);
        bbowl[bowler].balls++;
        a.balls++;
        abat[strikers[onstrike]].balls++;
        try{
            if(hitrun==7 || hitrun==8 || hitrun==9){
                throw hitrun;
            }
            //b.temp[strikers[onstrike]].runs+=random[ran];
            bbowl[bowler].runs+=hitrun;
            abat[strikers[onstrike]].runs+=hitrun;
            a.runs+=hitrun;
            if(hitrun%2!=0){
                onstrike=!onstrike;
                cleardevice();
                ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
            }
            if(bbowl[bowler].balls%6==0){
                onstrike=!onstrike;
                bowler++;
                if(bowler==5){
                    bowler=0;
                }
                cleardevice();
                ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
            }
            char c=(char)(hitrun+48);
            char st[]={c,'\0'};
            outtextxy(616,75,st);
            timel.timeline[timel.limit]=c;
            timel.limit++;
            timel.limit=timel.limit%6;
        }
        catch(int w){
            abat[strikers[onstrike]].status=false;
            timel.timeline[timel.limit]='w';
            timel.limit++;
            timel.limit=timel.limit%6;
            bbowl[bowler].wickets++;
            strikers[onstrike]= (strikers[0]>strikers[1]?strikers[0]:strikers[1])+1;
            a.wickets++;
            if(bbowl[bowler].balls%6==0){
                bowler++;
                onstrike=!onstrike;
                if(bowler==5){
                    bowler=0;
                }
            }
            outtextxy(615,75,"W");
            if(w==7){
                outtextxy(527,75,"CAUGHT!!");
                delay(1000);
            }
            else if(w==8){
                stumped_ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
                line(198,405,425,405);
                outtextxy(525,75,"BOWLED!!");
                delay(1000);
                //display CLEAN BOWLED and also stumps shatteres
            }
            else if(w==9){
                stumped_ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
                line(198,405,425,405);
                outtextxy(505,75,"HIT WICKET!!");
                delay(1000);
                //display HIT WICKET and also stumps shattered.
            }
            cleardevice();
            ground(a.teamname,b.teamname,a,abat[strikers[0]],abat[strikers[1]],bbowl[bowler],timel,onstrike,opponent,batfirst);
        }
    }
    if(!batfirst && !winbychase && a.runs!=b.runs){
        losebychase=true;
    }
}
void Match::bowl(bool batfirst,int opponent){
    //Batsman bbat[11];
    //Bowler abowl[5];
    Timeline timel;
    int strikers[]={0,1};
    int onstrike=0,bowler=0;
    int random[]={0,0,1,1,1,1,8,2,2,2,3,3,4,4,4,4,5,6,6,8};
    while(b.wickets!=10 && b.balls!=120){
        //char op[to_string(opponent).length()+1],br[to_string(b.runs).length()];
        //strcpy(op,to_string(opponent).c_str());
        //strcpy(br,to_string(b.runs).c_str());
        //outtextxy(0,300,op);
        //outtextxy(0,320,br);
        if(!batfirst){
            if((opponent-b.runs)<0){
                losebatfirst=true;
                break;
            }
        }
        if(!bbat[strikers[0]].didbat){
            bbat[strikers[0]].didbat=true;
        }
        if(!bbat[strikers[1]].didbat){
            bbat[strikers[1]].didbat=true;
        }
        ground(b.teamname,a.teamname,b,bbat[strikers[0]],bbat[strikers[1]],abowl[bowler],timel,onstrike,opponent,batfirst);
        if(!bbat[strikers[onstrike]].introduced){
            introBat(b.players[strikers[onstrike]]);
            delay(7000);
            cleardevice();
            bbat[strikers[onstrike]].introduced=true;
        }
        ground(b.teamname,a.teamname,b,bbat[strikers[0]],bbat[strikers[1]],abowl[bowler],timel,onstrike,opponent,batfirst);
        if(!abowl[bowler].introduced){
            introBowl(a.players[bowler+6]);
            delay(7000);
            abowl[bowler].introduced=true;
        }
        delay(1000);
        cleardevice();
        ground(b.teamname,a.teamname,b,bbat[strikers[0]],bbat[strikers[1]],abowl[bowler],timel,onstrike,opponent,batfirst);
        abowl[bowler].balls++;
        int ran=rand()%20;
        b.balls++;
        bbat[strikers[onstrike]].balls++;
        try{
            if(random[ran]==8){
                throw 'W';
            }
            //b.temp[strikers[onstrike]].runs+=random[ran];
            abowl[bowler].runs+=random[ran];
            bbat[strikers[onstrike]].runs+=random[ran];
            b.runs+=random[ran];
            if(random[ran]%2!=0){
                onstrike=!onstrike;
                cleardevice();
                ground(b.teamname,a.teamname,b,bbat[strikers[0]],bbat[strikers[1]],abowl[bowler],timel,onstrike,opponent,batfirst);
            }
            if(abowl[bowler].balls%6==0){
                onstrike=!onstrike;
                bowler++;
                if(bowler==5){
                    bowler=0;
                }
                cleardevice();
                ground(b.teamname,a.teamname,b,bbat[strikers[0]],bbat[strikers[1]],abowl[bowler],timel,onstrike,opponent,batfirst);
            }
            char c=(char)(random[ran]+48);
            char st[]={c,'\0'};
            outtextxy(616,75,st);
            timel.timeline[timel.limit]=c;
            timel.limit++;
            timel.limit=timel.limit%6;
        }
        catch(char c){
            bbat[strikers[onstrike]].status=false;
            timel.timeline[timel.limit]='w';
            timel.limit++;
            timel.limit=timel.limit%6;
            abowl[bowler].wickets++;
            strikers[onstrike]= (strikers[0]>strikers[1]?strikers[0]:strikers[1])+1;
            b.wickets++;
            if(abowl[bowler].balls%6==0){
                bowler++;
                onstrike=!onstrike;
                if(bowler==5){
                    bowler=0;
                }
            }
            outtextxy(615,75,"W");
            delay(1000);
            cleardevice();
            ground(b.teamname,a.teamname,b,bbat[strikers[0]],bbat[strikers[1]],abowl[bowler],timel,onstrike,opponent,batfirst);
        }
    }
    if(!batfirst && !losebatfirst && a.runs!=b.runs){
        winbatfirst=true;
    }
}
void Match::write_back(){
    ofstream fout;
    string afile="Team "+a.teamname+".txt";
    string bfile="Team "+b.teamname+".txt";
    fout.open(afile);
    //cout<<"\n\n\n"<<abat[0].runs<<"\n\n\n";
    //fout.open("Test Write.txt");
    int i,best=0;
    for(i=0;i<11;i++){
        if(abat[i].runs>a.players[i].bestScore)
            best=abat[i].runs;
        else{
            best=a.players[i].bestScore;
        }
        if(i<6){
            fout<<a.players[i].name<<" "<<a.players[i].hand<<" "<<a.players[i].position<<" "<<a.players[i].captain<<" "<<a.players[i].runs+abat[i].runs<<" "<<a.players[i].wickets<<" "<<best<<" "<<a.players[i].bestFigures<<"\n";
            a.players[i].runs+=abat[i].runs;
        }
        else{
            if(abowl[i-6].wickets>=a.players[i].bestFigWickets){
                if(abowl[i-6].wickets>a.players[i].bestFigWickets){
                    a.players[i].bestFigWickets=abowl[i-6].wickets;
                    a.players[i].bestFigRuns=abowl[i-6].runs;
                }
                else if(abowl[i-6].runs<a.players[i].bestFigRuns){
                    a.players[i].bestFigRuns=abowl[i-6].runs;
                }
                a.players[i].bestFigures=to_string(a.players[i].bestFigRuns)+"/"+to_string(a.players[i].bestFigWickets);
    //            cout<<"\n\n\n"<<a.players[i].bestFigures<<"\n\n\n\n";
            }
            fout<<a.players[i].name<<" "<<a.players[i].hand<<" "<<a.players[i].position<<" "<<a.players[i].captain<<" "<<a.players[i].runs+abat[i].runs<<" "<<a.players[i].wickets+abowl[i-6].wickets<<" "<<best<<" "<<a.players[i].bestFigures<<"\n";
            a.players[i].runs+=abat[i].runs;
            a.players[i].wickets+=abowl[i-6].wickets;
        }
    }
    fout.close();
    fout.open(bfile);
    best=0;
    for(i=0;i<11;i++){
        if(bbat[i].runs>b.players[i].bestScore)
            best=bbat[i].runs;
        else{
            best=b.players[i].bestScore;
        }
        if(i<6){
            fout<<b.players[i].name<<" "<<b.players[i].hand<<" "<<b.players[i].position<<" "<<b.players[i].captain<<" "<<b.players[i].runs+bbat[i].runs<<" "<<b.players[i].wickets<<" "<<best<<" "<<b.players[i].bestFigures<<"\n";
            b.players[i].runs+=bbat[i].runs;
        }
        else{
            if(bbowl[i-6].wickets>=b.players[i].bestFigWickets){
                if(bbowl[i-6].wickets>b.players[i].bestFigWickets){
                    b.players[i].bestFigWickets=bbowl[i-6].wickets;
                    b.players[i].bestFigRuns=bbowl[i-6].runs;
                }
                else if(bbowl[i-6].runs<b.players[i].bestFigRuns){
                    b.players[i].bestFigRuns=bbowl[i-6].runs;
                }
                b.players[i].bestFigures=to_string(b.players[i].bestFigRuns)+"/"+to_string(b.players[i].bestFigWickets);
                //cout<<"\n\n\n"<<a.players[i].bestFigures<<"\n\n\n\n";
            }
            fout<<b.players[i].name<<" "<<b.players[i].hand<<" "<<b.players[i].position<<" "<<b.players[i].captain<<" "<<b.players[i].runs+bbat[i].runs<<" "<<b.players[i].wickets+bbowl[i-6].wickets<<" "<<best<<" "<<b.players[i].bestFigures<<"\n";
            b.players[i].runs+=bbat[i].runs;
            b.players[i].wickets+=bbowl[i-6].wickets;
        }
    }
    fout.close();
    fout.open("Points Table.txt");
    if(winbatfirst || winbychase){
        int j;
        for(j=0;j<8;j++){
            if(!table[j].teamname.compare(a.teamname)){
                table[j].matches++;
                table[j].won++;
                table[j].points+=2;
            }
            if(!table[j].teamname.compare(b.teamname)){
                table[j].matches++;
                table[j].lost++;
            }
        }
    }
    else if(losebatfirst || losebychase){
        int j;
        for(j=0;j<8;j++){
            if(!table[j].teamname.compare(a.teamname)){
                table[j].matches++;
                table[j].lost++;
            }
            if(!table[j].teamname.compare(b.teamname)){
                table[j].matches++;
                table[j].won++;
                table[j].points+=2;
            }
        }
    }
    else{
        int j;
        for(j=0;j<8;j++){
            if(!table[j].teamname.compare(a.teamname)){
                table[j].matches++;
                table[j].draw++;
                table[j].points+=1;
            }
            if(!table[j].teamname.compare(b.teamname)){
                table[j].matches++;
                table[j].draw++;
                table[j].points+=1;
            }
        }
    }
    int x;
    for(x=0;x<8;x++){
        fout<<table[x].teamname<<" "<<table[x].matches<<" "<<table[x].won<<" "<<table[x].lost<<" "<<table[x].draw<<" "<<table[x].points<<"\n";
    }
    fout.close();
    matchNo++;
    fout.open("Match Number.txt");
    fout<<matchNo;
}
void Match::scoreboard(Team ob){
    int start=50;
    int i;
    char aTeam[a.teamname.length()+1],bTeam[b.teamname.length()+1];
    strcpy(aTeam,a.teamname.c_str());
    strcpy(bTeam,b.teamname.c_str());
    if(!a.teamname.compare(ob.teamname)){
        outtextxy(210,20,aTeam);
        for(i=0;i<11;i++){
            char playerName[abat[i].name.length()+1];
            strcpy(playerName,abat[i].name.c_str());
            outtextxy(10,start,playerName);
            if(abat[i].didbat){
                if(abat[i].status){
                    outtextxy(200,start,"not out");
                }
                else{
                    outtextxy(200,start,"out");
                }
            string batScore=to_string(abat[i].runs)+"("+to_string(abat[i].balls)+")";
            char batScoreAr[batScore.length()+1];
            strcpy(batScoreAr,batScore.c_str());
            outtextxy(350,start,batScoreAr);
            }
            start+=20;
        }
        start=360;
        outtextxy(210,300,bTeam);
        outtextxy(10,330,"Name");
        outtextxy(138,330,"Overs");
        outtextxy(215,330,"Runs");
        outtextxy(270,330,"Wickets");
        outtextxy(340,330,"Economy");
        for(i=0;i<5;i++){
            int whole=bbowl[i].balls/6,remain=bbowl[i].balls%6;
            string ov=to_string(whole)+"."+to_string(remain);
            float econ=(bbowl[i].runs/(float)bbowl[i].balls)*6;
            char bName[bbowl[i].name.length()+1],bRuns[to_string(bbowl[i].runs).length()+1],bWick[to_string(bbowl[i].wickets).length()+1],bEco[to_string(econ).length()+1],bOvers[ov.length()+1];
            snprintf(bEco,sizeof(bEco),"%0.2f",econ);
            strcpy(bName,bbowl[i].name.c_str());
            strcpy(bOvers,ov.c_str());
            sprintf(bRuns,"%d",bbowl[i].runs);
            sprintf(bWick,"%d",bbowl[i].wickets);
            outtextxy(10,start,bName);
            outtextxy(150,start,bOvers);
            outtextxy(220,start,bRuns);
            outtextxy(290,start,bWick);
            outtextxy(350,start,bEco);

            start+=20;
        }
    }
    else{
        outtextxy(210,20,bTeam);
        for(i=0;i<11;i++){
            char playerName[bbat[i].name.length()+1];
            strcpy(playerName,bbat[i].name.c_str());
            outtextxy(10,start,playerName);
            if(bbat[i].didbat){
                if(bbat[i].status){
                    outtextxy(200,start,"not out");
                }
                else{
                    outtextxy(200,start,"out");
                }
            }
            string batScore=to_string(bbat[i].runs)+"("+to_string(bbat[i].balls)+")";
            char batScoreAr[batScore.length()+1];
            strcpy(batScoreAr,batScore.c_str());
            outtextxy(350,start,batScoreAr);
            start+=20;
        }
        start=360;
        outtextxy(210,300,aTeam);
        outtextxy(10,330,"Name");
        outtextxy(138,330,"Overs");
        outtextxy(215,330,"Runs");
        outtextxy(270,330,"Wickets");
        outtextxy(340,330,"Economy");
        for(i=0;i<5;i++){
            int whole=abowl[i].balls/6,remain=abowl[i].balls%6;
            string ov=to_string(whole)+"."+to_string(remain);
            float econ=(abowl[i].runs/(float)abowl[i].balls)*6;
            char aName[abowl[i].name.length()+1],aRuns[to_string(abowl[i].runs).length()+1],aWick[to_string(abowl[i].wickets).length()+1],aEco[to_string(econ).length()+1],aOvers[ov.length()+1];
            snprintf(aEco,sizeof(aEco),"%0.2f",econ);
            strcpy(aName,abowl[i].name.c_str());
            strcpy(aOvers,ov.c_str());
            sprintf(aRuns,"%d",abowl[i].runs);
            sprintf(aWick,"%d",abowl[i].wickets);
            outtextxy(10,start,aName);
            outtextxy(150,start,aOvers);
            outtextxy(220,start,aRuns);
            outtextxy(290,start,aWick);
            outtextxy(350,start,aEco);

            start+=20;
        }
    }
}
void Match::result(){
    if(winbychase){
        awin=true;
        int rem=10-a.wickets;
        //char projected_ca[to_string(projected).length()+1]
        //sprintf(projected_ca,"%d",projected);
        string message=a.teamname+" win the match by "+to_string(rem)+" wickets";
        char msg[message.length()+1];
        strcpy(msg,message.c_str());
        outtextxy(100,100,msg);
    }
    else if(winbatfirst){
        awin=true;
        int rem=a.runs-b.runs;
        string message=a.teamname+" win the match by "+to_string(rem)+" runs";
        char msg[message.length()+1];
        strcpy(msg,message.c_str());
        outtextxy(100,100,msg);
    }
    else if(losebatfirst){
        bwin=true;
        int rem=10-b.wickets;
        string message=a.teamname+" lost the match by "+to_string(rem)+" wickets";
        char msg[message.length()+1];
        strcpy(msg,message.c_str());
        outtextxy(100,100,msg);
    }
    else if(losebychase){
        bwin=true;
        int rem=b.runs-a.runs;
        string message=a.teamname+" lost the match by "+to_string(rem)+" runs";
        char msg[message.length()+1];
        strcpy(msg,message.c_str());
        outtextxy(100,100,msg);
    }
    else{
        outtextxy(100,100,"Match Drawn");
    }
}
void Match::displayPoints(){
    int i;
    int start=140;
    outtextxy(200,50,"POINTS TABLE");
    outtextxy(100,100,"Teams\t     Matches   Won     Lost    Draw    Points");
    for(i=0;i<8;i++){
        string txt;
        if(table[i].teamname.length()==3)
            txt=table[i].teamname+"               "+to_string(table[i].matches)+"           "+to_string(table[i].won)+"           "+to_string(table[i].lost)+"          "+to_string(table[i].draw)+"           "+to_string(table[i].points);
        else if(table[i].teamname.length()==2)
            txt=table[i].teamname+"                 "+to_string(table[i].matches)+"           "+to_string(table[i].won)+"           "+to_string(table[i].lost)+"          "+to_string(table[i].draw)+"           "+to_string(table[i].points);
        else
            txt=table[i].teamname+"              "+to_string(table[i].matches)+"           "+to_string(table[i].won)+"           "+to_string(table[i].lost)+"          "+to_string(table[i].draw)+"           "+to_string(table[i].points);
        char txtAr[txt.length()+1];
        strcpy(txtAr,txt.c_str());
        //cout<<table[i].teamname<<"\t\t"<<table[i].matches<<"\t"<<table[i].won<<"\t"<<table[i].lost<<"\t"<<table[i].draw<<"\t  "<<table[i].points<<"\n";
        outtextxy(100,start,txtAr);
        start+=20;
    }
}

void Match::purpleCap(){
    ifstream fin;
    fin.open("Purple Cap.txt");
    Player pc[10];
    int i=0,j,k;
    while(fin>>pc[i].name>>pc[i].wickets){
        i++;
    }
    for(i=6;i<11;i++){
        for(j=0;j<10;j++){
            if(a.players[i].wickets>pc[j].wickets){
                Player temp1,temp2;
                temp1=pc[j];
                pc[j].name=a.players[i].name;
                pc[j].wickets=a.players[i].wickets;
                for(k=j;k<9;k++){
                    temp2=pc[k+1];
                    pc[k+1].name=temp1.name;
                    pc[k+1].wickets=temp1.wickets;
                    temp1=temp2;
                }
                break;
            }
        }
    }

    for(i=6;i<11;i++){
        for(j=0;j<10;j++){
            if(b.players[i].wickets>pc[j].wickets){
                Player temp1,temp2;
                temp1=pc[j];
                pc[j].name=b.players[i].name;
                pc[j].wickets=b.players[i].wickets;
                for(k=j;k<9;k++){
                    temp2=pc[k+1];
                    pc[k+1].name=temp1.name;
                    pc[k+1].wickets=temp1.wickets;
                    temp1=temp2;
                }
                break;
            }
        }
    }
    outtextxy(200,100,"Purple Cap List");
    int start=150;
    for(i=0;i<10;i++){
        string msg=pc[i].name+"    "+to_string(pc[i].wickets);
        char msgAr[msg.length()];
        strcpy(msgAr,msg.c_str());
        outtextxy(100,start,msgAr);
        start+=20;
    }
    fin.close();
    ofstream fout;
    fout.open("Purple Cap.txt");
    for(i=0;i<10;i++){
        fout<<pc[i].name<<" "<<pc[i].wickets<<"\n";
    }
    fout.close();
}
void Match::orangeCap(){
    ifstream fin;
    fin.open("Orange Cap.txt");
    if(fin){
        cleardevice();
        delay(3000);
        cleardevice();
    }
    Player oc[10];
    int i=0,j,k;
    while(fin>>oc[i].name>>oc[i].runs){
        i++;
    }
    for(i=0;i<11;i++){
        for(j=0;j<10;j++){
            if(a.players[i].runs>oc[j].runs){
                Player temp1,temp2;
                temp1=oc[j];
                oc[j].name=a.players[i].name;
                oc[j].runs=a.players[i].runs;
                for(k=j;k<9;k++){
                    temp2=oc[k+1];
                    oc[k+1].name=temp1.name;
                    oc[k+1].runs=temp1.runs;
                    temp1=temp2;
                }
                break;
            }
        }
    }

    for(i=0;i<11;i++){
        for(j=0;j<10;j++){
            if(b.players[i].runs>oc[j].runs){
                Player temp1,temp2;
                temp1=oc[j];
                oc[j].name=b.players[i].name;
                oc[j].runs=b.players[i].runs;
                for(k=j;k<9;k++){
                    temp2=oc[k+1];
                    oc[k+1].name=temp1.name;
                    oc[k+1].runs=temp1.runs;
                    temp1=temp2;
                }
                break;
            }
        }
    }
    outtextxy(200,100,"Orange Cap List");
    int start=150;
    for(i=0;i<10;i++){
        string msg=oc[i].name+"    "+to_string(oc[i].runs);
        char msgAr[msg.length()];
        strcpy(msgAr,msg.c_str());
        outtextxy(100,start,msgAr);
        start+=20;
    }
    fin.close();
    ofstream fout;
    fout.open("Orange Cap.txt");
    for(i=0;i<10;i++){
        fout<<oc[i].name<<" "<<oc[i].runs<<"\n";
    }
    fout.close();
}
