#include <iostream>
#include <fstream>
#include <string>
#include "snakegame.h"
#include "GridControl.h" 
#include "Scorebonus.h"
#include "SizeDown.h"
#include "DoubleSize.h"
#include "bonus.h"
using namespace std;

int main(){
    string playername;
    int firstpick;
    int dif; 
    cout<<"Input player name"<<endl;
    cin>>playername; 
    cout<<"-----SNAKE ROULLETE-----"<<endl;
    cout<<"     -----MENU-----"<<endl; 
    cout<<"Options(#1-3): \n"<<"1.Start new game\n"<<"2.Load game\n"<<"3.Exit game\n"<<"-----------------------\n"; 
    cin>>firstpick; 
    if (firstpick==1){
        cout<<"Enter difficulty(#1-3)\n1.Easy\n2.Medium\n3.Hard\n";
        cin>>dif; 
        GridControl newgame(playername,dif); 
        newgame.GridClear(); 
        newgame.Grid(); 
        char input;
        bool end=true; 
        string save;
        while (end!=false){
            cout<<"Enter Direction: left(a) right(d) down(s) up(w) Exit(E) or SaveAndExit(S)\n"; 
            cin>>input; 
            if (input!='S'){
                end=newgame.GridInput(input); 
            }
            else if (input=='S'){
                cout<<"Enter file to save game for later use\n";
                cin>>save; 
                newgame.save(save);
                end=false; 
            }
            if (newgame.bconsum==true){ //if bonus is consumed 
            Bonus* bonobj; 
            bonobj->bonusout(); 
                if (newgame.bonuschoice()==1){
                    Scorebonus bon;
                    int multi= bon.bonuseffect(); 
                    newgame.bonscore(multi); 
                    newgame.bconsum=false; 
                }
                else if (newgame.bonuschoice()==2){
                        DoubleSize obj;
                        obj.bonuseffectSize(); 
                        newgame.isize(); 
                        newgame.bconsum=false;
                }
                else if (newgame.bonuschoice()==3){
                    SizeDown obj2;
                    obj2.bonuseffectDSize(); 
                    newgame.dsize(); 
                    newgame.bconsum=false; 
                }
            }
            newgame.Grid();
        }
        if (end==false){
            cout<<"****GAME OVER****\n---SCORE: "<<newgame.getscore()<<"---";
        }
            
            
    }
    else if (firstpick==2){
        string filen;
        cout<<"Enter save file\n";
        cin>>filen; 
        GridControl loadgame; 
        loadgame.load(filen); 
        char in; 
        bool over=true; 
        while (over!=false){
            cout<<"Enter Direction: left(a) right(d) down(s) up(w) or Exit(E)\n"; 
            cin>>in; 
            over=loadgame.GridInput(in); 
            if (loadgame.bconsum==true){ //if bonus is consumed 
            Bonus* bonobj; 
            bonobj->bonusout(); 
                if (loadgame.bonuschoice()==1){
                    Scorebonus bon;
                    int multi= bon.bonuseffect(); 
                    loadgame.bonscore(multi); 
                    loadgame.bconsum=false; 
                }
                else if (loadgame.bonuschoice()==2){
                        DoubleSize obj;
                        obj.bonuseffectSize(); 
                        loadgame.isize(); 
                        loadgame.bconsum=false;
                }
                else if (loadgame.bonuschoice()==3){
                    SizeDown obj2;
                    obj2.bonuseffectDSize(); 
                    loadgame.dsize(); 
                    loadgame.bconsum=false; 
                }
            }
            loadgame.Grid();
        }
        if (over==false){
            cout<<"****GAME OVER****\n---SCORE: "<<loadgame.getscore()<<"---";
        }
    }

    else if (firstpick==3){return 1;}
    //to run:
    //g++ main.cpp bonus.cpp DoubleSize.cpp GridControl.cpp Scorebonus.cpp SizeDown.cpp snakegame.cpp -o main
    //then ./main 
    return 0; 
}