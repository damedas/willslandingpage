#include "snakegame.h"

snakegame::snakegame(){}

snakegame::snakegame(string pname, int diffy){
    player= pname;
    diff= diffy; 
    score=0; 
    slength=0; 

    if (diff==1){
        width= 6;
        height= 7; 
        x=2;
        y=1;
    }
    else if (diff==2){
        width=5;
        height=6;
        x=2; //headx
        y=1; //heady
    }
    else if (diff==3){
        width=4;
        height=5; 
        x=2;
        y=1;
    }
}
snakegame::snakegame(string pname, int diffy, int sx, int sy, int sscore, vector<int> tx, vector<int> ty, int sslength){
    player=pname; 
    diff= diffy; 
    score= sscore;
    slength= sslength; 

    if (diff==1){
        width= 6;
        height= 7; 
        x=sx;
        y=sy;
    }
    else if (diff==2){
        width=5;
        height=6;
        x=sx;
        y=sy;
    }
    else if (diff==3){
        width=4;
        height=5; 
        x=sx;
        y=sy;
    }
}
